//largest smallest number

#include <iostream>
#include <string>
#include <cstdlib>
#include <math.h>

using namespace std;



int main()
{
    int quit = -99;
    int userNumber;
    int smallNumber = 0;
    int largeNumber = 0;
    int userNumber2;
    string continu = "y";
    
    cout << "Please enter an integer. Enter " << quit << " to exit." << endl;
    cin >> userNumber;
    //cin.clear();
    
    while (continu == "y" || continu == "Y")
    {
        if (isdigit(userNumber))
        {
            cout << "Make sure you are entering a number!";
            cin >> userNumber;
        }
    
        else
        {
            userNumber2 = userNumber;
            while (userNumber != quit)
            {
                if (userNumber < smallNumber)
                {
                    smallNumber = userNumber;
                    //userNumber = -99;
                }
                else
                {
                    if (userNumber >= smallNumber)
                    {
                        smallNumber = smallNumber;
                        //userNumber = -99;
                    }
                }
                if (userNumber2 > largeNumber)
                {
                    largeNumber = userNumber2;
                }
                else
                {
                    if (userNumber2 <= largeNumber)
                    {
                        largeNumber = largeNumber;
                    }
                }
                
                cout << "Please enter another integer. Enter " << quit << " to exit." << endl;
                cin >> userNumber;
                cin.ignore();
            }
        }
    }
    
    cout << "The smallest number you entered was " << smallNumber << "." << "The largest number you entere was " << largeNumber << ".";
    return 0;
}