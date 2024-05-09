#include "UI.h"
#include <sstream>
#include <iostream>

void UI::initVariables()
{
	this->font.loadFromFile("font/Daydream.ttf");
	this->health_tex.loadFromFile("character/healthbar.png");
	this->currentFrame = sf::IntRect(0, 0, 32, 16);
	this->ammo_tex.loadFromFile("character/character.png");
}

void UI::initTitleUI()
{	
	this->title.setFont(this->font);
	this->title.setFillColor(sf::Color::Green);
	this->title.setCharacterSize(32);
	this->title.setString("Space Invaders");
	this->title.setPosition(180.f, 150.f);

	this->play.setFont(this->font);
	this->play.setFillColor(sf::Color::Green);
	this->play.setCharacterSize(24);
	this->play.setString("Play");
	this->play.setPosition(350.f, 270.f);

	this->play_btn.setSize(sf::Vector2f(150.f, 50.f));
	this->play_btn.setFillColor(sf::Color::Transparent);
	this->play_btn.setOutlineThickness(5.f);
	this->play_btn.setOutlineColor(sf::Color::Green);
	this->play_btn.setPosition(320.f, 265.f);

	this->quit.setFont(this->font);
	this->quit.setFillColor(sf::Color::Green);
	this->quit.setCharacterSize(24);
	this->quit.setString("Quit");
	this->quit.setPosition(350.f, 370.f);

	this->quit_btn.setSize(sf::Vector2f(150.f, 50.f));
	this->quit_btn.setFillColor(sf::Color::Transparent);
	this->quit_btn.setOutlineThickness(5.f);
	this->quit_btn.setOutlineColor(sf::Color::Green);
	this->quit_btn.setPosition(320.f, 365.f);
}

void UI::initEndUI(int& points)
{
	std::stringstream ss;
	std::string point = "Points: " + std::to_string(points);
	ss << point;

	this->endTitle.setFont(this->font);
	this->endTitle.setFillColor(sf::Color::Red);
	this->endTitle.setCharacterSize(32);
	this->endTitle.setString("Game Over!");
	this->endTitle.setPosition(240.f, 150.f);

	this->score.setFont(this->font);
	this->score.setCharacterSize(24);
	this->score.setFillColor(sf::Color::Red);
	this->score.setString(ss.str());
	this->score.setPosition(300.f, 230.f);

	this->play.setFont(this->font);
	this->play.setFillColor(sf::Color::Red);
	this->play.setCharacterSize(24);
	this->play.setString("Play");
	this->play.setPosition(350.f, 300.f);

	this->play_btn.setSize(sf::Vector2f(150.f, 50.f));
	this->play_btn.setFillColor(sf::Color::Transparent);
	this->play_btn.setOutlineThickness(5.f);
	this->play_btn.setOutlineColor(sf::Color::Red);
	this->play_btn.setPosition(320.f, 295.f);

	this->quit.setFont(this->font);
	this->quit.setFillColor(sf::Color::Red);
	this->quit.setCharacterSize(24);
	this->quit.setString("Quit");
	this->quit.setPosition(350.f, 400.f);

	this->quit_btn.setSize(sf::Vector2f(150.f, 50.f));
	this->quit_btn.setFillColor(sf::Color::Transparent);
	this->quit_btn.setOutlineThickness(5.f);
	this->quit_btn.setOutlineColor(sf::Color::Red);
	this->quit_btn.setPosition(320.f, 395.f);
}


UI::UI()
{
	this->initVariables();
}

void UI::playUI(int& health, int& points, int& bullets)
{
	int x = 0;
	std::stringstream ss;
	std::string point = "Points: " + std::to_string(points);
	ss << point;
	
	this->score.setFont(this->font);
	this->score.setCharacterSize(14);
	this->score.setFillColor(sf::Color::Green);
	this->score.setString(ss.str());
	this->score.setPosition(650.f, 30.f);

	this->healthBar.setTexture(this->health_tex);
	this->healthBar.setScale(2.5f, 2.5f);
	this->healthBar.setPosition(20.f, 20.f);
	if (health == 5)
	{
		this->currentFrame.top = 0;
	}
	if (health == 4)
	{
		this->currentFrame.top = 16;
	}
	if (health == 3)
	{
		this->currentFrame.top = 32;
	}
	if (health == 2)
	{
		this->currentFrame.top = 48;
	}
	if (health == 1)
	{
		this->currentFrame.top = 64;
	}
	if (health == 0)
	{
		this->currentFrame.top = 80;
	}
	this->ammo.setFont(this->font);
	this->ammo.setCharacterSize(10);
	this->ammo.setFillColor(sf::Color::Green);
	this->ammo.setString("AMMO");
	this->ammo.setPosition(10.f, 550.f);

	this->ammo_rect.setSize(sf::Vector2f(55.f, 20.f));
	this->ammo_rect.setFillColor(sf::Color::Transparent);
	this->ammo_rect.setOutlineColor(sf::Color::Green);
	this->ammo_rect.setOutlineThickness(5.f);
	this->ammo_rect.setPosition(15.f, 570.f);

	this->ammo_sprite.setTexture(this->ammo_tex);
	this->ammo_sprite.setTextureRect(sf::IntRect(32, 0, 16, 16));
	this->ammo_sprite.setScale(2.f, 2.f);
}

void UI::checkClick(sf::RenderWindow& window, std::string& state, bool& endGame)
{
	this->mousePos = sf::Mouse::getPosition(window);
	this->viewMousePos = window.mapPixelToCoords(this->mousePos);

	if (this->play_btn.getGlobalBounds().contains(this->viewMousePos) && sf::Mouse::isButtonPressed(sf::Mouse::Left) && endGame)
	{
		this->play_btn.setOutlineColor(sf::Color(1, 50, 32));
		this->restart = true;
	}
	if (this->play_btn.getGlobalBounds().contains(this->viewMousePos) && sf::Mouse::isButtonPressed(sf::Mouse::Left) && !endGame)
	{
		this->play_btn.setOutlineColor(sf::Color(1, 50, 32));
		state = "play";
	}
	if (this->quit_btn.getGlobalBounds().contains(this->viewMousePos) && sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		this->quit_btn.setOutlineColor(sf::Color(1, 50, 32));
		window.close();
	}
}

void UI::update(sf::RenderWindow& window, bool& endGame, std::string& state, int& points, int& health, int& bullets)
{
	if (!endGame)
	{
		if (state == "play");
		{
			//clearing the array
			this->texts.clear();
			this->buttons.clear();
			this->sprites.clear();

			//adding to array
			this->playUI(health, points, bullets);
			this->texts.push_back(this->score);
			this->healthBar.setTextureRect(this->currentFrame);
			this->sprites.push_back(this->healthBar);
			this->texts.push_back(this->ammo);
			this->buttons.push_back(this->ammo_rect);
			for (int bullet = 0; bullet < bullets; bullet++)
			{
				this->ammo_sprite.setPosition((5.f * (bullet + 1)), 565.f);
				this->sprites.push_back(this->ammo_sprite);
			}
		}
		if (state == "Title")
		{
			//clearing the array
			this->texts.clear();
			this->buttons.clear();
			this->sprites.clear();

			//adding to the array
			this->initTitleUI();
			this->texts.push_back(this->title);
			this->texts.push_back(this->play);
			this->texts.push_back(this->quit);
			this->buttons.push_back(this->play_btn);
			this->buttons.push_back(this->quit_btn);

			this->checkClick(window, state, endGame);
		}
	}
	else
	{
		if (state == "end")
		{
			//clearing the array
			this->texts.clear();
			this->buttons.clear();
			this->sprites.clear();

			//adding to the array
			this->initEndUI(points);
			this->texts.push_back(this->endTitle);
			this->texts.push_back(this->play);
			this->buttons.push_back(this->play_btn);
			this->texts.push_back(this->quit);
			this->buttons.push_back(this->quit_btn);
			this->texts.push_back(this->score);

			this->checkClick(window, state, endGame);
		}
	}
}

void UI::render(sf::RenderWindow* window)
{
	for (auto& text : this->texts)
	{
		window->draw(text);
	}

	for (auto& button : this->buttons)
	{
		window->draw(button);
	}
	for (auto& sprite : this->sprites)
	{
		window->draw(sprite);
	}
}
