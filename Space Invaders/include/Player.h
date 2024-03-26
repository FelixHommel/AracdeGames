#ifndef PLAYER_H
#define PLAYER_H

class Player
{
public:
	Player();
	~Player();

	//Accessors
	inline const size_t getAmountOfBullets() const { return m_bullets.size(); }
	inline const sf::FloatRect& getSingleBullet(const size_t location) const { return m_bullets.at(location).getGlobalBounds(); }

	//Modifieres
	inline void removeBullet(const size_t location) { m_bullets.erase(m_bullets.begin() + location); }

	void update(const float deltaTime);
	void render(sf::RenderTarget& target);

private:
	sf::Texture m_playerTexture;
	sf::Sprite m_player;

	HP m_playerHP;
	sf::Clock m_shootCooldown;
	std::vector<Bullet> m_bullets;

	void shoot();

	void updateBullets(const float deltaTime);

	void initPlayer();

private: // Const Player Variables
	const float MOVE_SPEED{ 150.f };
	const float BULLET_SPEED{ 100.f };
	const float SHOOT_COOLDOWN_MAX{ 0.25f };
};

#endif // !PLAYER_H
