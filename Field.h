#pragma once
#include "Snake.h"
#include "Cell.h"
#include "Apple.h"
#include <chrono>
#include <vector>
#include <conio.h>

class field {
public:
	static const int height = 20; //y
	static const int width = 20; //x
	field();

	void update();
	void build_field();
	bool is_end_game();
	void check_buttons();
	
	const std::vector<std::vector<cells>>& get_field() const;
private:
	std::vector<std::vector<cells>> source;
	snake _snake;
	apple _apple;
};

