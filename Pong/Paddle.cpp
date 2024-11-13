#include "Paddle.h"

Paddle::Paddle(int speed, bool isPlayer1, sf::Vector2f position)
{
	this->speed = speed;
	this->isPlayer1 = isPlayer1;
	if (this->paddleTexture.loadFromFile(isPlayer1 ? "./textures/Player1.png" : "./textures/Player2.png")) {
		std::cout << "File loaded successfully!\n";
	}
	else {
		std::cout << "File doesn't exist!\n";
	}
	this->paddle.setTexture(this->paddleTexture);
	this->paddleBounds = this->paddle.getGlobalBounds();
	this->originPosition = sf::Vector2f(this->paddleBounds.width / 2, this->paddleBounds.height / 2);
	this->paddle.setOrigin(this->originPosition);
	this->paddle.setPosition(position);

}



Paddle::~Paddle() {};



void Paddle::setPaddleSpeed(int &newSpeed) 
{
	this->speed = newSpeed;
}



int Paddle::getPaddleSpeed() 
{
	return this->speed;
}



void Paddle::setPaddlePosition(sf::Vector2f paddlePosition) {
	this->paddle.setPosition(paddlePosition);
}



sf::Vector2f Paddle::getPaddlePosition()
{
	return this->paddle.getPosition();
}



sf::Rect<float> Paddle::getPaddleBounds() {
	return this->paddleBounds;
}



sf::Vector2f Paddle::getOriginPosition() {
	return this->originPosition;
}



void Paddle::updateOriginPosition() {
	sf::Rect<float> bounds = this->paddle.getGlobalBounds();
	this->originPosition = sf::Vector2f(bounds.getPosition().x + bounds.width / 2, bounds.getPosition().y + bounds.height / 2);
}



void Paddle::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(this->paddle, states);
}
