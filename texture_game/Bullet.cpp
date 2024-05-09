#include "Bullet.h"

void Bullet::initVariables()
{
	this->points = 0;
	this->maxBullets = 10;
	this->moveSpeed = 5.f;
	this->location = "character/character.png";
	this->currentBullets = this->maxBullets;

	this->buffer.loadFromFile("sound/explosion.wav");
	this->sound.setBuffer(this->buffer);
}

void Bullet::initBullets()
{
	this->texture.loadFromFile(this->location, sf::IntRect(32, 0, 16, 16));
	this->bullet.setTexture(this->texture);
	this->bullet.setScale(2.f, 2.f);

}

Bullet::Bullet()
{
	this->initVariables();
}

void Bullet::spawnBullet(float x, float y)
{
	if (this->bullets.size() < this->maxBullets)
	{
		this->initBullets();
		this->bullet.setPosition(x, y);
		this->bullets.push_back(this->bullet);
		this->currentBullets--;
	}
}

void Bullet::bulletMovement(sf::RenderWindow& window)
{
	for (size_t bullet = 0; bullet < this->bullets.size(); bullet++)
	{
		this->bullets[bullet].move(0.f, -this->moveSpeed);
		
		if (this->bullets[bullet].getPosition().y < 0.f)
		{
			this->remove(bullet);
			this->currentBullets++;
		}
	}
}

void Bullet::bulletCollision(Enemy& enemies)
{
	for (size_t bullet = 0; bullet < this->bullets.size(); bullet++)
	{
		for (size_t enemy = 0; enemy < enemies.getEnemy().size(); enemy++)
		{
			if (this->bullets[bullet].getGlobalBounds().intersects(enemies.getEnemy()[enemy].getGlobalBounds()))
			{
				this->sound.play();
				this->remove(bullet);
				this->points++;
				this->currentBullets++;
				enemies.remove(enemy);
				break;
			}
		}
	}
}

void Bullet::remove(size_t& bullet)
{
	this->bullets.erase(this->bullets.begin() + bullet);
}

void Bullet::reset()
{
	this->bullets.clear();
	this->currentBullets = maxBullets;
}

void Bullet::update(sf::RenderWindow& window, Enemy& enemies)
{
	this->bulletMovement(window);
	this->bulletCollision(enemies);
}

void Bullet::render(sf::RenderWindow* window)
{
	for (auto& bullet : this->bullets)
	{
		window->draw(bullet);
	}
}
