#ifndef SWEEPER_H
#define SWEEPER_H

#include <SFML/Graphics.hpp>

#include "Global.h"
#include "RoomBuilder.h"
#include "Player.h"

enum CurrentAction
{
	WANDERING,
	CHASING,
	FLEEING
};

class Sweeper
{
public: // functions
	Sweeper();
	~Sweeper() {};

	void init(sf::Texture * t_texture, sf::Vector2f m_position);
	
	void update(RoomBuilder& m_room, Player& t_player);
	void render(sf::RenderWindow & t_window);

	

public: // variables
	


private: // functions
	void checkCollisions(RoomBuilder& t_builder);
	void wander(RoomBuilder& t_room);
	void ChaseWorker(RoomBuilder& t_room);
	void fleeFromPlayer(Player & t_player);

	void updateCone(Player &t_player);

private: // variables
	CurrentAction m_action{ CurrentAction::WANDERING };

	float m_FoV{ 30 };
	float m_coneLenght{ 100 };

	sf::Vector2f m_coneRight;
	sf::Vector2f m_coneLeft;

	sf::VertexArray m_viewCone{ sf::TriangleFan,3 };


	sf::Vector2f m_position;
	sf::Vector2f m_lastPosition;
	sf::Vector2f m_size{ 20,20};

	sf::Vector2f m_velocity{ 5,0 };
	
	
	float m_acceleration{ .5 };
	float m_slowScalar;
	float m_orientation{ 0 };

	sf::RectangleShape m_body;
	
};


#endif // !SWEEPER_H


