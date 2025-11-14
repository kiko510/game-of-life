#include "ConsoleRenderer.h"
#include <iostream>


void ConsoleRenderer::draw(const Grid& grid)
{
    const size_t width = grid.getWidth();
    const size_t height = grid.getHeight();

    std::cout << std::string(width * 2 + 2, '-') << '\n';

    for (size_t y = 0; y < height; ++y) {
        std::cout << "|";
        for (size_t x = 0; x < width; ++x) {
            std::cout << (grid.get(x, y) ? "* " : "  ");
        }
        std::cout << "| \n";
    }
    std::cout << std::string(width*2 + 2, '-') << '\n'; // separator line
}
