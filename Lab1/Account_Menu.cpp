#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>

using namespace std;

const int SIZE = 10;

struct Account
{
	int ID;
	string email;
	double balance;
};

Account* Find_Account_By_ID(Account* Account_info[], int account_ID)
{
	for (int i = 0; i < SIZE; i++)
	{
		if (Account_info[i]->ID == account_ID)
		{
			return Account_info[i];
		}
	}
	return nullptr;
}
void Update_balance(Account* useraccount)
{
	// ask the user how much they would like to deposit into the account
	double depositAmount;
	cout << "Enter the deposit amount for the account ID" << useraccount->ID <<": $";
	cin >> depositAmount;
	// update the value
	useraccount->balance += depositAmount;
	cout << "Amount has been succesfully been added to the account ID" << useraccount->ID << endl;
}
void Write_data_back(Account* Account_info[])
{
	// Write the array back into the data file with any updated values.
	ofstream ofs;
	// Open the file with data
	ofs.open("Account_Data.txt");
	if (ofs.fail())
	{
		cout << "Error opening the file for info update" << endl;
	}
	else
	{
		for (int i = 0; i < SIZE; i++)
		{
			ofs << Account_info[i]->ID << " " << Account_info[i]->email << " " << Account_info[i]->balance << endl;
		}
		ofs.close();
	}
}

int main()
{
	// Iniciate the strct to be used
	Account menu;
	ifstream ifs;
	// Open the file with data
	ifs.open("Account_Data.txt");
	// if fail to open then print an error and exit
	if (ifs.fail())
	{
		cout << "Error opening the file." << endl;
		return 1;
	}
	string Account_Data;
	// Make a pointer arry of size 10
	Account* Account_info[SIZE];
	for (int i = 0; i < SIZE; ++i)
	{
		// Create a new Account instance
		Account* newAccount = new Account;
		// Read data from the file
		ifs >> newAccount->ID >> newAccount->email >> newAccount->balance;
		// Add the Account pointer to the array
		Account_info[i] = newAccount;
	}
	ifs.close();

	int account_ID;
	cout << "Enter an ID to find and update balance: " << endl;
	cin >> account_ID;
	Account* Found_Account = Find_Account_By_ID(Account_info, account_ID);
	if (Found_Account != nullptr)
	{
		Update_balance(Found_Account);
		Write_data_back(Account_info);
	}
	else
	{
		cout << "ID not Found" << endl;
	}
	for (int i = 0; i < SIZE; ++i)
	{
		delete Account_info[i];
	}
	return 0;
}
	