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

void Missile::init(sf::Texture const & t_texture, sf::Vector2f t_position, float t_orientation)
{
	m_body.setTexture(&t_texture);
	m_body.setSize(m_size);
	m_body.setPosition(t_position);
	m_body.setOrigin(m_size.x * .5, m_size.y * .5);
	m_body.setRotation(t_orientation);
	m_speed = s_MAX_SPEED;
	m_alive = true;
}

bool Missile::update(RoomBuilder& t_tiles, std::vector<Sweeper>& t_sweepers)
{
	if (!inUse())
	{
		// If this projectile is not in use, there is no update routine to perform.
		return false;
	}

	sf::Vector2f position = m_body.getPosition();
	sf::Vector2f newPos(position.x + std::cos(RADIANSVAL * m_body.getRotation()) * m_speed,
	position.y + std::sin(RADIANSVAL* m_body.getRotation()) * m_speed);

	m_body.setPosition(newPos.x, newPos.y);

	if (projectileIsOnScreen(newPos))
	{
		m_speed = 0;
	}
	else
	{

		for each (Tile & tile in t_tiles.m_tiles)
		{
			if (m_body.getGlobalBounds().intersects(tile.m_bodySquare.getGlobalBounds()) && tile.m_type == TileType::WALL)
			{
				m_speed = 0;
				m_alive = false;
			}
		}
		for (Sweeper & sweeper: t_sweepers)
		{
			if (m_body.getGlobalBounds().intersects(sweeper.m_body.getGlobalBounds()))
			{
				sweeper.isDead = true;
				m_speed = 0;
				m_alive = false;
			}
		}
	}
	return m_speed == s_MAX_SPEED;
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

bool Missile::inUse() const
{
	return m_speed == s_MAX_SPEED;
}

bool Missile::projectileIsOnScreen(sf::Vector2f t_position) const
{
	return m_body.getPosition().x - m_size.x / 2 > 0.0f
		&& m_body.getPosition().x + m_size.x / 2 < GlobalSettings::s_width
		&& m_body.getPosition().y - m_size.y / 2 > 0.0f
		&& m_body.getPosition().y + m_size.y / 2 < GlobalSettings::s_height;
}
