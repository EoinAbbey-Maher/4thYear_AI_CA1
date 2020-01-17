#include "..\include\Nest.h"

Nest::Nest()
{
}

void Nest::render(sf::RenderWindow& t_window)
{
	t_window.draw(m_nestShape);
}

void Nest::setBody(sf::Texture* t_texture, sf::Vector2f t_position)
{
	m_nestPosition = t_position;
	m_nestShape.setTexture(t_texture);
	m_nestShape.setPosition(t_position);
	m_nestShape.setSize(m_size);
	m_nestShape.setOrigin(m_size.x * .5, m_size.y* .5);
}

void Nest::update(RoomBuilder& m_roombuilder)
{
	rotate();
}

void Nest::checkCollisions(RoomBuilder& t_roombuilder)
{
}

void Nest::rotate()
{
	m_nestShape.rotate(rotateSpeed);
}

void Nest::radiusCheck()
{
	
}


void Nest::shootMissile(sf::RenderWindow& t_window)
{
	
}

void Nest::deployPredators()
{

}



