#include "Enemy.h"

void Enemy::initVariables()
{
	this->spawnTimerMax = 1000.f;
	this->spawnTimer = this->spawnTimerMax;
	this->maxEnemy = 5;
	this->moveSpeed = 2.f;
}

void Enemy::initEnemy()
{
	this->enemy.setTexture(this->characters[rand()%3]);
	this->enemy.setScale(3.f, 3.f);
}

Enemy::Enemy()
{
	this->initVariables();
	this->pushCharacters();
}

void Enemy::pushCharacters()
{
	this->texture.loadFromFile("character/character.png", sf::IntRect(0, 0, 16, 16));
	this->characters.push_back(this->texture);
	this->texture.loadFromFile("character/character.png", sf::IntRect(0, 16, 16, 16));
	this->characters.push_back(this->texture);
	this->texture.loadFromFile("character/character.png", sf::IntRect(0, 32, 16, 16));
	this->characters.push_back(this->texture);
	this->texture.loadFromFile("character/character.png", sf::IntRect(0, 48, 16, 16));
	this->characters.push_back(this->texture);
}

void Enemy::spawnEnemy()
{
	if (this->spawnTimer < this->spawnTimerMax)
	{
		this->spawnTimer +=  10.f;
	} 
	else
	{
		if (this->enemies.size() <= this->maxEnemy)
		{
			this->initEnemy();
			this->enemy.setPosition(static_cast<float>(rand()%500), -48.f);
			this->enemies.push_back(this->enemy);
			this->spawnTimer = 0.f;
		}
	}
}

const std::vector<sf::Sprite>& Enemy::getEnemy() const
{
	return this->enemies;
}

void Enemy::enemyMovement(sf::RenderWindow& window, int& health)
{
	for (size_t enemy = 0; enemy < this->enemies.size(); enemy++)
	{
		this->enemies[enemy].move(0.f, this->moveSpeed);

		if (this->enemies[enemy].getPosition().y > (window.getSize().y - 32.f))
		{
			this->remove(enemy);
			health--;
			break;
		}
	}
}

void Enemy::remove(size_t& enemy)
{
	this->enemies.erase(this->enemies.begin() + enemy);
}

void Enemy::reset()
{
	this->enemies.clear();
	this->spawnTimer = this->spawnTimerMax;
}

void Enemy::update(sf::RenderWindow& window, int& health)
{
	this->spawnEnemy();
	this->enemyMovement(window, health);
}

void Enemy::render(sf::RenderWindow* window)
{
	for (auto& enemy : this->enemies)
	{
		window->draw(enemy);
	}
}
