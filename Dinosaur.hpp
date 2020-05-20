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
	Dinosaur(const Dinosaur& other);
	Dinosaur& operator= (const Dinosaur& other);
	Dinosaur(char* _name, char* _gender, char* _perod, char* _order, char* _species, char* _food);
	void del();
	void copy(const Dinosaur& other);
	char* getOrder();
	char* getName();
};