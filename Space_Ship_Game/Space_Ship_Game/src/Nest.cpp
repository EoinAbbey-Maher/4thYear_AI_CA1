#include "..\include\Nest.h"

Nest::Nest(sf::RenderWindow& t_window):
	m_lifeTotal{ 4 },
	m_missileFired{ false },
	m_window(t_window)
{
	setBody();
}

Nest::~Nest()
{
}

void Nest::rotate()
{
	m_nestShape.rotate(rotateSpeed);
}

void Nest::render()
{
	m_window.draw(m_nestShape);
}

void Nest::shootMissile(sf::RenderWindow& t_window)
{
	m_missile.render(t_window);
	m_missile.seek(m_player.m_position);
}

void Nest::checkPosition(RoomBuilder& t_roombuilder)
{
	for each (Tile & tile in t_roombuilder.m_tiles)
	{

		
		if (m_nestShape.getGlobalBounds().intersects(tile.m_bodySquare.getGlobalBounds())&& tile.m_type == TileType::WALL)
		{
			m_nestPosition = { m_random,m_random };
		}
	}
}

void Nest::radiusCheck()
{
	shootMissile(m_window);
}

void Nest::deployPredators()
{

}

void Nest::setBody()
{
	if (m_nestTexture.loadFromFile("ASSETS\\IMAGES\\nest.png"))
	{
		//std::cout << "loading nest" << std::endl;
		m_nestShape.setTexture(&m_nestTexture);
	}

	m_nestPosition = { m_random,m_random};
	m_nestShape.setPosition(m_nestPosition);
	m_nestShape.setSize(m_size);
	m_nestShape.setOrigin(m_size.x * .5, m_size.y* .5);
	

}
