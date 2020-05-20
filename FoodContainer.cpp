#include "FoodContainer.hpp"

FoodContainer::FoodContainer()
{
	size = 1;
	capacity = 20;
	food = new Food[capacity];
}

FoodContainer::~FoodContainer()
{
	delete[] food;
}

FoodContainer::FoodContainer(const FoodContainer& other)
{
	size = other.size;
	capacity = other.capacity;
	food = new Food[other.capacity];
}

FoodContainer& FoodContainer::operator=(const FoodContainer& other)
{
	if (this != &other)
	{
		delete[] food;
		size = other.size;
		capacity = other.capacity;
		food = new Food[other.capacity];
	}
	return *this;
}

void FoodContainer::addFood(Food newfood, unsigned _amount)
{
	if (size == capacity)
	{
		capacity *= 2;
		Food* newcontainer = new Food[capacity];

		for (unsigned i = 0; i < size; ++i)
		{
			newcontainer[i] = food[i];
		}

		delete[] food;
		food = newcontainer;
		food[size++] = newfood;
	}
}