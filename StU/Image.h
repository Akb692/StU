#pragma once
#include "Geometry.h"
#include <iostream>





class Image : public Geometry
{
public:
	Image(int x, int y, int w, int h, SDL_Renderer* renderer, const char* FilePath);
	
	
	
	SDL_Renderer* renderer;
	const char* FilePath;
	SDL_Texture* texture = NULL;
	void Draw(SDL_Renderer* renderer) override;
};
