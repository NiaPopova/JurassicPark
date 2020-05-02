#pragma once
#include<cstring>

class Dinosaur
{
private:
	char* name;
	char* gender;
	char* period;
	char* order;
	char* species;
	char* food;

public:
	Dinosaur();
	~Dinosaur();
	Dinosaur(char* _name, char* _gender, char* _perod, char* _order, char* _species, char* _food);
	char* getOrder();
	char* getName();
};

