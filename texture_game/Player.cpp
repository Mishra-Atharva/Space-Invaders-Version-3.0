#include "Player.h"
#include <iostream>

void Player::initVariables()
{
	this->health = 5;
	this->moveSpeed = 5.f;
	this->location = "character/character.png";
}

void Player::initPlayer()
{
	//loading the texture into the texture variable then setting the player sprite texture to that.
	this->texture.loadFromFile(this->location, sf::IntRect(64, 0, 16, 16));
	this->player.setTexture(this->texture);
	this->player.setScale(2.f, 2.f);
	this->player.setPosition(800.f/2 - 32.f, 600.f - 48.f);
}

Player::Player()
{
	this->initVariables();
	this->initPlayer();
}

void Player::playerInput(sf::RenderWindow& window, Bullet& bullet)
{
	//player controls move left, right and shoot
	static bool pressed = false;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && this->player.getPosition().x < (window.getSize().x - 28.f))
	{
		this->player.move(this->moveSpeed, 0.f);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && this->player.getPosition().x > 0)
	{
		this->player.move(-this->moveSpeed, 0.f);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && !pressed)
	{
		bullet.spawnBullet(this->player.getPosition().x, this->player.getPosition().y);
	}
	pressed = sf::Keyboard::isKeyPressed(sf::Keyboard::Space);
}

void Player::update(sf::RenderWindow& window, Bullet& bullet)
{
	this->playerInput(window, bullet);
}

void Player::render(sf::RenderWindow* window)
{
	window->draw(this->player);
}
