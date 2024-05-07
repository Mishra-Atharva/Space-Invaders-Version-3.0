#pragma once
#include <SFML/Graphics.hpp>
#include "Bullet.h"

class Player
{
private:
	sf::Texture texture;
	sf::Sprite player;
	std::string location;

	float moveSpeed;
	
	void initVariables();
	void initPlayer();

public:
	int health;
	
	Player();

	void playerInput(sf::RenderWindow& window, Bullet& bullet);

	void update(sf::RenderWindow& window, Bullet& bullet);
	void render(sf::RenderWindow* window);
};

