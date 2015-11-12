
#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>

using namespace std;



int main()
{
    ifstream infile;
    ofstream outfile;
    string fileName = "";
    string data [3] = {"hogwarts", "middleearth", "narnia"};

    cout << "Enter a file name: ";
    cin >> fileName;
    
    infile.open((fileName + ".txt").c_str());
    
    if (infile)
    {
        cout << "This file opened sucessfully!";
        infile.close();
        outfile.open((fileName + ".txt").c_str());
        int i = 0;
        for (; data[i] != "\0"; i++)
            {
                outfile << data[i] << endl;
            }
        outfile.close();
    }
    else
    {
        cout << "This file does not exist, but we shall create one for you.";
        outfile.open ((fileName + ".txt").c_str());
        outfile << "Writing to the newly created file";
        outfile.close();

    }

   
    return 0;
}