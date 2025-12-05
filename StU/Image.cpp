#include "Image.h"
#include <iostream>
using namespace std;

Image::Image(int x, int y, int w, int h, SDL_Renderer* r, const char* FP)
	: Geometry(x, y, w, h), renderer(r), FilePath(FP) {

}







void Image::Draw(SDL_Renderer* renderer)
{
	SDL_Surface* surface = NULL;
	texture = NULL;


	surface = SDL_LoadBMP(FilePath);

	if (surface == NULL)
	{
		cout << "loading error" << endl;
	}
	

	texture = SDL_CreateTextureFromSurface(renderer, surface);

	SDL_FreeSurface(surface);
	
	SDL_RenderCopy(renderer, texture, NULL, NULL);
	
	

	
}