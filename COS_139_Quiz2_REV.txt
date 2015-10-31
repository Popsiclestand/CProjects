//this program was supposed to convert binary to decimal numbers, but I could not figure out the algorithm to do that
//after trying for two weeks. on the plus side the program does not crash. it does convert your binary input (a string)
//into some type of decimal. Just not the correct type of decimal.
//i anxiously await the solution to this problem.

//I did write this program in python and was successful because I know it better than c++. However, my easy algorithm of traversing
//the indices of the input string backwards would not work. I could not find any examples online of such a simple thing. If I could traverse
//the string from right to left, doing the calculations for binary would be simple. If you don't mind, professor, could you also cover this
//in the answers to this quiz?

#include <iostream>
#include <string>
#include <cstdlib>
#include <math.h>
#include <bitset>

using namespace std;



int main()
{
    string userBinary;  //user input string
    int stringLength;
    int counter = 0;
    string continu = "y";
    double total = 0;
    int number;
    


    while (continu == "y" || continu == "Y") //a loop that gives the user the option to continue entering binary numbers to covert to decimal
    {   counter = 0;
        cout << "Please enter a BINARY NUMBER and press <ENTER>." << endl;
        getline(cin,userBinary);
        stringLength = userBinary.length();
        
        while (counter < stringLength || stringLength == 0) //if the user enteres invalid input then they are booted back to enter valid input
        {
            if (userBinary[counter] != '1' && userBinary[counter] != '0')
            {
                cout << "Please enter a BINARY number (only 0s and 1s please)." << endl;
                getline(cin,userBinary);
                stringLength = userBinary.length();
                cin.clear();
                counter = 0;
            }
            else
            {
                counter++;
            }
        
        if (counter == stringLength) //the calculations for converting the user's string into decimal.
        {
            string backwards;
            int x;
            int bit=1;
            for (x = userBinary.length()-1; x >=0; x--)
            {
                if (userBinary[x] == '1')
                {
                    total = total+bit;
                    bit = bit*2;
                }
                else
                {
                    if (userBinary[x] == '0')
                    {
                        total = total;
                        bit = bit*2;
                    }
                }
                
            }
            
            cout << "You entered " << userBinary << ". The decimal equivalent of " << userBinary << " is " << total << "." << endl; //prints out the users conversion
            cout << "\ny/Y to continue entering binary numbers, any other char to exit" << endl;
    		cin >> continu;
    		cin.clear();
    		cin.ignore();
    		total = 0;
        }
        }
        
    }       
    cout << "good-bye" << endl; //exists the program.
	system("pause");
    return 0;
  

}