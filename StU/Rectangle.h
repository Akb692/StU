#pragma once
#include "Geometry.h"
#include "SDL.h"
class Rectangle : public Geometry
{
public:
	Rectangle(int width, int height);

	SDL_Texture* texture = nullptr;

	void Draw(SDL_Renderer* renderer) override;

	void SetTexture(SDL_Texture* text)
	{
		texture = text;
	}
};