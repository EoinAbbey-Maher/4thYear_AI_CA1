#include <iostream>
#include <SFML/Graphics.hpp>

class Nest {
public:
	Nest();
	void rotate();
	void render(sf::RenderWindow& t_window);
	void setSprite();

	sf::Vector2f getPosition() { return m_nestPosition; }
private:
	sf::Vector2f m_nestPosition;
	sf::Texture m_nestTexture;
	sf::Sprite m_nestSprite;
};