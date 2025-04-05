#include "Animales.h"
#include <list>

class Zoo {
	private:
		std::list<Animal*> animals;

	public:
		Zoo();
		~Zoo();
		void AddAnimal();
		void RemoveAnimal(Animal &a);
		Animal* SearchAnimal(std::string term, bool isSpecies);
		void ShowAnimalInfo(Animal &a);
		void ListAnimals();
		void ListAnimalsByType();

};