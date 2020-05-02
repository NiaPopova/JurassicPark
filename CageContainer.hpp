#pragma once
#include "Cage.hpp"

class CageContainer
{
private:
	Cage* cage;
	unsigned size;
	unsigned capacity;

public:
	CageContainer();
	~CageContainer();
	void addCage(char* _climate, unsigned _capacity, char* _size, Dinosaur& _dino, char* _period);
	bool removeDfromCage(char* _name);
};

