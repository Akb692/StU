#pragma once
#include "Geometry.h"

class Entity : public Geometry
{
protected:


public:
    int HP = 1;

    Entity(int w, int h, int hp);

    void Draw(SDL_Renderer* renderer);

};