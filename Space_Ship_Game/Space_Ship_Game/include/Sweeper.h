#ifndef SWEEPER_H
#define SWEEPER_H

#include <SFML/Graphics.hpp>

#include "Global.h"
#include "RoomBuilder.h"

class Sweeper
{
public: // functions
	Sweeper();
	~Sweeper() {};

	void init(sf::Texture * t_texture);
	
	void update(RoomBuilder& m_room);
	void render(sf::RenderWindow & t_window);

public: // variables
	


private: // functions
	void checkCollisions(RoomBuilder& t_builder);
	void wander();
	void searchForPlayerWorker();
	void fleeFromPlayer();

private: // variables
	sf::Vector2f m_position;
	sf::Vector2f m_size;

	sf::RectangleShape m_body;
	
};


#endif // !SWEEPER_H


