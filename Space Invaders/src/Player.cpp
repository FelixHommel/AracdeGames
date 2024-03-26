#include "../stdafx.h"
#include "../include/Player.h"

Player::Player()
{
	initPlayer();
}

Player::~Player()
{
}

void Player::update(const float deltaTime)
{
	//Update Input
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		if (!(m_player.getGlobalBounds().left < 0)) //if not too far left move left
			m_player.move(-MOVE_SPEED * deltaTime, 0);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		if (m_player.getGlobalBounds().left + m_player.getGlobalBounds().width < 800) //if not too far right move right
			m_player.move(MOVE_SPEED * deltaTime, 0);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
		shoot();

	//Update Objects
	updateBullets(deltaTime);

	//

}

void Player::render(sf::RenderTarget& target)
{
	target.draw(m_player);

	for (auto& i : m_bullets)
		target.draw(i);
}

void Player::shoot()
{
	if (m_shootCooldown.getElapsedTime().asSeconds() > SHOOT_COOLDOWN_MAX)
	{
		Bullet newBullet{ sf::Vector2f(2, 5) };
		newBullet.setFillColor(sf::Color::Green);
		newBullet.setPosition((m_player.getPosition().x + (m_player.getGlobalBounds().width / 2)) - (newBullet.getSize().x / 2), m_player.getPosition().y);

		m_bullets.push_back(newBullet);

		m_shootCooldown.restart();

		//Visual Studio Macro for whether the solution is in DEBUG mode or not
#ifdef _DEBUG
		std::cout << m_bullets.size() << std::endl;
#endif // !_DEBUG
	}
}

void Player::updateBullets(const float deltaTime)
{
	for (int i{ 0 }; i < m_bullets.size(); ++i)
	{
		m_bullets[i].move(0, -BULLET_SPEED * deltaTime);

		if (m_bullets[i].getGlobalBounds().getPosition().y < 0)
		{
			m_bullets.erase(m_bullets.begin() + i);

			//Visual Studio Macro for whether the solution is in DEBUG mode or not
#ifdef _DEBUG
			std::cout << m_bullets.size() << std::endl;
#endif // !_DEBUG
		}
	}
}

void Player::initPlayer()
{
	if (!m_playerTexture.loadFromFile("Resources/Textures/Ship.png"))
	{
		std::cerr << "ERROR::PLAYER_CPP::initPlayer()::Unable_to_load_texture::Resources/Textures/Ship.png" << std::endl;
		std::exit(0);
	}
	else
		m_player.setTexture(m_playerTexture);

	m_player.setPosition(400.f, 500.f);
}
