#include "Sweeper.h"

Sweeper::Sweeper()
{
}

void Sweeper::init(sf::Texture* t_texture)
{
	m_body.setTexture(t_texture);
}

void Sweeper::update(RoomBuilder& m_room)
{
}

void Sweeper::render(sf::RenderWindow& t_window)
{
	t_window.draw(m_body);
}

void Sweeper::checkCollisions(RoomBuilder& t_builder)
{
}

void Sweeper::wander()
{
}

void Sweeper::searchForPlayerWorker()
{
}

void Sweeper::fleeFromPlayer()
{
}
