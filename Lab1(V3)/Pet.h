#ifndef PET_H
#define PET_H
#include <string>

using namespace std;

class Pet
{
public:

	// constructor

	Pet(string name, int id, int days_in_shelter, string breed, int age);

	// acessors

	string get_Name();
	int get_Id();
	string get_Breed();
	int get_Age();
	int get_DaysInShelter() const;

	// mutators

	void set_Name(string name);
	void set_Id(int id);
	void set_Breed(string breed);
	void set_Age(int age);
	void set_DaysInShelter(int days_in_shelter);

	// increment the days

	void incrementDaysInShelter();

private:

	string name;
	int id;
	int days_in_shelter;
	string breed;
	int age;

};

#endif