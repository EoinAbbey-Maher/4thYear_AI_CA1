#include "Missile.h"

Missile::Missile() :
	m_timeAlive{sf::seconds(5) },
	m_alive { false }
{
	m_missilePosition = { 0,0 };
	m_missileSprite.setPosition(m_missilePosition);
}

void Missile::seek(sf::Vector2f& t_playerPos)
{
	m_target.x = t_playerPos.x - m_missilePosition.x;
	m_target.y = t_playerPos.y - m_missilePosition.y;

	m_distance = std::sqrt((m_target.x * m_target.x) + (m_target.y * m_target.y));
	m_rotation = std::atan(m_target.y / m_target.x) * (180 / 3.14159265358979323846);

	m_missileSprite.setRotation(m_rotation);
	m_missileVelocity = (m_target / (m_distance * .2f));
}



void Missile::move()
{
	m_missileVelocity = m_target * MAX_SPEED;
	m_missilePosition = m_missilePosition + m_missileVelocity;
	m_missileSprite.setPosition(m_missilePosition);
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
