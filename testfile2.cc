// This program lets the user enter a filename.
#include <iostream>
#include <string>
#include <fstream>
#include <ctime>
#include <cstdlib>

using namespace std;


//void displayStats(string displayStatsUser);
string retrieveStats();
string validateUserResponse(string userEntry);
char validateUserResponse(char userEntry);
int validateUserResponse(int userEntry);
void displayStats(string displayStatsUser);
void menu(string menuUser);
bool generateAddition();

int main()
{
    string name;
    name = retrieveStats();
    displayStats(name);
    cout << "\n\n";
    menu(name);
   return 0;
}


// void displayStats(string displayStatsUser)
// {
//     string userNameStats = displayStatsUser; //pulls from the return value of initMenu
//     ifstream statsInfile;
//     ofstream statsOutfile;
//     int userStats[3] = {}; //holds an array of user stats pulled from file
//     string userStatsTitles[3] = {"Number of correct answers: ", "Number of wrong answers: ", "Amount of money earned: "};
//     int counter = 0;
//     int data;
    
//     cout << "Current Statistics for " << userNameStats << ":" << endl;
//     cout << "***********************************" << endl;
    
//     statsInfile.open((userNameStats + ".txt").c_str());
//     while (!statsInfile.eof())
//        {
//             getline(statsInfile,userStats[counter]);
//             counter++;
//             cout << data << endl;
//        }
//     statsInfile.close();
    
// }



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
            cout << "USER NAME: ";
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
char validateUserResponse(char userEntry) //needs work on logic
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

//user validation //THIS IS BROKEN!!!
int validateUserResponse(int userEntry)
{
    int response = userEntry;
    bool valid = 0;
    int counter = 0;
    int stringLength;
    
    
    while (valid == 0)
    {
        if(!isdigit(response))
        {
            cout << "Numbers only! Please try again.\n";
            cout << ">> ";
            cin >> response;
            cin.clear();
            cin.ignore();
            counter++;
        }
        else
        {
            valid = 1;
            break;
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
                //userStats[counter] << data << "\n";
                cout << userStatsTitles[counter] << data << "\n";
                counter++;
            }
        }
    statsInfile.close();
    
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
        cout << generateAddition();
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

    int number1;
    int number2;
    int userNumber;
    int answer=0;
    bool correct;
    
    srand(seedOne);
    number1 = rand() % 100;
    number2 = rand() % 100;
    
    answer = number1 + number2;
    
    cout << number1 << " + " << number2 << " = ";
    cin >> userNumber;
    cin.clear();
    cin.ignore();
    
    validateUserResponse(userNumber);
    
    if (userNumber == answer)
    {
        cout << "CORRECT!";
        correct = true;
    }
    else
    {
        cout << "INCORRECT!";
        correct = false;
    }
  
    return correct;

}