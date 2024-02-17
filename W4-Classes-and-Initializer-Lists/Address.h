#ifndef ADDRESS_H
#define ADDRESS_H

#include <string>

using namespace std;

class Address
{
public:
	Address(int street_number, string street_name);
	//getters
	int get_street_number() const;
	string get_street_name() const;
	//seters
	void set_street_number(int street_number);
	void set_street_name(string street_name);
	//print
	void print_address();
private:
	int street_number;
	string street_name;
};

#endif // !1