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
string validateUserResponse();
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
    displayStats();
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

//takes input of name, checks whether a file exists, creates a file if one does not exist
//if file is new, it creates a specific set of null data for the new user in the file and closes

string retrieveStats()
{
    string inputUserName = "";
    ifstream inputUserNameInFile;
    ofstream outputUserNameOutFile;
    
    cout << "USER NAME: ";
    cin >> inputUserName;
    
    inputUserNameInFile.open((inputUserName + ".txt").c_str());
    
    if (inputUserNameInFile)
    {
        inputUserNameInFile.close();
    }
    else
    {
        cout << "Your user name does not exist, but one shall be created for you." << endl;
        cout << endl;
        outputUserNameInFile.open((inputUserName + ".txt").c_str());
        outputUserNameOutFile.close();
    }
    
    return inputUserName;
}

//function that displays saved user stats
void displayStats(string displayStatsUser)
{
    string userNameStats; //pulls from the return value of initMenu
    ifstream statsInfile;
    ofstream statsOutfile;
    string userStats[3] = {}; //holds an array of user stats pulled from file
    string userStatsTitles[3] = {};
    
    cout << "prints out user stats using a loop that cycles through parallel arrays"
    
}

//user validation
string validateUserResponse()
{
    string validReponse;
    string invalidResponse;
    
    cout << "validates that user has entered an alphanumerical character. this is the very basic of user validation. functions will also have their own input specific validation"
    
    return validReponse;
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
