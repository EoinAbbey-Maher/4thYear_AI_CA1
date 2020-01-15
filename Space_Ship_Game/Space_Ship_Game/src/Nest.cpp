#include "..\include\Nest.h"

Nest::Nest():
	m_lifeTotal{ 4 },
	m_missileFired{ false }
{
	m_nestPosition = { random,random };
	m_nestSprite.setPosition(m_nestPosition);
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
	
	m_missile.render(t_window);
}

void Nest::radiusCheck()
{
	m_missile.seek();
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
	m_nestSprite.setOrigin(m_nestTexture.getSize().x / 2, m_nestTexture.getSize().y / 2);

}
