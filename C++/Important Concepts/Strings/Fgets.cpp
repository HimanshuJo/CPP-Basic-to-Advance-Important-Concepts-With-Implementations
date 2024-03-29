/*
fgets

	char *fgets(char *str, int num, FILE *stream );

-------

Get string from stream

Reads characters from stream and stores them as a C string into str 
until (num-1) characters have been read or either a newline or the 
end-of-file is reached, whichever happens first.

A newline character makes fgets stop reading, but it is considered a valid character by 
the function and included in the string copied to str.

A terminating null character is automatically appended after the characters copied to str.

Notice that fgets is quite different from gets: 

	not only fgets accepts a stream argument, but also allows to 
	specify the maximum size of str and includes in the string any 
	ending newline character.

-------

Parameters:

str

	Pointer to an array of chars where the string read is copied.

num

	Maximum number of characters to be copied into str 
	(including the terminating null-character).

stream

	Pointer to a FILE object that identifies an input stream.
	
	stdin can be used as argument to read from the standard input.

-------

Return Value:

	On success, the function returns str.

	If the end-of-file is encountered while attempting to read a character, 
	the eof indicator is set (feof). 

	If this happens before any characters could be read, the pointer returned 
	is a null pointer (and the contents of str remain unchanged).

	If a read error occurs, the error indicator (ferror) is set and a 
	null pointer is also returned (but the contents pointed by str may have changed).
*/

/* fgets example */
#include <stdio.h>

int main()
{
	FILE *pFile;
	char mystring[100];

	pFile = fopen("Test4.txt", "r");
	if (pFile == NULL)
		perror("Error opening file");
	else
	{
		if (fgets(mystring, 100, pFile) != NULL)
			puts(mystring);
		fclose(pFile);
	}
	return 0;
}

/*
Output:

	This is a test string. This is a test string. This is a test string. This is a test string

-------

This example reads the first line of myfile.txt or the first 99 characters, 
whichever comes first, and prints them on the screen.
*/
