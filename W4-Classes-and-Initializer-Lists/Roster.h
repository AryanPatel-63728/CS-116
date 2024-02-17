#ifndef ROSTER_H
#define ROSTER_H

#include "Student.h"

class Roster
{
public:
	Roster(int class_size);
	void add_student(int id, string name, int street_number, string street_name);
	void print_roster();
private:
	int class_size;
	int current_size;
	Student** students;
};

#endif // !1
