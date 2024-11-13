#include "Collision.h"

Collision::Collision(Paddle player, Ball *ball) 
{
	//TODO Fix ball entering paddle when bumpped from above or below 

	this->collided = false;
	sf::Rect<float> paddleBounds = player.getPaddleBounds();
	sf::Rect<float> ballBounds = ball->getBallBounds();
	
	if (ball->getOriginPosition().x + ballBounds.width / 2 >= player.getOriginPosition().x - paddleBounds.width / 2 &&
		ball->getOriginPosition().x - ballBounds.width / 2 <= player.getOriginPosition().x + paddleBounds.width / 2 &&
		ball->getOriginPosition().y + ballBounds.height / 2 >= player.getOriginPosition().y - paddleBounds.height / 2 &&
		ball->getOriginPosition().y - ballBounds.height / 2 <= player.getOriginPosition().y + paddleBounds.height / 2 &&
		!this->collided){
		ball->setVelocity(sf::Vector2f(ball->getVelocity().x * -1, ball->getVelocity().y));
	}
}              
Collision::Collision(Paddle *player, sf::Vector2f windowBounds)
{

	player->updateOriginPosition();
	sf::Rect<float> paddleBounds = player->getPaddleBounds();

	if (player->getOriginPosition().y - paddleBounds.height/2  < 0)
	{
		player->setPaddlePosition(sf::Vector2f(player->getPaddlePosition().x,0+paddleBounds.height/2));
	}
	if (player->getOriginPosition().y + paddleBounds.height / 2  > windowBounds.y) 
	{
		player->setPaddlePosition(sf::Vector2f(player->getPaddlePosition().x, windowBounds.y - paddleBounds.height/2));
	}
}

Collision::Collision(Ball *ball, sf::Vector2f windowBounds)
{
	ball->updateOriginPosition();
	sf::Rect<float> ballBounds = ball->getBallBounds();

	if (ball->getOriginPosition().y - ballBounds.height / 2 < 0)
	{
		ball->setVelocity(sf::Vector2f(ball->getVelocity().x, ball->getVelocity().y * -1));
		ball->setBallPosition(sf::Vector2f(ball->getBallPosition().x, 0 + ballBounds.height / 2));
	}
	if (ball->getOriginPosition().y + ballBounds.height / 2 > windowBounds.y)
	{
		ball->setVelocity(sf::Vector2f(ball->getVelocity().x, ball->getVelocity().y * -1));
		ball->setBallPosition(sf::Vector2f(ball->getBallPosition().x, windowBounds.y - ballBounds.height / 2));
	}
}

void Collision::resetCollided() 
{
	this->collided = false;
}

