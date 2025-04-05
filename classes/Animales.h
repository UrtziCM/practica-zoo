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
		
		Animal(std::string name, std::string species, int age, SEX sex, DIET diet);
		virtual ~Animal();
		std::string GetName();
		std::string GetSpecies();
		int GetAge();
		SEX GetSex();
		DIET GetDiet();

		void SetName(std::string name);
		void SetSpecies(std::string species);
		void SetAge(int age);
		void SetSex(SEX sex);
		void SetDiet(DIET diet);

	private:
		std::string name;
		std::string species;
		int age;
		SEX sex;
		DIET diet;
};

class Mammal : Animal {
	public:
		enum FUR {
			DEFINITIVE = 0,
			VIBRISSAE,
			PELAGE,
			SPINES,
			BRISTLES,
			VELLI,
			WOOL
		};

		Mammal(std::string name, std::string species, int age, SEX sex, DIET diet, int legCount, int daysToGest, FUR furType) : Animal(name, species, age, sex, diet) {
			this->legCount = legCount;
			this->daysToGest = daysToGest;
			this->furType = furType;
		};
		~Mammal();

		int GetLegCount();
		int GetDaysToGest();
		FUR GetFurType();

		void SetLegCount(int legCount);
		void SetDaysToGest(int daysToGest);
		void SetFurType(FUR furType);

	private:
		int legCount;
		int daysToGest;
		FUR furType;
};

class Reptile : Animal {};

class Bird : Animal {};