#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;



int main()
{
    long userNumber;
    long smallNumber = 0;
    long largeNumber = 0;
    long smallest = 0;
    long largest = 0;
    long quit = -99;
    long repeat = 0;
    
    cout << "Enter a number or type -99 to quit." << endl;
    cin >> userNumber;
    
    while (userNumber != quit)
    {
        smallNumber = userNumber;
        largeNumber = userNumber;
        smallest = userNumber;
        
        if (smallNumber < smallest)
        {
            smallest = smallNumber;
        }
        else
        {
            if (smallNumber >= smallest)
            {
                smallest = smallest;
            }
        }
        if (largeNumber > largest)
        {
            largest = largeNumber;
        }
        else
        {
            if (largeNumber <= largest)
            {
                largest = largest;
            }
        }
        
        cout << "Enter another number or type -99 to quit." << endl;
        cin >> userNumber;
    }
    cout << "The smallest number you entered was " << smallest << "." << "The largest number you entered was " << largest << ".";
    return 0;
}