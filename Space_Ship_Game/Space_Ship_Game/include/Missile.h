#ifndef MISSILE_H
#define MISSILE_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

#include "Global.h"
#include "Sweeper.h"
#include "RoomBuilder.h"

class Sweeper;
class RoomBuilder;

class Missile
{
public:
	Missile();
	void seek();
	void init(sf::Texture  const & t_texture, sf::Vector2f t_position, float t_orientation);
	bool update(RoomBuilder & t_tiles,std::vector<Sweeper> & t_sweepers);
	void render(sf::RenderWindow& t_window);
	void setSprite();
	
	bool inUse() const;

	sf::Vector2f getPosition() { return m_missilePosition; }

	sf::RectangleShape m_body;
private:
	
	bool Missile::projectileIsOnScreen(sf::Vector2f t_position) const;

	static constexpr float s_MAX_SPEED{ 100.0f};

	float m_speed{ s_MAX_SPEED };

	

	sf::Vector2f m_size{ 5,2 };
	
	sf::Vector2f m_missilePosition;
	sf::Texture m_missileTexture;
	sf::Sprite m_missileSprite;
	
	bool m_alive;
	sf::Time m_timeAlive;
};


#endif // !MISSILE_H