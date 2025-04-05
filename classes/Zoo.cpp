#include "Zoo.h"
#include <iostream>

Zoo::Zoo(){}

Zoo::~Zoo(){}

void Zoo::AddAnimal() {
	std::cout << "Que tipo de animal quieres crear?" << std::endl;
	std::cout << "\t1.Mamifero\n\t2.Reptil\n\t3.Ave" << std::endl;


}

void Zoo::RemoveAnimal(Animal& a) {
	for (auto it = animals.begin(); it != animals.end(); it++) {
		if ((*it) == &a) {
			animals.erase(it);
		}
	}
}

