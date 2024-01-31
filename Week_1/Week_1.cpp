
#include <fstream>
#include <iostream>
#include <sstream>

using namespace std;

const int SIZE = 10;

struct Account
{
public:
    int ID;
    string email;
    double balance;
private:

};

int ID_checker(Account* arry[], int user_ID)
{
    for (int i = 0; i < SIZE; i++)
    {
        if (user_ID === arry[i])
        {

        }
        else ()
        {

        }
    }
}

int main()
{
    Account menu;
    cout << "enter an ID: " << endl;
    int* user_ID;
    ifstream ifs;
    ifs.open("C:\\Users\\arypa\\OneDrive\\Desktop\\CS-116\\Week_1\\s.txt");
    if (ifs.fail())
    {
        cout << "failed to open the file" << endl;
    }
    else
    {
        cout << "File opened" << endl;
    }

    string s;
    int count = 0;
    Account* arry[SIZE];
    while (getline(ifs,s))
    {
        istringstream iss;
        iss.str(s);
        arry[count] = new Account;
        iss >> arry[count]->ID >> arry[count]->balance >> arry[count]->email;
        count++;
    }

    ifs.close();
    ofstream ofs;
    ofs.open("C:\\Users\\arypa\\OneDrive\\Desktop\\CS-116\\Week_1");

    for (int i = 0; i < count; i++)
    {
        ofs << arry[count]->ID << " " << arry[count]->email << " " << arry[count]->balance << " " << endl;
    }
}