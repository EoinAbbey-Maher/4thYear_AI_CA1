#include "Tile.h"

Tile::Tile()
{
}

Tile::~Tile()
{
}

void Tile::init(sf::Vector2f t_pos, sf::Texture * t_floor1, sf::Texture * t_floor2, sf::Texture * t_wall1, sf::Texture * t_wall2, sf::Texture * t_doorOpen, sf::Texture * t_starTile)
{
	m_textureDict["floor_1"] = t_floor1;
	m_textureDict["floor_2"] = t_floor2;
	m_textureDict["wall_1"] = t_wall1;
	m_textureDict["wall_2"] = t_wall2;
	m_textureDict["door_open"] = t_doorOpen;
	m_textureDict["star_tile"] = t_starTile;

	m_bodySquare.setPosition(m_position);
	m_bodySquare.setSize(sf::Vector2f(M_SIZE, M_SIZE));
}

void Tile::setTexture(TileType t_type, const int T_XPOS, const int T_YPOS)
{
	int randomNum;
	randomNum = std::rand() % 2;
	switch (t_type)
	{
	case TileType::FLOOR:
		switch (randomNum)
		{
		case 0:
			m_bodySquare.setTexture(m_textureDict["floor_1"]);
			break;
		case 1:
			m_bodySquare.setTexture(m_textureDict["floor_2"]);
			break;
		default:
			break;
		} // !case FLOOR
		break;
		m_type = t_type;
	case TileType::WALL:
		switch (randomNum)
		{
		case 0:
			m_bodySquare.setTexture(m_textureDict["wall_1"]);
			break;
		case 1:
			m_bodySquare.setTexture(m_textureDict["wall_2"]);
			break;
		default:
			break;
		} // !case WALL
		m_type = t_type;
		break;
	case TileType::DOOR:
		switch (randomNum)
		{
		case 0:
			m_bodySquare.setTexture(m_textureDict["door_open"]);
			break;
		default:
			break;
		} // !DOOR
		m_type = t_type;
		break;
	case TileType::EMPTY:
		m_bodySquare.setTexture(m_textureDict["star_tile"]);
		m_type = t_type;
		break;
	default:
		break;
	} // !Switch

	m_position = sf::Vector2f(M_SIZE * T_XPOS, M_SIZE * T_YPOS);
	m_bodySquare.setPosition(m_position);
	
}// !setTexture

void Tile::render(sf::RenderWindow & t_window)
{
	t_window.draw(m_bodySquare);
} // !render
