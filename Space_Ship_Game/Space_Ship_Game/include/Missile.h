#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

class Missile
{
public:
	Missile();
	void seek(sf::Vector2f& t_playerPos);
	void move();
	void render(sf::RenderWindow& t_window);
	void setSprite();

	sf::Vector2f getPosition() { return m_missilePosition; }
private:
	float const MAX_SPEED{ 10.0f };

	sf::Vector2f m_missilePosition;
	sf::Vector2f m_missileVelocity;
	sf::Vector2f m_target;
	sf::Texture m_missileTexture;
	sf::Sprite m_missileSprite;
	float m_rotation = { 0 };
	float m_distance = { 0 };
	bool m_alive;
	sf::Time m_timeAlive;
};

