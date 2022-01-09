#include "Apple.h"

apple::apple(int x, int y, int widht, int height)
{
	coords.x = x;
	coords.y = y;
	this->width = widht;
	this->height = height;
}

cell apple::generate_coords()
{
	coords.x = rand() % width;
	coords.y = rand() % height;
	return coords;
}

cell apple::get_coords()
{
	return coords;
}
