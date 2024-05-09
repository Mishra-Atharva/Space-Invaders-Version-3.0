#pragma once
#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Enemy.h"
#include "Bullet.h"
#include "UI.h"

class Game
{
private:
	sf::RenderWindow* window;
	sf::VideoMode videoMode;
	sf::Event ev;

	std::string state;
	bool endGame;


	//Images
	sf::Texture background_texture;
	sf::Sprite background;


	void initVariables();
	void initWindow();

	//calling images
	UI ui;
	Player player;
	Bullet bullet;
	Enemy enemy;

public:
	Game();
	virtual ~Game();

	void pollEvents();
	const bool isRunning() const;

	void update();
	void render();
};

