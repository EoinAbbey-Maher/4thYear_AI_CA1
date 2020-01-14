#ifndef GAME_HPP
#define GAME_HPP

#include <SFML/Graphics.hpp>
#include <vector>
#include <RoomBuilder.h>
#include <Nest.h>

class Game
{
public:
	Game();
	~Game();
	void run();

private:

	std::vector<Nest*> m_nests;
	std::vector<sf::Vector2f*> m_nestsPositions;
	void setUpNests();
	void processEvents();
	void processKeys(sf::Event t_event);
	void update(sf::Time t_deltaTime);
	void render();
	
	void setupSprite();
	RoomBuilder m_roombuilder;

	int noOfNests{ 2 };
	sf::RenderWindow m_window; // main SFML window

	bool m_exitGame; // control exiting game

};

#endif // !GAME_HPP

