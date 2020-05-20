#include "Food.hpp"
#include <cstring>

Food::Food()
{
	type = new char[5];
	strcpy(type, "meat");
}

Food::~Food()
{
	delete[] type;
}

Food::Food(char* _type)
{
	type = new char[strlen(_type) + 1];
	strcpy(type, _type);
}

Food::Food(const Food& other)
{
	type = new char[strlen(other.type) + 1];
	strcpy(type, other.type);
}

Food& Food::operator=(const Food& other)
{
	if (this != &other)
	{
		delete[] type;
		type = new char[strlen(other.type) + 1];
		strcpy(type, other.type);
	}
	return *this;
}