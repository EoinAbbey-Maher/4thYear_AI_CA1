#include "ProjectilePool.h"

void ProjectilePool::create(sf::Texture const& t_texture, sf::Vector2f t_position, float t_rotation)
{


	if (m_ispoolFull)
	{
		m_nextAvailable = (m_nextAvailable + 1) % s_POOL_SIZE;
	}
	m_current = m_nextAvailable;
	m_projectiles.at(m_nextAvailable).init(t_texture, t_position, t_rotation);
}

void ProjectilePool::update(RoomBuilder & t_room, std::vector<Sweeper> & t_sweepers)
{
	int noActive = 0;
	m_ispoolFull = false;

	for (int i = 0; i < s_POOL_SIZE; i++)
	{
		if (m_projectiles.at(i).update(t_room, t_sweepers))
		{
			m_nextAvailable = i;
		}
		else
		{
			noActive++;
		}

	}
	if(s_POOL_SIZE  == noActive)
	{
		m_ispoolFull = true;
	}
}

void ProjectilePool::render(sf::RenderWindow& t_window)
{
	for (int i = 0; i < s_POOL_SIZE; i++)
	{
		if (m_projectiles.at(i).inUse())
		{
			t_window.draw(m_projectiles.at(i).m_body);
		}
	}
}

Missile ProjectilePool::getActive()
{
	return m_projectiles.at(m_current);
}
