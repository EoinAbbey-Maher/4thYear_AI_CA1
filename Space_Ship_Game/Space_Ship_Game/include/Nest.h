#include <iostream>
#include <SFML/Graphics.hpp>
#include "Missile.h"

class Nest {
public:
	Nest();
	Missile m_missile;

	void rotate();
	void render(sf::RenderWindow& t_window);
	void shootMissile(Missile m_missile, sf::RenderWindow& t_window);
	void deployPredators();
	void setSprite();

	sf::Vector2f getPosition() { return m_nestPosition; }
private:
	sf::Vector2f m_nestPosition;
	sf::Texture m_nestTexture;
	sf::Sprite m_nestSprite;
	float random =  (rand() % 750 );
	float rotateSpeed{ 0.9f };
	float m_lifeTotal;
	bool m_missileFired;
};