#include "Zoo.h"

Zoo::Zoo(){}

Zoo::~Zoo(){}

void Zoo::AddAnimal(Animal &a) {
	animals.push_back(a);
}

void Zoo::RemoveAnimal(Animal& a) {
	for (auto it = animals.begin(); it != animals.end(); it++) {
		if ((*it) == &a) {
			animals.erase(it);
		}
	}
}

