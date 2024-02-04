#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <string>

using namespace std;

const int SIZE = 10;

struct Account
{
	int ID;
	string email;
	double balance;
};

// function declerations

void LoadData_From_file(Account* arry[], int& count, string filename);

Account* Find_Account_By_ID(Account* arry[], int count, int account_ID);

void Update_balance(Account* useraccount, double despositAmount);

void Write_data_back(Account* arry[], int& count, string filename);

int main()
{
    // Initialize the struct to be used
    Account* arr[SIZE];
    int count = 0;
    string filename = "Account_Data.txt";

    // Load data from the file
    LoadData_From_file(arr, count, filename);

    int account_id;
    cout << "Give your account ID: " << endl;
    cin >> account_id;

    // Check if the account ID is not in the data
    Account* userAccount = Find_Account_By_ID(arr, count, account_id);
    if (userAccount == nullptr)
    {
        // Create a new account
        if (count < SIZE)
        {
            arr[count] = new Account;
            arr[count]->ID = account_id;

            cout << "Enter email for account with ID " << account_id << ": ";
            cin >> arr[count]->email;

            // Set balance to 0 for new accounts
            arr[count]->balance = 0.0;

            userAccount = arr[count];
            count++;
        }
        else
        {
            cout << "Error: Cannot create a new account. Maximum size reached." << endl;
            return 1;
        }
    }

    // Ask for a deposit
    double deposit;
    cout << "How much deposit to account " << userAccount->ID << ": ";
    cin >> deposit;
    Update_balance(userAccount, deposit);

    // Update the data back to the file
    Write_data_back(arr, count, filename);

    // Clean up allocated memory
    for (int i = 0; i < count; ++i)
    {
        delete arr[i];
    }

    return 0;
}

void LoadData_From_file(Account* arry[], int& count, string filename)
{
    ifstream ifs(filename);
    string line;

    while (getline(ifs, line) && count < SIZE)
    {
        istringstream iss(line);
        int id;
        double balance;
        string email;

        iss >> id >> email >> balance;

        // Check if the ID is not found, then create a new account
        if (Find_Account_By_ID(arry, count, id) == nullptr)
        {
            arry[count] = new Account;
            arry[count]->ID = id;
            arry[count]->email = email;
            arry[count]->balance = balance;
            count++;
        }
    }

    ifs.close();
}

Account* Find_Account_By_ID(Account* arry[], int count, int account_ID)
{
	for (int i = 0; i < count; i++)
	{
		if (arry[i]->ID == account_ID)
		{
			return arry[i];
		}
	}
	return nullptr;
}

void Write_data_back(Account* arry[], int& count, string filename)
{
	ofstream ofs(filename);
	for (int i = 0; i < count; i++)
	{
		if (i < count - 1)
		{
			ofs << arry[i]->ID << " " << arry[i]->email << " " << arry[i]->balance << endl;
		}
		else
		{
			ofs << arry[i]->ID << " " << arry[i]->email << " " << arry[i]->balance;
		}
	}
	ofs.close();
}

void Update_balance(Account* useraccount, double despositAmount)
{
	useraccount->balance += despositAmount;
	cout << "Succesfully added the amount to the account" << endl;
}