#include "Animales.h"



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
	return sex:
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

Animal::GetSpecies() {
	return species;
}
