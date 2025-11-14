#include <iostream>

#include <Grid.h>
#include "ConsoleRenderer.h"
int main()
{
	Grid grid(20, 10);

	grid.set(5, 1, true);
	grid.set(5, 2, true);

	ConsoleRenderer::draw(grid);
	
	return 0;
}
