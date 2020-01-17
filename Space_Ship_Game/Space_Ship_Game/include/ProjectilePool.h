#ifndef PROJECTILEPOOL_H
#define PROJECTILEPOOL_H

#include <vector>
#include <array>
#include "Missile.h"

class Missile;
class Sweeper;
class Player;
class RoomBuilder;


class ProjectilePool
{
public: //Functions
	ProjectilePool() {
	};

	void create(sf::Texture const& t_texture, sf::Vector2f t_position, float t_rotation);
	void update(RoomBuilder& t_room, std::vector<Sweeper>& t_sweepers);
	void render(sf::RenderWindow& t_window);

public: //variables
	static const int s_POOL_SIZE = 50;


	std::vector<Missile> m_projectiles;

	Missile getActive();

private: //functions

private: // Variables
	int m_nextAvailable{ 0 };
	int m_current{ 0 };

	bool m_ispoolFull{ false };


};



#endif // !PROJECTILEPOOL_H

