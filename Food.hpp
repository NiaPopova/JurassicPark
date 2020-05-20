#pragma once
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
};