#include "Roster.h"
#include "Address.h"
#include "Student.h"

using namespace std;


int main()
{
	Roster s(20);
	s.add_student(89, "Aryan", 4109, "Broadmoor Common");
	s.add_student(90, "Hinal", 38039, "Geranium Street");
	s.print_roster();
	return 0;
}