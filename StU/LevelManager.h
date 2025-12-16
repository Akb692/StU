#pragma once
#include <vector>
#include <iostream>
#include "Geometry.h"
// #include "obstacle.h"
//#include "ennemy.h"
class LevelManager
{

private:

	std::vector<Geometry> obstacle; // type a changer la aussi ?
	std::vector<Geometry> ennemis; // type a changer
	char boss; // changer par la classe

public:

	bool LoadLevel(const std::string filename);
	void ClearLevel();
};

