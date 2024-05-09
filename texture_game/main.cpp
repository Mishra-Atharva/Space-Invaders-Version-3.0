#include "Game.h"

int main()
{
	srand(static_cast<unsigned int>(time(NULL)));
	Game game;

	while (game.isRunning())
	{
		game.update();
		game.render();
	}
}