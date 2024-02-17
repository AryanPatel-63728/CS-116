#include "Student.h"
#include <iostream>

Student::Student(int id, string name, int street_number, string street_name) : address(street_number, street_name)
{
	set_name(name);
	set_id(id);
}

//seters
void Student::set_name(string name)
{
	this->name = name;
}

void Student::set_id(int id)
{
	this->id = id;
}

//getters
string Student::get_name()
{
	return name;
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
	cout << "Name: " << get_name() << ", ID: " << get_id() << ", Address: ";
	address.print_address();
}