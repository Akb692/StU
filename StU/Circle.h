#pragma once
#include "Geometry.h"


class Circle : public Geometry
{
public:
	int precision;
	int radius;

	void Draw(SDL_Renderer* renderer) override;
};

