#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>
#include "wavePoint.h"

using namespace std;

sf::RenderWindow window(sf::VideoMode(600, 600), "Wave");

vector<WavePoint> points;
sf::VertexArray midline(sf::LinesStrip, 2);
sf::VertexArray joints(sf:: LinesStrip, 10);

void setup() {
	window.setVerticalSyncEnabled(false);
	
	for (int i = 1; i < 11; i++) { // Create point objects
		points.push_back(WavePoint(i*50, 300, 10, i));
	}
	
	// Midline setup
    midline[0].position = sf::Vector2f(0, 300);
    midline[1].position = sf::Vector2f(600, 300);
    midline[0].color = sf::Color::Black;
    midline[1].color = sf::Color::Black;
}

void draw() {
	window.clear(sf::Color::White);
	window.draw(midline);
	window.draw(joints);
	for (int i = 0; i < points.size(); i++) {
		WavePoint* iPoint = &points[i];
		iPoint->update();
		window.draw(iPoint->shape);
		
		joints[i].color = sf::Color::Black;
		joints[i].position = sf::Vector2f(iPoint->x + 10, iPoint->y + 10);
	}
	
	window.display();	
}

int main() {
	setup();

	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window.close();
			}
		}
		
		draw();
	}

	return 0;
}
