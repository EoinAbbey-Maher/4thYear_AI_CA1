#include <SFML/Graphics.hpp>
#include <iostream>
#pragma once
class Worker
{
public:
	Worker();
	void wander();
	void move();
	void render(sf::RenderWindow& t_window);
	void setSprite();
	
	sf::Vector2f getPosition() { return m_workerPosition; }
private:
	float const MAX_SPEED{ 4.0f };
	float const PI{ 3.14159265358979323846 };
	float m_randomDirection;
	float m_rotation;
	float m_maxRotation;
	float m_magnitude;
	sf::Vector2f m_workerVelocity;
	sf::Vector2f m_workerPosition;
	sf::Vector2f m_direction;
	float random = (rand()%750);
	sf::Texture m_WorkerTexture;
	sf::Sprite m_WorkerSprite;
};

