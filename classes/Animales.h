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
		virtual ~Mammal();

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

class Reptile : Animal {
	public:
		enum BODY_TEMPERATURE {
			POIKILOTHERMY = 0,
			ECTOTHERMY,
			OPTIMAL,
			CRITICAL,
			REGIONAL_HETEROTHERMY
		};
		enum SKIN {
			KERATINIZED_SCALY = 0,
			OSTEODERMIC,
			LEATHERY,
			GLANDULAR,
			SHEDDING
		};

		Reptile(std::string name, std::string species, int age, SEX sex, DIET diet, BODY_TEMPERATURE bt, SKIN skin) : Animal(name, species, age, sex, diet) {
			this->body_temperature = bt;
			this->skin = skin;
		};
		virtual ~Reptile();

		BODY_TEMPERATURE GetBodyTemperature();
		SKIN GetSkin();

		void SetBodyTemperature(BODY_TEMPERATURE bt);
		void SetSkin(SKIN skin);

	private:
		BODY_TEMPERATURE body_temperature;
		SKIN skin;
};

class Bird : Animal {
public:
	enum BEAK {
		CURVED = 0,
		TWEEZER,
		SPEAR,
		HOOKED,
		CRACKER,
		PROBING
	};

	Bird(std::string name, std::string species, int age, SEX sex, DIET diet, BEAK beak, bool flight) : Animal(name, species, age, sex, diet) {
		this->beak = beak;
		this->flight = flight;
	};
	virtual ~Bird();

	bool GetFlight();
	BEAK GetBeak();

	void SetFlight(bool flight);
	void SetBeak(BEAK beak);

private;
	bool flight;
	BEAK beak;
};