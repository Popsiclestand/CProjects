//TIC TAC TOE lets 2 human players compete to win at the classic game.

//libraries being used
#include <iostream>
#include <string>
//#include <fstream>
#include <ctime>
#include <cstdlib>
//#include <math>
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
void checkPositionAvailability (string grid1[], string grid2[],string grid3[], string& userMove, string& currentUser, int userTurn);
void validateInput(string& playAgain);
void checkWin(bool& itsATie, bool& whoWon, string grid1[], string grid2[], string grid3[]);




//main function that calls all of the other functions.
int main()
{
    string name1 = "";
    string name2 = "";
    string playAgain = "y";
    splashScreen();
    cout << "\n";
    askForUserNames(name1, name2);
    cout << "\n\n";
    while (playAgain == "y" || playAgain == "Y")
    {
        displayGrid(name1,name2);
        cout << "Would you like to play again? Type 'y/n'" << endl;
        cout << ">>";
        getline(cin,playAgain);
        validateInput(playAgain);
    }
    return 0;
}

//prints the welcoming message for user and first instructions to enter user name
void splashScreen()
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

//validates user name input. accepts only letters.
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

//validates whether the playAgain option in main function contains appropriate letters (Y/y, N/n)
void validateInput(string& playAgain)
{
    int counter = 0;
    int stringLength;
    
    stringLength = playAgain.length();
    
    while (counter < stringLength || stringLength == 0)
    {
        if (!isalpha(playAgain[counter]))
        {
            cout << "No special characters. No spaces. Please try again.\n";
            cout << ">>";
            getline(cin,playAgain);
            stringLength = playAgain.length();
            counter = 0;
        }
        else
        {
            counter++;
        }
        if (playAgain != "Y" && playAgain != "y" && playAgain != "N" && playAgain != "n")
        {
            cout << "Choose Y/y or N/n. Please try again.\n";
            cout << ">>";
            getline(cin,playAgain);
            stringLength = playAgain.length();
            counter = 0;
        }
    }
    
}

//displays game grid and allows users to make moves
void displayGrid(string& user1, string& user2)
{
    const int ARRAY_SIZE = 3;
    string topRow[ARRAY_SIZE] = {"0","1","2"};
    string middleRow[ARRAY_SIZE] = {"3","4","5"};
    string bottomRow[ARRAY_SIZE] = {"6","7","8"};
    int userTurn = 1;
    string continu = "y";
    string userMove="";
    bool whoWon = false;
    bool itsATie;
    
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
        
        bool whoWon;
        
        //changes user turn & determines win or tie
        if(userTurn == 1)
        {
            checkWin(itsATie, whoWon,topRow, middleRow, bottomRow);
            if(whoWon == true)
            {
                cout << user2 << " won this round!" << endl;
                continu = "n";
            }
            else if (whoWon == false && itsATie == true)
            {
                cout << "It's a tie!" << endl;
                continu = "n";
            }
            else
            {
                cout << "\nIt is " << user1 << "'s turn; You are 'X'\nGive me your best move! Enter a free number." << endl;
                playerMakeMove(user1,userMove);
                checkPositionAvailability(topRow,middleRow,bottomRow,userMove, user1, userTurn);
                
            }
            userTurn = 2;
            
            
        }
        
        else
        {
            if(userTurn == 2)
            {
                checkWin(itsATie, whoWon,topRow, middleRow, bottomRow);
                if(whoWon == true)
                {
                    cout << user1 << " won this round!" << endl;
                    continu = "n";
                }
                else if (whoWon == false && itsATie == true)
                {
                    cout << "It's a tie!" << endl;
                    continu = "n";
                }
                
                else
                {
                    cout << "\nIt is " << user2 << "'s turn; You are 'Y'\nGive me your best move! Enter a free number." << endl;
                    playerMakeMove(user2,userMove);
                    checkPositionAvailability(topRow,middleRow,bottomRow,userMove, user2, userTurn);
                    
                }
                userTurn = 1;
                
            }
            
        }
        
    }
    
}

//accepts player input for moves
void playerMakeMove(string& currentUser, string& userMove)
{
    cout << ">>";
    getline(cin,userMove);
    validatePlayersMove(userMove,currentUser);
}

//validates player's input for moves
void validatePlayersMove(string& userMove, string& currentUser)
{
    int counter = 0;
    int stringLength;
    string functionPass = "n";
    
    stringLength = userMove.length();
    
    while (functionPass == "n")
    {
        while (counter < stringLength || stringLength == 0)
        {
            if (!isdigit(userMove[counter]))
            {
                cout << "Choose from selections listed. No spaces. It is still " << currentUser << "'s turn.\n";
                cout << ">>";
                getline(cin,userMove);
                stringLength = userMove.length();
                counter = 0;
            }
            else
            {
                counter++;
            }
            
        }
        int integerMove = stoi(userMove);
        if (integerMove < 0 || integerMove >8)
        {
            cout << "Choose from the selections listed ONLY" << endl;
            cout << ">>";
            getline(cin,userMove);
            stringLength = userMove.length();
            counter = 0;
        }
        else
        {
            functionPass = "y";
        }
    }
    
    
}

//checks the availability of positions
void checkPositionAvailability (string grid1[], string grid2[], string grid3[], string& userMove, string& currentUser, int userTurn)
{
    const int SIZE = 3;
    string numberAvailable = "n";
    int count=0;
    while (count < SIZE)
    {
        for (count = 0; count < SIZE; count++)
        {
            if (grid1[count] == userMove || grid2[count] == userMove || grid3[count] == userMove)
            {
                numberAvailable = "y";
                count = SIZE;
            }
            else
            {
                numberAvailable = "n";
            }
            
        }
        
        
        if (numberAvailable == "y")
        {
            for (int count = 0; count < SIZE; count++)
            {
                if (grid1[count] == userMove)
                {
                    if(userTurn == 1)
                    {
                        grid1[count] = "X";
                    }
                    else
                    {
                        grid1[count] = "Y";
                    }
                }
                
            }
            
            for (int count = 0; count < SIZE; count++)
            {
                if (grid2[count] == userMove)
                {
                    if(userTurn == 1)
                    {
                        grid2[count] = "X";
                    }
                    else
                    {
                        grid2[count] = "Y";
                    }
                }
                
            }
            
            for (int count = 0; count < SIZE; count++)
            {
                if (grid3[count] == userMove)
                {
                    if(userTurn == 1)
                    {
                        grid3[count] = "X";
                    }
                    else
                    {
                        grid3[count] = "Y";
                    }
                }
                
            }
        }
        else
        {
            if(numberAvailable == "n")
            {
                cout << "That number is no longer available. Please choose a different number. It is still " << currentUser << "'s turn." << endl;
                playerMakeMove(currentUser, userMove);
                count = 0;
            }
        }
    }
}

//checks whether the game has been won or, if all spaces are unavailable, whether there has been a tie
void checkWin(bool& itsATie, bool& whoWon,string grid1[], string grid2[], string grid3[])
{
    int counterHorizontal = 0;
    int counterVertical = 0;
    int counterDiagonal = 0;
    whoWon = false;
    itsATie = false;
    
    
    if (grid1[counterHorizontal] == "X")
    {
        counterHorizontal++;
        
        if(grid1[counterHorizontal] == "X")
        {
            counterHorizontal++;
            
            if(grid1[counterHorizontal] == "X")
            {
                whoWon = true;
            }
        }
    }
    
    counterHorizontal = 0;
    
    if (grid1[counterHorizontal] == "Y")
    {
        counterHorizontal++;
        
        if(grid1[counterHorizontal] == "Y")
        {
            counterHorizontal++;
            
            if(grid1[counterHorizontal] == "Y")
            {
                whoWon = true;
            }
        }
    }
    
    counterHorizontal = 0;
    
    if (grid2[counterHorizontal] == "X")
    {
        counterHorizontal++;
        
        if(grid2[counterHorizontal] == "X")
        {
            counterHorizontal++;
            
            if(grid2[counterHorizontal] == "X")
            {
                whoWon = true;
            }
        }
    }
    
    counterHorizontal = 0;
    
    if (grid2[counterHorizontal] == "Y")
    {
        counterHorizontal++;
        
        if(grid2[counterHorizontal] == "Y")
        {
            counterHorizontal++;
            
            if(grid2[counterHorizontal] == "Y")
            {
                whoWon = true;
            }
        }
    }
    
    counterHorizontal = 0;
    
    if (grid3[counterHorizontal] == "X")
    {
        counterHorizontal++;
        
        if(grid3[counterHorizontal] == "X")
        {
            counterHorizontal++;
            
            if(grid3[counterHorizontal] == "X")
            {
                whoWon = true;
            }
        }
    }
    
    counterHorizontal = 0;
    
    if (grid3[counterHorizontal] == "Y")
    {
        counterHorizontal++;
        
        if(grid3[counterHorizontal] == "Y")
        {
            counterHorizontal++;
            
            if(grid3[counterHorizontal] == "Y")
            {
                whoWon = true;
            }
        }
    }
    
    if(grid1[counterVertical] == "X")
    {
        if(grid2[counterVertical] == "X")
        {
            if(grid3[counterVertical] == "X")
            {
                whoWon = true;
            }
        }
    }
    counterVertical++;
    
    if(grid1[counterVertical] == "X")
    {
        if(grid2[counterVertical] == "X")
        {
            if(grid3[counterVertical] == "X")
            {
                whoWon = true;
            }
        }
    }
    counterVertical++;
    
    if(grid1[counterVertical] == "X")
    {
        if(grid2[counterVertical] == "X")
        {
            if(grid3[counterVertical] == "X")
            {
                whoWon = true;
            }
        }
    }
    counterVertical++;
    counterVertical = 0;
    
    if(grid1[counterVertical] == "Y")
    {
        if(grid2[counterVertical] == "Y")
        {
            if(grid3[counterVertical] == "Y")
            {
                whoWon = true;
            }
        }
    }
    counterVertical++;
    
    if(grid1[counterVertical] == "Y")
    {
        if(grid2[counterVertical] == "Y")
        {
            if(grid3[counterVertical] == "Y")
            {
                whoWon = true;
            }
        }
    }
    counterVertical++;
    
    if(grid1[counterVertical] == "Y")
    {
        if(grid2[counterVertical] == "Y")
        {
            if(grid3[counterVertical] == "Y")
            {
                whoWon = true;
            }
        }
    }
    
    if(grid1[counterDiagonal] == "X")
    {
        counterDiagonal++;
        
        if(grid2[counterDiagonal] == "X")
        {
            counterDiagonal++;
            
            if(grid3[counterDiagonal] == "X")
            {
                whoWon = true;
            }
        }
    }
    counterDiagonal = 0;
    
    if(grid1[counterDiagonal] == "Y")
    {
        counterDiagonal++;
        
        if(grid2[counterDiagonal] == "Y")
        {
            counterDiagonal++;
            
            if(grid3[counterDiagonal] == "Y")
            {
                whoWon = true;
            }
        }
    }
    counterDiagonal = 2;
    
    if(grid1[counterDiagonal] == "X")
    {
        counterDiagonal--;
        
        if(grid2[counterDiagonal] == "X")
        {
            counterDiagonal--;
            
            if(grid3[counterDiagonal] == "X")
            {
                whoWon = true;
            }
        }
    }
    
    counterDiagonal = 2;
    
    if(grid1[counterDiagonal] == "Y")
    {
        counterDiagonal--;
        
        if(grid2[counterDiagonal] == "Y")
        {
            counterDiagonal--;
            
            if(grid3[counterDiagonal] == "Y")
            {
                whoWon = true;
            }
        }
    }
    
    for (int tieCount = 0; tieCount < 3; tieCount++)
    {
        if (grid1[tieCount] == "X" || grid1[tieCount] == "Y")
        {
            itsATie = true;
        }
        else
        {
            itsATie = false;
            tieCount = 3;
        }
        if (grid2[tieCount] == "X" || grid2[tieCount] == "Y")
        {
            itsATie = true;
        }
        else
        {
            itsATie = false;
            tieCount = 3;
        }
        if (grid3[tieCount] == "X" || grid3[tieCount] == "Y")
        {
            itsATie = true;
        }
        else
        {
            itsATie = false;
            tieCount = 3;
        }
        
    }
}