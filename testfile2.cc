#include <iostream>
#include <string>
#include <cstdlib>
#include <math>

using namespace std;



int main()
{
    string userBinary;
    int stringLength;
    int counter = 0;
    string continu = "y";
    int total = 0;
    int bitArray[8] = {128,64,32,16,8,4,2,1};
    
    while (continu == "y" || continu == "Y")
    {
        while (counter < stringLength || stringLength == 0)
        {
            cout << "Please enter a BINARY NUMBER and press <ENTER>." << endl;
            getline(cin,userBinary);
            stringLength = userBinary.length();
            //cout << stringLength;
        
            if (userBinary[counter] != '1' && userBinary[counter] != '0')
                {
                    cout << "Please enter a BINARY number (only 0s and 1s please)." << endl;
                    counter = 0;
                }
            else
            {
                if (userBinary[counter-1] == '1')
                {
                    //do some calcuations here
                    counter++;
                    total = total + bitArray[counter-1];
                }
                else
                {
                    counter++;
                }
            }
        }
    cout << total;
    }       
    return 0;
  

}