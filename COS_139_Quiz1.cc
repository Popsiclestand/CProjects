#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;



int main()
{
	string userNumber;
    string continu = "y";
    int strLength;
    int counter = 0;
    int userNumberCount = 0;

	while (continu == "y" || continu =="Y")
	{
		counter = 0;

		cout << "Enter a POSTIVE integer >= 0 and press <ENTER>" << endl;
		getline(cin,userNumber);
	
		strLength = userNumber.length();

		while( counter < strLength || strLength == 0)
		{		
				if(!isdigit(userNumber[counter]))
				{
				cout << "That is not a POSITIVE number >= 0, try again\n";
				getline(cin,userNumber);
				strLength = userNumber.length();
				counter = 0;
				}
				else
				{
					if (userNumber[counter] % 2 == 0)
					{
						cout << userNumber[counter] << " ";
						userNumberCount++;
						counter++;
					}
					else
					{
						counter++;
					}
				}
		   }
		if (userNumberCount == 0)
		{
			cout << "You did not enter any even numbers.\n";
			cout << "\nThe number you entered is " << userNumber << endl;
			cout << "\ny/Y to continue entering numbers, any other char to exit" << endl;
			cin >> continu;
			cin.ignore();
		}
		else
		{
			cout << "\nThe number you entered is " << userNumber << endl;
			cout << "\ny/Y to continue entering numbers, any other char to exit" << endl;
			cin >> continu;
			cin.ignore();
		}
	}
	cout << "good-bye" << endl;
	system("pause");
    return 0;
}
