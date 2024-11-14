#pragma once
#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include "SFML/System.hpp"
#include <iostream>

class MovingObject {
public:
	MovingObject(int speed, bool isPlayer1, sf::Vector2f position, sf::Texture texture);
	~MovingObject();

	void setObjectSpeed(int&);
	void setObjectPosition(sf::Vector2f);
	sf::Vector2f getObjectPosition();
	int getObjectSpeed();
	sf::Rect<float> getObjectBounds();
	sf::Vector2f getOriginPosition();
	void updateOriginPosition();
private:
	int speed;
	sf::Sprite Object;
	sf::Texture ObjectTexture;
	sf::Vector2f originPosition;
	sf::Rect<float> ObjectBounds;
};