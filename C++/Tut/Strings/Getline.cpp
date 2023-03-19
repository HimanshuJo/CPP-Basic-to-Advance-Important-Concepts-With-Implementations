/*
std::getline (string)

	istream& getline (istream&  is, string& str, char delim);
	istream& getline (istream&& is, string& str, char delim);

	istream& getline (istream&  is, string& str);
	istream& getline (istream&& is, string& str);

-------

Get line from stream into string

	Extracts characters from is and stores them into str until the delimitation character 
	delim is found (or the newline character, '\n', for (2)).

	The extraction also stops if the end of file is reached in is or if some other error occurs 
	during the input operation.

	If the delimiter is found, it is extracted and discarded (i.e. it is not stored and the next 
	input operation will begin after it).

	Note that any content in str before the call is replaced by the newly extracted sequence.

	Each extracted character is appended to the string as if its member push_back was called.

-------

Parameters

	is
	
		istream object from which characters are extracted.

	str
	
		string object where the extracted line is stored.
		
		The contents in the string before the call (if any) are discarded and 
		replaced by the extracted line.

-------

Return Value

The same as parameter is.

A call to this function may set any of the internal state flags of is if:

	flag	error
	
	eofbit	The end of the source of characters is reached during its operations.
	
	failbit	The input obtained could not be interpreted as a valid textual representation of an object of this type.
	
			In this case, distr preserves the parameters and internal data it had before the call.
	
			Notice that some eofbit cases will also set failbit.
	
	badbit	An error other than the above happened.
*/

#include <iostream>
#include <string>

int main ()
{
  std::string name;

  std::cout << "Please, enter your full name: ";
  std::getline (std::cin,name);
  std::cout << "Hello, " << name << "!\n";

  return 0;
}
