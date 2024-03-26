#ifndef GAME_H
#define GAME_H

#include "Player.h"
#include "Enemy.h"

class Game
{
public:
	Game();
	~Game();

	void gameLoop();

private:
	sf::RenderWindow* m_window;
	sf::Clock gameClock;

	Player m_player;
	sf::Texture m_enemyTexture;
	std::vector<Enemy*> m_enemies;

	

	void checkBulletHit();
	void moveEnemies();

	void masterUpdate();
	void masterRender();

	void initEnemies();

private:
};

#endif // !GAME_H
