#pragma once
#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include "SFML/System.hpp"
#include <iostream>

class Paddle : public sf::Transformable, public sf::Drawable
{
public:
	Paddle(int speed, bool isPlayer1, sf::Vector2f position, sf::Vector2f paddleScale);
	~Paddle();

	void setPaddleSpeed(int&);
	void setPaddlePosition(sf::Vector2f);
	sf::Vector2f getPaddlePosition();
	void setPaddleScale(sf::Vector2f);
	int getPaddleSpeed();
	sf::Rect<float> getPaddleBounds();
	sf::Vector2f getOriginPosition();
	void updateOriginPosition();
private:
	int speed;
	bool isPlayer1;
	sf::Sprite paddle;
	sf::Texture paddleTexture;
	sf::Vector2f originPosition;
	sf::Rect<float> paddleBounds;
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};
