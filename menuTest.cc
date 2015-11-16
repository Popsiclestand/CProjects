
#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>
#include <boost/algorithm/string.hpp>

using namespace std;

void stats()
{
    
}


//main menu that presents options
bool menu(string menuUser)
{
    string user = menuUser;
    char selection;
    bool money;

    cout << "**********************************************" << endl;
    cout << "**********      THE MATH GAME!      **********" << endl;
    cout << "**********************************************" << endl;
    cout << "**********************************************" << endl;
    cout << "*  What kind of math problem would you like? *" << endl;
    cout << "*          (1) Addition                      *" << endl;
    cout << "*          (2) Subtraction                   *" << endl;
    cout << "*          (3) Multiplication                *" << endl;
    cout << "*          (4) Division                      *" << endl; //remember to protect from divide by zero error for this selection
    cout << "*          (5) Quit                          *" << endl;
    cout << "**********************************************" << endl;
    cout << ">>";
    
    cin >> selection;
    cin.clear();
    cin.ignore();
    selection = validateUserResponse(selection);
    cout << selection <<endl;
    
    switch (selection)
    {
        case '1':
        money = generateAddition();
        break;
        
        case '2':
        money = generateSubtraction();
        break;
        
        case '3':
        money = generateMultiplication();
        break;
        
        case '4':
        money = generateDivision();
        break;
        
        case '5':
        
        break;
        
        default:
        cout << "Error, quitting program.\n" << endl;

    }
    return money;
    
}

string userFile(string fN)
{
    //declare variables
    
    ifstream infile; //this will be the variable to open files that already exist and read data from them
    ofstream outfile; //this will be the variable to create non-existent files and write to them
    string fileName = fN; //this variable takes on the value of the passed argument from the menu function
    string data; //to hold data from file to display stats

    infile.open((fileName + ".txt").c_str()); //concat the user defined name to open/create a text file for the user.
    
    if (infile)
    {
        cout << "              Let's play, " << endl;
        cout << "                 " << fileName << "!" << endl;
        infile.close();
        outfile.open((fileName + ".txt").c_str());
        mainMenu();
        
    }
    else
    {
        cout << "Your user name does not exist, but a new user & file shall be created for you." << endl;
        cout << endl;
        outfile.open ((fileName + ".txt").c_str());
        outfile << "Writing to the newly created file\n";
        cout << "Current Statistics:" << endl;
        outfile.close();
        infile.open((fileName + ".txt").c_str());
        while (!infile.eof())
        {
            getline(infile,data);
            cout << data << endl;
        }
        
        mainMenu();
        
    }


    return fileName;
}

string menu()
{
    string userName;
    //string userNameUpper;
    cout << "*************************************" << endl;
    cout << "***** WELCOME TO THE MATH GAME! *****" << endl;
    cout << "*Test your knowledge of arithmetic. *" << endl;
    cout << "*************************************" << endl;
    cout << "*    PLEASE ENTER YOUR USER NAME    *" << endl;
    //cout << "*                                   *" << endl;
    cout << "*************************************" << endl;
    cout << "   User Name: ";cin >> userName; cout <<endl;
    
    //figure out how to convert userName to upper case to make sure any case
    //is acceptable for file name.
    cout << string(50, '\n');
    userFile(userName);


}


int main()
{
    menu();
    //userFile(MAIN_USER);
    //mainMenu();
    //stats();
    
    return 0;
}