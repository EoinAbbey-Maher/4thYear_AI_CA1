#include <iostream>
#include <SFML/Graphics.hpp>
#include "Missile.h"
#include "Player.h"
#include "Global.h"
#include "RoomBuilder.h"
#include <time.h>

class Nest {
public:
	Nest(sf::RenderWindow& t_window = sf::RenderWindow());
	~Nest();
	Missile m_missile;
	Player m_player;

	void rotate();
	void render();
	void shootMissile(sf::RenderWindow& t_window);
	void checkPosition(RoomBuilder& t_roombuilder);
	void radiusCheck();

	void deployPredators();
	void setBody();
	
	sf::Vector2f getPosition() { return m_nestPosition; }
private:
	sf::Vector2f m_nestPosition;
	sf::Vector2f m_size{50,50};
	sf::Texture m_nestTexture;
	sf::RectangleShape m_nestShape;
	float m_random = rand() % GlobalSettings::s_width;
	float rotateSpeed{ 0.9f };
	float m_lifeTotal;
	bool m_missileFired;
	sf::RenderWindow& m_window;
	
};