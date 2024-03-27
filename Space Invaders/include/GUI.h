#ifndef GUI_H
#define GUI_H
namespace GUI
{
	enum BTN_STATE
	{
		BTN_STATE_IDLE = 0,
		BTN_STATE_HOVERED,
		BTN_STATE_PRESSED,

		BTN_STATE_MAX
	};

	class Button
	{
	public:
		Button(const float xPos, const float yPos, const float width, const float height, sf::Font* font, const std::string& text, const unsigned int charSize,
			const sf::Color idleTextColor, const sf::Color hoverTextColor, const sf::Color pressedTextColor,
			const sf::Color idleColor, const sf::Color hoverColor, const sf::Color pressedColor,
			const sf::Color idleOutlineColor = sf::Color::Transparent, const sf::Color hoverOutlineColor = sf::Color::Transparent, const sf::Color pressedOutlineColor = sf::Color::Transparent,
			const unsigned short id = 0
		);

		~Button();

		const bool isPressed() const;

		void update(const float dT, const sf::Vector2i& mousePos);
		void render(sf::RenderTarget& target);

	private:
		unsigned short m_btnState{ BTN_STATE_IDLE };
		unsigned short m_ID;

		sf::RectangleShape m_button;

		sf::Font* m_font;
		sf::Text m_buttonLable;

		sf::Color m_idleTextColor;
		sf::Color m_idleColor;
		sf::Color m_idleOutlineColor;

		sf::Color m_hoverTextColor;
		sf::Color m_hoverColor;
		sf::Color m_hoverOutlineColor;

		sf::Color m_pressedTextColor;
		sf::Color m_pressedColor;
		sf::Color m_pressedOutlineColor;

		float cooldown{ 0.f };
		float cooldownMax{ 5.f };

		const bool getCooldown();
		const void updateCooldown(const float dT);
	};
}
#endif // !GUI_H
