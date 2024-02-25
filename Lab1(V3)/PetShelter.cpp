#include "PetShelter.h"
#include <iostream>
#include <fstream>

// adds pet to vector
void PetShelter::addPet(const string& name, int id, int days_in_shelter, const string& breed, int age)
{
    pets.push_back(new Pet(name, id, days_in_shelter, breed, age));
}

void PetShelter::addPetPointer(Pet* pet)
{
    pets.push_back(pet);
}

// prints the pets in the shelter
void PetShelter::listPets() const
{
    cout << "Pets currently in shelter:\n";
    if (pets.empty()) {
        cout << "No pets in the shelter.\n";
        return;
    }
    for (const auto& pet : pets) {
        cout << "Name: " << pet->get_Name() << ", ID: " << pet->get_Id() << ", Days in Shelter: " << pet->get_DaysInShelter() << ", Breed: " << pet->get_Breed() << ", Age: " << pet->get_Age() << endl;
    }
}

Pet* PetShelter::getOldestPet() const
{
    if (pets.empty()) 
    {
        return nullptr;
    }

    Pet* oldestPet = pets[0];
    for (const auto& pet : pets) 
    {
        if (pet->get_Age() > oldestPet->get_Age()) 
        {
            oldestPet = pet;
        }
    }
    return oldestPet;
}

void PetShelter::updateShelter()
{
    for (auto& pet : pets) 
    {
        pet->incrementDaysInShelter();
    }
    cout << "Shelter updated.\n";
}

void PetShelter::saveToFile(const string& filename) const
{
    ofstream outFile(filename);
    if (outFile.is_open()) 
    {
        for (const auto& pet : pets) 
        {
            outFile << pet->get_Name() << "," << pet->get_Id() << "," << pet->get_DaysInShelter() << "," << pet->get_Breed() << "," << pet->get_Age() << endl;
        }
        cout << "Data saved to file successfully.\n";
        outFile.close();
    }
    else 
    {
        cout << "Unable to open file for saving.\n";
    }
}