#ifndef PETSHELTER_H
#define PETSHELTER_H
#include "Pet.h"
#include "vector"

class PetShelter
{
public:
	// adds pet to vector
	void addPet(const string& name, int id, int days_in_shelter, const string& breed, int age);
	void addPetPointer(Pet* pet);
	// prints the pets in the shelter
	void listPets() const;
	// returns the oldest pet
	Pet* getOldestPet() const;
	// saves the data back to file
	void saveToFile(const string& filename) const;
	// increment the days in shelter for all pets
	void updateShelter();
	
private:

	// vector for pets using the info from pet class with pointer
	vector<Pet*> pets;

};

#endif