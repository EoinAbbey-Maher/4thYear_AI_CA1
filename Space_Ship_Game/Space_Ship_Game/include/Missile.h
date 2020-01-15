#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

class Missile
{
public:
	Missile();
	void seek();
	void render(sf::RenderWindow& t_window);
	void setSprite();

	sf::Vector2f getPosition() { return m_missilePosition; }
private:
	sf::Vector2f m_missilePosition;
	sf::Texture m_missileTexture;
	sf::Sprite m_missileSprite;
	bool m_alive;
	sf::Time m_timeAlive;
};

