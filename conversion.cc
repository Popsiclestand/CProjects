//http://www.cplusplus.com/reference/cctype/
//#include <climits>// limits of named constants, see page 1284
//#include <cmath> //math library
#include <cctype> // library for strings and other useful validations
#include <iomanip> // library for manipulating output
#include <fstream> // library to direct output to files and get input from files
//#include <cstdlib> // library for the rand and srand functions
#include <ctime> // library to work with time
#include <string> //string library
#include <cstring> //to be able to use strlen
#include <sstream>//convert integer to string
#include <iostream>

using namespace std;

int main() 
{
	cout << "**********************************" << endl;
	cout << "**convert integers to strings!!!**" << endl;
	cout << "**********************************" << endl;
	//convert integers to strings!!!
	//this method (#1) uses to_string();
	int x = 8;
	string someString = to_string(x);//this works in visual studio but not in Dev C++
	cout << someString << " as a string!" <<  endl;
	cout << "===========================" << endl;

	//the code method (#2) 
	//it uses sstream and you will need #include <sstream> in your directives
	x = 23;
	stringstream convertedIntTostring;//declare a variable of type stringstream 
	string someOtherString;//declare a string
	convertedIntTostring << x;//load into the variable convertedIntTostring which is of type stringstream the integer value of x
	someOtherString = convertedIntTostring.str();//"consume" from the stringstream the value which you just inserted
	convertedIntTostring.str("");//clear the sstream
	convertedIntTostring.str(string());//clear the sstream--> this is the proper way to clear the sstream.
	//want to clear the sstream in cases where you are doing multiple conversions in a ("while", "do-while" or "for")loop 
	cout << someOtherString << " as a string!" <<  endl;
	cout << "===========================" << endl;

	
	//this method (#3) uses itoa();
	//http://www.cplusplus.com/reference/cstdlib/itoa/
	//char *  itoa ( int value, char * str, int base );
	//value: Value to be converted to a string.
	//str: Array in memory where to store the resulting null-terminated string.
	//base: Numerical base used to represent the value as a string, between 2 and 36, where 10 means decimal base, 16 hexadecimal, 8 octal, and 2 binary. 
	x = 55;
	string yetOneMoreString;
	char someCharArray[3];
	itoa (x,someCharArray,10);//notice that you need an char array and it is the address of the array that is passed to itoa()
	yetOneMoreString = someCharArray;//in this statement you simply assign the value which is stored at the base address of the array someCharArray
	cout << yetOneMoreString << " as a string!" <<  endl;
	cout << "===========================" << endl;

	cout << "**********************************" << endl;
	cout << "**convert strings to integers!!!**" << endl;
	cout << "**********************************" << endl;

	//this method (#1) uses stoi();
	string convertibleString = "123";
	int someInt = stoi(convertibleString);//works in visual studio, but not in Dev C++   
	cout << someInt << " as an integer!" <<  endl;
	cout << "===========================" << endl;

    //this method (#2) uses atoi
	string anotherConvertibleString = "246";
	int playersChoice = atoi(anotherConvertibleString.c_str());//the inclusing of c_str() is necessary to get this to work in Dev C++
	//notice that atoi requires an argument of of type c-string, which is nothing but an array of chars terminated by a null
	cout << anotherConvertibleString << " as an integer!" <<  endl;
	cout << "===========================" << endl;

	cout << "**********************************" << endl;
	cout << "***convert chars to integers!!!***" << endl;
	cout << "**********************************" << endl;

	//this method (#1) uses the fact that when performing mathematical computations like additions or subtractions with chars, it is their encoded ASCII value that is used in the computation
	//and the resultant is of data type integer
	char choice = '1';
	int check;
    check = (choice - 48); //48 is the ascii value of zero
	cout << check << " as an integer!" <<  endl;
	cout << "===========================" << endl;

	system("pause");
	return 0;
}