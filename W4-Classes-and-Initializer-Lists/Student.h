#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include "Address.h"

using namespace std;

class Student
{
public:
	Student(int id, string firstname, string lastname, int street_number, string street_name);
	//seters
	void set_firstName(string firstName);
	void set_lastName(string lastName);
	void set_id(int id);
	//getters
	string get_firstName();
	string get_lastName();
	int get_id();
	Address get_address();
	//print all 3 private varibles
	void print_student();

	// overloading operators

	//== compares id
	//!= compares id
	//<< output operator (look at 12.1 for an example)

	bool operator < (const Student& other);
	bool operator > (const Student& other);

	bool operator==(Student a, Student b);
	bool operator!=(Student a, Student b);

	friend 

private:
	string first_name;
	string last_name;
	int id;
	Address address;
};

#endif // !1
