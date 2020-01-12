#ifndef GAME_HPP
#define GAME_HPP

#include <SFML/Graphics.hpp>
#include <vector>
#include "Worker.h"

class Game
{
public:
	Game();
	~Game();
	void run();
	
	
	

private:

	std::vector<Worker*> m_workers;
	std::vector<sf::Vector2f*> m_workersPositions;
	void setUpWorkers();
	void processEvents();
	void processKeys(sf::Event t_event);
	void update(sf::Time t_deltaTime);
	void render();
	
	
	void setupFontAndText();
	void setupSprite();

	int noOfWorkers{ 5 };
	sf::RenderWindow m_window; // main SFML window

	bool m_exitGame; // control exiting game

};

#endif // !GAME_HPP

