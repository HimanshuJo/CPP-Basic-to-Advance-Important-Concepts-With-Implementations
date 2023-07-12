/*
Different methods to reverse a string in C/C++
*/

#include <bits/stdc++.h>
using namespace std;

// Function to reverse a string
void reverseStr(string& str)
{
	int n = str.length();

	// Swap character starting from two
	// corners
	for (int i = 0; i < n / 2; i++)
		swap(str[i], str[n - i - 1]);
}

// Function to reverse string and return
// reverse string pointer of that
char* reverseConstString(char const* str)
{
	// find length of string
	int n = strlen(str);

	// create a dynamic pointer char array
	char *rev = new char[n+1];

	// copy of string to ptr array
	strcpy(rev, str);

	// Swap character starting from two
	// corners
	for (int i=0, j=n-1; i<j; i++,j--)
		swap(rev[i], rev[j]);	
	
	// return pointer of the reversed string
	return rev;
}

int main()
{
	string str = "geeksforgeeks";
	reverseStr(str);
	cout << str << endl;

    string str2 = "geeksforgeeks";

	// Reverse str[begin..end]
	reverse(str2.begin(), str2.end());
	cout << str2 << endl;

    const char *s = "GeeksforGeeks";
	printf("%s", reverseConstString(s));
	return 0;
}

/*
Output:
skeegrofskeeg
skeegrofskeeg
skeeGrofskeeG
*/