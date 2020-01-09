#include <SFML/Graphics.hpp>
#include <iostream>
#pragma once
class Worker
{
public:
	Worker(float posX, float posY);
	void setUpAssets();
	void wander();
	void workerMove();
	sf::Texture m_WorkerTexture;
	sf::Sprite m_WorkerSprite;

private:
	float const MAX_SPEED{ 4.0f };
	float const PI{ 3.14159265358979323846 };
	float m_randomDirection;
	float m_rotation = { 0 };
	float m_maxRotation = { 0 };
	float m_magnitude;
	sf::Vector2f m_workerVelocity{ -2.0f,0.0f };
	sf::Vector2f m_workerPosition;
	sf::Vector2f m_direction;
};

