#include "Menu.h"
#include <iostream>

using namespace std;

void Menu::displayMenu()
{
    cout << "=== Pet Shelter Management Menu ===" << endl;
    cout << "1. List pets" << endl;
    cout << "2. Add pet" << endl;
    cout << "3. Display oldest pet" << endl;
    cout << "4. Update shelter" << endl;
    cout << "5. Save to file" << endl;
    cout << "6. Exit" << endl;
    cout << "===================================" << endl;
    cout << "Enter your choice: ";
}

int Menu::getUserChoice()
{
    int choice;
    cin >> choice;
    return choice;
}

int Menu::promptFileChoice()
{
    cout << "Do you have a file of pets you would like to open? (yes/no): ";
    string choice;
    cin >> choice;
    // check if the choice is yes or no
    return (choice == "yes") ? 1 : 0;
}