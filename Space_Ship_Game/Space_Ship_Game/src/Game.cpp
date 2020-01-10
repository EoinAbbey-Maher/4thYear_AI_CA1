
#include "Game.h"
#include <iostream>

Game::Game() :
	m_window{ sf::VideoMode{ GlobalSettings::s_width, GlobalSettings::s_width, 32U }, "SFML Game" },
	m_roombuilder{m_window},
	m_exitGame{false} ,
	m_player{m_window}
{
	m_roombuilder.loadFile("Assets\\Level.txt");
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
	m_playerView.setCenter(m_player.m_position);
	m_playerCircle.setPosition(m_player.m_position);
	m_player.update(t_deltaTime, m_roombuilder);
}

void Game::render()
{
	m_window.clear(sf::Color::Black);
	m_window.setView(m_playerView);
	m_roombuilder.render();
	m_player.render();

	m_window.setView(m_miniMapView);
	m_roombuilder.render();
	m_window.draw(m_playerCircle);
	m_window.draw(m_mapShape);
	
	m_window.display();
}
