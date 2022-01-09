#include "Field.h"


field::field() : _snake(5, 5, width, height), _apple(3, 3, width, height) {
	for (int i = 0; i < width; i++) {
		std::vector<cells> cells;
		for (int j = 0; j < height; j++) {
			cells.push_back(EMPTY);
		}
		source.push_back(cells);
	}
}

void field::update(){
	
	cell apple_coords = _apple.get_coords();
	cell snake_head = _snake.get_body()[0];
	if (snake_head == apple_coords) {
		_snake.ate_apple();
		const auto& body = _snake.get_body();
		bool flag = true;
		while (flag) {
			flag = false;
			cell new_apple_coords = _apple.generate_coords();
			for (auto cell : body) {
				if (cell == new_apple_coords) {
					flag = true;
					break;
				}
			}
		}
	}
	_snake.go();

	if (!_snake.end()) {
		build_field();
	}
}

bool field::is_end_game() {
	return _snake.end();
}

void field::check_buttons(){
	int c = _getch();
	if (c == 72) {
		_snake.change_dir(snake::DOWN);
	}
	if (c == 80) {
		_snake.change_dir(snake::UP);
	}
	if (c == 75) {
		_snake.change_dir(snake::LEFT);
	}
	if (c == 77) {
		_snake.change_dir(snake::RIGHT);
	}
}

void field::build_field() {
	const auto& body = _snake.get_body();

	for (int i = 0; i < width; i++) {
		for (int j = 0; j < height; j++) {
			source[i][j] = EMPTY;
		}
	}

	source[_apple.get_coords().x][_apple.get_coords().y] = APPLE;

	for (const auto& cell : body) {
		source[cell.x][cell.y] = SNAKE;
	}
}


const std::vector<std::vector<cells>>& field::get_field() const {
	return source;
}
