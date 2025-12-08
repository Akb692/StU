#include "Geometry.h"
#include <iostream>
using namespace std;
Geometry::Geometry(int x, int y, int w, int h)
	: posX(x), posY(y), width(w), height(h) {

	Color color = { 255,255,255, 0 };

}

void Geometry::Draw(SDL_Renderer* renderer)
{


}



void Geometry::SetPosition(int x, int y, float anchorX, float anchorY)
{

	if(anchorX > 1 || anchorX < 0 || anchorY > 1 || anchorY < 0 )
	{
		cout << "anchor point error";
		return;
	}

	float offsetX = (float)width * anchorX;
	float offsetY = (float)height * anchorY;

	int newposX = x - offsetX;
	int newposY = y - offsetY;

	this->posX = newposX;
	this->posY = newposY;
}

Vector2 Geometry::GetPosition(float anchorX, float anchorY)
{

	float offsetX = (float)width * anchorX;
	float offsetY = (float)height * anchorY;

	float newposX = posX + offsetX;
	float newposY = posY + offsetY;

	Vector2 vector{ newposX, newposY };

	return vector;
}


void Geometry::Move(float x, float y)
{
	posX += x, posY += y;
}