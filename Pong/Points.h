#pragma once
#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include "SFML/System.hpp"
#include <iostream>

class Points: public sf::Drawable, public sf::Transformable {
public:
	Points(bool isPlayer1);
	~Points();
	void setPoints(int);
	int getPoints();
	void updatePoints();

private:
	sf::Font font;
	sf::Text playerPoints;
	int points;
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};