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

Dinosaur::Dinosaur(const Dinosaur& other)
{
	copy(other);
}

Dinosaur& Dinosaur::operator=(const Dinosaur& other)
{
	if (this != &other)
	{
		del();
		copy(other);
	}
	return *this;
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

void Dinosaur::del()
{
	delete[] name;
	delete[] gender;
	delete[] period;
	delete[] order;
	delete[] species;
	delete[] food;
}

void Dinosaur::copy(const Dinosaur& other)
{
	name = new char[strlen(other.name) + 1];
	strcpy(name, other.name);

	gender = new char[strlen(other.gender) + 1];
	strcpy(gender, other.gender);

	period = new char[strlen(other.period) + 1];
	strcpy(period, other.period);

	order = new char[strlen(other.order) + 1];
	strcpy(order, other.order);

	species = new char[strlen(other.species) + 1];
	strcpy(species, other.species);

	food = new char[strlen(other.food) + 1];
	strcpy(food, other.food);
}

char* Dinosaur::getOrder()
{
	return order;
}

char* Dinosaur::getName()
{
	return name;
}

void Dinosaur::read(std::istream& file)
{
	int temp;
	file.read((char*)&temp, sizeof(int));
	file.read((char*)name, temp);

	file.read((char*)&temp, sizeof(int));
	file.read((char*)gender, temp);

	//file.read((char*)&id, sizeof(int));
}

void Dinosaur::write(std::ostream& file)
{
	int temp = strlen(name);
	file.write((const char*)&temp, sizeof(int));
	file.write((const char*)name, strlen(name));

	temp = strlen(gender);
	file.write((const char*)&temp, sizeof(int));
	file.write((const char*)gender, strlen(gender));



	file.write((const char*)period, strlen(period));


	//file.write((const char*)&id, sizeof(id);
}
