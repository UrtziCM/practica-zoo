#include "Animales.h"

int Animal::GetAge() {
	return age;
}

Animal::Animal(std::string name, std::string species, int age, SEX sex, DIET diet) {
	this->name = name;
	this->species = species;
	this->age = age;
	this->sex = sex;
	this->diet = diet;
}

Animal::~Animal() {};