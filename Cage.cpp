#include "Cage.hpp"

Cage::Cage()
{
	size = new char[6];
	strcpy(size, "small");
	amount = 0;
	capacity = 1;
	climate = new char[4];
	animal = new Dinosaur[amount];
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

Cage::Cage(const Cage& other)
{
	copy(other);
}

Cage& Cage::operator=(const Cage& other)
{
	if (this != &other)
	{
		del();
		copy(other);
	}
	return *this;
}

Cage::Cage(char* _size, char* _climate, char* _period)
{
	size = new char[strlen(_size) + 1];
	strcpy(size, _size);
	climate = new char[strlen(_climate) + 1];
	strcpy(climate, _climate);
	period = new char[strlen(_period) + 1];
	strcpy(period, _period);
	if (size == "small")
	{
		capacity = 1;
	}
	else if (size == "medium")
	{
		capacity = 3;
	}
	else
	{
		capacity = 10;
	}
	amount = 0;
	delete[] animal;//
}

void Cage::del()
{
	delete[] size;
	delete[] climate;
	delete[] animal;
	delete[] period;
}

void Cage::copy(const Cage& other)
{
	size = new char[strlen(other.size) + 1];
	strcpy(size, other.size);

	climate = new char[strlen(other.climate) + 1];
	strcpy(climate, other.climate);

	period = new char[strlen(other.period) + 1];
	strcpy(period, other.period);

	animal = new Dinosaur[other.capacity];

	amount = other.amount;
	capacity = other.capacity;
}

void Cage::addDino(Dinosaur _dino)
{
	animal[amount++] = _dino;
}

void Cage::setClimate(char* _climate)
{
	climate = new char[strlen(_climate) + 1];
	strcpy(climate, _climate);
}

char* Cage::getClimate()
{
	return climate;
}

bool Cage::removeDino(char* _name)
{
	for (unsigned i = 0; i < amount; ++i)
	{
		if (strcmp(animal[i].getName(), _name) == 0)
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

char* Cage::getSize()
{
	return size;
}

void Cage::setAmount(unsigned _amount)
{
	amount = _amount;
}

void Cage::setPeriod(char* _period)
{
	period = new char[strlen(_period) + 1];
	strcpy(period, _period);
}

char* Cage::getPeriod()
{
	return period;
}

unsigned Cage::getAmount()
{
	return amount;
}

unsigned Cage::getCapacity()
{
	return capacity;
}