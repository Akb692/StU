#pragma once
#include "Geometry.h"
#include <iostream>





class Image : public Geometry
{
public:
	Image(int x, int y, int w, int h, SDL_Renderer* renderer, std::string FilePath);
	
	
	std::string FilePath;
	SDL_Renderer* renderer;
	SDL_Texture* texture;
	void Draw(SDL_Renderer* renderer) override;
};

