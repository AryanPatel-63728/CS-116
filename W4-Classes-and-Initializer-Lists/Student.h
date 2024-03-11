#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include "Address.h"

using namespace std;

class Student
{
public:
	// constructor
	Student(int id, string firstname, string lastname, int street_number, string street_name);

	//seters
	void set_firstName(string firstName);
	void set_lastName(string lastName);
	void set_id(int id);

	// getters
	string get_firstName();
	string get_lastName();
	int get_id();
	Address get_address();

	// print all 3 private varibles
	void print_student();

	// overloading operators
	
	friend bool operator<(const Student& s1, const Student& s2);
	friend bool operator>(const Student& s1, const Student& s2);

	friend bool operator==(const Student& s1, const Student& s2);
	friend bool operator!=(const Student& s1, const Student& s2);

	friend std::ostream& operator<<(std::ostream& out, const Student& student);

private:
	string first_name;
	string last_name;
	int id;
	Address address;
};

#endif
