#pragma once
#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include "SFML/System.hpp"
#include "Paddle.h"
#include "Points.h"
#include "Ball.h"
#include <iostream>

class Collision {
private:
	bool collided;
public:
	Collision(Paddle, Ball*);
	Collision(Paddle*, sf::Vector2f);
	Collision(Ball* ball, sf::Vector2f windowBounds, Points *player1, Points *player2, sf::Clock *ballWaitClock, bool *alreadyChecked, Paddle* paddle1, Paddle* paddle2);
	void resetCollided();
};