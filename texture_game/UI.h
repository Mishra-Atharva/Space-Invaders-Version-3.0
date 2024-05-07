#pragma once
#include <SFML/Graphics.hpp>

class UI
{
private:
	sf::Font font;
	sf::Text title;
	sf::Text endTitle;
	sf::Text play;
	sf::RectangleShape play_btn;
	sf::Text quit;
	sf::RectangleShape quit_btn;
	sf::Text score;

	sf::Texture health_tex;
	sf::Sprite healthBar;
	sf::IntRect currentFrame;
	
	std::vector<sf::Text> texts;
	std::vector<sf::RectangleShape> buttons;
	std::vector<sf::Sprite> sprites;

	sf::Vector2i mousePos;
	sf::Vector2f viewMousePos;


	void initVariables();
	void initTitleUI();
	void initEndUI();

public:
	bool restart = false;
	
	UI();

	void playUI(int& health, int& points);
	void checkClick(sf::RenderWindow& window, std::string& state, bool& endGame);

	void update(sf::RenderWindow& window, bool& endGame, std::string& state, int& points, int& health);
	void render(sf::RenderWindow* window);
};

