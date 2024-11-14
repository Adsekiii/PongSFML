#include "MovingObject.h"

MovingObject::MovingObject(int speed, bool isPlayer1, sf::Vector2f position, sf::Texture texture)
{
	this->speed = speed;
	this->Object.setTexture(texture);
	this->ObjectBounds = this->Object.getGlobalBounds();
	this->originPosition = sf::Vector2f(this->ObjectBounds.width / 2, this->ObjectBounds.height / 2);
	this->Object.setOrigin(this->originPosition);
	this->Object.setPosition(position);

}



MovingObject::~MovingObject() {};



void MovingObject::setObjectSpeed(int& newSpeed)
{
	this->speed = newSpeed;
}



int MovingObject::getObjectSpeed()
{
	return this->speed;
}



void MovingObject::setObjectPosition(sf::Vector2f paddlePosition) {
	this->Object.setPosition(paddlePosition);
}



sf::Vector2f MovingObject::getObjectPosition()
{
	return this->Object.getPosition();
}



sf::Rect<float> MovingObject::getObjectBounds() {
	return this->ObjectBounds;
}



sf::Vector2f MovingObject::getOriginPosition() {
	return this->originPosition;
}



void MovingObject::updateOriginPosition() {
	sf::Rect<float> bounds = this->Object.getGlobalBounds();
	this->originPosition = sf::Vector2f(bounds.getPosition().x + bounds.width / 2, bounds.getPosition().y + bounds.height / 2);
}
