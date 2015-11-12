
#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>
#include <boost/algorithm/string.hpp>

using namespace std;

string mainMenu(string u)
{
    string user = u;
    //string userNameUpper;
    cout << "*************************************" << endl;
    cout << "******     THE MATH GAME!       *****" << endl;
    cout << "*        Welcome " << user << "            *" << endl;
    cout << "*************************************" << endl;
    cout << "*************************************" << endl;
}

string userFile(string fN)
{
    //declare variables
    
    ifstream infile; //this will be the variable to open files that already exist and read data from them
    ofstream outfile; //this will be the variable to create non-existent files and write to them
    string fileName = fN; //this variable takes on the value of the passed argument from the menu function

    infile.open((fileName + ".txt").c_str()); //concat the user defined name to open/create a text file for the user.
    
    if (infile)
    {
        cout << "Welcome back " << fileName << "!" <<endl;
        infile.close();
        outfile.open((fileName + ".txt").c_str());
    }
    else
    {
        cout << "Your user name does not exist, but a new user & file shall be created for you." << endl";
        outfile.open ((fileName + ".txt").c_str());
        outfile << "Writing to the newly created file";
        //outfile.close();
    }
    mainMenu(fileName);

    return fileName;
}

string menu()
{
    string userName;
    //string userNameUpper;
    cout << "*************************************" << endl;
    cout << "***** WELCOME TO THE MATH GAME! *****" << endl;
    //cout << "*************************************" << endl;
    cout << "*Test your knowledge of arithmatic. *" << endl;
    cout << "*************************************" << endl;
    cout << "*    PLEASE ENTER YOUR USER NAME    *" << endl;
    cout << "*                                   *" << endl;
    cout << "*************************************" << endl;
    cout << "   User Name: ";cin >> userName; cout <<endl;
    
    //figure out how to convert userName to upper case to make sure any case
    //is acceptable for file name.

    userFile(userName);


}


int main()
{
    menu();
    //const string USERNAME = menu(); 
    //cout << USERNAME;
    //userFile();
    
    return 0;
}