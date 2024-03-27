#include "../stdafx.h"
#include "../include/GUI.h"

namespace GUI
{
	Button::Button(const float xPos, const float yPos, const float width, const float height, sf::Font* font, const std::string& text, const unsigned int charSize, const sf::Color idleTextColor, const sf::Color hoverTextColor, const sf::Color pressedTextColor, const sf::Color idleColor, const sf::Color hoverColor, const sf::Color pressedColor, const sf::Color idleOutlineColor, const sf::Color hoverOutlineColor, const sf::Color pressedOutlineColor, const unsigned short id)
		: m_font{ font }
		, m_idleTextColor{ idleTextColor }
		, m_hoverTextColor{ hoverTextColor }
		, m_pressedTextColor{ pressedTextColor }
		, m_idleColor{ idleColor }
		, m_hoverColor{ hoverColor }
		, m_pressedColor{ pressedColor }
		, m_idleOutlineColor{ idleOutlineColor }
		, m_hoverOutlineColor{ hoverOutlineColor }
		, m_pressedOutlineColor{ pressedOutlineColor }
		, m_ID{ id }
	{
		m_button.setPosition(sf::Vector2f(xPos, yPos));
		m_button.setSize(sf::Vector2f(width, height));
		m_buttonLable.setFont(*m_font);
		m_buttonLable.setString(text);
		m_buttonLable.setCharacterSize(charSize);
		m_buttonLable.setPosition
		(
			m_button.getPosition().x + (m_button.getGlobalBounds().width / 2.f) - m_buttonLable.getGlobalBounds().width / 2.f,
			m_button.getPosition().y
		);

		m_button.setFillColor(m_idleColor);
		m_button.setOutlineThickness(3.f);
		m_button.setOutlineColor(m_idleOutlineColor);
		m_buttonLable.setFillColor(m_idleTextColor);
	}

	Button::~Button()
	{
	}

	const bool Button::isPressed() const
	{
		if (m_btnState == BTN_STATE_PRESSED)
			return true;
		else
			return false;
	}

	void Button::update(const float dT, const sf::Vector2i& mousePos)
	{
		updateCooldown(dT);
		m_btnState = BTN_STATE_IDLE;

		if (m_button.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos)))
		{
			m_btnState = BTN_STATE_HOVERED;

			if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && getCooldown())
				m_btnState = BTN_STATE_PRESSED;
		}

		switch (m_btnState)
		{
		case BTN_STATE_IDLE:
			m_button.setFillColor(m_idleColor);
			m_button.setOutlineColor(m_idleOutlineColor);
			m_buttonLable.setFillColor(m_idleTextColor);
			break;
		case BTN_STATE_HOVERED:
			m_button.setFillColor(m_hoverColor);
			m_button.setOutlineColor(m_hoverOutlineColor);
			m_buttonLable.setFillColor(m_hoverTextColor);
			break;
		case BTN_STATE_PRESSED:
			m_button.setFillColor(m_pressedColor);
			m_button.setOutlineColor(m_pressedOutlineColor);
			m_buttonLable.setFillColor(m_pressedTextColor);
			break;
		}
	}

	void Button::render(sf::RenderTarget& target)
	{
		target.draw(this->m_button);
		target.draw(this->m_buttonLable);
	}

	const bool Button::getCooldown()
	{
		if (cooldown >= cooldownMax)
		{
			cooldown = 0.f;
			return true;
		}
		return false;
	}

	const void Button::updateCooldown(const float dT)
	{
		if (cooldown < cooldownMax)
			cooldown += 10.f * dT;
	}
}
