/*
In C++, std::substr() is a predefined function used for string handling. 

	string.h is the header file required for string functions.

This function takes two values pos and len as an argument and returns a newly 
constructed string object with its value initialized to a copy of a sub-string of this object. 

	Copying of string start from pos and done till pos+len means [pos, pos+len).

-------

Important points:

	The index of the first character is 0 (not 1).

	If pos is equal to the string length, the function returns an empty string.

	If pos is greater than the string length, it throws out_of_range. 

		If this happen, there are no changes in the string.

	If for the requested sub-string len is greater than size of string, 
    then returned sub-string is [pos, size()).

Syntax:

	string substr (size_t pos, size_t len) const;
	
	Parameters:

		pos: Position of the first character to be copied.

		len: Length of the sub-string.

		size_t: It is an unsigned integral type.

Return value: It returns a string object.
*/

/*
Applications :

    Getting sub-string after a character?

		In this a string and a character is given and you have to print the sub-string 
		followed by the given character.
		
		Extract everything after the “:” in the string “dog:cat”.
*/

#include <string.h>
#include <iostream>
using namespace std;

void stringSubstringCheck1(string s){
	// Copy three characters of s1 (starting
	// from position 1)
	string r = s.substr(1, 3);

	// prints the result
	cout << "String is: " << r;
}

void stringSubstringCheck2(string s){
    // Find position of ':' using find()
    int pos = s.find(":");

    // Copy substring after pos
    string sub = s.substr(pos + 1);

    // prints the result
    cout << "String is: " << sub;
}

int main()
{
	string s1 = "Geeks";
    stringSubstringCheck1(s1);
    cout<<endl;
    string s2 = "dog:cat";
    stringSubstringCheck2(s2);
	return 0;
}

/*
Output:
String is: eek
String is: cat
*/