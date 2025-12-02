#include "Grid.h"

#include <iostream>
#include <thread>

#include "Game.h"
#include "ConsoleRenderer.h"

Grid getStartGrid() 
{
	Grid grid(100, 100);

	grid.set(10, 10, true);
	grid.set(11, 10, true);
	grid.set(12, 10, true);
	grid.set(11, 9, true);

	return grid;
}


Grid getGlider() 
{
	Grid grid(100, 100);
	size_t xPos = 30;
	size_t yPos = 30;
	grid.set(xPos + 1, xPos + 2, true);
	grid.set(xPos + 2, xPos + 2, true);
	grid.set(xPos + 3, xPos + 2, true);
	grid.set(xPos + 3, xPos + 1, true);
	grid.set(xPos + 2, xPos + 0, true);

	return grid;
}

int main()
{
	int nSteps = 255;
	Game game = Game(getGlider());
	Viewport viewport{20, 30, 30, 20};

	for (int i = 0; i < 200; ++i) {
		ConsoleRenderer::draw(game.getGrid(), viewport);
		game.step();
		std::this_thread::sleep_for(std::chrono::milliseconds(500));
	}

	
	return 0;
}
