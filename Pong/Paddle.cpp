#include "Paddle.h"

Paddle::Paddle(int speed, bool isPlayer1, sf::Vector2f position, sf::Vector2f paddleScale = sf::Vector2f(1.f, 3.f))
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
	sf::Rect<float> size = this->paddle.getGlobalBounds();
	this->paddle.setOrigin(sf::Vector2f(size.width/2, size.height/2));
	this->paddle.setPosition(position);
	this->paddle.setScale(paddleScale);

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
void Paddle::setPaddleScale(sf::Vector2f newScale) 
{
	this->paddle.setScale(newScale);
}
sf::Vector2f Paddle::getPaddlePosition()
{
	return this->paddle.getPosition();
}
void Paddle::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(this->paddle, states);
}
