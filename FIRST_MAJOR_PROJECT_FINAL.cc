// This program lets the user earn money while playing a math game
#include <iostream>
#include <string>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include <math.h>
#include <iomanip>
#include <sstream>

using namespace std;

void credits();
string retrieveStats();
string validateUserResponse(string userEntry);
string validateUserResponse2(string userEntry);
void displayStats(string displayStatsUser);
void menu(string menuUser);
void generateAddition(string userName);
void generateDivision();
void generateSubtraction();
void generateMultiplication();
void quit();
void updateStats(string userName, bool adjustStat);

//global constants
const double ADD_MONEY = 0.05;
const double SUBTRACT_MONEY = 0.03;


int main()
{
    string name;
    credits();
    cout << "\n";
    name = retrieveStats();
    displayStats(name);
    //displayStats(retrieveStats());
    cout << "\n\n\n";
    menu(name);
    
    return 0;
}

void credits()
{
    cout << "**************************************" << endl;
    cout << "***** WELCOME TO THE MATH GAME! ******" << endl;
    cout << "*****   By Tiffany McMichael    ******" << endl;
    cout << "**************************************" << endl;
    cout << "**   PLEASE ENTER YOUR USER NAME    **" << endl;
    cout << "**   and press <ENTER>.             **" << endl;
    cout << "**************************************" << endl;
    cout << "**************************************" << endl;
}


string retrieveStats()
{
    string inputUserName = "";
    string temp;
    ifstream inputUserNameInFile;
    ofstream outputUserNameOutFile;
    int defaultData[3] = {0,0,0};
    int counter = 0;
    
    cout << ">>";
    getline(cin,inputUserName);
    cout << "\n\n\n";
    
    temp = validateUserResponse(inputUserName);
    inputUserName = temp;
    
    inputUserNameInFile.open((inputUserName + ".txt").c_str());
    
    if (inputUserNameInFile)
    {
        inputUserNameInFile.close();
    }
    else
    {
        cout << "Your user name does not exist, but one shall be created for you." << endl;
        cout << endl;
        outputUserNameOutFile.open((inputUserName + ".txt").c_str());
        
        for (counter = 0; counter <= 2 ; counter++)
        {
            outputUserNameOutFile << defaultData[counter] << "\n";
        }
        
        outputUserNameOutFile.close();
    }
    
    return inputUserName;
}

//user validation for string entries ONLY!! Checks for the use of special characters
//could possibly add in the uppercase conversion as well
string validateUserResponse(string userEntry)
{
    string response = userEntry;
    int counter = 0;
    int stringLength;
    
    stringLength = response.length();
    
    while (counter < stringLength || stringLength == 0)
    {
        if (!isalpha(response[counter]))
        {
            cout << "Special characters are not allowed. Only numbers and letters. Please try again.\n";
            cout << ">>";
            getline(cin,response);
            stringLength = response.length();
            counter = 0;
        }
        else
        {
            counter++;
        }
    }
    return response;
    
}

//function that displays saved user stats
void displayStats(string displayStatsUser)
{
    string userNameStats = displayStatsUser; //pulls from the return value of initMenu
    ifstream statsInfile;
    ofstream statsOutfile;
    string userStatsTitles[3] = {"CORRECT ANSWERS: ", "WRONG ANSWERS: ", "MONEY EARNED: $"};
    int counter = 0;
    string data;
    //int strLength = userNameStats.length();
    
    cout << "\n\nCurrent Statistics For " << userNameStats << endl;
    cout << "***********************************" << endl;
    
    statsInfile.open((userNameStats + ".txt").c_str());
    while (!statsInfile.eof())
    {
        while(getline(statsInfile,data))
        {
            cout << userStatsTitles[counter] << data << "\n";
            counter++;
        }
    }
    statsInfile.close();
    cout << "\n\n";
    
}

//main menu that presents options
void menu(string menuUser)
{
    string user = menuUser;
    cout << user << endl;
    string selection;
    int temp = 0;
    
    while (selection != "6" && temp != 6)
    {
        
        cout << "**********************************************" << endl;
        cout << "**********      THE MATH GAME!      **********" << endl;
        cout << "**********************************************" << endl;
        cout << "**********************************************" << endl;
        cout << "*  What kind of math problem would you like? *" << endl;
        cout << "*          (1) Addition                      *" << endl;
        cout << "*          (2) Subtraction                   *" << endl;
        cout << "*          (3) Multiplication                *" << endl;
        cout << "*          (4) Division                      *" << endl;
        cout << "*          (5) Check Stats                   *" << endl;
        cout << "*          (6) Quit                          *" << endl;
        cout << "**********************************************" << endl;
        cout << ">>";
        
        getline(cin,selection);
        validateUserResponse2(selection);
        temp = stoi(selection);
        
        switch (temp)
        {
            case 1:
                generateAddition(user);
                break;
                
            case 2:
                generateSubtraction();
                break;
                
            case 3:
                generateMultiplication();
                break;
                
            case 4:
                generateDivision();
                break;
            case 5:
                displayStats(user);
                break;
                
            case 6:
                quit();
                break;
                
            default:
                cout << "Invalid input. No special characters OR SPACES. Try again!\n" << endl;
                
        }
        
    }
}

//generates addition problem and answer
void generateAddition(string userName)
{
    int unsigned seedOne = time(0);
    int number1;
    int number2;
    string userNumber;
    int convertedNumber;
    int answer=0;
    bool correct;
    string temp;
    string user = userName;
    
    srand(seedOne);
    number1 = rand() % 1000;
    number2 = rand() % 1000;
    
    answer = number1 + number2;
    
    cout << number1 << " + " << number2 << " = ";
    getline(cin,userNumber);
    
    temp = validateUserResponse2(userNumber);
    convertedNumber = atoi(temp.c_str());
    
    if (convertedNumber == answer)
    {
        cout << "*****CORRECT!*****\n\n";
        correct = true;
    }
    else
    {
        cout << "*****INCORRECT!*****\n\n";
        correct = false;
    }
    updateStats(user,correct);
    
}

//generates division problem and answer
void generateDivision()
{
    int unsigned seed = time(0);
    int number1=0;
    int number2=0;
    string userNumber;
    int answer;
    bool correct;
    string temp;
    int convertedNumber;
    srand(seed);
    
    while (number2 == 0 || number2 > number1 || number1%number2 != 0)
    {
        number1 = rand() % 1000;
        //cout << number1 << endl; //printing for debugging
        number2 = rand() % 1000;
        //cout << number2 << endl; //printing for debugging
    }
    
    answer = number1/number2;
    
    cout << number1 << " / " << number2 << " = ";
    getline(cin,userNumber);
    
    temp = validateUserResponse2(userNumber);
    convertedNumber = atoi(temp.c_str());

    cout << endl;
    if (convertedNumber == answer)
    {
        cout << "*****CORRECT!*****\n\n";
        correct = true;
    }
    else
    {
        cout << "*****INCORRECT!*****\n\n";
        correct = false;
    }
    
}

//generates multiplication problem and answer
void generateMultiplication()
{
    int unsigned seedOne = time(0);
    
    int number1;
    int number2;
    string userNumber;
    string temp;
    int answer=0;
    bool correct;
    int convertedNumber;
    
    srand(seedOne);
    number1 = rand() % 1000;
    number2 = rand() % 1000;
    
    answer = number1 * number2;
    
    cout << number1 << " x " << number2 << " = ";
    getline(cin,userNumber);
    
    temp = validateUserResponse2(userNumber);
    convertedNumber = atoi(temp.c_str());
    
    if (convertedNumber == answer)
    {
        cout << "*****CORRECT!*****\n\n";
        correct = true;
    }
    else
    {
        cout << "*****INCORRECT!*****\n\n";
        correct = false;
    }
    
}

//generates subtraction problem and answer
void generateSubtraction()
{
    int unsigned seedOne = time(0);
    
    int number1;
    int number2;
    string userNumber;
    string temp;
    int answer=0;
    bool correct;
    int convertedNumber;
    
    srand(seedOne);
    while (number1<number2)
    {
        number1 = rand() % 1000;
        number2 = rand() % 1000;
    }
    answer = number1 - number2;
    
    cout << number1 << " - " << number2 << " = ";
    getline(cin,userNumber);
    
    temp = validateUserResponse2(userNumber);
    convertedNumber = atoi(temp.c_str());
    
    if (convertedNumber == answer)
    {
        cout << "*****CORRECT!*****\n\n";
        correct = true;
    }
    else
    {
        cout << "*****INCORRECT!*****\n\n";
        correct = false;
    }
    
}

void quit()
{
    cout << "Thank you for playing THE MATH GAME! See you soon!" << endl;
}

//validates user response for different selections
string validateUserResponse2(string userEntry)
{
    string response = userEntry;
    int counter = 0;
    int stringLength;
    
    stringLength = response.length();
    
    while (counter < stringLength || stringLength == 0)
    {
        if (!isdigit(response[counter]))
        {
            cout << "Numbers only. No spaces. Please try again.\n";
            cout << ">> ";
            getline(cin,response);
            stringLength = response.length();
            counter = 0;
        }
        else
        {
            counter++;
        }
    }
    return response;
    
}


void updateStats(string userName, bool adjustStat)
{
    string user = userName;
    bool status = adjustStat;
    ifstream updateStatsIn;
    ofstream updateStatsOut;
    
}