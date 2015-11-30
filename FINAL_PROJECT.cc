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
void splashScreen();
void askForUserNames(string& user1, string& user2);
void validateUserName(string& user);
void displayGrid(string& user1, string& user2);
void validatePlayersMove(string& playersMove, string& currentUser);
void playerMakeMove(string& currentUser, string& userMove);
void checkPositionAvailability (string grid1[], string grid2[],string grid3[], string& userMove, string& continu, int userTurn);


//main function that calls all of the other functions.
int main()
{
    string name1 = "";
    string name2 = "";
    splashScreen();
    cout << "\n";
    askForUserNames(name1, name2);
    cout << "\n\n";
    displayGrid(name1,name2);
    
    return 0;
}

void splashScreen()//prints the welcoming message for user and first instructions to enter user name
{
    cout << "**************************************" << endl;
    cout << "*****        TIC TAC TOE        ******" << endl;
    cout << "*****   By Tiffany McMichael    ******" << endl;
    cout << "**************************************" << endl;
    cout << "**        ENTER PLAYER NAMES        **" << endl;
    cout << "**        and press <ENTER>.        **" << endl;
    cout << "**************************************" << endl;
    cout << "**************************************" << endl;
}

void askForUserNames(string& user1, string& user2)
{
    cout << "Player1 >>";
    getline(cin, user1);
    validateUserName(user1);
    cout << "Thank you, " << user1 << endl;
    cout << "Player2 >>";
    getline(cin,user2);
    validateUserName(user2);
    cout << "Thank you, " << user2 << endl;
    
}

void validateUserName(string& user)
{
    int counter = 0;
    int stringLength;
    
    stringLength = user.length();
    
    while (counter < stringLength || stringLength == 0)
    {
        if (!isalpha(user[counter]))
        {
            cout << "No special characters. No spaces. Only letters. Please try again.\n";
            cout << ">>";
            getline(cin,user);
            stringLength = user.length();
            counter = 0;
        }
        else
        {
            counter++;
        }
    }
    
}

void displayGrid(string& user1, string& user2)
{
    const int ARRAY_SIZE = 3;
    string topRow[ARRAY_SIZE] = {"0","1","2"};
    string middleRow[ARRAY_SIZE] = {"3","4","5"};
    string bottomRow[ARRAY_SIZE] = {"6","7","8"};
    int user1Points = 0;
    int user2Points = 0;
    int userTurn = 1;
    string continu = "y";
    string userMove="";
    
    while (continu == "y" || continu == "Y")
    {
        cout << "TIC-TAC-TOE" << endl;
        cout << "  |-----|" << endl;
        cout << "  |";
        
        for (int count = 0; count < ARRAY_SIZE; count++)
        {
            cout << topRow[count] << "|";
        }
        cout << endl;
        cout << "  |";
        for (int count = 0; count < ARRAY_SIZE; count++)
        {
            cout << middleRow[count] << "|";
        }
        
        cout << endl;
        cout << "  |";
        
        for (int count = 0; count < ARRAY_SIZE; count++)
        {
            cout << bottomRow[count] << "|";
        }
        cout << endl;
        cout << "  |-----|" << endl;
    
        //this could be modularized into switch player at a later time.
        if(userTurn == 1)
        {
            cout << "\nIt is " << user1 << "'s turn; You are 'X'\nGive me your best move! Enter a free number." << endl;
            playerMakeMove(user1,userMove);
            userTurn = 2;
        }
        else
        {
            cout << "\nIt is " << user2 << "'s turn; You are 'Y'\nGive me your best move! Enter a free number." << endl;
            playerMakeMove(user2,userMove);
            userTurn = 1;
            
        }
        checkPositionAvailability(topRow,middleRow,bottomRow,userMove, continu, userTurn);
        
    }
    
}


void playerMakeMove(string& currentUser, string& userMove)
{
    string playersMove;
    cout << ">>";
    getline(cin,playersMove);
    validatePlayersMove(playersMove,currentUser);
    userMove = playersMove;
}

void validatePlayersMove(string& playersMove, string& currentUser) //this also needs to validate that int is between 0-9. could maybe use ascii value....?
{
    string move = playersMove;
    int counter = 0;
    int stringLength;
    
    stringLength = move.length();
    
    while (counter < stringLength || stringLength == 0)
    {
        if (!isdigit(move[counter]))
        {
            cout << "Choose from selections listed. No spaces. It is still " << currentUser << "'s turn.\n";
            cout << ">>";
            getline(cin,move);
            stringLength = move.length();
            counter = 0;
        }
        else
        {
            counter++;
        }
        
    }
    
}

void checkPositionAvailability (string grid1[], string grid2[], string grid3[], string& userMove, string& continu, int userTurn)
{
    //int integerMove = stoi(userMove);
    const int SIZE = 3;
    
    for (int count = 0; count < SIZE; count++)
    {
        if (grid1[count] == userMove)
        {
           if(userTurn == 1)
           {
               grid1[count] = "Y";
           }
            else
            {
                grid1[count] = "X";
            }
        }
        
    }
    
    for (int count = 0; count < SIZE; count++)
    {
        if (grid2[count] == userMove)
        {
            if(userTurn == 1)
            {
                grid2[count] = "Y";
            }
            else
            {
                grid2[count] = "X";
            }
        }
        
    }

    for (int count = 0; count < SIZE; count++)
    {
        if (grid3[count] == userMove)
        {
            if(userTurn == 1)
            {
                grid3[count] = "Y";
            }
            else
            {
                grid3[count] = "X";
            }
        }
        
    }
    
}