#include "Ball.h"

Ball::Ball(int speed, sf::Vector2f position, sf::Vector2f scale = sf::Vector2f(1.f,1.f))
{
	if (this->texture.loadFromFile("./textures/Ball.png")) {
		std::cout << "File loaded successfully!\n";
	}
	else {
		std::cout << "File doesn't exist!\n";
	}
	this->ball.setTexture(this->texture);
	this->ball.setScale(scale);
	sf::Rect<float> size = this->ball.getGlobalBounds();
	this->ball.setOrigin(sf::Vector2f(size.width/2,size.height/2));
	this->ball.setPosition(position);
	this->speed = speed;
}
Ball::~Ball() 
{

}
void Ball::setBallPosition(sf::Vector2f position) 
{
	this->ball.setPosition(position);
}
void Ball::setBallScale(sf::Vector2f scale)
{
	this->ball.setScale(scale);
}
sf::Vector2f Ball::getBallPosition() 
{
	return this->ball.getPosition();
}
void startBall() {

}
void Ball::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(this->ball, states);
}