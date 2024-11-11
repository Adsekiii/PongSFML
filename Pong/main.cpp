#include "Main.h"

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600

int main() 
{
	sf::String windowTitle = "Pong";
	sf::VideoMode windowSize(WINDOW_WIDTH,WINDOW_HEIGHT);
	sf::RenderWindow window(windowSize, windowTitle);

	Paddle player1(100,true,sf::Vector2f(400,300),sf::Vector2f(1.f,1.f));

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

		window.clear();
		window.draw(player1);
		window.display();
	}

	return EXIT_SUCCESS;
}
