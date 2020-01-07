#include "RoomBuilder.h"

RoomBuilder::RoomBuilder(sf::RenderWindow & t_window) :
	m_window(t_window)
{
	loadAssets();
	
	for (int i = 0; i < M_TOTALHEIGHT; i++)
	{
		for (int j = 0; j  < M_TOTALWIDTH; j++)
		{			
			m_tiles[i][j].init(sf::Vector2f(0, 0),&floor1, &floor2, &wall1, &wall2, &door1, &door2);						
		} // !for j
		
	} // !for i
}

RoomBuilder::~RoomBuilder()
{
} // !~RoomBuilder

/// <summary>
/// Function to load the room layout txt file
/// </summary>
/// <param name="t_roomName">file name</param>
void RoomBuilder::loadFile(std::string t_roomName)
{
	emptyRoom();

	std::cout << "builder" << std::endl;

	std::ifstream lvlfile;
	lvlfile.open(t_roomName);
	if (lvlfile.is_open())
	{
		std::cout << "file opened" << std::endl;
		while (!lvlfile.eof())
		{
			
			for (int i = 0; i < M_TOTALHEIGHT; i++)
			{
				
				for (int j = 0; j < M_TOTALWIDTH; j++)
				{
					lvlfile >> m_tileValue[i][j];
					std::cout << m_tileValue[i][j];


					m_tiles[i][j].setTexture(TileType(m_tileValue[i][j]), j, i);
					if (j == M_TOTALWIDTH - 1)
					{
						std::cout  << std::endl;
					} //! if
				
				} // for j

			} // !for i
						
		} // !while loop
		std::cout << "closed" << std::endl;
		lvlfile.close();
	} // !if(lvl.is_open) 
	
}

/// <summary>
/// Function to empty game room
/// </summary>
void RoomBuilder::emptyRoom()
{
	for (int i = 0; i < M_TOTALHEIGHT; i++)
	{
		for (int j = 0; j < M_TOTALWIDTH; j++)
		{

			m_tileValue[i][j] = 0;
		} // !for j
	
	} // !for i

} // !emptyRoom

/// <summary>
/// Function to load in tile assets and textures
/// </summary>
void RoomBuilder::loadAssets()
{
	if (floor1.loadFromFile("Assets\\Sprites\\Floor1.png")) { std::cout << "loaded"; }
	if (floor2.loadFromFile("Assets\\Sprites\\Floor2.png")) { std::cout << "loaded"; }
	if (wall1.loadFromFile("Assets\\Sprites\\Wall1.png")) { std::cout << "loaded"; }
	if (wall2.loadFromFile("Assets\\Sprites\\wall2.png")) { std::cout << "loaded"; }
	if (door1.loadFromFile("Assets\\Sprites\\DoorClosed.png")) { std::cout << "loaded"; }
	if (door2.loadFromFile("Assets\\Sprites\\DoorOpen.png")) { std::cout << "loaded"; }

} // !loadAssets

void RoomBuilder::render()
{
	for (int i = 0; i < M_TOTALHEIGHT; i++)
	{
		for (int j = 0; j < M_TOTALWIDTH; j++)
		{
			m_tiles[i][j].render(m_window);
		} // !for j

	} // !for i

} // !render
