#include "Cage.hpp"

Cage::Cage()
{
	size = new char[6];
	strcpy(size, "small");

	amount = 0;
	capacity = 1;

	climate = new char[4];
	strcpy(climate, "air");

	period = new char[5];
	strcpy(period, "jura");

	animal = new Dinosaur[amount];
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

	if (strcmp(size, "small") == 0)
	{
		capacity = 1;
	}
	else if (strcmp(size, "medium") == 0)
	{
		capacity = 3;
	}
	else
	{
		capacity = 10;
	}

	amount = 0;

	animal = new Dinosaur[capacity];
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

	amount = other.amount;
	capacity = other.capacity;

	animal = new Dinosaur[other.capacity];
	for (unsigned i = 0; i < other.amount; ++i)
	{
		animal[i] = other.animal[i];
	}
}

void Cage::addDino(Dinosaur _dino)
{
	if (amount < capacity)
	{
		animal[amount++] = _dino;
	}
	else
	{
		std::cout << "NO SPACE HUMAN!";
	}
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

void Cage::read(std::istream& file)
{
	int temp;
	file.read((char*)&temp, sizeof(int));
	file.read((char*)size, temp);

	file.read((char*)&amount, sizeof(amount));

	file.read((char*)&capacity, sizeof(capacity));

	file.read((char*)&temp, sizeof(int));
	file.read((char*)climate, temp);

	file.read((char*)&temp, sizeof(int));
	file.read((char*)period, temp);

	for (unsigned i = 0; i < amount; ++i)
	{
		animal[i].read(file);
	}
}

void Cage::write(std::ostream& file)
{
	int temp = strlen(size);
	file.write((const char*)&temp, sizeof(int));
	file.write((const char*)size, temp);

	file.write((const char*)&amount, sizeof(amount));

	file.write((const char*)&capacity, sizeof(capacity));

	temp = strlen(climate);
	file.write((const char*)&temp, sizeof(int));
	file.write((const char*)climate, temp);

	temp = strlen(period);
	file.write((const char*)&temp, sizeof(int));
	file.write((const char*)period, temp);

	for (unsigned i = 0; i < amount; ++i)
	{
		animal[i].write(file);
	}
}