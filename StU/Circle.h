#pragma once
#include "Geometry.h"


class Circle : public Geometry
{
public:

	Circle(int x, int y, int w, int h, int r, int p);


	int precision;
	int radius;
	void Draw(SDL_Renderer* renderer) override;
	void Right(Circle c);
};

