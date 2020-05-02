#pragma once
#include <iostream>
#include <cstring>
#include "Dinosaur.hpp"

class Cage
{
private:
	char* size;
	unsigned amount;
	unsigned capacity;
	char* climate;
	Dinosaur* animal;
	char* period;

public:
	Cage();
	~Cage();
	//void addDino(Dinosaur& _dino);
	void setClimate(char* _climate);
	char* getClimate();
	//char* getDino();
	bool removeDino(char* _name);
	void setSize(char* _size);
	void setAmount(unsigned _amount);
	void setPeriod(char* _period);
};

