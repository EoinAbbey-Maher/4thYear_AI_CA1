#include "Missile.h"

Missile::Missile() :
	m_timeAlive{sf::seconds(5) },
	m_alive { false }
{
	m_missilePosition = { 0,0 };
	m_missileSprite.setPosition(m_missilePosition);
}

void Missile::seek()
{
	

}

void Missile::render(sf::RenderWindow& t_window)
{
	t_window.draw(m_missileSprite);
}

void Missile::setSprite()
{
	if (!m_missileTexture.loadFromFile("ASSETS\\IMAGES\\missile.png"))
	{
		std::cout << "problem loading missile" << std::endl;
	}
	m_missileSprite.setTexture(m_missileTexture);
	m_missileSprite.setOrigin(m_missileTexture.getSize().x / 2, m_missileTexture.getSize().y / 2);
}
