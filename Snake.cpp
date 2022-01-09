#include "Snake.h"

snake::snake(int x, int y, int width, int height) {
	body.push_back({ x, y });
	body.push_back({ x - 1, y });
	body.push_back({ x - 2, y });
	this->width = width;
	this->height = height;
	this->dir = RIGHT;
}

void snake::go() {
	cell tmp_1 = body[0];
	cell tmp_2;
	for (auto it = body.begin() + 1; it != body.end(); it++) {
		tmp_2 = *it;
		*it = tmp_1;
		tmp_1 = tmp_2;
	}

	if (dir == RIGHT) {
		body[0].x++;
	}
	if (dir == LEFT) {
		body[0].x--;
	}
	if (dir == UP) {
		body[0].y++;
	}
	if (dir == DOWN) {
		body[0].y--;
	}

	if (body[0].x < 0 || body[0].x >= width) {
		is_end = true;
	}
	if (body[0].y < 0 || body[0].y >= height) {
		is_end = true;
	}

	for (auto it = body.begin() + 1; it != body.end(); it++) {
		if (*it == body[0]) {
			is_end = true;
		}
	}
}

void snake::ate_apple() {
	body.push_back({ 0, 0 });
}

void snake::change_dir(direction dir)
{
	if (this->dir == UP || this->dir == DOWN) {
		if (dir == UP || dir == DOWN) {
			return;
		}
	}
	if (this->dir == LEFT || this->dir == RIGHT) {
		if (dir == LEFT || dir == RIGHT) {
			return;
		}
	}
	this->dir = dir;
}

const std::vector<cell>& snake::get_body() {
	return body;
}

bool snake::end() {
	return is_end;
}
