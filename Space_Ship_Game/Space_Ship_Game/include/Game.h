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
	
	std::vector<Worker> workers;

private:

	void processEvents();
	void processKeys(sf::Event t_event);
	void update(sf::Time t_deltaTime);
	void render();
	void movement();
	
	void setupFontAndText();
	void setupSprite();

	
	sf::RenderWindow m_window; // main SFML window

	bool m_exitGame; // control exiting game

};

#endif // !GAME_HPP

