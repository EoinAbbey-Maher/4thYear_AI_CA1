#include "Predator.h"

Predator::Predator()
{
}

void Predator::setBody(sf::Texture* t_texture, sf::Vector2f t_position)
{
	m_predatorPosition = t_position;
	m_predatorShape.setTexture(t_texture);
	m_predatorShape.setPosition(t_position);
	m_predatorShape.setSize(m_size);
	m_predatorShape.setOrigin(m_size.x * .5, m_size.y * .5);
}

void Predator::update(RoomBuilder& m_roombuilder,sf::Vector2f& m_player)
{
	std::cout << m_predatorPosition.x << std::endl;
	std::cout << m_predatorPosition.y << std::endl;


	searchForPlayer(m_player);
	move();
	checkCollisions(m_roombuilder);
}

void Predator::render(sf::RenderWindow& t_window)
{
	t_window.draw(m_predatorShape);
}

void Predator::checkCollisions(RoomBuilder& t_roombuilder)
{
	for each (Tile & tile in t_roombuilder.m_tiles)
	{
		if (m_predatorShape.getGlobalBounds().intersects(tile.m_bodySquare.getGlobalBounds()) && tile.m_type == TileType::WALL)
		{
			m_predatorPosition = m_lastPosition;
			m_predatorShape.setPosition(m_predatorPosition);
		}
	}
}

void Predator::searchForPlayer(sf::Vector2f& pos)
{
	m_direction.x = pos.x - m_predatorPosition.x;
	m_direction.y = pos.y - m_predatorPosition.y;

	m_distance = std::sqrt((m_direction.x * m_direction.x) + (m_direction.y * m_direction.y));
	m_rotation = std::atan(m_direction.y / m_direction.x) * (180 / 3.14159265358979323846);
	m_predatorShape.setRotation(m_rotation);
}

void Predator::move()
{
	m_velocity = m_direction * MAXPREDATORVELOCITY;
	m_predatorPosition = m_predatorPosition + m_velocity;
	m_predatorShape.setPosition(m_predatorPosition);
}


