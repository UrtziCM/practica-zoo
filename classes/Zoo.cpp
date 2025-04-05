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
	switch (option) {
		case 1 : { // Mamifero
			int legCount, daysToGest;
			Mammal::FUR furType;
			// Introducir cantidad de patas
			std::cout << "Cantidad de patas: " << std::endl;
			std::cin >> buffer;
			try {
				legCount = std::stoi(buffer);
			}
			catch (std::invalid_argument) {
				std::cout << "ERROR: Mal formato para patas, estableciendo a 0." << std::endl;
				legCount = 0;
			}

			// Introducir dias de gestacion
			std::cout << "Dias de gestacion: " << std::endl;
			std::cin >> buffer;
			try {
				daysToGest = std::stoi(buffer);
			}
			catch (std::invalid_argument) {
				std::cout << "ERROR: Mal formato en días de gest., estableciendo a 0." << std::endl;
				daysToGest = 0;
			}

			std::cout << "Pelaje: " << std::endl;
			std::cout << "\t1.Definitivo\n\t2.Vibrissae\n\t3.Peludo\n\t4.Espinas\t\n5.Cerdas\t\n6.Vello\t\n7.Lanudo" << std::endl;
			std::cin >> buffer;

			try {
				iBuffer = std::stoi(buffer);
			}
			catch (std::invalid_argument) {
				std::cout << "ERROR: Mal formato para Pelaje, estableciendo a definitivo." << std::endl;
				iBuffer = 1;
			}
			// Tipos de pelitos
			switch (iBuffer) {
			case 1: 
				furType = Mammal::DEFINITIVE;
				break;
			case 2: 
				furType = Mammal::VIBRISSAE;
				break;
			case 3: 
				furType = Mammal::PELAGE;
				break;
			case 4: 
				furType = Mammal::SPINES;
				break;
			case 5: 
				furType = Mammal::BRISTLES;
				break;
			case 6: 
				furType = Mammal::VELLI;
				break;
			case 7: 
				furType = Mammal::WOOL;
				break;

			default: // JIC: To evade errors
				std::cout << "ERROR: Opcion fuera de rango, estableciendo a definitivo." << std::endl;
				furType = Mammal::DEFINITIVE;
				break;
			}

			Mammal* m = new Mammal(name, species, age, sex, diet, legCount, daysToGest, furType);
			animals.push_back(m);
			break;
		}
		case 2: { // Reptil //
			Reptile::BODY_TEMPERATURE body_temperature;
			Reptile::SKIN skin;

			std::cout << "Temperatura corporal: " << std::endl;
			std::cout << "\t1.Poiquilotermia\n\t2.Ectotermia\n\t3.Optima\n\t4.Critica\t\n5.Heterotermia regional" << std::endl;
			std::cin >> buffer;

			try {
				iBuffer = std::stoi(buffer);
			}
			catch (std::invalid_argument) {
				std::cout << "ERROR: Mal formato para temperatura, estableciendo a optima." << std::endl;
				iBuffer = 1;
			}
			// Temperaturas
			switch (iBuffer) {
			case 1:
				body_temperature = Reptile::POIKILOTHERMY;
				break;
			case 2:
				body_temperature = Reptile::ECTOTHERMY;
				break;
			case 3:
				body_temperature = Reptile::OPTIMAL;
				break;
			case 4:
				body_temperature = Reptile::CRITICAL;
				break;
			case 5:
				body_temperature = Reptile::REGIONAL_HETEROTHERMY;
				break;
			default: // JIC: To evade errors
				std::cout << "ERROR: Opcion fuera de rango, estableciendo a optima." << std::endl;
				body_temperature = Reptile::OPTIMAL;
				break;
			}

			std::cout << "Piel: " << std::endl;
			std::cout << "\t1.Escamas queratinizadas\n\t2.Osteaodermica\n\t3.Cuerudo\n\t4.Glandular\t\n5.Muda" << std::endl;
			std::cin >> buffer;

			try {
				iBuffer = std::stoi(buffer);
			}
			catch (std::invalid_argument) {
				std::cout << "ERROR: Mal formato para piel, estableciendo a muda." << std::endl;
				iBuffer = 5;
			}
			// Tipos de pieles
			switch (iBuffer) {
			case 1:
				skin = Reptile::KERATINIZED_SCALY;
				break;
			case 2:
				skin = Reptile::OSTEODERMIC;
				break;
			case 3:
				skin = Reptile::LEATHERY;
				break;
			case 4:
				skin = Reptile::GLANDULAR;
				break;
			case 5:
				skin = Reptile::SHEDDING;
				break;

			default: // JIC: To evade errors
				std::cout << "ERROR: Opcion fuera de rango, estableciendo a muda." << std::endl;
				skin = Reptile::SHEDDING;
				break;
			}

			Reptile* r = new Reptile(name, species, age, sex, diet, body_temperature, skin);
			break;
		}


		case 3: { // Ave

			break;
		}
		case 4: { // Canino

			break;
		}
		case 5: { // Squamata

			break;
		}
	}

}

void Zoo::RemoveAnimal(Animal& a) {
	for (auto it = animals.begin(); it != animals.end(); it++) {
		if ((*it) == &a) {
			animals.erase(it);
		}
	}
}

