#pragma once
#include <SFML/Graphics.hpp>

class Enemy
{
private:
	sf::Texture texture;
	sf::Sprite enemy;
	std::vector<sf::Sprite> enemies;

	float spawnTimer;
	float spawnTimerMax;
	float maxEnemy;
	float moveSpeed;
	std::vector<sf::Texture> characters;

	void initVariables();
	void initEnemy();

public:
	Enemy();

	void pushCharacters();

	void spawnEnemy();
	const std::vector<sf::Sprite>& getEnemy() const;
	void enemyMovement(sf::RenderWindow& window, int& health);
	void remove(size_t& enemy);
	void reset();

	void update(sf::RenderWindow& window, int& health);
	void render(sf::RenderWindow* window);
};

