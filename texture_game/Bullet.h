#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Enemy.h"

class Bullet
{
private:
	sf::Texture texture;
	sf::Sprite bullet;
	std::vector<sf::Sprite> bullets;

	sf::SoundBuffer buffer;
	sf::Sound sound;

	int maxBullets;
	float moveSpeed;
	std::string location;

	void initVariables();
	void initBullets();

public:
	int currentBullets;
	int points;
	
	Bullet();

	void reset();
	void bulletMovement(sf::RenderWindow& window);
	void spawnBullet(float x, float y);
	void bulletCollision(Enemy& enemies);
	void remove(size_t& bullet);

	void update(sf::RenderWindow& window, Enemy& enemies);
	void render(sf::RenderWindow* window);
};

