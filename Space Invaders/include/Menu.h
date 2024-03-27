#ifndef MENU_H
#define MENU_H

#include "GUI.h"

class Menu
{
public:
	Menu(sf::Font* font);
	~Menu();

	const inline bool exitMenu() const { return m_exitMenu; }

	void update(const float dT, const sf::Vector2i& mousePos);
	void render(sf::RenderTarget& target);

private:
	sf::Font* m_font;
	bool m_exitMenu{ false };

	GUI::Button* m_button;

	void updateButtonEvent();
};

#endif // !MENU_H
