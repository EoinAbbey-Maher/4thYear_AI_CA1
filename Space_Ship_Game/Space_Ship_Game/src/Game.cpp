
#include "Game.h"
#include <iostream>


Game::Game() :
	m_window{ sf::VideoMode{ 1344, 1344, 32U }, "SFML Game" },
	m_roombuilder{m_window},
	m_exitGame{false} //when true game will exit
{
	m_roombuilder.loadFile("Assets\\Level.txt");
	setUpNests();
	setupSprite();
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

void Game::setUpNests()
{
	m_nests.reserve(noOfNests);
	m_nestsPositions.reserve(m_nests.capacity());
	for (int i = 0; i < m_nests.capacity(); i++)
	{
		m_nests.push_back(new Nest());
		m_nestsPositions.push_back(&m_nests[i]->getPosition());
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
	for (int i = 0; i < m_nests.size(); i++)
	{
		m_nests[i]->rotate();
	}
}

void Game::render()
{
	m_window.clear(sf::Color::Black);
	m_roombuilder.render();
	for (Nest* nest : m_nests)
	{
		nest->render(m_window);
	}
	m_window.display();
}

void Game::setupSprite()
{
	for (int i = 0; i < m_nests.size(); i++)
	{
		m_nests[i]->setSprite();
	}
}
