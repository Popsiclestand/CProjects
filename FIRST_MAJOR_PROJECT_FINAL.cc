// The Math Program lets users earn money while answering simple arithmetic problems

//libraries being used
#include <iostream>
#include <string>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include <math.h>
#include <iomanip>
#include <sstream>

//setting namespace to be used
using namespace std;

//function prototype declarations
void credits();
void retrieveStats(string& userName);
void validateUserResponse(string& userEntry);
int validateUserResponse2(string userEntry); //this does not utilize pass by reference because the data type of the variable that needs to be returned is different than the data type of the parameter for the function
void displayStats(string& userName);
void menu(string& userName);
void generateAddition(string& userName);
void generateDivision(string& userName);
void generateSubtraction(string& userName);
void generateMultiplication(string& userName);
void quit();
void updateStats(string& userName, bool& status);

//global constants declarations
const double ADD_MONEY = 0.05;
const double SUBTRACT_MONEY = 0.03;

//main function that calls all of the other functions.
int main()
{
    string name = "";
    credits();
    cout << "\n";
    retrieveStats(name);
    displayStats(name);
    menu(name);
    
    return 0;
}

void credits()//prints the welcoming message for user and first instructions to enter user name
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


//this function opens files for users that exist and creates files for users that do not, populating that file with default data
void retrieveStats(string& userName)
{
    //string temp;
    ifstream inputUserNameInFile;
    ofstream outputUserNameOutFile;
    string correctAnswers = "0";
    string wrongAnswers = "0";
    string moneyEarned = "0.00";
    
    cout << ">>";
    getline(cin,userName);
    cout << "\n\n\n";
    
    validateUserResponse(userName);
    //userName = temp;
    
    inputUserNameInFile.open((userName + ".txt").c_str());
    
    if (inputUserNameInFile)
    {
        inputUserNameInFile.close();
    }
    else
    {
        cout << "Your user name does not exist, but one shall be created for you." << endl;
        
        outputUserNameOutFile.open((userName + ".txt").c_str());

        outputUserNameOutFile << correctAnswers << "\n" << wrongAnswers << "\n" << moneyEarned;
        
        outputUserNameOutFile.close();
    }
    
}

//module to validate the user's responses to check for spaces, and special characters
void validateUserResponse(string& userEntry)
{
    int counter = 0;
    int stringLength;
    
    stringLength = userEntry.length();
    
    while (counter < stringLength || stringLength == 0)
    {
        if (!isalpha(userEntry[counter]))
        {
            cout << "Special characters are not allowed. Only numbers and letters. Please try again.\n";
            cout << ">>";
            getline(cin,userEntry);
            stringLength = userEntry.length();
            counter = 0;
        }
        else
        {
            counter++;
        }
    }
    
}

//function that displays saved user stats from file
void displayStats(string& userName)
{
    ifstream statsInfile;
    ofstream statsOutfile;
    string userStatsTitles[3] = {"CORRECT ANSWERS: ", "WRONG ANSWERS: ", "MONEY EARNED: $"};
    int counter = 0;
    string data;
    string correctAnswerIn;
    string wrongAnswerIn;
    string moneyEarnedIn;
    string tempDataIn[3] = {};
    double moneyEarnedDouble;
    
    cout << "\nCurrent Statistics For " << userName << endl;
    cout << "**********************************************" << endl;
    
    statsInfile.open((userName + ".txt").c_str());
    while (!statsInfile.eof())
    {
        while(getline(statsInfile,data))
        {
            tempDataIn[counter] = data;
            counter++;
        }
    }
    statsInfile.close();
    
    correctAnswerIn = tempDataIn[0];
    wrongAnswerIn = tempDataIn[1];
    moneyEarnedIn = tempDataIn[2];
    
    moneyEarnedDouble = stod(moneyEarnedIn);
    
    cout << userStatsTitles[0] << correctAnswerIn << "\n" << userStatsTitles[1] << wrongAnswerIn << endl;
    cout << userStatsTitles[2];
    cout << fixed << showpoint;
    cout << setprecision(2);
    cout << moneyEarnedDouble << endl;
    
}

//main menu that presents options
void menu(string& userName)
{
    string continu;
    string selection = "";
    int testSelection;
    int temp = 0;
    
    while (selection != "6")
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
        temp = validateUserResponse2(selection);
        
        switch (temp)
        {
            case 1:
                generateAddition(userName);
                break;
                
            case 2:
                generateSubtraction(userName);
                break;
                
            case 3:
                generateMultiplication(userName);
                break;
                
            case 4:
                generateDivision(userName);
                break;
                
            case 5:
                displayStats(userName);
                break;
                
            case 6:
                quit();
                break;
                
            default:
                cout << "Invalid input. No special characters OR SPACES. Try again!\n" << endl;
                break;
                
        }
    
    }
    
}

//generates addition problem and answer
void generateAddition(string& userName)
{
    int unsigned seedOne = time(0);
    int number1;
    int number2;
    string userNumber;
    int convertedNumber;
    int answer=0;
    bool correct;
    int temp;
    
    srand(seedOne);
    number1 = rand() % 30;
    number2 = rand() % 30;
    
    answer = number1 + number2;
    
    cout << number1 << " + " << number2 << " = ";
    getline(cin,userNumber);
    
    
    temp = validateUserResponse2(userNumber);
    
    if (temp == answer)
    {
        cout << "*****CORRECT!*****\n\n";
        correct = true;
    }
    else
    {
        cout << "*****INCORRECT!*****\n\n";
        correct = false;
    }
    updateStats(userName,correct);
    
}

//generates division problem and answer
void generateDivision(string& userName)
{
    int unsigned seed = time(0);
    int number1=0;
    int number2=0;
    string userNumber;
    int answer;
    bool correct;
    int temp;
    int convertedNumber;
    srand(seed);
    
    while (number2 == 0 || number2 > number1 || number1%number2 != 0) //makes sure there is no divide by 0 error and also that answers are only positive integers
    {
        number1 = rand() % 100;
        number2 = rand() % 10;
    }
    
    answer = number1/number2;
    
    cout << number1 << " / " << number2 << " = ";
    getline(cin,userNumber);
    
    temp = validateUserResponse2(userNumber);

    cout << endl;
    if (temp == answer)
    {
        cout << "*****CORRECT!*****\n\n";
        correct = true;
    }
    else
    {
        cout << "*****INCORRECT!*****\n\n";
        correct = false;
    }
    updateStats(userName,correct);
    
}

//generates multiplication problem and answer
void generateMultiplication(string& userName)
{
    int unsigned seedOne = time(0);
    int number1;
    int number2;
    string userNumber;
    int temp;
    int answer=0;
    bool correct;
    int convertedNumber;
    
    srand(seedOne);
    number1 = rand() % 10;
    number2 = rand() % 10;
    
    answer = number1 * number2;
    
    cout << number1 << " x " << number2 << " = ";
    getline(cin,userNumber);
    
    temp = validateUserResponse2(userNumber);
    
    if (temp == answer)
    {
        cout << "*****CORRECT!*****\n\n";
        correct = true;
    }
    else
    {
        cout << "*****INCORRECT!*****\n\n";
        correct = false;
    }
    updateStats(userName,correct);
    
}

//generates subtraction problem and answer
void generateSubtraction(string& userName)
{
    int unsigned seedOne = time(0);
    int number1=0;
    int number2=0;
    string userNumber;
    int temp;
    int answer=0;
    bool correct;
    int convertedNumber;
    
    srand(seedOne);
    number1 = rand() % 100;
    number2 = rand() % 100;
    
    while (number1 < number2)
    {
        number1 = rand() % 100;
        number2 = rand() % 100;
    }
    answer = number1 - number2;
    
    cout << number1 << " - " << number2 << " = ";
    getline(cin,userNumber);
    
    temp = validateUserResponse2(userNumber);

    
    if (temp == answer)
    {
        cout << "*****CORRECT!*****\n\n";
        correct = true;
    }
    else
    {
        cout << "*****INCORRECT!*****\n\n";
        correct = false;
    }
    updateStats(userName,correct);
    
}

//function to exit the program
void quit()
{
    cout << "Thank you for playing THE MATH GAME! See you soon!" << endl;
    exit(EXIT_SUCCESS);
}

//validates user response for different selections (for ints only)
int validateUserResponse2(string userEntry)
{
    string response = userEntry;
    int integerResponse = 0;
    int counter = 0;
    int stringLength;
    
    stringLength = response.length();
    
    while (counter < stringLength || stringLength == 0)
    {
        if (!isdigit(response[counter]))
        {
            cout << "Numbers only. Choose from selections listed. No spaces. Please try again.\n";
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
    integerResponse = stoi(response);
    return integerResponse;
    
}

//function to update user files/stats depending on user's correct answer
void updateStats(string& userName, bool& status)
{
    ifstream updateStatsIn;
    ofstream updateStatsOut;
    int counter = 0;
    string data;
    string infoTemp[3] = {};
    string correctAnswerIn;
    string wrongAnswerIn;
    string moneyEarnedIn;
    int correctAnswerCalculate;
    int wrongAnswerCalculate;
    double moneyEarnedCalculate;
    string correctAnswerOut;
    string wrongAnswerOut;
    string moneyEarnedOut;
    
    
    updateStatsIn.open((userName + ".txt").c_str());
    while (!updateStatsIn.eof())
    {
        while(getline(updateStatsIn,data))
        {
            infoTemp[counter] = data;
            counter++;
        }

    }
    updateStatsIn.close();
    
    correctAnswerIn = infoTemp[0];
    wrongAnswerIn = infoTemp[1];
    moneyEarnedIn = infoTemp[2];
    
    correctAnswerCalculate = stoi(correctAnswerIn);
    wrongAnswerCalculate = stoi(wrongAnswerIn);
    moneyEarnedCalculate = stod(moneyEarnedIn);
    
    if (status == true)
    {
        correctAnswerCalculate++;
        moneyEarnedCalculate = moneyEarnedCalculate + ADD_MONEY;
    }
    else
    {
        wrongAnswerCalculate++;
        moneyEarnedCalculate = moneyEarnedCalculate - SUBTRACT_MONEY;
    }
    
    correctAnswerOut = to_string(correctAnswerCalculate);
    wrongAnswerOut = to_string(wrongAnswerCalculate);
    moneyEarnedOut = to_string(moneyEarnedCalculate);
    
    updateStatsOut.open((userName + ".txt").c_str());
    
    updateStatsOut << correctAnswerOut << "\n" << wrongAnswerOut << "\n" << moneyEarnedOut << "\n";
    
    updateStatsOut.close();

}