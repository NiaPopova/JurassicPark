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

CageContainer::CageContainer(const CageContainer& other)
{
	copy(other);
}


CageContainer& CageContainer::operator=(const CageContainer& other)
{
	if (this != &other)
	{
		del();
		copy(other);
	}
	return *this;
}

void CageContainer::del()
{
	delete[] cage;
}

void CageContainer::copy(const CageContainer& other)
{
	cage = new Cage[other.capacity];
	size = other.size;
	capacity = other.capacity;
}

void CageContainer::addCage(Cage newcage)
{
	if (size == capacity)
	{
		capacity *= 2;
		Cage* newcontainer = new Cage[capacity];

		for (unsigned i = 0; i < size; ++i)
		{
			newcontainer[i] = cage[i];
		}

		delete[] cage;
		cage = newcontainer;
		cage[size++] = newcage;
	}
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

bool CageContainer::checkCage(char* _size, char* _climate, char* period, Dinosaur _dino)
{
	for (unsigned i = 0; i < capacity; ++i)
	{
		if (strcmp(cage[i].getSize(), _size) == 0)
		{
			if (strcmp(cage[i].getClimate(), _climate) == 0)
			{
				if (strcmp(cage[i].getPeriod(), period) == 0)
				{
					if (cage[i].getAmount() < cage[i].getCapacity())
					{
						cage->addDino(_dino);
						return true;
					}
				}
			}
		}
	}
	return false;
}

unsigned CageContainer::getSize()
{
	return size;
}