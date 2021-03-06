
#include "Game.h"
#include <iostream>

Game::Game() :
	m_window{ sf::VideoMode{ GlobalSettings::s_width, GlobalSettings::s_height, 32U }, "SFML Game" },
	m_roombuilder{m_window},
	m_exitGame{false} ,
	m_player{m_window}
{
	
	
	srand(time(NULL));

	m_roombuilder.loadFile("Assets\\Level.txt");
	if (m_nestTexture.loadFromFile("ASSETS\\IMAGES\\Nest.png"))
	{
		setUpNests();
	}
	if (m_predatorTexture.loadFromFile("ASSETS\\IMAGES\\predator.png"))
	{
		setUpPredators();
	}

	m_playerView.setCenter(m_player.m_position);
	m_playerView.setSize(150, 150);
	m_playerView.setViewport(sf::FloatRect(0, 0, 1, 1));

	if (m_mapFrame.loadFromFile("ASSETS\\IMAGES\\MapBorder.png"))
	{
		m_mapShape.setTexture(&m_mapFrame);
		m_mapShape.setPosition(0, 0);
		m_mapShape.setSize(sf::Vector2f(GlobalSettings::s_width, GlobalSettings::s_height));
	}

	m_miniMapView.setCenter(GlobalSettings::s_width * .5, GlobalSettings::s_height * .5);
	m_miniMapView.setSize(GlobalSettings::s_width, GlobalSettings::s_height);
	m_miniMapView.setViewport(sf::FloatRect(.65,.65,.35f,.35f));

	m_playerCircle.setFillColor(sf::Color::Green);
	m_playerCircle.setPosition(m_player.m_position);
	m_playerCircle.setOrigin(m_playerCircle.getRadius(), m_playerCircle.getRadius());

	if (m_workerTexture.loadFromFile("ASSETS\\IMAGES\\worker.png"))
	{
		setUpWorkers();
	}
	if (m_sweeperTexture.loadFromFile("ASSETS\\IMAGES\\SweeperBot.png"))
	{
		setupSweepers();
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

void Game::setUpNests()
{

	for (int i = 0; i < noOfNests; i++)
	{
		m_nests.push_back(Nest());
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
		m_nests[i].setBody(&m_nestTexture, sf::Vector2f(newPos));
	}
}

void Game::setUpPredators()
{
	for (int i = 0; i < 3; i++)
	{
		
		m_predators.push_back(Predator());
		int j = 0;
		m_predators[i].setBody(&m_predatorTexture, m_nests[j].m_nestShape.getPosition());
		
	}
	for (int i = 3; i < noOfPredators; i++)
	{
		m_predators.push_back(Predator());
		int j = 1;
		m_predators[i].setBody(&m_predatorTexture, m_nests[j].m_nestShape.getPosition());
	}
}

sf::Vector2i Game::getNewPosition()
{
	sf::Vector2i NewPos = sf::Vector2i((rand() % m_roombuilder.M_TOTALWIDTH), (rand() % m_roombuilder.M_TOTALHEIGHT));
	return NewPos;
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

	m_player.processGameEvents(t_event);
}

void Game::update(sf::Time t_deltaTime)
{
	if (m_exitGame)
	{
		m_window.close();
	}
	for (Nest& nest : m_nests)
	{
		nest.update(m_roombuilder);
	}
	
	for (Worker& worker : m_workers)
	{
		worker.update(m_roombuilder);
	}
	
	for (Predator& predator : m_predators)
	{
		//predator.update(m_roombuilder,m_player.m_position);
	}

	m_playerView.setCenter(m_player.m_position);
	m_playerCircle.setPosition(m_player.m_position);
	m_player.update(t_deltaTime, m_roombuilder, m_sweepers);
	for (Sweeper& sweeper :m_sweepers)
	{
		sweeper.update(m_roombuilder, m_player);
	}
}

void Game::render()
{

	m_window.clear(sf::Color::Black);
	m_window.setView(m_playerView);
	m_roombuilder.render();
	for each (Worker worker in m_workers)
	{
		worker.render(m_window);
	}

	m_player.render();
	for each(Nest nest in m_nests)
	{
		nest.render(m_window);
	}
	for each (Predator predator in m_predators)
	{
		predator.render(m_window);
	}
	
	for each (Sweeper sweeper in m_sweepers)
	{
		sweeper.render(m_window);
	}

	m_window.setView(m_miniMapView);
	m_roombuilder.render();
	for each (Nest nest in m_nests)
	{
		nest.render(m_window);
	}
	for each (Predator predator in m_predators)
	{
		predator.render(m_window);
	}
	for each (Sweeper sweeper in m_sweepers)
	{
		sweeper.render(m_window);
	}
		for each (Worker worker in m_workers)
	{
		worker.render(m_window);
	}

	m_window.draw(m_playerCircle);
	m_window.draw(m_mapShape);
	m_window.display();
}

void Game::setupSprite()
{
	
}

void Game::setupSweepers()
{
	for (int i = 0; i < NOOFSWEEPERS; i++)
	{
		m_sweepers.push_back(Sweeper());
		sf::Vector2i newPos = getNewPosition();
		while(m_roombuilder.m_tiles[newPos.x][newPos.y].m_type != TileType::FLOOR)
		{
			newPos = getNewPosition();
			if (m_roombuilder.m_tiles[newPos.x][newPos.y].m_type == TileType::FLOOR)
			{
				break;
			}
		}
			newPos = sf::Vector2i(m_roombuilder.m_tiles[newPos.x][newPos.y].m_bodySquare.getPosition());
			m_sweepers[i].init(&m_sweeperTexture, sf::Vector2f(newPos));
	}
}
