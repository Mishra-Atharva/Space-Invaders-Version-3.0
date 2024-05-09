#include "Game.h"
#include <iostream>
void Game::initVariables()
{
	this->endGame = false;
	this->state = "Title";
}

void Game::initWindow()
{
	this->videoMode = sf::VideoMode(800, 600);
	this->window = new sf::RenderWindow(this->videoMode, "Game");
	this->window->setFramerateLimit(60);
}

Game::Game() :ui(), player(), bullet(), enemy()
{
	this->initVariables();
	this->initWindow();
}

Game::~Game()
{
	delete this->window;
}

void Game::pollEvents()
{
	while (this->window->pollEvent(this->ev))
	{
		switch (this->ev.type)
		{
		case sf::Event::Closed:
			this->window->close();
			break;
		case sf::Event::KeyPressed:
			if (this->ev.key.code == sf::Keyboard::Escape)
			{
				this->window->close();
				break;
			}
		}
	}
}

const bool Game::isRunning() const
{
	return this->window->isOpen();
}

void Game::update()
{
	this->pollEvents();
	this->ui.update(*this->window, this->endGame, this->state, this->bullet.points, this->player.health, this->bullet.currentBullets);
	if (this->player.health <= 0)
	{
		this->endGame = true;
		this->state = "end";
	}
	if (this->ui.restart)
	{
		endGame = false;
		this->ui.restart = false;
		this->enemy.reset();
		this->bullet.reset();
		this->player.health = 5;
		this->bullet.points = 0;
		this->state = "play";
	}
	if (!this->endGame)
	{
		//run updates
		this->enemy.update(*this->window, this->player.health);
		this->bullet.update(*this->window, this->enemy);
		this->player.update(*this->window, this->bullet);
	}
}

void Game::render()
{
	this->window->clear();
	if (!this->endGame && this->state == "play")
	{
		//run renders
		this->enemy.render(this->window);
		this->bullet.render(this->window);
		this->player.render(this->window);
	}
	this->ui.render(this->window);
	this->window->display();
}
