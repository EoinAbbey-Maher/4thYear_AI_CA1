#include <iostream>
#include <SFML/Graphics.hpp>
#include "Missile.h"
#include "Global.h"
#include "RoomBuilder.h"
 

class Nest {
public:
	Nest(sf::RenderWindow& t_window);
	~Nest();
	Missile m_missile;

	void rotate();
	void render(sf::RenderWindow& t_window);
	void shootMissile(sf::RenderWindow& t_window);
	void checkPosition(RoomBuilder& t_roombuilder);
	void radiusCheck();

	void deployPredators();
	void setSprite();
	
	sf::Vector2f getPosition() { return m_nestPosition; }
private:
	sf::Vector2f m_nestPosition;
	sf::Texture m_nestTexture;
	sf::Sprite m_nestSprite;
	float rotateSpeed{ 0.9f };
	float m_lifeTotal;
	bool m_missileFired;
	sf::RenderWindow& m_window;
};