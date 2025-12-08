#include "Circle.h"
#include <cmath>
#include <SDL.h>
Circle::Circle(int x, int y, int w, int h, int r, int p)
	: Geometry(x, y, w, h), radius(r), precision(p) {

}


void Circle::Draw(SDL_Renderer* renderer)
{
	float dist = 2.0f * M_PI / precision;
	int lastX = radius * cos(0) + posX;
	int lastY = radius * sin(0) + posY;

	for (int i = 1; i <= precision; i++)
	{
		int newX = radius * cos(dist * i) + posX;
		int newY = radius * sin(dist * i) + posY;
		SDL_RenderDrawLine(renderer, lastX, lastY, newX, newY);
		lastX = newX;
		lastY = newY;
	}
}

void Circle::Right(Circle c)
{

}
