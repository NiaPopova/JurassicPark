#pragma once
#include <fstream>
class Food
{
private:
	char* type;

public:
	Food();
	~Food();
	Food(char* _type);
	Food(const Food& other);
	Food& operator=(const Food& other);
	void read(std::istream& file);
	void write(std::ostream& file);
};