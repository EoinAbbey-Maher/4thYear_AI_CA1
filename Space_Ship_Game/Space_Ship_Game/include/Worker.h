#include <SFML/Graphics.hpp>
#include <iostream>
#pragma once
class Worker
{
public:
	Worker(float posX, float posY);
	void run(std::vector <Worker>& w);
	void wander(std::vector <Worker>& w);
	void move(std::vector <Worker>& w);
	sf::Texture m_WorkerTexture;
	sf::Sprite m_WorkerSprite;

private:
	float const MAX_SPEED{ 4.0f };
	float const PI{ 3.14159265358979323846 };
	float m_randomDirection{ 0 };
	float m_rotation = { 0 };
	float m_maxRotation = { 0 };
	float m_magnitude{ 0 };
	sf::Vector2f m_workerVelocity{ -2.0f,0.0f };
	sf::Vector2f m_workerPosition;
	sf::Vector2f m_direction;
};

