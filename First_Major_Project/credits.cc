//the purpose of this script is to serve as a function that takes input
//from the user of their name, checks to see if a text file with that user's
//name already exists. If the user exists the a greeting statement with the
//user's name is displayed. If the user does not exist, a different
//greeting statement is displayed and a text file for that user is created.

#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;



int main()
{
    string userName;
    cout << "Enter your name: " << endl;
    getline(cin,userName);
    
    //something that checks a file existing and also opens that file if it exists
    //if it does not exist then a new text file is created.
    
    cout << "Hello, " << userName << endl << "Thank you for playing the math game!" << endl;
    cout << "The math game is just what the name says. You will be asked\nseveral math questions";
    
    return 0;
}