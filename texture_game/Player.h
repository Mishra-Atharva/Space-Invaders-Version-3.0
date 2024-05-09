#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Bullet.h"

class Player
{
private:
	sf::Texture texture;
	sf::Sprite player;
	std::string location;
	sf::SoundBuffer buffer;
	sf::Sound sound;

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

