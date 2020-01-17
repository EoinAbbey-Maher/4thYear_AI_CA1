#include "Player.h"

Player::Player(sf::RenderWindow& t_window) :
	m_window(t_window)
{
	setupBody();

	m_velocity.x = std::cos(m_orientation * RADIANSVAL) * m_acceleration;
	m_velocity.y = std::sin(m_orientation * RADIANSVAL) * m_acceleration;
}

Player::~Player()
{
}

void Player::update(sf::Time t_td, RoomBuilder & t_rb, std::vector<Sweeper>& t_sweepers)
{
	m_lastPosition = m_position;
	m_bodyShape.setPosition(m_position);
	m_position += m_velocity;
	m_bodyShape.setPosition(m_position);
	checkBoundaries(t_rb);
	
	if (m_fireRequested && m_shootTimer > 0)
	{
		m_shootTimer -= t_td.asSeconds();
	}
	else
	{
		m_shootTimer = 1100;
		m_fireRequested = false;
	}
}

void Player::render()
{
	m_window.draw(m_bodyShape);
}

void Player::processGameEvents(sf::Event t_e)
{
	if (sf::Keyboard::W == t_e.key.code)
	{
		m_bodyShape.setTexture(&m_accelTexture);
		move(.1);
	}
 	else if(sf::Keyboard::S == t_e.key.code)
	{
		move(-.1);
	}

	if (sf::Keyboard::A == t_e.key.code)
	{
		turn(-3);
	}
	else if (sf::Keyboard::D == t_e.key.code)
	{
		turn(3);
	}

	
	if (sf::Keyboard::Space == t_e.key.code)
	{
		requestfire();
	}

	if (m_bodyShape.getTexture() != &m_texure && !sf::Keyboard::W == t_e.key.code)
	{
		m_bodyShape.setTexture(&m_texure);
	}
}

void Player::move(float t_accel)
{
	if (!(sqrt((m_velocity.x * m_velocity.x) + (m_velocity.y * m_velocity.y) >= MAXPLAYERVELOCITY))
		&& t_accel >= 0)
	{
		m_acceleration += t_accel;
	}
	else if ((!sqrt((m_velocity.x * m_velocity.x) + (m_velocity.y * m_velocity.y) == 0)) &&
		t_accel < 0)
	{
		m_acceleration += t_accel;
	}

	m_velocity.x = std::cos(m_orientation * RADIANSVAL) * m_acceleration;
	m_velocity.y = std::sin(m_orientation * RADIANSVAL) * m_acceleration;
}

void Player::turn(float t_accel)
{
	m_orientation += t_accel;

	if (m_orientation < 0)
	{
		m_orientation = 359;
	}
	else if (m_orientation > 360)
	{
		m_orientation = 0;
	}

	m_velocity.x = std::cos(m_orientation * RADIANSVAL) * m_acceleration;
	m_velocity.y = std::sin(m_orientation * RADIANSVAL) * m_acceleration;

	m_bodyShape.setRotation(m_orientation);
}

void Player::checkBoundaries(RoomBuilder& t_roombuilder)
{

	for each (Tile &tile in t_roombuilder.m_tiles)
	{
		if (m_bodyShape.getGlobalBounds().intersects(tile.m_bodySquare.getGlobalBounds()) && tile.m_type == TileType::WALL)
		{
			m_position = m_lastPosition;
			m_bodyShape.setPosition(m_position);
		}
	}
}

void Player::requestfire()
{
	m_fireRequested = true;
	if (m_shootTimer == s_TIME_BETWEEN_SHOTS)
	{
		sf::Vector2f tipOfShip(m_bodyShape.getPosition().x + 2.0f, m_bodyShape.getPosition().y);
		tipOfShip.x += std::cos(RADIANSVAL * m_bodyShape.getRotation()) * ((m_bodyShape.getLocalBounds().top + m_bodyShape.getLocalBounds().height) * 1.7f);
		tipOfShip.y += std::sin(RADIANSVAL * m_bodyShape.getRotation()) * ((m_bodyShape.getLocalBounds().top + m_bodyShape.getLocalBounds().height) * 1.7f);
	}
}

void Player::setupBody()
{
	if (m_texure.loadFromFile("ASSETS\\IMAGES\\bluePlayerIdle.png"))
	{
		std::cout << "loaded Player texture";
		m_bodyShape.setTexture(&m_texure);
	}
	m_accelTexture.loadFromFile("ASSETS\\IMAGES\\bluePlayerGas.png");

	m_bulletTexture.loadFromFile("ASSETS\\IMAGES\\bullet.png");

	m_bodyShape.setRotation(m_orientation);
	m_bodyShape.setPosition(m_position);
	m_bodyShape.setSize(m_size);
	m_bodyShape.setOrigin(m_size.x * .5, m_size.y * .5);
}
