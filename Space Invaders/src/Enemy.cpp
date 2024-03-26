#include "../stdafx.h"
#include "../include/Enemy.h"

//-------------- Enemy --------------//

Enemy::Enemy(const sf::Texture& texture, const float posX, const float posY)
{
	initEnemy(texture, posX, posY);
}

Enemy::Enemy(const sf::Texture& texture, const sf::Vector2f pos)
{
	initEnemy(texture, pos.x, pos.y);
}

Enemy::~Enemy()
{
}

void Enemy::move(const float deltaTime, MOVE_DIRECTION direction)
{
	m_enemy.move();
}

void Enemy::update(const float deltaTime)
{
	//animation maybe
}

void Enemy::render(sf::RenderTarget& target)
{
	target.draw(m_enemy);
}

void Enemy::initEnemy(const sf::Texture& texture, const float posX, const float posY)
{
	m_enemy.setTexture(texture);

	m_enemy.setPosition(posX, posY);
}

//-------------- EnemyGroup --------------//

EnemyGroup::EnemyGroup()
{
	initEnemyGroup();
}

EnemyGroup::~EnemyGroup()
{
	for (auto i : m_enemies)
		delete i;
}

void EnemyGroup::update(const float deltaTime, std::vector<Bullet>& bullets)
{
	updateDeath(bullets);
}

void EnemyGroup::render(sf::RenderTarget& target)
{
	for (auto& i : m_enemies)
		i->render(target);
}

void EnemyGroup::updateDeath(std::vector<Bullet>& bullets)
{
	
}

void EnemyGroup::initEnemyGroup()
{
	if (!m_enemyTexture.loadFromFile("Resources/Textures/enemy01.png"))
	{
		std::cerr << "ERROR::GAME_CPP::initEnemies()::Unable_to_load_texture::Resources/Textures/enemy01.png" << std::endl;
		std::exit(0);
	}

	// there are 5 rows of 11 enemies each so 55 enemies total
	for (uint8_t row{ 0 }; row < rowCount; ++row)
		for (uint8_t col{ 0 }; col < colCount; ++col)
		{
			m_enemies.push_back(new Enemy(m_enemyTexture, 60 + 32 * col * 2, 20 + 32 * row * 2));
		}
}
