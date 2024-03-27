#ifndef DEFINITION_H
#define DEFINITION_H

#include <cstdint>

enum class GAME_STATE
{
	MENU,
	PLAYING,
	PAUSED
};

typedef uint8_t HP;
typedef sf::RectangleShape Bullet;

namespace WINDOW
{
	constexpr unsigned int WIDTH{ 800 };
	constexpr unsigned int HEIGHT{ 600 };
}

constexpr uint8_t rowCount{ 5 };
constexpr uint8_t colCount{ 11 };

constexpr float enemySize{ 32.f };

#endif // !DEFINITION_H
