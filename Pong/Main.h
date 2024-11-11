#pragma once
#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include "SFML/System.hpp"
#include "Paddle.h"
#include "Ball.h"
#include <iostream>

void controlPlayer1(Paddle player, float dt);
void controlPlayer2(Paddle player, float dt);
void startGame();