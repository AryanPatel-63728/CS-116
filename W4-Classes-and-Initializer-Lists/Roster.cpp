#include "Roster.h"
#include <iostream>

Roster::Roster(int class_size)
{
	this->students = new Student*[class_size];
	this->current_size = 0;
	this->class_size = class_size;
}

void Roster::add_student(int id, string name, int street_number, string street_name)
{
	if (this->current_size < this->class_size)
	{
		this->students[this->current_size] = new Student(id, name, street_number, street_name);
	}
	current_size++;
}

void search_by_id(int student_id)
{

}

void Roster::print_roster()
{
	for (int i = 0; i < this->current_size; ++i)
	{
		// Dereference the pointer to access the actual Student object
		Student* student = this->students[i];
		cout << "[" << i << "] ID: " << student->get_id() << ", Name: " << student->get_name(); // Add a newline for formatting
		Address studentAddress = student->get_address();
		cout << ", Address: " << studentAddress.get_street_number() << " " << studentAddress.get_street_name() << endl;
	}
}