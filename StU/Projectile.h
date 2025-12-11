#pragma once
#include "Rectangle.h"
#include "Circle.h"

class Projectile : public Rectangle
{
private:

	int Damage;
	float Speed;
	Vector2f Direction;

public:
	Projectile(int width, int height);

	//~Projectile();
};