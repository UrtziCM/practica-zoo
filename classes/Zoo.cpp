#include "Zoo.h"
#include <iostream>

Zoo::Zoo(){}

Zoo::~Zoo(){
	// Borrar todos los animales de dentro porque los creamos con new y no los borramos en ningun sitio
	while (animals.size() > 0) {
		delete (*animals.begin());
		animals.pop_front();
	}
}

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
			animals.push_back(r);
			break;
		}


		case 3: { // Ave
			Bird::BEAK beak;
			bool doFly;

			std::cout << "Pico: " << std::endl;
			std::cout << "\t1.Curvado\n\t2.Pinza\n\t3.Lanza\n\t4.Gancho\t\n5.Quebrador\t\n6.Sondeador" << std::endl;
			std::cin >> buffer;

			try {
				iBuffer = std::stoi(buffer);
			}
			catch (std::invalid_argument) {
				std::cout << "ERROR: Mal formato para pico, estableciendo a pinza." << std::endl;
				iBuffer = 2;
			}
			// Tipos de pieles
			switch (iBuffer) {
			case 1:
				beak = Bird::CURVED;
				break;
			case 2:
				beak = Bird::TWEEZER;
				break;
			case 3:
				beak = Bird::SPEAR;
				break;
			case 4:
				beak = Bird::HOOKED;
				break;
			case 5:
				beak = Bird::CRACKER;
				break;
			case 6:
				beak = Bird::PROBING;
				break;

			default: // JIC: To evade errors
				std::cout << "ERROR: Opcion fuera de rango, estableciendo a pinza." << std::endl;
				beak = Bird::TWEEZER;
				break;
			}

			std::cout << "Puede volar?: [s/n]" << std::endl;
			std::cin >> buffer;

			doFly = buffer == "s";

			Bird* b = new Bird(name, species, age, sex, diet, beak, doFly);
			animals.push_back(b);

			break;
		}
		case 4: { // Canino
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
			std::cout << "\t1.Definitivo\n\t2.Vibrissae\n\t3.Peludo\n\t4.Espinas\n\t5.Cerdas\n\t6.Vello\n\t7.Lanudo" << std::endl;
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

			std::string bff;
			bool gbg;

			std::cout << "Quien es su mejor amigo?" << std::endl;
			std::cin >> bff;
			std::cout << "Es un buen chico/a? [s/n]" << std::endl;
			std::cin >> buffer;
			gbg = buffer == "s";

			Canine* c = new Canine(name, species, age, sex, diet, legCount, daysToGest, furType, bff, gbg);
			animals.push_back(c);
			break;
		}
		case 5: { // Squamata
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

			bool poisonous, extremities;

			std::cout << "Es un venenoso? [s/n]" << std::endl;
			std::cin >> buffer;
			poisonous = buffer == "s";
			
			std::cout << "Tiene extremidades? [s / n]" << std::endl;
			std::cin >> buffer;
			extremities = buffer == "s";

			Squamata* s = new Squamata(name, species, age, sex, diet, body_temperature, skin, poisonous, extremities);

			animals.push_back(s);
			break;
		}
	}

}

void Zoo::RemoveAnimal(Animal& a) {
	Animal* animalPointer = nullptr;
	for (auto it = animals.begin(); it != animals.end(); it++) {
		if ((*it) == &a) {
			animalPointer = (*it); // Guardamos el pointer para borrarlo luego
			animals.erase(it); // Borramos de la lista
		}
	}
	delete animalPointer; // Evitamos mem-leaks
}

Animal* Zoo::SearchAnimal(std::string term, bool isSpecies) {
	Animal* a = nullptr;

	for (auto it = animals.begin(); it != animals.end(); it++) {
		// Si buscamos por nombre y el nombre concuerda O si buscamos por especie y la especie concuerda
		if ((!isSpecies && (*it)->GetName() == term) || (isSpecies && (*it)->GetSpecies() == term)) {
			a = (*it);
		}
	}

	return a;
}

void Zoo::ShowAnimalInfo(Animal& a)
{
	std::cout << a.ToString() << std::endl;
}

void Zoo::ListAnimals() {
	for (auto it = animals.begin(); it != animals.end(); it++) {
		std::cout << (*it)->ToString() << std::endl; // Usar el tostring para mostrar su contenido
	}
}

void Zoo::ListAnimalsByType()
{
	std::string buffer;
	int iBuffer;

	std::cout << "Que tipo quieres visualizar?" << std::endl;
	std::cout << "\t1.Mamiferos\n\t2.Reptiles\n\t3.Aves\n\t4.Caninos\n\t5.Squamatas" << std::endl;
	std::cin >> buffer;
	try {
		iBuffer = std::stoi(buffer);
	}
	catch (std::invalid_argument) { // Por si se pasa de listo
		std::cout << "ERROR: Mal formato, estableciendo a Mamifero." << std::endl;
		iBuffer = 1;
	}
	// Dependiendo de la eleccion mostrar solo los de un tipo específico
	switch (iBuffer)
	{
		case 1:
			for (auto it = animals.begin(); it != animals.end(); it++) { // Mostrar mamíferos
				if (dynamic_cast<Mammal*>((*it)) != nullptr) {
					this->ShowAnimalInfo((**it));
				}
			}
			break;
		case 2:
			for (auto it = animals.begin(); it != animals.end(); it++) { // Mostrar reptiles
				if (dynamic_cast<Reptile*>((*it)) != nullptr) {
					this->ShowAnimalInfo((**it));
				}
			}
			break;
		case 3:
			for (auto it = animals.begin(); it != animals.end(); it++) { // Mostrar aves
				if (dynamic_cast<Bird*>((*it)) != nullptr) {
					this->ShowAnimalInfo((**it));
				}
			}
			break;
		case 4:
			for (auto it = animals.begin(); it != animals.end(); it++) { // Mostrar canidos
				if (dynamic_cast<Canine*>((*it)) != nullptr) {
					this->ShowAnimalInfo((**it));
				}
			}
			break;
		case 5:
			for (auto it = animals.begin(); it != animals.end(); it++) { // Mostrar squa...
				if (dynamic_cast<Squamata*>((*it)) != nullptr) {
					this->ShowAnimalInfo((**it));
				}
			}
			break;
		default:
			break;
	}


}


