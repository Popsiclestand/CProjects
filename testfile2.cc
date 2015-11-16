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
bool generateDivision();
bool generateSubtraction();
bool generateMultiplication();
void updateStats(string updateStatsUser, bool moneyEarned);


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
            //break;
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
    
    
    //while (valid == 0)
    //{
        if(!isdigit(response))
        {
            cout << "Numbers only! Please try again.\n";
            cout << ">> ";
            cin >> response;
            cin.clear();
            cin.ignore();
            //counter++;
        }
        else
        {
            valid = 1;
        }
    //}
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
    bool money;
    
    while (selection != 5)
    {
        
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
            cout << "Quit function" << endl;
            break;
            
            default:
            cout << "Error, quitting program.\n" << endl;
    
        }
        
        updateStats(menuUser,money);
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
    
    //validateUserResponse(userNumber);
    
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

//generates division problem and answer
bool generateDivision()
{
    int unsigned seedOne = time(0);

    double number1=0;
    double number2=0;
    int userNumber;
    double answer;
    bool correct;
    
    while (number2 == 0 || number1 < number2)
    {
        srand(seedOne);
        number1 = rand() % 100;
        //cout << number1 << endl; //printing for debugging
        number2 = rand() % 100;
        //cout <<number2<<endl; //printing for debugging
    }
    
    answer = number1 / number2;
    cout << answer << endl;
    
    cout << "(Round up to the nearest integer)\n" << number1 << " / " << number2 << " = ";
    cin >> userNumber;
    cin.clear();
    cin.ignore();
    
    //validateUserResponse(userNumber);
    
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

//generates multiplication problem and answer
bool generateMultiplication()
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
    
    answer = number1 * number2;
    
    cout << number1 << " x " << number2 << " = ";
    cin >> userNumber;
    cin.clear();
    cin.ignore();
    
    //validateUserResponse(userNumber);
    
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

//generates subtraction problem and answer
bool generateSubtraction()
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
    
    answer = number1 - number2;
    
    cout << number1 << " - " << number2 << " = ";
    cin >> userNumber;
    cin.clear();
    cin.ignore();
    
    //validateUserResponse(userNumber);
    
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

void updateStats(string updateStatsUser, bool moneyEarned)
{
    string userNameStats = updateStatsUser; //pulls from the return value of initMenu
    bool money = moneyEarned;
    ifstream statsInfile;
    ofstream statsOutfile;
    string userStats[3] = {}; //holds an array of user stats pulled from file
    string userStatsTitles[3] = {"Number of correct answers: ", "Number of wrong answers: ", "Amount of money earned: "};
    int counter = 0;
    string data;
    int strLength = userNameStats.length();

    statsInfile.open((userNameStats + ".txt").c_str());
     while (!statsInfile.eof()) //somehow use this to read the contents of the file into the 3 item array up there
        {
            while(getline(statsInfile,data))
            {
                //userStats[counter] << data << "\n";
                userStats[counter] << data << "\n";
                counter++;
            }
        }
    statsInfile.close();
    
    
    //construct a second while statement to write to the file with the values stored in the userStats array
    //if/else statement that adds or subtracts from the third value using the global constants depending on the value of money
    //if/else statement that adds 1 to either of the first two values depending on the value of money
    //these two statements will of course be combined
    
}