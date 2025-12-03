#include "Rectangle.h"
#include <iostream>
using namespace std;

<<<<<<< HEAD


Rectangle::Rectangle(int x, int y, int w, int h)
	: Geometry(x, y, w, h) {
}


=======
>>>>>>> f93304038edf9d7410a5aa0a3f823bc6fe267601
void Rectangle::Draw(SDL_Renderer* renderer)
{
	SDL_RenderDrawLine(renderer, posX, posY, posX + width, posY);
	SDL_RenderDrawLine(renderer, posX + width, posY, posX + width, posY + height);
	SDL_RenderDrawLine(renderer, posX + width, posY + height, posX, posY + height);
	SDL_RenderDrawLine(renderer, posX, posY + height, posX, posY);
}