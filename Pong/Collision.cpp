#include "Collision.h"

Collision::Collision(Paddle player, Ball *ball) 
{
	this->collided = false;
	sf::Rect<float> paddleBounds = player.getPaddleBounds();
	sf::Rect<float> ballBounds = ball->getBallBounds();
	
	if (ball->getOriginPosition().x + ballBounds.width / 2 <= player.getOriginPosition().x + paddleBounds.width / 2 &&
		ball->getOriginPosition().x - ballBounds.width / 2 >= player.getOriginPosition().x - paddleBounds.width / 2 &&
		ball->getOriginPosition().y + ballBounds.height / 2 >= player.getOriginPosition().y + paddleBounds.height / 2 &&
		ball->getOriginPosition().y - ballBounds.height / 2 <= player.getOriginPosition().y - paddleBounds.height / 2) {
		ball->setVelocity(sf::Vector2f(ball->getVelocity().x * -1, ball->getVelocity().y));
	}

}
Collision::Collision(Paddle *player, sf::Vector2f windowBounds)
{

	//Title line is included in y level need to fix that 

	player->updateOriginPosition();
	sf::Rect<float> paddleBounds = player->getPaddleBounds();
	
	std::cout << player->getOriginPosition().y<<"\n";

	if (player->getOriginPosition().y - paddleBounds.height/2 * 3 < 0)
	{
		player->setPaddlePosition(sf::Vector2f(player->getPaddlePosition().x,0+paddleBounds.height*3));
	}
	if (player->getOriginPosition().y + paddleBounds.height / 2 * 3 > windowBounds.y) 
	{
		player->setPaddlePosition(sf::Vector2f(player->getPaddlePosition().x, windowBounds.y - paddleBounds.height*3));
	}
}

Collision::Collision(Ball *ball, sf::Vector2f windowBounds)
{
	sf::Rect<float> ballBounds = ball->getBallBounds();

	if (ball->getOriginPosition().y - ballBounds.height / 2 < 0)
	{
		ball->setVelocity(sf::Vector2f(ball->getVelocity().x, ball->getVelocity().y * -1));
	}
	if (ball->getOriginPosition().y + ballBounds.height / 2 > windowBounds.y)
	{
		ball->setVelocity(sf::Vector2f(ball->getVelocity().x, ball->getVelocity().y * -1));
	}
}

void Collision::resetCollided() 
{
	this->collided = false;
}

