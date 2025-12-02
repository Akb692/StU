#include <SDL.h>
#include <iostream>
#include "Circle.h"
#include "Rectangle.h"
void DrawHorizontalLine(SDL_Renderer* renderer, int x, int y, int length)
{
	SDL_RenderDrawPoint(renderer, x, y);

	for (int i = 0; i < length; i++)
	{
		SDL_RenderDrawPoint(renderer, i, y);
	}
}

void DrawVerticalLine(SDL_Renderer* renderer, int x, int y, int length)
{
	SDL_RenderDrawPoint(renderer, x, y);

	for (int i = 0; i < length; i++)
	{
		SDL_RenderDrawPoint(renderer, x, i);
	}
}

void DrawRectangle(SDL_Renderer* renderer, int x, int y, int width, int height)
{
	SDL_RenderDrawLine(renderer, x, y, x + width, y);
	SDL_RenderDrawLine(renderer, x + width, y, x + width, y + height);
	SDL_RenderDrawLine(renderer, x + width, y + height, x, y + height);
	SDL_RenderDrawLine(renderer, x, y + height, x, y);

}


void DrawCircle(SDL_Renderer* renderer, int x, int y, int radius, int precision)
{
	float dist = 2.0f * M_PI / precision;
	int lastX = radius * cos(0) + x;
	int lastY = radius * sin(0) + y;

	for (int i = 1; i <= precision; i++)
	{
		int newX = radius * cos(dist * i) + x;
		int newY = radius * sin(dist * i) + y;
		SDL_RenderDrawLine(renderer, lastX, lastY, newX, newY);
		lastX = newX;
		lastY = newY;
	}

}

void DrawLine(SDL_Renderer* renderer, float x1, float y1, float x2, float y2)
{

	int translationX = x1 + x2;
	int translationY = y1 + y2;

	int distX = abs(translationX);
	int distY = abs(translationY);

	int max = std::max(distX, distY);

	float stepX = translationX / (float)max;
	float stepY = translationY / (float)max;

	float x = x1;
	float y = y1;
}

int main(int argc, char* argv[1])
{

	if (SDL_Init(SDL_INIT_VIDEO) != 0)
	{
		std::cout << "SDL_Init Error : " << SDL_GetError() << std::endl;
		return 1;
	}


	SDL_Window* window = SDL_CreateWindow("SDL", 100, 100, 640, 480, SDL_WINDOW_SHOWN);

	if (!window)
	{
		std::cout << "SDL_CreateWindow Error : " << SDL_GetError << std::endl;
		SDL_Quit();
		return 1;
	}



	SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
	//dessiner un pixel


	Circle c (200)



	SDL_Delay(200);
	SDL_RenderPresent(renderer);
	SDL_Delay(2000);


	return 0;
}


