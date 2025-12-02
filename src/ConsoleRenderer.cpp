#include "ConsoleRenderer.h"

#include <iostream>
#include <cstdlib>

void ConsoleRenderer::draw(const Grid& grid, const Viewport& viewport)
{
    system("cls");

    std::cout << std::string(viewport.viewWidth * 2 + 2, '-') << '\n';

    for (size_t y = 0; y < viewport.viewHeight; ++y) {
        std::cout << "|";
        for (size_t x = 0; x < viewport.viewWidth; ++x) {
            std::cout << (grid.get(x + viewport.xGridPos, y + viewport.yGridPos) ? "* " : "  ");
        }
        std::cout << "| \n";
    }
    std::cout << std::string(viewport.viewWidth * 2 + 2, '-') << '\n'; // separator line
}
