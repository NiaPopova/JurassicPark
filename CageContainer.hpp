#pragma once
#include "Cage.hpp"

class CageContainer
{
private:
	unsigned size;
	unsigned capacity;
	Cage* cage;

public:
	CageContainer();
	~CageContainer();
	CageContainer(const CageContainer& other);
	CageContainer& operator= (const CageContainer& other);
	void del();
	void copy(const CageContainer& other);
	void addCage(Cage newcage);
	bool removeDfromCage(char* _name);
	bool checkCage(char* _size, char* _climate, char* period, Dinosaur _dino);
	unsigned getSize();
	void read(std::istream& file);
	void write(std::ostream& file);
	//void print();
};