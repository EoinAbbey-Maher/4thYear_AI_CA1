#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "RoomBuilder.h"

static const float MAXPREDATORVELOCITY{ 5 };

class Predator
{
public:
	Predator();
	~Predator() {};
	
	void setBody(sf::Texture* t_texture, sf::Vector2f t_position);
	void update(RoomBuilder& m_roombuilder,sf::Vector2f& m_player);
	void render(sf::RenderWindow& t_window);

	void searchForPlayer(sf::Vector2f& pos);

	void move();
	

	void checkCollisions(RoomBuilder& t_roombuilder);
private:

	sf::Vector2f m_predatorPosition;
	sf::Vector2f m_size{ 20,30 };
	sf::Vector2f m_velocity{ 1.0f,10.0f };
	sf::Vector2f m_lastPosition;
	sf::RectangleShape m_predatorShape;
	sf::Vector2f m_direction;
	float m_distance{ 0 };
	float m_rotation{ 0 };
	

};

