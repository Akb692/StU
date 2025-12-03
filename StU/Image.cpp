#include "Image.h"


Image::Image(int x, int y, int w, int h, SDL_Renderer* r, std::string FP)
	: Geometry(x,y,w,h) , renderer(r), FilePath(FP){

} 


void Image::Draw(SDL_Renderer* renderer)
{

	SDL_RenderCopy(renderer, texture, NULL, NULL);
}