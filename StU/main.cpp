#include <SDL.h>
#include <iostream>
#include "Circle.h"
#include "Rectangle.h"
#include "Math.h"

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


	SDL_Window* window = SDL_CreateWindow("SDL", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1080, 940, SDL_WINDOW_SHOWN);

	if (!window)
	{
		std::cout << "SDL_CreateWindow Error : " << SDL_GetError << std::endl;
		SDL_Quit();
		return 1;
	}



	SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
	//dessiner un pixel

	

	

	Rectangle r1(200, 200, 100, 100);
	r1.SetPosition(0, 0, 0, 0);
	r1.Draw(renderer);

	Rectangle r2(200, 200, 100, 100);
	r2.SetPosition(1080, 0, 1, 0);
	r2.Draw(renderer);

	Rectangle r3(200, 200, 100, 100);
	r3.SetPosition(0, 940, 0, 1);
	r3.Draw(renderer);

	Rectangle r4(200, 200, 100, 100);
	r4.SetPosition(1080, 940, 1, 1);
	r4.Draw(renderer);

	Rectangle r5(200, 200, 100, 100);
	r5.SetPosition(540, 470, 0.5, 0.5);
	r5.Draw(renderer);
	

	
	Vector2 PosHautGauche = r5.GetPosition(0, 0);
	Vector2 PosHautDroite = r5.GetPosition(1, 0);
	Vector2 PosBasGauche = r5.GetPosition(0, 1);
	Vector2 PosBasDroite = r5.GetPosition(1, 1);

	Circle c1(PosHautGauche.x, PosHautGauche.y, 10, 10, 20, 600);
	c1.Draw(renderer);

	Circle c2(PosHautDroite.x, PosHautDroite.y, 10, 10, 20, 600);
	c2.Draw(renderer);

	Circle c3(PosBasGauche.x, PosBasGauche.y, 10, 10, 20, 600);
	c3.Draw(renderer); 
	
	Circle c4(PosBasDroite.x, PosBasDroite.y, 10, 10, 20, 600);
	c4.Draw(renderer);




	SDL_Delay(900);
	SDL_RenderPresent(renderer);
	SDL_Delay(900);


	return 0;
}


