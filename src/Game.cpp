#include "Game.h"

#include "Grid.h"


Game::Game(const size_t gridWidth, const size_t gridHeight) :
	m_grid(Grid(gridWidth, gridHeight))
{
}


Game::Game(Grid grid) :
	m_grid(std::move(grid))
{
}


Grid Game::getGrid() const
{
	return m_grid;
}


void Game::step()
{
	Grid nextGenGrid = Grid(m_grid.getWidth(), m_grid.getHeight());

	for (size_t x = 0; x < m_grid.getWidth(); x++)
	{
		for (size_t y = 0; y < m_grid.getHeight(); y++)
		{
			nextGenGrid.set(x, y, getNextCellState(x, y));
		}
	}

	m_grid = std::move(nextGenGrid);

}


bool Game::getNextCellState(const size_t x, const size_t y) const
{
	int nLiveNeigbours = m_grid.getLiveNeighbours(x, y);
	
	// Any live cell with fewer than two live neighbours dies, as if by underpopulation.
	if (m_grid.get(x, y) && nLiveNeigbours < 2)
		return false;

	// Any live cell with two or three live neighbours lives on to the next generation.
	if (m_grid.get(x, y) && nLiveNeigbours >= 2 && nLiveNeigbours <= 3)
		return true;

	// Any live cell with more than three live neighbours dies, as if by overpopulation.
	if (m_grid.get(x, y) && nLiveNeigbours > 3)
		return false;

	// Any dead cell with exactly three live neighbours becomes a live cell, as if by reproduction.
	if (!m_grid.get(x, y) && nLiveNeigbours == 3)
		return true;

	// return current state
	return m_grid.get(x, y);
}
