#pragma once
#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include "SFML/System.hpp"
#include <random>
#include <time.h>
#include <iostream>

class Ball : public sf::Drawable, public sf::Transformable {
public:
	Ball(int speed, sf::Vector2f position);
	~Ball();
	void setBallPosition(sf::Vector2f);
	sf::Vector2f getBallPosition();
	void setRandomVelocity();
	void setVelocity(sf::Vector2f);
	void updateBall(float dt);
	sf::Vector2f getVelocity();
	sf::Rect<float> getBallBounds();
	sf::Vector2f getOriginPosition();
	void updateOriginPosition();


private:
	sf::Texture texture;
	sf::Sprite ball;
	int speed;
	sf::Vector2f originPosition;
	sf::Vector2f velocity;
	sf::Rect<float> ballBounds;
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

};