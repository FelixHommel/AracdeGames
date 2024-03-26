#include "../stdafx.h"
#include "../include/Game.h"

Game::Game()
{
	m_window = new sf::RenderWindow(sf::VideoMode(static_cast<unsigned int>(WINDOW_WIDTH), static_cast<unsigned int>(WINDOW_HEIGHT)), "Space Invaders", sf::Style::Default);
	gameClock.restart();

	initEnemies();
}

Game::~Game()
{
	for (auto& i : m_enemies)
		delete i;

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

void Game::checkBulletHit()
{
	for (size_t e{ 0 }; e < m_enemies.size(); ++e)
		for (size_t b{ 0 }; b < m_player.getAmountOfBullets(); ++b)
		{
			if (m_enemies[e]->getGlobalBounds().intersects(m_player.getSingleBullet(b)))
			{
				m_player.removeBullet(b);
				m_enemies.erase(m_enemies.begin() + e);
#ifdef _DEBUG
				std::cout << m_enemies.size() << std::endl;
#endif // !_DEBUG
			}
		}
}

void Game::moveEnemies()
{
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
			break;
		case sf::Event::KeyPressed:
			switch (e.key.code)
			{
			case sf::Keyboard::Escape:
				m_window->close();
				break;
			}
			break;
		}
	}
	//Game logic update
	float deltaTime{ gameClock.restart().asSeconds() };

	m_player.update(deltaTime);
	//m_enemies.update(deltaTime, m_player.getBullets());
	checkBulletHit();
	moveEnemies();
}

void Game::masterRender()
{
	m_window->clear(sf::Color::Black);

	m_player.render(*m_window);
	//m_enemies.render(*m_window);
	for (auto& i : m_enemies)
		i->render(*m_window);

	m_window->display();
}

void Game::initEnemies()
{
	if (!m_enemyTexture.loadFromFile("Resources/Textures/enemy01.png"))
	{
		std::cerr << "ERROR::GAME_CPP::initEnemies()::Unable_to_load_texture::Resources/Textures/enemy01.png" << std::endl;
		std::exit(0);
	}

	for (uint8_t row{ 0 }; row < rowCount; ++row)
		for (uint8_t col{ 0 }; col < colCount; ++col)
		{
			m_enemies.push_back(new Enemy(m_enemyTexture, 60.f + 32.f * col * 2.f, 20.f + 32.f * row * 2.f));
		}

	//Visual Studio Macro for whether the solution is in DEBUG mode or not
#ifdef _DEBUG
	std::cout << m_enemies.size() << std::endl;
#endif // !_DEBUG
}
