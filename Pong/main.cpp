#include "Main.h"

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600

int main() 
{
	sf::String windowTitle = "Pong";
	sf::VideoMode windowSize(WINDOW_WIDTH,WINDOW_HEIGHT);
	sf::RenderWindow window(windowSize, windowTitle);

	sf::Clock clock;

	
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


		sf::Time elapsed = clock.restart();
		dt = elapsed.asSeconds();
		//This piece of code isn't working I will try to resolve this next time
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
			player1.setPaddlePosition(sf::Vector2f(player1.getPaddlePosition().x, player1.getPaddlePosition().y - player1.getPaddleSpeed() * dt));
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
			player1.setPaddlePosition(sf::Vector2f(player1.getPaddlePosition().x, player1.getPaddlePosition().y + player1.getPaddleSpeed() * dt));
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
			player2.setPaddlePosition(sf::Vector2f(player2.getPaddlePosition().x, player2.getPaddlePosition().y - player2.getPaddleSpeed() * dt));
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
			player2.setPaddlePosition(sf::Vector2f(player2.getPaddlePosition().x, player2.getPaddlePosition().y + player2.getPaddleSpeed() * dt));
		}
		

		window.clear();
		window.draw(player1);
		window.draw(player2);
		window.draw(ball);
		window.display();
	}

	return EXIT_SUCCESS;
}


