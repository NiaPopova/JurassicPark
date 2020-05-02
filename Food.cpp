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
