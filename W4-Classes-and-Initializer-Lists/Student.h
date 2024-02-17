#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include "Address.h"

using namespace std;

class Student
{
public:
	Student(int id, string name, int street_number, string street_name);
	//seters
	void set_name(string name);
	void set_id(int id);
	//getters
	string get_name();
	int get_id();
	Address get_address();
	//print all 3 private varibles
	void print_student();
private:
	string name;
	int id;
	Address address;
};

#endif // !1
