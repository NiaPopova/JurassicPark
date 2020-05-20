#include "WorkerContainer.hpp"

WorkerContainer::WorkerContainer()
{
	size = 1;
	capacity = 20;
}

WorkerContainer::WorkerContainer(const WorkerContainer& other)
{
	size = other.size;
	capacity = other.capacity;
}

WorkerContainer& WorkerContainer::operator=(const WorkerContainer& other)
{
	if (this != &other)
	{
		size = other.size;
		capacity = other.capacity;
	}
	return *this;
}

void WorkerContainer::addWorker(CageContainer container)
{
	if (size = capacity)
	{
		capacity *= 2;
	}
	if (size < container.getSize())
	{
		size = container.getSize();
	}
}