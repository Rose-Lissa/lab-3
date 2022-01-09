#include<iostream>
#include<windows.h>
#include<ctime>
#include<chrono>
#include"Window.h"
#include"field.h"
#include <stdio.h>
#include <conio.h>
#include <random>

int main() {
	srand(time(0));
	field _field;
	window game_window(_field);
	auto begin = std::chrono::system_clock::now();

	while (1) {
		while (!_kbhit()) {
			auto end = std::chrono::system_clock::now();
			std::chrono::duration<double> sec = end - begin;
			//_field.check_buttons();
			if (sec.count() > 0.25) {
				_field.update();
				if (_field.is_end_game()) {
					break;
				}
				game_window.draw();
				begin = std::chrono::system_clock::now();
			}
		}
		if (_field.is_end_game()) {
			break;
		}
		_field.check_buttons();
	}

	system("cls");
	std::cout << "game over" << std::endl;
	return 0;
}