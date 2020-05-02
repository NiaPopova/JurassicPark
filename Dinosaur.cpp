#include "Dinosaur.hpp"

Dinosaur::Dinosaur()
{
	name = new char[5];
	strcpy(name, "Dino");
	gender = new char[5];
	strcpy(gender, "male");
	period = new char[5];
	strcpy(period, "jura");
	order = new char[11];
	strcpy(order, "flying");
	species = new char[12];
	strcpy(species, "pterodactyl");
	food = new char[5];
	strcpy(food, "meat");
}

Dinosaur::~Dinosaur()
{
	delete[] name;
	delete[] gender;
	delete[] period;
	delete[] order;
	delete[] species;
	delete[] food;
}

Dinosaur::Dinosaur(char* _name, char* _gender, char* _period, char* _order, char* _species, char* _food)
{
	name = new char[strlen(_name) + 1];
	strcpy(name, _name);
	gender = new char[strlen(_gender) + 1];
	strcpy(gender, _gender);
	period = new char[strlen(_period) + 1];
	strcpy(period, _period);
	order = new char[strlen(_order) + 1];
	strcpy(order, _order);
	species = new char[strlen(_species) + 1];
	strcpy(species, _species);
	food = new char[strlen(_food) + 1];
	strcpy(food, _food);
}

char* Dinosaur::getOrder()
{
	return order;
}

char* Dinosaur::getName()
{
	return name;
}
