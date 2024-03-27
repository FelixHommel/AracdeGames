#include "../stdafx.h"
#include "../include/Game.h"

Game::Game()
{
	m_window = new sf::RenderWindow(sf::VideoMode(WINDOW::WIDTH, WINDOW::HEIGHT), "Space Invaders", sf::Style::Default);
	gameClock.restart();

	initFont();
	initEnemies();
	m_menu = new Menu(m_font);
}

Game::~Game()
{
	for (auto& i : m_enemies)
		delete i;

	delete m_menu;

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
			if (m_enemies.at(e)->getGlobalBounds().intersects(m_player.getSingleBullet(b)))
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

void Game::menuUpdate(const float deltaTime)
{
	m_menu->update(deltaTime, sf::Mouse::getPosition(*m_window));
	if (m_menu->exitMenu())
		m_currentGameState = GAME_STATE::PLAYING;
}

void Game::playingUpdate(const float deltaTime)
{
	m_player.update(deltaTime);
	checkBulletHit();
	moveEnemies();
}

void Game::pausedUpdate()
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
#ifdef _DEBUG
			case sf::Keyboard::Up:
				m_currentGameState = GAME_STATE::PLAYING;
				break;
			case sf::Keyboard::Down:
				m_currentGameState = GAME_STATE::MENU;
				break;
#endif
			}
			break;
		}
	}
	//Game logic update
	float deltaTime{ gameClock.restart().asSeconds() };

	switch (m_currentGameState)
	{
	case GAME_STATE::MENU:
		menuUpdate(deltaTime);
		break;
	case GAME_STATE::PLAYING:
		playingUpdate(deltaTime);
		break;
	case GAME_STATE::PAUSED:
		//Implement later
		pausedUpdate();
		exit(0);
		break;
	}
}

void Game::menuRender()
{
	m_menu->render(*m_window);
}

void Game::playingRender()
{
	m_player.render(*m_window);
	for (auto& i : m_enemies)
		i->render(*m_window);
}

void Game::pausedRender()
{
}

void Game::masterRender()
{
	m_window->clear(sf::Color::Black);

	switch (m_currentGameState)
	{
	case GAME_STATE::MENU:
		menuRender();
		break;
	case GAME_STATE::PLAYING:
		playingRender();
		break;
	case GAME_STATE::PAUSED:
		//Implement later
		pausedRender();
		exit(0);
		break;
	}

	m_window->display();
}

void Game::initFont()
{
	m_font = new sf::Font();
	if (!m_font->loadFromFile("Resources/Fonts/PixellettersFull.ttf"))
	{
		//implement better error handling later
		std::cerr << "Unable to load ../Resources/Fonts/PixellettersFull.ttf" << std::endl;
		m_window->close();
	}
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
