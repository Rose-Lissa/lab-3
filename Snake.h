#pragma once
#include <vector>
#include "Cell.h"

class snake {
public:
	snake(int x, int y, int width, int height);
	enum direction {RIGHT, LEFT, UP, DOWN};
	void go();
	void ate_apple();
	void change_dir(enum direction dir);
	const std::vector<cell>& get_body();
	bool end();
private:
	std::vector <cell> body;
	enum direction dir;
	bool is_end;
	int height;
	int width;
};

