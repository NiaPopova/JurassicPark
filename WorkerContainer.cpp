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

void WorkerContainer::read(std::istream& file)
{
	file.read((char*)&size, sizeof(size));

	file.read((char*)&capacity, sizeof(capacity));
}

void WorkerContainer::write(std::ostream& file)
{
	file.write((const char*)&size, sizeof(size));

	file.write((const char*)&capacity, sizeof(capacity));
}