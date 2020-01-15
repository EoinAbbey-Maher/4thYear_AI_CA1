#include "..\include\Nest.h"

Nest::Nest(sf::RenderWindow& t_window):
	m_lifeTotal{ 4 },
	m_missileFired{ false },
	m_window(t_window)
{
	setSprite();
}

Nest::~Nest()
{
}

void Nest::rotate()
{
	m_nestSprite.rotate(rotateSpeed);
}

void Nest::render(sf::RenderWindow& t_window)
{
	t_window.draw(m_nestSprite);
}

void Nest::shootMissile(sf::RenderWindow& t_window)
{
	
	//m_missile.render(t_window);
	//m_missile.seek();
}

void Nest::checkPosition(RoomBuilder& t_roombuilder)
{
	for each (Tile & tile in t_roombuilder.m_tiles)
	{
		if (m_nestSprite.getGlobalBounds().intersects(tile.m_bodySquare.getGlobalBounds())&& tile.m_type == TileType::WALL)
		{
			setSprite();
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

void Nest::setSprite()
{
	if (!m_nestTexture.loadFromFile("ASSETS\\IMAGES\\nest.png"))
	{
		std::cout << "problem loading nest" << std::endl;
	}
	m_nestSprite.setTexture(m_nestTexture);
	m_nestSprite.setScale(0.7f,0.7f);
	m_nestSprite.setOrigin(m_nestTexture.getSize().x / 2, m_nestTexture.getSize().y / 2);
	m_nestPosition = { static_cast <float>(rand() % GlobalSettings::s_width),static_cast <float>(rand() % GlobalSettings::s_width) };
	m_nestSprite.setPosition(m_nestPosition);

}
