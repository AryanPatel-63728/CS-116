#include "Helper.h"

void greet()
{
    string name, input;
    cout << "Hello user, could you provide a name? \n";
    cin >> name;
    cout << setw(56) << "This Program is about a system at a Pet Shelter to keep \n";
    cout << setw(56) << "track of the animals that are currently in the Shelter \n";
    cout << setw(56) << "and keep track of how long they have been at the Shelter \n";
    cout << setw(52) << "Would you like to run this program " << name << "? \n";
    cout << "Y or N \n";
    cin >> input;
    if (input == "N") 
    {
        cout << "Thank you for looking at this program \n";
        cout << "I Hope you have a wonderful day! \n";
        exit(0);
    }
    else 
    {
        PetShelter shelter;
        Menu menu;
        int fileChoice = menu.promptFileChoice();
        if (fileChoice == 1) 
        {
            string filename;
            cout << "Enter the filename of the pet file: ";
            cin >> filename;

            ifstream inFile(filename);
            if (inFile.is_open()) {
                string line;
                while (getline(inFile, line)) 
                {
                    stringstream ss(line);
                    string petName, breed;
                    int id, age, days_in_shelter;

                    // Read individual values from stringstream using ',' as a delimiter
                    if (getline(ss, petName, ',') &&
                        ss >> id && ss.ignore() &&
                        ss >> days_in_shelter && ss.ignore() &&
                        getline(ss, breed, ',') &&
                        ss >> age)
                    {
                        // Create a new Pet object and set its attributes
                        Pet* newPet = new Pet(petName, id, days_in_shelter, breed, age);
                        shelter.addPetPointer(newPet);
                    }
                    else {
                        cout << "Error parsing line: " << line << endl;
                    }
                }
                inFile.close();
                cout << "Pets loaded from file successfully.\n";
            }
            else 
            {
                cout << "Unable to open file.\n";
            }
        }
        activate(shelter); // Pass shelter object to activate
    }
}

void activate(PetShelter& shelter)
{
    Menu menu;
    cout << "Welcome to the Pet Shelter Management Program!\n";
    int choice;
    do {
        menu.displayMenu();
        choice = menu.getUserChoice();
        bool option4Executed = false; // Flag to track if option 4 has been executed

        switch (choice) {
        case 1:
            shelter.listPets();
            break;
        case 2: {
            string name, breed;
            int id, age, days_in_shelter;
            cout << "Enter pet details (name, id, days in shelter, breed, age): \n";
            cin >> name >> id >> days_in_shelter >> breed >> age;
            shelter.addPet(name, id, days_in_shelter, breed, age);
            break;
        }
        case 3: {
            Pet* oldestPet = shelter.getOldestPet();
            if (oldestPet != nullptr) {
                cout << "The pet that has been in the shelter the longest is: " << oldestPet->get_Name() << endl;
            }
            else {
                cout << "No pets in the shelter.\n";
            }
            break;
        }
        case 4:
            shelter.updateShelter();
            option4Executed = true;
            break;
        case 5: {
            string filename;
            cout << "Enter the filename to save: ";
            cin >> filename;
            shelter.saveToFile(filename);
            break;
        }
        case 6:
            if (!option4Executed) 
            {
                shelter.updateShelter(); // Increment days in shelter if update days_in_shelter hasn't been executed
            }
            cout << "Exiting program.\n";
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 6);
}