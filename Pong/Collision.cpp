#include "Collision.h"

Collision::Collision(Paddle player, Ball *ball) 
{
	//TODO Fix ball entering paddle when bumpped from above or below 

	sf::Rect<float> paddleBounds = player.getPaddleBounds();
	sf::Rect<float> ballBounds = ball->getBallBounds();
	
	if (ball->getOriginPosition().x + ballBounds.width / 2 >= player.getOriginPosition().x - paddleBounds.width / 2 &&
		ball->getOriginPosition().x - ballBounds.width / 2 <= player.getOriginPosition().x + paddleBounds.width / 2 &&
		ball->getOriginPosition().y + ballBounds.height / 2 >= player.getOriginPosition().y - paddleBounds.height / 2 &&
		ball->getOriginPosition().y - ballBounds.height / 2 <= player.getOriginPosition().y + paddleBounds.height / 2)
	{
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

Collision::Collision(Ball *ball, sf::Vector2f windowBounds, Points *player1, Points *player2 , sf::Clock *ballWaitClock, bool* alreadyChecked, Paddle *paddle1, Paddle *paddle2)
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
	if (ball->getOriginPosition().x + ballBounds.width / 2 < 0 )
	{
		ball->setVelocity(sf::Vector2f(0.f,0.f));
		ball->setBallPosition(sf::Vector2f(windowBounds.x/2,windowBounds.y/2));
		player2->setPoints(player2->getPoints() + 1);
		*alreadyChecked = false;
		ballWaitClock->restart();
		paddle1->setPaddlePosition(sf::Vector2f(paddle1->getPaddlePosition().x, windowBounds.y / 2));
		paddle2->setPaddlePosition(sf::Vector2f(paddle2->getPaddlePosition().x, windowBounds.y / 2));
	}
	if (ball->getOriginPosition().x + ballBounds.width / 2 > windowBounds.x)
	{
		ball->setVelocity(sf::Vector2f(0.f, 0.f));
		ball->setBallPosition(sf::Vector2f(windowBounds.x / 2, windowBounds.y / 2));
		player1->setPoints(player1->getPoints() + 1);
		*alreadyChecked = false;
		ballWaitClock->restart();
		paddle1->setPaddlePosition(sf::Vector2f(paddle1->getPaddlePosition().x, windowBounds.y / 2));
		paddle2->setPaddlePosition(sf::Vector2f(paddle2->getPaddlePosition().x, windowBounds.y / 2));
	}
}

void Collision::resetCollided() 
{
	this->collided = false;
}

