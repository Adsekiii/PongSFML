#include "Main.h"

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600

int main() 
{
	sf::String windowTitle = "Pong";
	sf::VideoMode windowSize(WINDOW_WIDTH,WINDOW_HEIGHT);
	sf::RenderWindow window(windowSize, windowTitle);

	sf::Clock deltaTimeClock;
	sf::Clock startGame;

	float dt;
	bool alreadyChecked = false;

	Paddle player1(150, true, sf::Vector2f(64, 300));
	Paddle player2(150, false, sf::Vector2f(736, 300));

	Points player1Points(true);
	Points player2Points(false);

	Ball ball(100, sf::Vector2f(400.f,300.f));

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed) 
			{
				window.close();
			}
		}
		if (startGame.getElapsedTime() > sf::Time(sf::seconds(1)) && !alreadyChecked) {
			ball.setRandomVelocity();
			alreadyChecked = !alreadyChecked;
		}

		sf::Time elapsed = deltaTimeClock.restart();
		dt = elapsed.asSeconds();

		Collision player1Collision(&player1, sf::Vector2f(WINDOW_WIDTH, WINDOW_HEIGHT));
		Collision player2Collision(&player2, sf::Vector2f(WINDOW_WIDTH, WINDOW_HEIGHT));
		Collision ballCollisions(&ball, sf::Vector2f(WINDOW_WIDTH,WINDOW_HEIGHT),&player1Points,&player2Points,&startGame,&alreadyChecked, &player1, &player2);
		Collision player1ToBallCollision(player1, &ball);
		Collision player2ToBallCollision(player2, &ball);

		player1Points.updatePoints();
		player2Points.updatePoints();

		player1Movement(&player1,dt);
		player2Movement(&player2,dt);
		ball.updateBall(dt);
		window.clear();
		window.draw(player1);
		window.draw(player2);
		window.draw(player1Points);
		window.draw(player2Points);
		window.draw(ball);
		window.display();
	}

	return EXIT_SUCCESS;
}

void player1Movement(Paddle *player, float dt) {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
		player->setPaddlePosition(sf::Vector2f(player->getPaddlePosition().x, player->getPaddlePosition().y - player->getPaddleSpeed() * dt));
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
		player->setPaddlePosition(sf::Vector2f(player->getPaddlePosition().x, player->getPaddlePosition().y + player->getPaddleSpeed() * dt));
	}
}
void player2Movement(Paddle *player,float dt) {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
		player->setPaddlePosition(sf::Vector2f(player->getPaddlePosition().x, player->getPaddlePosition().y - player->getPaddleSpeed() * dt));
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
		player->setPaddlePosition(sf::Vector2f(player->getPaddlePosition().x, player->getPaddlePosition().y + player->getPaddleSpeed() * dt));
	}
}
