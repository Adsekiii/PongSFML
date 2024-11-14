#pragma once
#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include "SFML/System.hpp"
#include "Paddle.h"
#include "Ball.h"
#include "Collision.h"
#include "Points.h"
#include <iostream>

int main();
void player1Movement(Paddle *player, float dt);
void player2Movement(Paddle *player, float dt);