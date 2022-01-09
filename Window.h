#pragma once
#include "Field.h"
#include "Cell.h"

class window
{
public:
	window(const field& f);

	void draw();
private:
	const field& game_field;
	static const unsigned char snake_cell = 152;
	static const unsigned char empty_cell = 0;
	static const unsigned char apple_cell = 174;
	static const unsigned char wall_cell = 35;
};

