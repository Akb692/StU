#pragma once
#include <SDL.h>
#include <vector>
#include "Math.h"

struct Color
{
	int r;
	int g;
	int b;
	int a;

};
class Geometry
{
public:
	
	int posX;
	int posY;
	int width;
	int height;
	Color color;

	Geometry(int x, int y, int w, int h);

	void SetPosition(int x, int y, float anchorX, float anchorY);
	
	Vector2 GetPosition(float anchorX, float anchorY);

	virtual void Draw(SDL_Renderer* renderer) = 0;

	void Move(float x, float y);
};



