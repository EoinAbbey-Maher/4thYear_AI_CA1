#include <iostream>
#include <SFML/Graphics.hpp>

class Nest {
public:
	Nest();
	void rotate();
	void render(sf::RenderWindow& t_window);
	void shootMissile();
	void deployPredators();
	void setSprite();

	sf::Vector2f getPosition() { return m_nestPosition; }
private:
	sf::Vector2f m_nestPosition;
	sf::Texture m_nestTexture;
	sf::Sprite m_nestSprite;
	float random{ 100.0f };
	float rotateSpeed{ 0.7f };
	float m_lifeTotal;
	bool m_missileFired;
};