#pragma once
#include <SDL.h>
#include <vector>
#include "Math.h"

class Geometry
{
public:
	
	int posX;
	int posY;
	int width;
	int height;
	Geometry(int x, int y, int w, int h);

	void SetPosition(int x, int y, float anchorX, float anchorY);
	
	Vector2 GetPosition(float anchorX, float anchorY);

	virtual void Draw(SDL_Renderer* renderer);
};

