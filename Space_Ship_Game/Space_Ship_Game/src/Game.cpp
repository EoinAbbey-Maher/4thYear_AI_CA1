
#include "Game.h"
#include <iostream>


Game::Game() :
	m_window{ sf::VideoMode{ 800U, 600U, 32U }, "SFML Game" },
	m_exitGame{false} //when true game will exit
{
	if (m_workerTexture.loadFromFile("ASSETS\\IMAGES\\Worker.png"))
	{
		setUpWorkers();
	}
	
	
}


Game::~Game()
{
}



void Game::run()
{
	sf::Clock clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;
	const float fps{ 60.0f };
	sf::Time timePerFrame = sf::seconds(1.0f / fps); // 60 fps
	while (m_window.isOpen())
	{
		processEvents(); // as many as possible
		timeSinceLastUpdate += clock.restart();
		while (timeSinceLastUpdate > timePerFrame)
		{
			timeSinceLastUpdate -= timePerFrame;
			processEvents(); // at least 60 fps
			update(timePerFrame); //60 fps
		}
		render(); // as many as possible
	}
}




void Game::setUpWorkers()
{
	for (int i = 0; i < noOfWorkers; i++)
	{
		m_workers.push_back(Worker());
		sf::Vector2i newPos = getNewPosition();
		while (m_roombuilder.m_tiles[newPos.x][newPos.y].m_type != TileType::FLOOR)
		{
			newPos = getNewPosition();
			if (m_roombuilder.m_tiles[newPos.x][newPos.y].m_type == TileType::FLOOR)
			{
				break;
			}
		}
		newPos = sf::Vector2i(m_roombuilder.m_tiles[newPos.x][newPos.y].m_bodySquare.getPosition());
		m_workers[i].setBody(&m_workerTexture, sf::Vector2f(newPos));
	}
}

void Game::processEvents()
{
	sf::Event newEvent;
	while (m_window.pollEvent(newEvent))
	{
		if ( sf::Event::Closed == newEvent.type) // window message
		{
			m_exitGame = true;
		}
		if (sf::Event::KeyPressed == newEvent.type) //user pressed a key
		{
			processKeys(newEvent);
		}
	}
	
}


void Game::processKeys(sf::Event t_event)
{
	if (sf::Keyboard::Escape == t_event.key.code)
	{
		m_exitGame = true;
	}
}


void Game::update(sf::Time t_deltaTime)
{
	if (m_exitGame)
	{
		m_window.close();
	}
	for (Worker& worker : m_workers)
	{
		worker.update(m_roombuilder);
	}
	
}


void Game::render()
{
	m_window.clear(sf::Color::White);
	for each (Worker worker in m_workers)
	{
		worker.render(m_window);
	}
	m_window.display();
}


