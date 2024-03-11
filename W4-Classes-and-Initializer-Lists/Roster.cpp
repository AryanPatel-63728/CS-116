#include "Roster.h"
#include <iostream>

Roster::Roster(int class_size)
{
	this->students = new Student*[class_size];
	this->current_size = 0;
	this->class_size = class_size;
}

Roster::~Roster()
{
	for (int i = 0; i < current_size; ++i)
	{
		delete students[i];
	}
	delete[] students;
}

void Roster::add_student(int id, string firstname, string lastname, int street_number, string street_name)
{
	if (this->current_size < this->class_size)
	{
		this->students[this->current_size] = new Student(id, firstname, lastname, street_number, street_name);
		this->current_size++;  // Increment current_size only when adding a student
	}
}

Student* Roster::search_by_id(int student_id)
{
	for (int i = 0; i < current_size; ++i)  // Iterate until current_size, not SIZE_MAX
	{
		if (students[i]->get_id() == student_id)
		{
			return students[i];
		}
	}
	return nullptr;
}

void Roster::print_roster()
{
	for (int i = 0; i < this->current_size; ++i)
	{
		// Dereference the pointer to access the actual Student object
		Student* student = this->students[i];
		cout << "[" << i << "] ID: " << student->get_id() << ", First Name: " << student->get_firstName() << ", Last Name: " << student->get_lastName(); // Add a newline for formatting
		Address studentAddress = student->get_address();
		cout << ", Address: " << studentAddress.get_street_number() << " " << studentAddress.get_street_name() << endl;
	}
}