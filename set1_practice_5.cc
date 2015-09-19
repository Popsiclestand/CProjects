
//**************************************************************
// This program will convert the temp in Celsius to Fahrenheit.
//**************************************************************

#include <iostream>
#include <string>

using namespace std;
 
int main()  
{ 
   //declare variables
    float temperatureInCelsius = 0;
    float temperatureInFahrenheit;

    //get input from user
    cout << "Enter the temperature in degrees Celsius: ";
    cin >> temperatureInCelsius;
    
    const float FAHRENHEIT = (9.0/5.0) * temperatureInCelsius + 32.0;
   
    //calculations
    cout << temperatureInCelsius << " degrees Celsius is equal to " 
         << FAHRENHEIT << " degrees Fahrenheit!";

    return 0;
}  
  /*Professor Flores, is it okay to declare a variable in the middle of
  a program? I did so for two reasons. 1, I wanted to have a constant variable
  for the calculation of Fahrenheit so that if I needed to insert this function
  into a program that required this a bunch of times, all I would have to change
  is the value of the FAHRENHEIT constant. 2, if i declared that value at
  the beginning of the main function, it would calculate using either the 
  initialized value of temperatureInCelsius (which was initialized to 0 for safety).
  
  Anyway, the program works. However, I have not learned exception handling
  in C++ yet, so it can be crashed should a non numerical value be used, but
  I'll fix that once I learn how to do exception handling here.
  */