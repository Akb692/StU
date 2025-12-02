#include "Circle.h"


Circle::Circle(int x, int y, int w, int h, int r, int p)
	: Geometry(x, y, w, h) {

}


void Draw(SDL_Renderer* renderer, Circle& circle)
{
	float dist = 2.0f * M_PI / circle.precision;
	int lastX = circle.radius * cos(0) + circle.posX;
	int lastY = circle.radius * sin(0) + circle.posY;

	for (int i = 1; i <= circle.precision; i++)
	{
		int newX = circle.radius * cos(dist * i) + circle.posX;
		int newY = circle.radius * sin(dist * i) + circle.posY;
		SDL_RenderDrawLine(renderer, lastX, lastY, newX, newY);
		lastX = newX;
		lastY = newY;
	}
}