// This is simple c++ projects to register and login user using username and password and in this project user can change password also if user forgot password.
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

void login();
void Registration();
void Forgotpassword();

int main()
{
    cout << "        Welcome to Login Page       " << endl;
    int c;
    cout << "       Enter 1 for regster user :" << endl;
    cout << "       Enter 2 for login user:" << endl;
    cout << "       Enter 3 for password Access:" << endl;
    cout << "       Enter 4 to exit:" << endl;
    cout << "       Please enter your choice:" << endl;
    cin >> c;
    cout << endl;
    switch (c)
    {
    case 1:
        Registration();
        break;
    case 2:
        login();
        break;
    case 3:
        Forgotpassword();
        break;
    case 4:
        cout << "Thank you!" << endl;
        return 0;
    default:
        cout << "Please select from the given options:" << endl;
    }
    main();
}

void Registration()
{
    system("cls");
    string registeru, rpwd;
    cout << "Enter username:" << endl;
    cin >> registeru;
    cout << "Enter password:" << endl;
    cin >> rpwd;
    ofstream R("user.txt", ios::app);
    R << registeru << " " << rpwd << endl;
    cout << "Registration successful" << endl;
    main();
}

void login()
{

    system("cls");
    int count = 0;
    string user_id, password, id, pass;
    cout << "Please enter username & password:" << endl;
    cout << "USERNAME : ";
    cin >> user_id;
    cout << "PASSWORD : ";
    cin >> password;

    ifstream in("user.txt");    //open file and read username and password
    while (in >> id >> pass)          
    {
        if (id == user_id && pass == password)
        {
            count = 1;
            break;
        }
    }
    in.close();

    if (count == 1)
    {
        cout << "Your login is successful" << endl;
    }
    else
    {
        cout << "Login error" << endl;
    }
    main();
}

void Forgotpassword()
{
    int option;
    cout << "You forgot the password, reset your password:" << endl;
    cout << "Press 1 to search your id by username:" << endl;
    cout << "Press 2 to go to the main menu:" << endl;
    cout << "Enter your choice:" << endl;
    cin >> option;

    switch (option)
    {
    case 1:
    {
        int count = 0;
        string suserid, sid, spass, newpass;
        cout << "Enter username which you remember:" << endl;
        cin >> suserid;

        ifstream check("user.txt");
        ofstream temp("temp.txt");

        while (check >> sid >> spass)
        {
            if (sid == suserid)
            {
                count = 1;
                cout << "Your account is found. Please enter a new password:" << endl;
                cin >> newpass;
                temp << sid << " " << newpass << endl;    // Write the updated password
            }
            else
            {
                temp << sid << " " << spass << endl;    // Write the original data
            }
        }
        check.close();
        temp.close();

        remove("user.txt");
        rename("temp.txt", "user.txt");

        if (count == 1)
        {
            cout << "Password updated successfully!" << endl;
        }
        else
        {
            cout << "Sorry, your account not found!" << endl;
        }
        break;
    }
    case 2:
        return;
    default:
        cout << "Wrong choice, please try again" << endl;
        Forgotpassword();
    }
}
