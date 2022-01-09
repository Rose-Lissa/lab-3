#pragma once
#include"Cell.h"
#include<random>
class apple {
public:
	apple(int x, int y, int widht, int height);
	cell generate_coords();
	cell get_coords();
private:
	cell coords;
	int width;
	int height;
};

