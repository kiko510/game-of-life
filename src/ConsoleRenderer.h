#ifndef CONSOLE_RENDERER__H
#define CONSOLE_RENDERER__H

#include "Grid.h"
#include "Viewport.h"

class ConsoleRenderer
{
public:
	static void draw(const Grid& grid, const Viewport& viewport);

};

#endif // !CONSOLE_RENDERER__H