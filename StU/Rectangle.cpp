#include "Rectangle.h"
#include <iostream>

using namespace std;

void Rectangle::Draw(SDL_Renderer* renderer)
{
	SDL_RenderDrawLine(renderer, posX, posY, posX + width, posY);
	SDL_RenderDrawLine(renderer, posX + width, posY, posX + width, posY + height);
	SDL_RenderDrawLine(renderer, posX + width, posY + height, posX, posY + height);
	SDL_RenderDrawLine(renderer, posX, posY + height, posX, posY);
}