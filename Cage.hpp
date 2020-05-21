#pragma once
#include <iostream>
#include <cstring>
#include "Dinosaur.hpp"

class Cage
{
private:
	char* size;
	unsigned amount;
	unsigned capacity;
	char* climate;
	char* period;
	Dinosaur* animal;

public:
	Cage();
	~Cage();
	Cage(const Cage& other);
	Cage& operator= (const Cage& other);
	Cage(char* _size, char* _climate, char* _period);
	void del();
	void copy(const Cage& other);
	void addDino(Dinosaur _dino);
	void setClimate(char* _climate);
	char* getClimate();
	bool removeDino(char* _name);
	void setSize(char* _size);
	char* getSize();
	void setAmount(unsigned _amount);
	void setPeriod(char* _period);
	char* getPeriod();
	unsigned getAmount();
	unsigned getCapacity();
};