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

// < less than compares the names of the students.First by last name, then by first name
bool operator<(const Student& s1, const Student& s2)
{
	if (s1.last_name == s2.last_name)
	{
		return s1.first_name < s2.first_name;
	}
	else
	{
		return s1.last_name < s2.last_name;
	}
}

// > greater than compares the names of the students.First by last name, then by first name
bool operator>(const Student& s1, const Student& s2)
{
	if (s1.last_name == s2.last_name)
	{
		return s1.first_name > s2.first_name;
	}
	else
	{
		return s1.last_name > s2.last_name;
	}
}

// == compares id
bool operator==(const Student& s1, const Student& s2)
{
    return s1.id == s2.id;
}

// != compares id
bool operator!=(const Student& s1, const Student& s2)
{
    return !(s1 == s2);
}

// << output operator
std::ostream& operator<<(std::ostream& out, const Student& student)
{
	out << "ID: " << student.id << ", Name: " << student.first_name << " " << student.last_name;
	return out;
}