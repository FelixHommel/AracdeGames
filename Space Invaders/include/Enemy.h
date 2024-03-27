#ifndef ENEMY_H
#define ENEMY_H

enum class MOVE_DIRECTION
{
	LEFT = -1,
	RIGHT = 1
};

class Enemy
{
public:
	Enemy(const sf::Texture& texture, const float posX, const float posY);
	Enemy(const sf::Texture& texture, const sf::Vector2f pos);
	~Enemy();

	//Accessor          
	inline const sf::FloatRect& getGlobalBounds() const { return  m_enemy.getGlobalBounds(); }

	//Modefier
	void move(const float deltaTime, MOVE_DIRECTION direction);

	void update(const float deltaTime);
	void render(sf::RenderTarget& target);

private:
	sf::Sprite m_enemy;

	void initEnemy(const sf::Texture& texture, const float posX, const float posY);
};

#endif // !ENEMY_H
