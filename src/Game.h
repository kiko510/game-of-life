#ifndef GAME__H
#define GAME__H

#include "Grid.h"

class Game
{
public:
	Game(const size_t gridWidth, const size_t gridHeight);
	Game(Grid grid);

	Grid getGrid() const;

	void step();

private:
	bool getNextCellState(const size_t x, const size_t y) const;
	Grid m_grid;
};

#endif // !GAME__H
