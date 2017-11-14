#ifndef WAVEPOINT_H
#define WAVEPOINT_H

#include <SFML/Graphics.hpp>

class WavePoint {
	public:
		float x;
		float y;
		sf::CircleShape shape;
	private:
		float yOff;
		float rad;
		float seed;
	public:
		WavePoint(float x_, float y_, float r, float s_);
		void update();
};

#endif
