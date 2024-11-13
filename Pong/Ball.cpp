#include "Ball.h"

Ball::Ball(int speed, sf::Vector2f position)
{
	if (this->texture.loadFromFile("./textures/Ball.png")) {
		std::cout << "File loaded successfully!\n";
	}
	else {
		std::cout << "File doesn't exist!\n";
	}
	this->ball.setTexture(this->texture);
	this->ballBounds = this->ball.getGlobalBounds();
	this->originPosition = sf::Vector2f(this->ballBounds.width / 2, this->ballBounds.height / 2);
	this->ball.setOrigin(this->originPosition);
	this->ball.setPosition(position);
	this->speed = speed;
	this->setVelocity(sf::Vector2f(0.f, 0.f));
}
Ball::~Ball() 
{

}
void Ball::setBallPosition(sf::Vector2f position) 
{
	this->ball.setPosition(position);
}
sf::Vector2f Ball::getBallPosition() 
{
	return this->ball.getPosition();
}
void Ball::setVelocity(sf::Vector2f newVelocity) {
	this->velocity = newVelocity;
}
sf::Vector2f Ball::getVelocity() {
	return this->velocity;
}
void Ball::setRandomVelocity() {
	srand(time(NULL));
	this->setVelocity(sf::Vector2f(rand() % 2 == 0 ? -1.f : 1.f, rand() % 2 == 0 ? -1.f : 1.f));
}
void Ball::updateBall(float dt) {
	this->setBallPosition(sf::Vector2f(this->getBallPosition().x + (this->getVelocity().x * this->speed * dt), this->getBallPosition().y + (this->getVelocity().y * this->speed * dt)));
}
sf::Rect<float> Ball::getBallBounds() {
	return this->ballBounds;
}
sf::Vector2f Ball::getOriginPosition() {
	return this->originPosition;
}
void Ball::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(this->ball, states);
}