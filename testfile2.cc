// This program lets the user enter a filename.
#include <iostream>
#include <string>
#include <fstream>
using namespace std;


//void displayStats(string displayStatsUser);
string retrieveStats();

int main()
{
   retrieveStats();
   //displayStats()
   return 0;
}


// void displayStats(string displayStatsUser)
// {
//     string userNameStats = displayStatsUser; //pulls from the return value of initMenu
//     ifstream statsInfile;
//     ofstream statsOutfile;
//     int userStats[3] = {}; //holds an array of user stats pulled from file
//     string userStatsTitles[3] = {"Number of correct answers: ", "Number of wrong answers: ", "Amount of money earned: "};
//     int counter = 0;
//     int data;
    
//     cout << "Current Statistics for " << userNameStats << ":" << endl;
//     cout << "***********************************" << endl;
    
//     statsInfile.open((userNameStats + ".txt").c_str());
//     while (!statsInfile.eof())
//        {
//             getline(statsInfile,userStats[counter]);
//             counter++;
//             cout << data << endl;
//        }
//     statsInfile.close();
    
// }



string retrieveStats()
{
    string inputUserName = "";
    ifstream inputUserNameInFile;
    ofstream outputUserNameOutFile;
    int defaultData[3] = {0,0,0};
    int counter = 0;
    
    cout << "USER NAME: ";
    cin >> inputUserName;
    cin.clear();
    cin.ignore();
    
    inputUserNameInFile.open((inputUserName + ".txt").c_str());
    
    if (inputUserNameInFile)
    {
        inputUserNameInFile.close();
    }
    else
    {
        cout << "Your user name does not exist, but one shall be created for you." << endl;
        cout << endl;
        outputUserNameOutFile.open((inputUserName + ".txt").c_str());
        
        for (counter = 0; counter <= 2 ; counter++)
        {
            outputUserNameOutFile << defaultData[counter] << "\n";
        }
        
        outputUserNameOutFile.close();
    }
    
    return inputUserName;
}