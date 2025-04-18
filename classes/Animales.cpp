#include "Animales.h"
#include <sstream>

Animal::Animal(std::string name, std::string species, int age, SEX sex, DIET diet) {
	this->name = name;
	this->species = species;
	this->age = age;
	this->sex = sex;
	this->diet = diet;
}

Animal::~Animal() {};

int Animal::GetAge() {
	return age;
}

std::string Animal::GetName() {
	return name;
}

Animal::SEX Animal::GetSex() {
	return sex;
}

Animal::DIET Animal::GetDiet(){
	return diet;
}

void Animal::SetName(std::string name)
{
	this->name = name;
}

void Animal::SetSpecies(std::string species)
{
	this->species = species;
}

void Animal::SetAge(int age)
{
	this->age = age;
}

void Animal::SetSex(SEX sex)
{
	this->sex = sex;
}

void Animal::SetDiet(DIET diet)
{
	this->diet = diet;
}

std::string Animal::GetSpecies() {
	return species;
}

std::string Animal::ToString() {
	std::stringstream StringAnimal;
	StringAnimal << "Name = " << name << ", Species = " << species << ", Age = " << age << ", Sex = " << sex << ", Diet = " << diet;
	return StringAnimal.str();
}

Mammal:: ~Mammal() {};

int Mammal::GetLegCount() {
	return legCount;
};

int Mammal::GetDaysToGest() {
	return daysToGest;
};

Mammal::FUR Mammal::GetFurType() {
	return furType;
};

void Mammal::SetLegCount(int legCount) {
	this->legCount = legCount;
};

void Mammal::SetDaysToGest(int daysToGest) {
	this->daysToGest = daysToGest;
};

void Mammal::SetFurType(FUR furType) {
	this->furType = furType;
};

std::string Mammal::ToString() {
	std::stringstream StringAnimal;
	StringAnimal << "Name = " << this->GetName() << ", Species = " << this->GetSpecies() << ", Age = " << this->GetAge() << ", Sex = " << this->GetSex() << ", Diet = " << this->GetDiet() << ", Leg Count = " << legCount << ", Days to Gest = " << daysToGest << ", Fur Type = " << furType;
	return StringAnimal.str();
}

Reptile::~Reptile() {};

Reptile::BODY_TEMPERATURE Reptile::GetBodyTemperature() {
	return body_temperature;
};
Reptile::SKIN Reptile::GetSkin() {
	return skin;
};

void Reptile::SetBodyTemperature(BODY_TEMPERATURE bt) {
	this->body_temperature = bt;
};

void Reptile::SetSkin(SKIN skin) {
	this->skin = skin;
};

std::string Reptile::ToString() {
	std::stringstream StringAnimal;
	StringAnimal << "Name = " << this->GetName() << ", Species = " << this->GetSpecies() << ", Age = " << this->GetAge() << ", Sex = " << this->GetSex() << ", Diet = " << this->GetDiet() << ", Body temperature = " << body_temperature << ", skin = " << skin;
	return StringAnimal.str();
}

Bird::~Bird() {};

bool Bird::GetFlight() {
	return flight;
};

Bird::BEAK Bird::GetBeak() {
	return beak;
};

void Bird::SetFlight(bool flight) {
	this->flight = flight;
};

void Bird::SetBeak(BEAK beak) {
	this->beak = beak;
};

std::string Bird::ToString() {
	std::stringstream StringAnimal;
	StringAnimal << "Name = " << this->GetName() << ", Species = " << this->GetSpecies() << ", Age = " << this->GetAge() << ", Sex = " << this->GetSex() << ", Diet = " << this->GetDiet() << ", Flight = " << flight << ", Beak = " << beak;
	return StringAnimal.str();
}

Canine::~Canine() {}

std::string Canine::GetBFF() {
	return BFF;
};

bool Canine::GetGoodBoyOrGirl() {
	return goodBoyOrGirl;
};

void Canine::SetBFF(std::string bff) {
	this->BFF = bff;
};

void Canine::SetGoodBoyOrGirl(bool gbg) {
	this->goodBoyOrGirl = gbg;
};

std::string Canine::ToString() {
	std::stringstream StringAnimal;
	StringAnimal << "Name = " << this->GetName() << ", Species = " << this->GetSpecies() << ", Age = " << this->GetAge() << ", Sex = " << this->GetSex() << ", Diet = " << this->GetDiet() << ", BFF = " << BFF << ", Is a good Boy or Girl? = " << goodBoyOrGirl;
	return StringAnimal.str();
}

Squamata::~Squamata() {};

bool Squamata::GetPoisonous() {
	return poisonous;
};

bool Squamata::GetExtremities() {
	return extremities;
};

void Squamata::SetPoisonous(bool poisonous) {
	this->poisonous = poisonous;
};

void Squamata::SetExtremities(bool extremities) {
	this->extremities = extremities;
};

std::string Squamata::ToString() {
	std::stringstream StringAnimal;
	StringAnimal << "Name = " << this->GetName() << ", Species = " << this->GetSpecies() << ", Age = " << this->GetAge() << ", Sex = " << this->GetSex() << ", Diet = " << this->GetDiet() << ", Poisonous = " << poisonous << ", Extremities = " << extremities;
	return StringAnimal.str();
}