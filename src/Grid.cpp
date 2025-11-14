#include<iostream>
#include "Grid.h"

Grid::Grid(size_t width, size_t height) :
	m_width(width),
	m_height(height),
	m_cells(height, std::vector<bool>(width, false))
{
}

bool Grid::get(const size_t x, const size_t y) const
{
	if (!isInBounds(x, y))
		return false;

	return m_cells[y][x];
}

void Grid::set(const size_t x, const size_t y, const bool value)
{
	if (!isInBounds(x, y))
		return;

	m_cells[y][x] = value;
}

size_t Grid::getWidth() const
{
	return m_width;
}

size_t Grid::getHeight() const
{
	return m_height;
}

bool Grid::isInBounds(const size_t x, const size_t y) const
{
	return x >= 0 && x < m_width && y >= 0 && y < m_height;
}
