
#include "Game.h"
#include <iostream>


Game::Game() :
	m_window{ sf::VideoMode{ 800U, 600U, 32U }, "SFML Game" },
	m_exitGame{false} //when true game will exit
{
	setupSprite();
	populateVector(workers);
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

int Game::getSize()
{
	return workers.size();
}

Worker Game::getWorker(int i)
{
	return workers[i];
}

void Game::addWorker(Worker w)
{
	workers.push_back(w);
}

void Game::wandering()
{
	for (int i = 0; i < workers.size(); i++)
	{
		workers[i].run(workers);
	}
}

void Game::populateVector(std::vector<Worker>& workers)
{
	float x;
	float y;
	
	for (int i = 0; i< noOfWorkers;i++)
	{ 
		x = rand() % 750;
		y = rand() % 750;
		
		Worker newWorker(x, y);

		workers.push_back(newWorker);
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
	movement();
}


void Game::render()
{
	m_window.clear(sf::Color::White);
	

	for (int i = 0; i < noOfWorkers; i++)
	{
		m_window.draw(workers[i].m_WorkerSprite);

	}
	
	m_window.display();
}

void Game::movement()
{
	for (int i = 0; i < noOfWorkers; i++)
	{
		workers[i].workerMove();
		workers[i].wander();
	}
}

void Game::setupFontAndText()
{
}

void Game::setupSprite()
{
	
}
