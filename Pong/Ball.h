#pragma once
#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include "SFML/System.hpp"
#include <iostream>

class Ball : public sf::Drawable, public sf::Transformable {
public:
	Ball(int speed, sf::Vector2f position, sf::Vector2f scale);
	~Ball();
	void setBallPosition(sf::Vector2f);
	void setBallScale(sf::Vector2f);
	sf::Vector2f getBallPosition();
	void startBall();

private:
	sf::Texture texture;
	sf::Sprite ball;
	int speed;
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

};