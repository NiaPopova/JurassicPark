#include "CageContainer.hpp"

CageContainer::CageContainer()
{
	size = 1;
	capacity = 20;
	cage = new Cage[capacity];
}

CageContainer::~CageContainer()
{
	delete[] cage;
}


void CageContainer::addCage(char* _climate, unsigned _capacity, char* _size, Dinosaur& _dino,char* _period)
{
	if (size == capacity)
	{
		capacity *= 2;
	}
	cage = new Cage[_capacity];
	cage->setSize(_size);
	cage->setAmount(1);
	cage->setClimate(_climate);
	cage->setPeriod(_period);
	size++;
}

bool CageContainer::removeDfromCage(char* _name)
{
	for (unsigned i = 0; i < size; ++i)
	{
		if (cage[i].removeDino(_name) == true)
		{
			return true;
		}
	}
	return false;
}
