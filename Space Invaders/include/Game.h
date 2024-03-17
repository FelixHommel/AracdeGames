#ifndef GAME_H
#define GAME_H

class Game
{
public:
	Game();
	~Game();

	void gameLoop();

private:
	sf::RenderWindow* m_window;
	sf::Clock gameClock;

	void masterUpdate();
	void masterRender();
};

#endif // !GAME_H
