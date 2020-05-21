#pragma once
#include"Food.hpp"

class FoodContainer
{
private:
	unsigned size;
	unsigned capacity;
	Food* food;

public:
	FoodContainer();
	~FoodContainer();
	FoodContainer(const FoodContainer& other);
	FoodContainer& operator=(const FoodContainer& other);
	void addFood(Food* newfood,unsigned amount);
};