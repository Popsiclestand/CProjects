#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;



int main()
{
    unsigned seed = time(0);
    int randomNumber;
    int userNumber;
    int guesses = 0;
    
    srand(seed);
    randomNumber = rand() % 100;
    
    do
    {
        cout << "Enter a number." << endl;
        cin >> userNumber;
     
    
        if (userNumber > randomNumber)
       {
           cout << "Too high, try again. ";
           guesses ++;
       }
       else 
       {
           if (userNumber < randomNumber)
           {
               cout << "Too low, try again. ";
               guesses ++;
           }
       }
    }
    
    while (userNumber != randomNumber);
    
    cout << "You guessed right after " << guesses + 1 << " guesses! " << randomNumber << " is the correct answer!";

    return 0;
}