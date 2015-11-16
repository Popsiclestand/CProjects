//problems I already see. The arrays are strings thus there may need to be some type 
//of typecasting for the const to be used

#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>
#include <ctime>
//#include <boost/algorithm/string.hpp>

using namespace std;

//function prototype declarations
void credits();
string retriveStats();
void menu(string menuUser);
string validateUserResponse(string userEntry);
char validateUserResponse(char userEntry);
bool generateAddition();
bool generateSubtraction();
bool generateMultiplication();
bool generateDivision();
void quit(userQuit);
void displayStats(string displayStatsUser);
void updateStats(string updateStatsUser);


//global constants declarations
const double RIGHT_ANSWER = 0.05;
const double WRONG_ANSWER = 0.03;


int main()
{
    string name;
    credits();
    cout << string(50, '\n'); //clears screen for the init menu
    retrieveStats();
    cout << string(50, '\n'); //clears screen for the menu
    name = retrieveStats();
    displayStats(name);
    cout << "\n\n";
    menu(name);
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
    string temp;
    ifstream inputUserNameInFile;
    ofstream outputUserNameOutFile;
    int defaultData[3] = {0,0,0};
    int counter = 0;
    
    cout << "USER NAME: ";
    cin >> inputUserName;
    cin.clear();
    cin.ignore();
    
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

//function that displays saved user stats
void displayStats(string displayStatsUser)
{
    string userNameStats = displayStatsUser; //pulls from the return value of initMenu
    ifstream statsInfile;
    ofstream statsOutfile;
    string userStats[3] = {}; //holds an array of user stats pulled from file
    string userStatsTitles[3] = {"Number of correct answers: ", "Number of wrong answers: ", "Amount of money earned: "};
    int counter = 0;
    string data;
    int strLength = userNameStats.length();
    
    cout << "Current Statistics for " << userNameStats << endl;
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
    
}

//user validation
string validateUserResponse(string userEntry) //needs work on logic
{
    string response = userEntry;
    bool valid = 0;
    int counter = 0;
    int stringLength;
    
    stringLength = response.length();
    
    while (counter < stringLength || stringLength == 0)
    {
        if (!isalpha(response[counter]))
        {
            cout << "Special characters are not allowed. Only numbers and letters. Please try again.\n";
            cout << ">> ";
            cin >> response;
            cin.clear();
            cin.ignore();
            counter = 0;
        }
        else
        {
            counter++;
        }
    }
    return response;
    
}

//user validation
char validateUserResponse(char userEntry)
{
    char response = userEntry;
    bool valid = 0;
    int counter = 0;
    int stringLength;
    
    
    while (counter == 0)
    {
        if (!isdigit(response))
        {
            cout << "Special characters are not allowed. Please try again.\n";
            cout << ">> ";
            cin >> response;
            cin.clear();
            cin.ignore();
            counter = 0;
        }
        else
        {
            counter++;
            break;
        }
    }
    return response;
    
}


//main menu that presents options
void menu(string menuUser)
{
    string user = menuUser;
    char selection;

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
    
    selection = validateUserResponse(selection);
    
    switch (selection)
    {
        case '1':
        bool generateAddition();
        break;
        
        case '2':
        cout << "Subtraction Function Here" << endl;
        break;
        
        case '3':
        cout << "Multiplication Function Here" << endl;
        break;
        
        case '4':
        cout << "Dividsion Function Here" << endl;
        break;
        
        case '5':
        cout << "Quit function" << endl;
        break;

    }
    
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
    cout << ">>" << endl;
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
