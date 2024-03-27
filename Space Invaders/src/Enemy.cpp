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
	//m_enemy.move();
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
