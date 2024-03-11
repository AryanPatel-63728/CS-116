#ifndef ROSTER_H
#define ROSTER_H

#include "Student.h"
#include <vector>

class Roster
{
public:
	// constructor
	Roster(int class_size);

	// deconstructor
	~Roster();

	// member functions
	void add_student(int id, string firstname, string lastname, int street_number, string street_name);
	void print_roster();
	Student* search_by_id(int student_id);

private:
	int class_size;
	int current_size;
	Student** students;
};

#endif // !1
