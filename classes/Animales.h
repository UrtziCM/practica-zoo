#include <string>
class Animal {
	public:
		enum SEX {
			MALE = 0,
			FEMALE,
			HERMAPHRODITE,
			NONE
		};

		enum DIET {
			CARNIVORE = 0,
			HERBIVORE,
			OMNIVORE
		};
		
		Animal();
		virtual ~Animal();
		std::string GetName();
		std::string GetSpecies();
		int GetAge();
		SEX GetSex();
		DIET GetDiet();

	private:
		std::string name;
		std::string species;
		int age;
		SEX sex;
		DIET diet;
};

class Mammal : Animal {
	
};

class Reptile : Animal {};

class Bird : Animal {};