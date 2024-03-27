#ifndef GAME_H
#define GAME_H

#include "Menu.h"
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

	GAME_STATE m_currentGameState{ GAME_STATE::MENU };

	sf::Font* m_font;

	Menu* m_menu;
	Player m_player;
	sf::Texture m_enemyTexture;
	std::vector<Enemy*> m_enemies;

	void checkBulletHit();
	void moveEnemies();

	void menuUpdate(const float deltaTime);
	void playingUpdate(const float deltaTime);
	void pausedUpdate();
	void masterUpdate();

	void menuRender();
	void playingRender();
	void pausedRender();
	void masterRender();

	void initFont();
	void initEnemies();

private:
};

#endif // !GAME_H
