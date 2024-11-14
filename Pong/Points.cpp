#include "Points.h"

Points::Points(bool isPlayer1) {
	this->points = 0;
	if (!this->font.loadFromFile("./arial.ttf")) {
		std::cout << "Couldn't load font file!\n";
	}
	this->playerPoints.setFont(this->font);
	this->playerPoints.setString(std::to_string(this->points));
	sf::Rect<float> bounds = this->playerPoints.getGlobalBounds();
	this->playerPoints.setOrigin(sf::Vector2f(bounds.width/2, bounds.height/2));
	if (isPlayer1) {
		this->playerPoints.setPosition(sf::Vector2f(200, 300));
	}
	else {
		this->playerPoints.setPosition(sf::Vector2f(600,300));
	}

}

Points::~Points() {}

void Points::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(this->playerPoints, states);
}

void Points::setPoints(int points) {
	this->points = points;
}

void Points::updatePoints() {
	this->playerPoints.setString(std::to_string(this->points));
}

int Points::getPoints() {
	return this->points;
}