#include "Zoo.h"
#include <iostream>

Zoo::Zoo(){}

Zoo::~Zoo(){}

void Zoo::AddAnimal() {
	int option;

	// Recoger tipo de animal
	do {
		std::cout << "Que tipo de animal quieres crear?" << std::endl;
		std::cout << "\t1.Mamifero\n\t2.Reptil\n\t3.Ave\n\t4.Canino\n\t5.Acuatico" << std::endl;
		std::cin >> option;
	} while (option > 6 || option <= 0);

	// Declaracion de variables de Animal
	std::string name, species, buffer;
	int age, iBuffer;
	Animal::SEX sex;
	Animal::DIET diet;
	// Introducir nombre
	std::cout << "Nombre: " << std::endl;
	std::cin >> name;
	// Introducir especie
	std::cout << "Especie: " << std::endl;
	std::cin >> species;
	// Introducir edad
	std::cout << "Edad: " << std::endl;
	std::cin >> buffer;
	try {
		age = std::stoi(buffer);
	}
	catch (std::invalid_argument) {
		std::cout << "ERROR: Edad incorrecta, estableciendo a 0." << std::endl;
		age = 0;
	}

	std::cout << "Sexo: " << std::endl;
	std::cout << "\t1.Macho\n\t2.Hembra\n\t3.Hermafrodita\n\t4.Ninguno" << std::endl;
	std::cin >> buffer;

	try {
		iBuffer = std::stoi(buffer);
	}
	catch (std::invalid_argument) {
		std::cout << "ERROR: Sexo fuera de rango, estableciendo a ninguno." << std::endl;
		iBuffer = 4;
	}

	switch (iBuffer) {
	case 1: // Macho
		sex = Animal::MALE;
		break;
	case 2: // Hembra
		sex = Animal::FEMALE;
		break;
	case 3: // Herm.
		sex = Animal::HERMAPHRODITE;
		break;
	case 4: // None
		sex = Animal::NONE;
		break;
	default:
		std::cout << "ERROR: Opcion fuera de rango, estableciendo a ninguno." << std::endl;
		sex = Animal::NONE;
		break;
	}

	std::cout << "Dieta: " << std::endl;
	std::cout << "\t1.Carnivoro\n\t2.Herviboro\n\t3.Omnivoro" << std::endl;
	std::cin >> buffer;
	try {
		iBuffer = std::stoi(buffer);
	}
	catch (std::invalid_argument) {
		std::cout << "ERROR: Dieta incorrecta, estableciendo a omnivora." << std::endl;
		iBuffer = 3;
	}

	switch (iBuffer) {
	case 1: // Carnivoro
		diet = Animal::CARNIVORE;
		break;
	case 2: // Herviboro
		diet = Animal::HERBIVORE;
		break;
	case 3: // Omnivoro
		diet = Animal::OMNIVORE;
		break;
	default: // JIC: To evade errors
		std::cout << "ERROR: Opcion fuera de rango, estableciendo a omnivoro." << std::endl;
		diet = Animal::OMNIVORE;
		break;
	}

	// Recogida de datos específicos de cada clase
	switch (option)	{
		case 1: // Mamifero
			break;
		case 2: // Reptil
			break;
		case 3: // Ave
			break;
		case 4: // Canino
			break;
		case 5: // Acuatico
			break;

		default:
			break;
	}

}

void Zoo::RemoveAnimal(Animal& a) {
	for (auto it = animals.begin(); it != animals.end(); it++) {
		if ((*it) == &a) {
			animals.erase(it);
		}
	}
}

