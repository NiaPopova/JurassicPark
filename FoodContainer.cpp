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

	for (unsigned i = 0; i < other.size; ++i)
	{
		food[i] = other.food[i];
	}
}

FoodContainer& FoodContainer::operator=(const FoodContainer& other)
{
	if (this != &other)
	{
		delete[] food;
		
		size = other.size;
		capacity = other.capacity;
		food = new Food[other.capacity];
	
		for (unsigned i = 0; i < other.size; ++i)
		{
			food[i] = other.food[i];
		}
	}
	return *this;
}

void FoodContainer::addFood(Food* newfood, unsigned amount)
{
	if ((size + amount) >= capacity)
	{
		capacity += amount;
		capacity *= 2;
		
		Food* newcontainer = new Food[capacity];

		for (unsigned i = 0; i < size; ++i)
		{
			newcontainer[i] = food[i];
		}

		delete[] food;
		
		food = newcontainer;
	}
	for (unsigned i = 0; i < amount; ++i)
	{
		food[size++] = newfood[i];
	}
}

void FoodContainer::read(std::istream& file)
{
	file.read((char*)&size, sizeof(size));

	file.read((char*)&capacity, sizeof(capacity));

	for (unsigned i = 0; i < size; ++i)
	{
		food[i].read(file);
	}
}

void FoodContainer::write(std::ostream& file)
{
	file.write((const char*)&size, sizeof(size));

	file.write((const char*)&capacity, sizeof(capacity));

	for (unsigned i = 0; i < size; ++i)
	{
		food[i].write(file);
	}
}