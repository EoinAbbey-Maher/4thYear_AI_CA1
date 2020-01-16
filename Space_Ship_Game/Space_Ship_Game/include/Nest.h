#include <iostream>
#include <SFML/Graphics.hpp>
#include "Missile.h"
#include "Player.h"
#include "Global.h"
#include "RoomBuilder.h"


class Nest {
public: // functions
	Nest();
	~Nest() {};

	void render(sf::RenderWindow & t_window);
	void setBody(sf::Texture * t_texture, sf::Vector2f t_position);
	void update(RoomBuilder& m_roombuilder);

private:

	void checkCollisions(RoomBuilder& t_roombuilder);
	void rotate();
	void radiusCheck();	
	void shootMissile(sf::RenderWindow& t_window);
	void deployPredators();

	sf::Vector2f m_nestPosition;
	sf::Vector2f m_size{50,50};

	float m_random = rand() % GlobalSettings::s_width;
	float rotateSpeed{ 0.9f };
	float m_lifeTotal{ 4 };
	bool m_missileFired{ false };

	sf::RectangleShape m_nestShape;
	
};