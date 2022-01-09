#include "Window.h"
#include <iostream>
#include <windows.h>

window::window(const field& f) : game_field(f)
{
}

void window::draw()
{
	system("cls");
	const auto& f = game_field.get_field();
	for (int i = -1; i < game_field.width + 1; i++) {
		std::cout << wall_cell;
	}
	std::cout << std::endl;
	for (int i = 0; i < game_field.height; i++) {
		std::cout << wall_cell;
		for (int j = 0; j < game_field.width; j++) {
			if (f[j][i] == EMPTY)
				std::cout << empty_cell;
			else if (f[j][i] == SNAKE)
				std::cout << snake_cell;
			else if (f[j][i] == APPLE)
				std::cout << apple_cell;
		}
		std::cout << wall_cell << std::endl;
	}
	for (int i = -1; i < game_field.width + 1; i++) {
		std::cout << wall_cell;
	}
	std::cout << std::endl;
}
