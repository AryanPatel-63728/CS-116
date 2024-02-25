#include "Pet.h"

using namespace std;

// Constructor

Pet::Pet(string name, int id, int days_in_shelter, string breed, int age)
{
	this->name = name;
	this->id = id;
	this->breed = breed;
	this->age = age;
	this->days_in_shelter = days_in_shelter;
}

// Getters

string Pet::get_Name()
{
	return name;
}

int Pet::get_Id()
{
	return id;
}

string Pet::get_Breed()
{
	return breed;
}

int Pet::get_Age()
{
	return age;
}

int Pet::get_DaysInShelter() const
{
	return days_in_shelter;
}

// Setters (don't need)

void Pet::set_Name(string name)
{
	this->name = name;
}

void Pet::set_Id(int id)
{
	this->id = id;
}

void Pet::set_Breed(string breed)
{
	this->breed = breed;
}

void Pet::set_Age(int age)
{
	this->age = age;
}

void Pet::set_DaysInShelter(int days_in_shelter)
{
	this->days_in_shelter = days_in_shelter;
}

void Pet::incrementDaysInShelter()
{
	this->days_in_shelter++;
}