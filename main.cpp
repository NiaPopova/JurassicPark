#include <iostream>
#include <fstream>
#include "Dinosaur.hpp"
#include "Cage.hpp"
#include "CageContainer.hpp"
#include "Food.hpp"
#include "FoodContainer.hpp"
#include "WorkerContainer.hpp"

void read(char* command, CageContainer& container, FoodContainer& _container, WorkerContainer& _container_)
{
	char name[20];
	char gender[7];
	char period[6];
	char order[12];
	char species[25];
	char food[6];
	char climate[6];
	char size[7];
	char answer;

	if (strcmp(command, "add_dino") == 0)
	{
		std::cout << "Enter the name of the new dinosaur: ";
		std::cin >> name;

		std::cout << "Enter the gender of the new dinosaur [male/female]: ";
		std::cin >> gender;

		while (strcmp(gender, "male") != 0 && strcmp(gender, "female") != 0)
		{
			std::cout << "You've entered wrong gender. Try again: ";
			std::cin >> gender;
		}

		std::cout << "Enter from which period is the new dinosaur [trias/creda/jura]: ";
		std::cin >> period;

		while (strcmp(period, "trias") != 0 && strcmp(period, "creda") && strcmp(period, "jura") != 0)
		{
			std::cout << "You've entered wrong period. Try again: ";
			std::cin >> period;
		}

		std::cout << "Enter the order of the new dinosaur [herbivorous/carnivorous/flying/aquatic]: ";
		std::cin >> order;

		while (strcmp(order, "herbivorous") != 0 && strcmp(order, "carnivorous") && strcmp(order, "flying") != 0 && strcmp(order, "aquatic") != 0)
		{
			std::cout << "You've entered wrong order. Try again: ";
			std::cin >> order;
		}

		if (strcmp(order, "herbivorous") == 0)
		{
			strcpy(food, "grass");
			strcpy(climate, "land");
		}
		else if (strcmp(order, "carnivorous") == 0)
		{
			strcpy(food, "meat");
			strcpy(climate, "land");
		}
		else if (strcmp(order, "flying") == 0)
		{
			std::cout << "What kind of food does the dinosaur eat [grass/meat/fish]: ";
			std::cin >> food;

			while (strcmp(food, "grass") != 0 && strcmp(food, "meat") != 0 && strcmp(food, "fish") != 0)
			{
				std::cout << "You've entered wrong food. Try again: ";
				std::cin >> food;
			}

			strcpy(climate, "air");
		}
		else
		{
			strcpy(food, "fish");
			strcpy(climate, "water");
		}

		std::cout << "Enter the species of the new dinosaur: ";
		std::cin >> species;

		Dinosaur dino(name, gender, period, order, species, food);

		std::cout << "In cage with what size would you like to add the new dinosaur [s/m/l]: ";
		std::cin >> answer;

		while (answer != 's' && answer != 'm' && answer != 'l')
		{
			std::cout << "You've entered wrong answer. enter <s> for small, <m> for medium or <l> for large: ";
			std::cin >> answer;
		}

		if (answer == 's')
		{
			strcpy(size, "small");
		}
		else if (answer == 'm')
		{
			strcpy(size, "medium");
		}
		else if (answer == 'l')
		{
			strcpy(size, "large");
		}

		if (container.checkCage(size, climate, period, dino) == true)
		{
			std::cout << "The new dinosaur was added successfully." << std::endl;
		}
		else
		{
			std::cout << "There are no free cages. We couldn't add the new dinosaur. Enter <build_cage> to create one. " << std::endl;
		}
	}
	else if (strcmp(command, "build_cage") == 0)
	{
		std::cout << "How big do you want the new cage to be [s/m/l]: ";
		std::cin >> answer;

		while (answer != 's' && answer != 'm' && answer != 'l')
		{
			std::cout << "You've entered wrong answer. enter <s> for small, <m> for medium or <l> for large: ";
			std::cin >> answer;
		}

		if (answer == 's')
		{
			strcpy(size, "small");
		}
		else if (answer == 'm')
		{
			strcpy(size, "medium");
		}
		else if (answer == 'l')
		{
			strcpy(size, "large");
		}

		std::cout << "Enter the climate of the cage [land/air/water]: ";
		std::cin >> climate;

		while (strcmp(climate, "land") != 0 && strcmp(climate, "air") && strcmp(climate, "water") != 0)
		{
			std::cout << "You've entered wrong climate. Try again: ";
			std::cin >> climate;
		}

		std::cout << "Enter period of the cage [trias/creda/jura]: ";
		std::cin >> period;

		while (strcmp(period, "trias") != 0 && strcmp(period, "creda") && strcmp(period, "jura") != 0)
		{
			std::cout << "You've entered wrong period. Try again: ";
			std::cin >> period;
		}

		Cage newCage(size, climate, period);
		container.addCage(newCage);
		_container_.addWorker(container);
	}
	else if (strcmp(command, "remove_dino") == 0)
	{
		std::cout << "Enter the name of the dinosaur you want to remove: ";
		std::cin >> name;

		if (container.removeDfromCage(name) == true)
		{
			std::cout << "The dinosaur was removed" << std::endl;
		}
		else
		{
			std::cout << "There is no such dinosaur." << std::endl;
		}
	}
	else if (strcmp(command, "load_food") == 0)
	{
		unsigned amount;

		std::cout << "What type of food do you want to add [grass/meat/fish]: ";
		std::cin >> food;

		while (strcmp(food, "grass") != 0 && strcmp(food, "meat") != 0 && strcmp(food, "fish") != 0)
		{
			std::cout << "You've entered wrong food. Try again: ";
			std::cin >> food;
		}

		std::cout << "Enter the amount of food you want to add: ";
		std::cin >> amount;

		while (amount < 0)
		{
			std::cout << "The amount must be a positive number: ";
			std::cin >> amount;
		}
		Food food(food);
		Food* foods = new Food[amount];
		for (int i = 0; i < amount; ++i)
		{
			foods[i] = food;
		}
		_container.addFood(foods,amount);
	}
	else if (strcmp(command, "exit") == 0)
	{
		//TODO запазване на информацията във файл
		std::ofstream file;
		file.open("Zoo", std::ios::in | std::ios::binary);
		std::cout << "The program is closed" << std::endl;
	}
	else
	{
	std::cout << "You've entered wrong command!"<<std::endl;
	}
}

int main()
{
	char command[20];
	CageContainer container;
	FoodContainer _container;
	WorkerContainer _container_;

	std::cout << "Welcome to Jurasic Park!" << std::endl;
	std::cout << "The program can control the park with the following commands:" << std::endl;
	std::cout << "<add_dino> - adding a new dinosaur" << std::endl;
	std::cout << "<build_cage> - creating a new cage" << std::endl;
	std::cout << "<remove_dino> - removing an existing dinosaur from the park" << std::endl;
	std::cout << "<load_food> - adding food" << std::endl;
	std::cout << "<exit> - exit the program" << std::endl;

	do
	{
		std::cout << "Enter a command: ";
		std::cin >> command;

		read(command, container, _container, _container_);
	} while (strcmp(command, "exit") != 0);

	return 0;
}