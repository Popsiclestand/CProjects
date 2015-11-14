// This program lets the user enter a filename.
#include <iostream>
#include <string>
#include <fstream>
using namespace std;


string statement();
int numbers(int x, int y);

int main()
{
   string newText;
   statement();
   newText = statement();
   //numbers(2,4);
   
   cout << newText << endl;
   cout << numbers(2,4);
   
   return 0;
}

string statement()
{
   string text = "Print this text";
   return text;
}

int numbers(int x, int y)
{
   int answer;

   answer = x + y;
   
   return answer;
}