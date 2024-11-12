#pragma once
#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include "SFML/System.hpp"
#include "Paddle.h"
#include "Ball.h"
#include <iostream>

class Collision {
private:
	bool collided;
public:
	Collision(Paddle, Ball*);
	Collision(Paddle*, sf::Vector2f);
	Collision(Ball*, sf::Vector2f);
	void resetCollided();
};