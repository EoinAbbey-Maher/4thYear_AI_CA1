#ifndef GAME_HPP
#define GAME_HPP

//SDKs
#include <SFML/Graphics.hpp>
#include <vector>
#include <Nest.h>

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

	std::vector<Nest*> m_nests;
	std::vector<sf::Vector2f*> m_nestsPositions;
	void setUpNests();
	
private: //Functions
	void processEvents();
	void processKeys(sf::Event t_event);
	void update(sf::Time t_deltaTime);
	void render();
	
	void setupSprite();
	RoomBuilder m_roombuilder;

	int noOfNests{ 2 };

private: //Variables

	Player m_player;
	
	sf::View m_playerView;
	sf::View m_miniMapView;
	sf::RenderWindow m_window; // main SFML window

	sf::CircleShape m_playerCircle{ 18 };

	sf::Texture m_mapFrame;
	sf::RectangleShape m_mapShape;

	sf::Texture m_sweeperTexture;

	bool m_exitGame; // control exiting game

};

#endif // !GAME_HPP

