#include "Roster.h"
#include "Address.h"
#include "Student.h"
#include <iostream>

using namespace std;


int main()
{
	Roster s(20);
	s.add_student(89, "Aryan", "Patel", 4109, "Broadmoor Common");
	s.add_student(90, "Hinal", "Patel", 38039, "Geranium Street");

    std::cout << "Roster:" << std::endl;
    s.print_roster();

    Student* foundStudent = s.search_by_id(89);
    if (foundStudent != nullptr)
    {
        std::cout << "\nFound student: " << std::endl;
        foundStudent->print_student();
        return 0; // Return with 0 indicating success
    }
    else
    {
        std::cout << "\nStudent not found." << std::endl;
        return 1; // Return with non-zero indicating failure
    }
}