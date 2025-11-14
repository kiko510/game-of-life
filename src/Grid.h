#ifndef GRID__H
#define GRID__H

#include <vector>

class Grid {
private:
	std::vector<std::vector<bool>> m_cells;
	const size_t m_height;
	const size_t m_width;
public:
	Grid(size_t width, size_t height);

	bool get(const size_t x, const size_t y) const;
	void set(const size_t x, const size_t y, const bool value);

	size_t getWidth() const;
	size_t getHeight() const;

	bool isInBounds(const size_t x, const size_t y) const;
};

#endif // !GRID__H