#include "Cage.hpp"

Cage::Cage()
{
	size = new char[6];
	strcpy(size, "small");
	amount = 1;
	capacity = 1;
	climate = new char[4];
	animal = new Dinosaur[1];
	strcpy(climate, "air");
	period = new char[5];
	strcpy(period, "jura");
}

Cage::~Cage()
{
	delete[] size;
	delete[] climate;
	delete[] animal;
	delete[] period;
}

/*void Cage::addDino(Dinosaur& _dino)
{
	
}*/

void Cage::setClimate(char* _climate)
{
	climate = new char[strlen(_climate) + 1];
	strcpy(climate, _climate);
}

char* Cage::getClimate()
{
	return climate;
}

//char* Cage::getDino()
//{
//	for (unsigned i = 0; i < amount; ++i)
//	{
//		return (animal[i].getName());
//	}
//}

bool Cage::removeDino(char* _name)
{
	for (unsigned i = 0; i < amount; ++i)
	{
		if (strcmp(animal[i].getName(),_name)==0)
		{
			std::swap(animal[0], animal[i]);
			amount--;
			return true;
		}
	}
	return false;
}

void Cage::setSize(char* _size)
{
	size = new char[strlen(_size) + 1];
	strcpy(size, _size);
}

void Cage::setAmount(unsigned _amount)
{
	amount=_amount;
}

void Cage::setPeriod(char* _period)
{
	period = new char[strlen(_period) + 1];
	strcpy(period, _period);
}
