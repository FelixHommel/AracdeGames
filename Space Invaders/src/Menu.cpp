#include "../stdafx.h"
#include "../include/Menu.h"

Menu::Menu(sf::Font* font)
	: m_font{ font }
{
	m_button = new GUI::Button
	(
		static_cast<float>(WINDOW::WIDTH) / 2, static_cast<float>(WINDOW::HEIGHT) / 2, 100.f, 50.f,
		m_font, "PLAY", 32,
		sf::Color::White, sf::Color::White, sf::Color::White,
		sf::Color::Black, sf::Color::Black, sf::Color::Black,
		sf::Color::Transparent, sf::Color::White, sf::Color::White
	);
}

Menu::~Menu()
{
	delete m_button;
}

void Menu::update(const float dT, const sf::Vector2i& mousePos)
{
	m_button->update(dT, mousePos);
	updateButtonEvent();
}

void Menu::render(sf::RenderTarget& target)
{
	m_button->render(target);
}

void Menu::updateButtonEvent()
{
	if (m_button->isPressed())
		m_exitMenu = true;
}
