#include "Grid.h"

#include <iostream>
#include <thread>

#include "Game.h"
#include "ConsoleRenderer.h"

Grid getStartGrid() 
{
	Grid grid(30, 20);

	grid.set(10, 10, true);
	grid.set(11, 10, true);
	grid.set(12, 10, true);
	grid.set(11, 9, true);

	return grid;
}


Grid getGlider() 
{
	Grid grid(30, 20);

	grid.set(1, 2, true);
	grid.set(2, 2, true);
	grid.set(3, 2, true);
	grid.set(3, 1, true);
	grid.set(2, 0, true);

	return grid;
}

int main()
{
	int nSteps = 255;
	Game game = Game(getGlider());

	for (int i = 0; i < 200; ++i) {
		ConsoleRenderer::draw(game.getGrid());
		game.step();
		std::this_thread::sleep_for(std::chrono::milliseconds(500));
	}

	
	return 0;
}
