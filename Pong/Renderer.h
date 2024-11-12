#pragma once
#include "SFML/Graphics.hpp"
#include "SFML/System.hpp"
#include "SFML/Window.hpp"
#include <iostream>



class Render {
private:
	#define WINDOW_WIDTH 800
	#define WINDOW_HEIGHT 600
	sf::VideoMode windowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
	sf::RenderWindow window;
public:
	void render();
};