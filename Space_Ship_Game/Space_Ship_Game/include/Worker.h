#ifndef WORKERS_H
#define WORKERS_H

#include <SFML/Graphics.hpp>
#include "Roombuilder.h"
#include <iostream>

class Worker
{
public:
	Worker();
	~Worker() {};

	
	void render(sf::RenderWindow& t_window);
	void setBody(sf::Texture * t_texture,sf::Vector2f t_position);
	void update(RoomBuilder& m_roombuilder);


private:

	void wander(RoomBuilder& m_roombuilder);
	void checkCollisions(RoomBuilder& t_roombuilder);
	float const MAX_SPEED{ 4.0f };
	float const PI{ 3.14159265358979323846 };
	float m_randomDirection;
	float m_rotation;
	float m_maxRotation;
	float m_magnitude;

	sf::Vector2f m_size{ 15,15 };
	sf::Vector2f m_workerVelocity{ -2.0f,0.0f };
	sf::Vector2f m_workerPosition;
	sf::Vector2f m_lastPosition;
	sf::Vector2f m_direction;

	sf::RectangleShape m_workerShape;
};

#endif // !WORKERS_H
