#pragma once
struct cell {
	int x;
	int y;

	bool operator==(const cell& other) {
		return this->x == other.x && this->y == other.y;
	}
};

enum cells {
	APPLE,
	SNAKE,
	EMPTY
};