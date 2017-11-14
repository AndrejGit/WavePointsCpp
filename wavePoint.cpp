#include "wavePoint.h"
#include <cmath>
#include <SFML/Graphics.hpp>

WavePoint::WavePoint(float x_, float y_, float r, float s_) {
	x = x_;
	y = y_;
	yOff = y_;
	rad = r;
	seed = s_;
			
	shape.setRadius(rad);
	shape.setFillColor(sf::Color::White);
	shape.setOutlineThickness(2);
	shape.setOutlineColor(sf::Color::Black);
}
		
void WavePoint::update() {
	y = yOff + sin(seed) * 50;
	seed += 0.01; // freq
	shape.setPosition(sf::Vector2f(x, y));
}
