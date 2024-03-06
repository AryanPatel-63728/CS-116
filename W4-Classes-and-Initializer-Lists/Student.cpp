#include "Student.h"
#include <iostream>

Student::Student(int id, string firstname, string lastname, int street_number, string street_name) : address(street_number, street_name)
{
	set_firstName(firstname);
	set_lastName(lastname);
	set_id(id);
}

//seters
void Student::set_firstName(string firstname)
{
	this->first_name = firstname;
}

void Student::set_lastName(string lastname)
{
	this->last_name = lastname;
}

void Student::set_id(int id)
{
	this->id = id;
}

//getters
string Student::get_firstName()
{
	return first_name;
}

string Student::get_lastName()
{
	return last_name;
}

int Student::get_id()
{
	return id;
}

Address Student::get_address()
{
	return address;
}

//print all 3 private varibles
void Student::print_student()
{
	cout << "First Name: " << get_firstName() << ", Last Name: " << get_lastName() << ", ID: " << get_id() << ", Address: ";
	address.print_address();
}

// overloading operators

//< less than compares the names of the students.First by last name, then by first name
//> greater than compares the names of the students.First by last name, then by first name
//== compares id
//!= compares id
//<< output operator (look at 12.1 for an example)

bool Student::operator== (const Student& other)
{

}

ostream& operator<<(ostream& out, Student a)
{
	out << a.get_firstName() << " " << a.get_lastName();
	return out;
}