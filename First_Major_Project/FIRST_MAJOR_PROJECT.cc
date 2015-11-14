//problems I already see. The arrays are strings thus there may need to be some type 
//of typecasting for the const to be used

#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>
//#include <boost/algorithm/string.hpp>

using namespace std;

//function prototype declarations
void credits();
string retriveStats();
string menu();
void validateUserResponse(string userEntry);
bool generateAddition();
bool generateSubtraction();
bool generateMultiplication();
bool generateDivision();
void quit(userQuit);
void displayStats(displayStatsUser);
void updateStats(updateStatsUser);


//global constants declarations
const double RIGHT_ANSWER = 0.05;
const double WRONG_ANSWER = 0.03;


int main()
{
    credits();
    cout << string(50, '\n'); //clears screen for the init menu
    retrieveStats();
    cout << string(50, '\n'); //clears screen for the menu
    displayStats(retrieveStats());
    cout << endl;
    menu();
    updateStats(inputUserName,correct);
    
    return 0;
}

//credits fucntion displays instructions for the game asks for user to input username value
void credits()
{
    cout << "*************************************" << endl;
    cout << "***** WELCOME TO THE MATH GAME! *****" << endl;
    cout << "*Test your knowledge of arithmetic. *" << endl;
    cout << "*************************************" << endl;
    cout << "*    PLEASE ENTER YOUR USER NAME    *" << endl;
    cout << "*************************************" << endl;
    cout << "*************************************" << endl;
}

//takes input of user's name, checks whether a file exists, creates a file if one does not exist
//if file is new, it generates a set of default values for the new user in the file and closes
//this module has been tested and works!
//the only advanced addition i would like is to convert all to upper case so that returning
//users can access their previous stats/file even if they make mistakes in case.
//probably need to include input validation in case of the use of special characters

string retrieveStats()
{
    string inputUserName = "";
    ifstream inputUserNameInFile;
    ofstream outputUserNameOutFile;
    int defaultData[3] = {0,0,0};
    int counter = 0;
    
    cout << "USER NAME: ";
    cin >> inputUserName;
    cin.clear();
    cin.ignore();
    
    validateUserResponse(inputUserName);
    
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

//function that displays saved user stats
void displayStats(string displayStatsUser)
{
    string userNameStats = displayStatsUser; //pulls from the return value of initMenu
    ifstream statsInfile;
    ofstream statsOutfile;
    int userStats[3] = {}; //holds an array of user stats pulled from file
    string userStatsTitles[3] = {"Number of correct answers: ", "Number of wrong answers: ", "Amount of money earned: "};
    int counter = 0;
    int data;
    
    cout << "Current Statistics for " << userNameStats << ":" << endl;
    cout << "***********************************" << endl;
    
    statsInfile.open((userNameStats + ".txt").c_str());
     while (!statsInfile.eof())
        {
            getline(statsInfile,userStats[counter]);
            counter++;
            cout << data << endl;
        }
    statsInfile.close();
    
}

//user validation
void validateUserResponse(string userEntry) //needs work on logic
{
    string response = userEntry;
    
    while (!isdigit(response))
    {
        cout << "Special characters are not allowed. Only numbers and letters. Please try again.\n";
    }
    
}


//main menu that presents options
bool menu()
{
    char userSelection;
    cout "generates menu and asks user for alphanumerical selection"
    validateUserResponse();
    //if user passes input validation, if/else statements and fail statements will select one of the following functions
    generateAddition();
    generateSubtraction();
    generateMultiplication();
    generateDivision();
    quit();
    
    return correct;
    
}


//generates addition problem and answer
bool generateAddition()
{
    int unsigned seedOne = time(0);
    int unsigned seedTwo = time(0);
    
    int number1;
    int number2;
    int userNumber;
    int answer;
    bool correct;
    
    srand(seedOne);
    srand(seedTwo);
    number1 = rand(seedOne) % 100;
    number2 = rand(seedTwo) % 100;
    
    answer = number1 + number2;
    
    cout << number1 << " + " << number2 << endl;
    cout << "Answer: " << endl;
    cin << userNumber
    
    if (isdigit(userNumber))
    {
        if (userNumber == answer)
        {
            correct = true;
        }
        else
        {
            correct = false;
        }
    }
    return correct;

}

bool generateSubtraction()
{
    int unsigned seedOne = time(0);
    int unsigned seedTwo = time(0);
    
    int number1;
    int number2;
    int userNumber;
    int answer;
    bool correct;
    
    srand(seedOne);
    srand(seedTwo);
    number1 = rand(seedOne) % 100;
    number2 = rand(seedTwo) % 100;
    
    answer = number1 - number2;
    
    cout << number1 << " - " << number2 << endl;
    cout << "Answer: " << endl;
    cin << userNumber
    
    if (isdigit(userNumber))
    {
        if (userNumber == answer)
        {
            correct = true;
        }
        else
        {
            correct = false;
        }
    }
    
    return correct;
    
}

bool generateMultiplication()
{
    int unsigned seedOne = time(0);
    int unsigned seedTwo = time(0);
    
    int number1;
    int number2;
    int userNumber;
    int answer;
    bool correct;
    
    srand(seedOne);
    srand(seedTwo);
    number1 = rand(seedOne) % 100;
    number2 = rand(seedTwo) % 100;
    
    answer = number1 * number2;
    
    cout << number1 << " x " << number2 << endl;
    cout << "Answer: " << endl;
    cin << userNumber
    
    if (isdigit(userNumber))
    {
        if (userNumber == answer)
        {
            correct = true;
        }
        else
        {
            correct = false;
        }
    }
    return correct;

}

bool generateDivision()
{
    int unsigned seedOne = time(0);
    int unsigned seedTwo = time(0);
    
    int number1;
    int number2;
    int userNumber;
    int answer;
    bool correct;
    
    while (number2 == 0) //protects for any divide by zero errors.
    {
        srand(seedOne);
        srand(seedTwo);
        number1 = rand() % 100;
        number2 = rand() % 100;
    }
    
    answer = number1 / number2;
    
    cout << number1 << " / " << number2 << endl;
    cout << "Answer: " << endl;
    cin << userNumber
    
    if (isdigit(userNumber))
    {
        if (userNumber == answer)
        {
            correct = true;
        }
        else
        {
            correct = false;
        }
    }
    
    return correct;
}

void quit(quitUser) //parameter gathered from initial launch of retrieveStats
{
    string userName = quitUser);
    cout << "Thank you for playing, " << userName; << "!";
}

void updateStats(string updateStatsUser, bool updateStatsAnswer)
{
    
}
