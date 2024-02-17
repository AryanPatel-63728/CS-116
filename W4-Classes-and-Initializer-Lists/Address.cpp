#include "Address.h"
#include <iostream>

Address::Address(int street_number, string street_name) : street_number(street_number), street_name(street_name)
{
	this->street_number = street_number;
	this->street_name = street_name;
}

//getters
int Address::get_street_number() const
{
	return street_number;
}

string Address::get_street_name() const
{
	return street_name;
}

//seters
void Address::set_street_number(int street_number)
{
	this->street_number = street_number;
}

void Address::set_street_name(string street_name)
{
	this->street_name = street_name;
}

//print
void Address::print_address()
{
	cout << this->street_number << this->street_name << endl;
}