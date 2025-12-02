#pragma once
#include <SDL.h>
class Geometry
{
public:
	int posX;
	int posY;
	int width;
	int height;
	
	Geometry() : posX(500), posY(500), width(200), height(200) {}

	virtual void Draw(SDL_Renderer* renderer);
};

