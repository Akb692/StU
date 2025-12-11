#include <SDL.h>
#include <iostream>
#include "Circle.h"
#include "Rectangle.h"
#include "Math.h"
#include "Image.h"
#include "InputManager.h"
#include <cmath>
#include "Projectile.h"
#include "GameManager.h"
using namespace std;


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

/*

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
	
	
	//TP 2
	
	/*

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
	/*
	Circle c2(PosHautDroite.x, PosHautDroite.y, 10, 10, 20, 600);
	c2.Draw(renderer);

	Circle c3(PosBasGauche.x, PosBasGauche.y, 10, 10, 20, 600);
	c3.Draw(renderer); 
	
	Circle c4(PosBasDroite.x, PosBasDroite.y, 10, 10, 20, 600);
	c4.Draw(renderer);
	
	*/



	/*
	Image mechantloup(0, 0, 888, 1070, renderer, "C:/Users/isahouli/Downloads/loup mechant.bmp");
	mechantloup.Draw(renderer);

	SDL_Delay(40);
	SDL_RenderPresent(renderer);
	SDL_Delay(40);

	*/
	/*
	//TP 3
	bool held = false;
	bool running = true;
	Circle c1(0, 0, 100, 100, 200, 600);
	c1.SetPosition(540, 470, 0.5, 0.5);
	c1.Draw(renderer);
	while (running == true)
	{

		SDL_Event event;
		while (SDL_PollEvent(&event))
			
		{
			
			int size;
			SDL_GetKeyboardState(&size);

			switch (event.type)
			{
			case SDL_KEYDOWN:

				if (event.key.keysym.sym == SDLK_ESCAPE) // sortir du programme
				
				{
					cout << "escaped.." << endl;
					running = false;
				}

				if (event.key.keysym.sym == SDLK_a) // etat a down

				{
					cout << " a down" << endl;
					c1.posX += 100;
				}
				
				if (held == true)
				{
					cout << " a held" << endl;
				}


				if (event.key.keysym.sym != SDLK_a)
				{
					cout << SDL_GetKeyName(event.key.keysym.sym) <<" down" << endl;
					held = true;
				}
				break;

			case SDL_KEYUP:

				if (event.key.keysym.sym == SDLK_a) // etat a released

				{
					cout << " a released" << endl; 
					held = false;
				}


				if (event.key.keysym.sym != SDLK_a)
				{
					cout << SDL_GetKeyName(event.key.keysym.sym)<< "  up" << endl;
				}
				break;

			case SDL_MOUSEBUTTONDOWN:

				cout << "click pressed at x : " << event.button.x << ", y : " << event.button.y << endl; // detecte clic pressé 
				break;

			case SDL_MOUSEBUTTONUP:

				cout << "click released at x : " << event.button.x << ", y : " << event.button.y << endl; // detecte clic relaché
				break;


				SDL_Delay(400);
				SDL_RenderPresent(renderer);
				SDL_Delay(400);











			}
		}
		
	}
	

// TP4

Circle c1(0, 0, 100, 100, 200, 600);
c1.SetPosition(540, 470, 0.5, 0.5);
c1.Draw(renderer);

SDL_Event event;
while (true)
{
	while (SDL_PollEvent(&event))
	{

		

		if (event.key.keysym.sym == SDLK_d )
		{
			c1.posX += 100;
		}


		SDL_Delay(400);
		SDL_RenderPresent(renderer);
		SDL_Delay(400);
	}


}




Circle c1(500, 500, 100, 100, 50, 600);
Circle c2(200, 500, 100, 100, 50, 600);

while (true)
{
	// EVENT
	InputManager::Get()->Update();


	//UPDATE
	if (InputManager::Get()->IsHeld(SDLK_z))
	{
		c1.Move(0.f, -0.05f);
	}

	if (InputManager::Get()->IsHeld(SDLK_q))
	{
		c1.posX -= 100;
	}

	// DRAW
	SDL_SetRenderDrawColor(renderer, 100, 200, 200, 255);
	SDL_RenderClear(renderer);
	c1.Draw(renderer);


	SDL_Delay(400);
	SDL_RenderPresent(renderer);


}

	return 0;
}
*/



#define WIDTH 800
#define HEIGHT 400

#define CENTER_X (WIDTH - 1) / 2
#define CENTER_Y (HEIGHT - 1) / 2

#define TARGET_FPS 60
#define TARGET_DELTA_TIME 1.f / TARGET_FPS

SDL_Renderer* renderer;

Color White = { 255, 255, 255, 255 };
Color Grey = { 127, 127, 127, 255 };
Color Black = { 0, 0, 0, 255 };
Color Red = { 255, 0, 0, 255 };
Color Orange = { 255, 127, 0, 255 };
Color Yellow = { 255, 255, 0, 255 };
Color Green = { 0, 255, 0, 255 };
Color Cyan = { 0, 255, 255, 255 };
Color Blue = { 0, 0, 255, 255 };
Color Magenta = { 255, 0, 255, 255 };

void ChooseColor(std::string s)
{
	if (s == "Red")
	{
		SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
	}

	else if (s == "Orange")
	{
		SDL_SetRenderDrawColor(renderer, 255, 127, 0, 255);
	}

	else if (s == "Yellow")
	{
		SDL_SetRenderDrawColor(renderer, 255, 255, 0, 255);
	}

	else if (s == "Green")
	{
		SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
	}

	else if (s == "Cyan")
	{
		SDL_SetRenderDrawColor(renderer, 0, 255, 255, 255);
	}

	else if (s == "Blue")
	{
		SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
	}

	else if (s == "Magenta")
	{
		SDL_SetRenderDrawColor(renderer, 255, 0, 255, 255);
	}

	else if (s == "Pink")
	{
		SDL_SetRenderDrawColor(renderer, 255, 150, 150, 255);
	}

	else if (s == "White")
	{
		SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
	}

	else if (s == "Grey")
	{
		SDL_SetRenderDrawColor(renderer, 127, 127, 127, 255);
	}

	else if (s == "Black")
	{
		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	}
}

int main(int argc, char** argv)
{
	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS) < 0)
	{
		std::cout << "Error SDL2 Initialization : " << SDL_GetError();
		return 1;
	}

	SDL_Window* window;


	window = SDL_CreateWindow("Draw", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT, SDL_WINDOW_OPENGL);
	if (window == NULL)
	{
		std::cout << "Error window creation";
		return false;
	}

	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	if (renderer == NULL)
	{
		std::cout << "Error renderer creation";
		return false;
	}

	Vector2 projectiles;

	//init
	Rectangle r1(150, 40);
	r1.SetPosition(WIDTH / 8, HEIGHT / 2);
	

	

	// creation du projectile et getpos

	Projectile p (25,10);
	p.m_color = {255, 255, 255, 255};
	p.SetPosition(-1000, -1000);
	GameManager gm;

	Circle c2(100);
	c2.SetPosition(200, HEIGHT / 2);

	int speedc1 = 300;
	int speedc2 = 50;

	float deltaTime = 0;

	while (true)
	{
		Vector2f pos = r1.GetPosition(1, 0.5);
		Uint64 start = SDL_GetTicks64();
		SDL_Event* event;
		Vector2f PosProj = p.GetPosition(1, 0.5f);
		
		
		//EVENT
		InputManager::Get()->Update();

		//UPDATE
		
	
		if (InputManager::Get()->IsHeld(SDLK_z))
		{
			//move up
			r1.Move(0.f, -speedc1 * deltaTime);
		}
		if (InputManager::Get()->IsHeld(SDLK_q))
		{
			//move left
			r1.Move(-speedc1 * deltaTime, 0.f);

		}
		if (InputManager::Get()->IsHeld(SDLK_s))
		{
			//move down
			r1.Move(0.f, speedc1 * deltaTime);
		}
		if (InputManager::Get()->IsHeld(SDLK_d))
		{
			//move right
			r1.Move(speedc1 * deltaTime, 0.f);
		}
		if (InputManager::Get()->IsDown(SDLK_SPACE))
		{
			p.SetPosition(pos.x, pos.y);
			gm.Projectile.push_back(&p);
		}

		c2.Move(0.f, -speedc2 * deltaTime);



		/*
		if (InputManager::Get()->IsHeld(SDL_MOUSEBUTTONDOWN))
		{
			//move right
			r1.Move(speedc1 * deltaTime, 0.f);
		}
		*/





		if (c2.GetPosition(0.f, 1.f).y < 0)
			c2.SetPosition(200, HEIGHT + c2.GetRadius());

		if (r1.GetPosition(0.5f, 0.f).y < 0)
		{
			r1.SetPosition(r1.GetPosition(0.5f, 0.5f).x, 0, 0.5, 0);
		}

		if (r1.GetPosition(0.5f, 1.f).y > HEIGHT)
		{
			r1.SetPosition(r1.GetPosition(0.5f, 0.5f).x, HEIGHT, 0.5, 1);
		}

		if (r1.GetPosition(0.f, 0.5f).x < 0)
		{
			r1.SetPosition(0, r1.GetPosition(0.5f, 0.5f).y, 0, 0.5);
		}

		if (r1.GetPosition(1.f, 0.5f).x > WIDTH / 4)
		{
			r1.SetPosition(WIDTH / 4, r1.GetPosition(0.5f, 0.5f).y, 1, 0.5);
		}

		//DRAW
		ChooseColor("Black");
		SDL_RenderClear(renderer);
		c2.Draw(renderer);
		r1.Draw(renderer);
		p.Draw(renderer);
	    p.Move(speedc1 * deltaTime, 0.f);
		//cout << PosProj.x << endl;
		bool isdestroyed = false;

 		if (PosProj.x >= WIDTH)
		{
			//~&p;
			
			gm.Projectile.pop_back();
			delete(&p);
			cout << "projectile detruit" << endl;
		}


		SDL_RenderPresent(renderer);
		Uint64 end = SDL_GetTicks64();

		deltaTime = (end - start) / 1000.f;
		float diff = TARGET_DELTA_TIME - deltaTime;

		//Cap FPS
		if (diff > 0)
		{
			SDL_Delay(diff * 1000);
			deltaTime = TARGET_DELTA_TIME;
		}

		cout << gm.Projectile.size() << endl;
		//Display FPS
		//std::cout << 1.f / deltaTime << std::endl;

	}

	SDL_Delay(1000);
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();

	return 0;
}
