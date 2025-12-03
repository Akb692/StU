#pragma once
#include "Geometry.h"


class Rectangle : public Geometry

{
public:

	Rectangle(int x, int y, int w, int h);


	void Draw(SDL_Renderer* renderer) override;

};

