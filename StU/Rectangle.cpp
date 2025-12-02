#include "Rectangle.h"
#include <iostream>

using namespace std;

void Draw(SDL_Renderer* renderer,Rectangle& rectangle)
{
	SDL_RenderDrawLine(renderer, rectangle.posX, rectangle.posY, rectangle.posX + rectangle.width, rectangle.posY);
	SDL_RenderDrawLine(renderer, rectangle.posX + rectangle.width, rectangle.posY, rectangle.posX + rectangle.width, rectangle.posY + rectangle.height);
	SDL_RenderDrawLine(renderer, rectangle.posX + rectangle.width, rectangle.posY + rectangle.height, rectangle.posX, rectangle.posY + rectangle.height);
	SDL_RenderDrawLine(renderer, rectangle.posX, rectangle.posY + rectangle.height, rectangle.posX, rectangle.posY);
}