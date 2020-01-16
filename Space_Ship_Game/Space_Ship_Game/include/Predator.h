#pragma once
#include <SFML/Graphics.hpp>
#include "RoomBuilder.h"

class Predator
{
public:
	Predator();
	~Predator() {};

	void setBody(sf::Texture* t_texture, sf::Vector2f t_position);
	void update(RoomBuilder& m_roombuilder);
	void render(sf::RenderWindow& t_window);

private:
	void checkCollisions(RoomBuilder& t_roombuilder);
	void searchForPlayer();
	void moveWithPredators();

};

