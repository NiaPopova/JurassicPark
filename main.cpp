#include <iostream>
#include "Dinosaur.hpp"
#include "Cage.hpp"
#include "CageContainer.hpp"

void read(char* command, CageContainer& container)
{
	char name[20];
	char gender[7];
	char period[6];
	char order[12];
	char species[25];
	char food[6];
	char climate[6];
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

		std::cout << "Do you want to put the dinosour in new cage? [y/n]: ";
		std::cin >> answer;

		while (answer != 'y' && answer != 'n')
		{
			std::cout << "You've entered wrong answer. Enter <y> for yes or <n> for no: ";
			std::cin >> answer;
		}

		if (answer == 'y')
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
				char size[6] = "small";
				container.addCage(climate, 1, size, dino, period);
				std::cout << "The new dinosaur was added in the park." << std::endl;
			}
			else if (answer == 'm')
			{
				char size[7] = "medium";
				container.addCage(climate, 3, size, dino, period);
				std::cout << "The new dinosaur was added in the park." << std::endl;
			}
			else if (answer == 'l')
			{
				char size[6] = "large";
				container.addCage(climate, 10, size, dino, period);
				std::cout << "The new dinosaur was added in the park." << std::endl;
			}
		}
		else if (answer == 'n')
		{
			//TODO проверка на клетка
			//TODO ако няма такава, да се създаде

			std::cout << "In cage with what size would you like to add the new dinosaur [s/m/l]: ";
			std::cin >> answer;

			while (answer != 's' && answer != 'm' && answer != 'l')
			{
				std::cout << "You've entered wrong answer. enter <s> for small, <m> for medium or <l> for large: ";
				std::cin >> answer;
			}
			if (answer == 's')
			{
				std::cout << "The new dinosaur was added in the park." << std::endl;
			}
			else if (answer == 'm')
			{

				std::cout << "The new dinosaur was added in the park." << std::endl;
			}
			else if (answer == 'l')
			{

				std::cout << "The new dinosaur was added in the park." << std::endl;
			}
		}

	}
	else if (strcmp(command, "build_cage") == 0)
	{

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
		//addfood;
	}
	else if (strcmp(command, "exit") == 0)
	{
		//TODO запазване на информацията във файл
		std::cout << "The program is closed" << std::endl;
	}
}

int main()
{
	char command[20];
	CageContainer container;

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

		read(command, container);
	} while (strcmp(command, "exit") != 0);

	return 0;
}