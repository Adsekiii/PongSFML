#include "Main.h"

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600

int main() 
{
	sf::String windowTitle = "Pong";
	sf::VideoMode windowSize(WINDOW_WIDTH,WINDOW_HEIGHT);
	sf::RenderWindow window(windowSize, windowTitle);

	sf::Clock clock;

	sf::Time time;
	float dt;

	Paddle player1(100, true, sf::Vector2f(64, 300), sf::Vector2f(1.f, 5.f));
	Paddle player2(100, false, sf::Vector2f(736, 300), sf::Vector2f(1.f, 5.f));

	Ball ball(100, sf::Vector2f(400.f,300.f), sf::Vector2f(1.f,1.f));

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


		time = clock.getElapsedTime();
		dt = time.asMilliseconds();
		//This piece of code isn't working I will try to resolve this next time
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::W)) {
			player1.setPaddlePosition(sf::Vector2f(player1.getPosition().x, player1.getPosition().y - player1.getPaddleSpeed() * dt));
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::W)) {
			player1.setPaddlePosition(sf::Vector2f(player1.getPosition().x, player1.getPosition().y + player1.getPaddleSpeed() * dt));
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::W)) {
			player2.setPaddlePosition(sf::Vector2f(player2.getPosition().x, player2.getPosition().y - player2.getPaddleSpeed() * dt));
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::W)) {
			player2.setPaddlePosition(sf::Vector2f(player2.getPosition().x, player2.getPosition().y + player2.getPaddleSpeed() * dt));
		}
		

		window.clear();
		window.draw(player1);
		window.draw(player2);
		window.draw(ball);
		window.display();
		
		clock.restart();
	}

	return EXIT_SUCCESS;
}


