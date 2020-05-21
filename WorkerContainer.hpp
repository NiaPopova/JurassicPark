#pragma once
#include "CageContainer.hpp"

class WorkerContainer
{
private:
	unsigned size;
	unsigned capacity;

public:
	WorkerContainer();
	WorkerContainer(const WorkerContainer& other);
	WorkerContainer& operator=(const WorkerContainer& other);
	void addWorker(CageContainer container);
	void read(std::istream& file);
	void write(std::ostream& file);
};