#include "Sweeper.h"

Sweeper::Sweeper()
{
}

void Sweeper::init(sf::Texture* t_texture, sf::Vector2f t_position)
{
	m_position = t_position;
	m_body.setTexture(t_texture);
	m_body.setPosition(t_position);
	m_body.setSize(m_size);
	m_body.setOrigin(m_size.x * .5, m_size.y * .5);
	
	m_viewCone.append(m_position);
	m_viewCone.append(sf::Vector2f(-25 + cos(m_orientation), 60 + sin(m_orientation)));
	m_viewCone.append(sf::Vector2f(25 + cos(m_orientation), 60 + sin(m_orientation)));
}

void Sweeper::update(RoomBuilder& t_room, Player& t_player)
{
	updateCone(t_player);
	switch (m_action)
	{
	case WANDERING:
		wander(t_room);
		break;
	case CHASING:
		
		break;
	case FLEEING:
		fleeFromPlayer(t_player);
		break;
	default:
		break;
	}

	m_lastPosition = m_position;
	wander(t_room);
	m_body.setPosition(m_position);
}

void Sweeper::render(sf::RenderWindow& t_window)
{
	t_window.draw(m_body);

}

void Sweeper::checkCollisions(RoomBuilder& t_builder)
{
	for each (Tile & tile in t_builder.m_tiles)
	{
		if (m_body.getGlobalBounds().intersects(tile.m_bodySquare.getGlobalBounds()) && tile.m_type == TileType::WALL)
		{
			m_position = m_lastPosition;
			m_acceleration *= -1;
		}
	}
}

void Sweeper::wander(RoomBuilder& t_room)
{
	int rotation = ((rand() % 4));
	switch (rand() % 2)
	{
	case 0:
		rotation *= -1;

		break;
	default:
		break;
	}


	m_orientation += rotation;
	m_body.setRotation(m_orientation);

	m_velocity.x = std::cos(m_orientation * RADIANSVAL) * m_acceleration;
	m_velocity.y = std::sin(m_orientation * RADIANSVAL) * m_acceleration;

	m_position.x += (m_velocity.x * -1);
	m_position.y += (m_velocity.y * -1);

	checkCollisions(t_room);
}

void Sweeper::ChaseWorker(RoomBuilder& t_room)
{
}

void Sweeper::fleeFromPlayer(Player& t_player)
{
	sf::Vector2f direction = m_position - t_player.m_position;
	m_orientation = (atan2(direction.y, direction.x) / RADIANSVAL) * -1;
	m_body.setRotation(m_orientation);

	m_velocity.x = std::cos(m_orientation * RADIANSVAL) * m_acceleration;
	m_velocity.y = std::sin(m_orientation * RADIANSVAL) * m_acceleration;



	m_position.x += (m_velocity.x * -1);
	m_position.y += (m_velocity.y * -1);
	updateCone(t_player);
}

void Sweeper::updateCone(Player& t_player)
{
	m_viewCone.clear();

	m_coneLeft.x = m_coneLenght * std::cos((m_orientation + m_FoV) * RADIANSVAL * -1);
	m_coneLeft.y = m_coneLenght * std::sin((m_orientation + m_FoV) * RADIANSVAL * -1);
	m_coneLeft += m_position;

	m_coneRight.x = m_coneLenght * std::cos((m_orientation - m_FoV) * RADIANSVAL * -1);
	m_coneRight.y = m_coneLenght * std::sin((m_orientation - m_FoV) * RADIANSVAL * -1);
	m_coneRight += m_position;

	m_viewCone.append(m_position);
	m_viewCone.append(m_coneLeft);
	m_viewCone.append(m_coneRight);


	sf::Vector2f distance = t_player.m_position - m_position;
	float distToPlayer = sqrt((distance.x * distance.x) + (distance.y * distance.y)); //Lenght

	if (distToPlayer < m_coneLenght)
	{
		float posMag = sqrt((m_velocity.x * m_velocity.x) + (m_velocity.y * m_velocity.y));
		float distMag = sqrt((distance.x * distance.x) + (distance.y * distance.y));

		sf::Vector2f unitPos = sf::Vector2f(m_velocity.x / posMag, m_velocity.y / posMag);
		sf::Vector2f unitDistance = sf::Vector2f(distance.x / distMag, distance.y / distMag);

		float dotProduct = ((unitPos.x * unitDistance.x) + (unitPos.x * unitDistance.y)) * (m_orientation * -1);
		if (dotProduct > 1.0f)
		{
			dotProduct = 1.0f;
		}

		float angleBetween = std::acos(dotProduct) * RADIANSVAL;

		if (angleBetween < m_FoV)
		{
			for (int i = 0; i < m_viewCone.getVertexCount(); i++)
			{
				m_action = CurrentAction::FLEEING;
			}
		}
		else
		{
			m_action = CurrentAction::WANDERING;
		}
		
	}

	else
	{
		for (int i = 0; i < m_viewCone.getVertexCount(); i++)
		{
			m_viewCone[i].color = sf::Color(255, 255, 255, 125);
		}
	}
}
