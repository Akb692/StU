#include "Image.h"
#include <iostream>
using namespace std;

Image::Image(int x, int y, int w, int h, SDL_Renderer* r, const char* FP)
	: Geometry(x, y, w, h), renderer(r), FilePath(FP) {

}







void Image::Draw(SDL_Renderer* renderer)
{
	SDL_Surface* tmp = NULL;
	texture = NULL;
	tmp = SDL_LoadBMP(FilePath);

	if (tmp == NULL)
	{
		cout << "erreur" << endl;
	}
	SDL_RenderCopy(renderer, texture, NULL, NULL);
	
	SDL_CreateTextureFromSurface(renderer, tmp);

	
}