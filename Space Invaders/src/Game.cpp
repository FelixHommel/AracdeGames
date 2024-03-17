#include "../include/stdafx.h"
#include "../include/Game.h"

Game::Game()
{
	m_window = new sf::RenderWindow(sf::VideoMode(800, 600), "Space Invaders", sf::Style::Default);
	gameClock.restart();
}

Game::~Game()
{
	delete m_window;
}

void Game::gameLoop()
{
	while (m_window->isOpen())
	{
		masterUpdate();
		masterRender();
	}
}

void Game::masterUpdate()
{
	sf::Event e;
	//User Input
	while (m_window->pollEvent(e))
	{
		switch (e.type)
		{
		case sf::Event::Closed:
			m_window->close();
		}
	}
	//Game logic update
	float deltaTime{ gameClock.restart().asSeconds() };
}

void Game::masterRender()
{
	m_window->clear(sf::Color::Black);



	m_window->display();
}
