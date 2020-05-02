#include "FoodContainer.h"

FoodContainer::FoodContainer()
{
	size = 5;
	capacity = 10;
	food = new Food[capacity];
}
