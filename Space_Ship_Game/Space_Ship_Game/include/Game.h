#ifndef GAME_HPP
#define GAME_HPP

//SDKs
#include <SFML/Graphics.hpp>

//User Files
#include "RoomBuilder.h"
#include "Player.h"

class Game
{
public:
	Game();
	~Game();
	void run();

public: //Variables


private: //Functions
	void processEvents();
	void processKeys(sf::Event t_event);
	void update(sf::Time t_deltaTime);
	void render();

private: //Variables

	Player m_player;
	RoomBuilder m_roombuilder;

	sf::View m_playerView;
	sf::View m_miniMapView;
	sf::RenderWindow m_window; // main SFML window

	sf::CircleShape m_playerCircle{ 18 };

	sf::Texture m_mapFrame;
	sf::RectangleShape m_mapShape;

	bool m_exitGame; // control exiting game

};

#endif // !GAME_HPP

