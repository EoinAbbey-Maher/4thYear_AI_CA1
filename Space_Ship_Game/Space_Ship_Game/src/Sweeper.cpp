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
}

void Sweeper::update(RoomBuilder& t_room)
{
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

void Sweeper::searchForPlayerWorker()
{
}

void Sweeper::fleeFromPlayer()
{
}
