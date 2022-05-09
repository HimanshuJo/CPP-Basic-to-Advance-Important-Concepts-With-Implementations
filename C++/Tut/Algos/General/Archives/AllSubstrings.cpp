/*
Program to print all substrings of a given string

Given a string as an input. We need to write a program that will print all non-empty
substrings of that given string.

Examples :

Input :  abcd
Output :  a
          b
          c
          d
          ab
          bc
          cd
          abc
          bcd
          abcd

*/
/*
We can run three nested loops,

	the outermost loop picks a starting character,

	mid-loop considers all characters on the right of the picked character as the
	ending character of the substring.

	The innermost loop prints characters from the currently picked starting point
	to the picked ending point.
*/

#include<bits/stdc++.h>
using namespace std;

void subString(char str[], int n)
{
	// Pick starting point
	for (int len = 1; len <= n; len++)
	{
		// Pick ending point
		for (int i = 0; i <= n - len; i++)
		{
			// Print characters from current
			// starting point to current ending
			// point.
			int j = i + len - 1;
			for (int k = i; k <= j; k++)
				cout << str[k];

			cout << endl;
		}
	}
}

int main()
{
	char str[] = "abc";
	subString(str, strlen(str));
	return 0;
}

/*
Output:

a
b
c
ab
bc
abc
*/
/*
Method 2 (Using substr() function)

    s.substr(i, len) prints substring of length ‘len’ starting from index i in string s.

#include<bits/stdc++.h>
using namespace std;

void subString(string s, int n)
{
	// Pick starting point in outer loop
	// and lengths of different strings for
	// a given starting point
	for (int i = 0; i < n; i++)
		for (int len = 1; len <= n - i; len++)
			cout << s.substr(i, len) << endl;
}

int main()
{
	string s = "abcd";
	subString(s,s.length());
	return 0;
}

Output:

a
ab
abc
abcd
b
bc
bcd
c
cd
d
*/
/*
Method 3 (Generate a substring using the previous substring)

#include<bits/stdc++.h>
using namespace std;

//Function to print all (n * (n + 1)) / 2
//substrings of a given string s of length n.

void printAllSubstrings(string s, int n)
{

	//Fix start index in outer loop.
	//Reveal new character in inner loop till end of string.
	//Print till-now-formed string.

	for (int i = 0; i < n; i++)
	{
		char temp[n - i + 1];
		int tempindex = 0;
		for (int j = i; j < n; j++)
		{
			temp[tempindex++] = s[j];
			temp[tempindex] = '\0';
			printf("%s\n", temp);
		}
	}
}

int main()
{
	string s = "Geeky";
	printAllSubstrings(s, s.length());
	return 0;
}

Output:

G
Ge
Gee
Geek
Geeky
e
ee
eek
eeky
e
ek
eky
k
ky
y
*/
/*
Method 4 (using three nested loops)

#include <stdio.h>
void printSubstrings(char str[])
{

	// outermost for loop
	// this is for the selection
	// of starting point
	for (int start = 0; str[start] != '\0'; start++) {

		// 2nd for loop is for selection
		// of ending point
		for (int end = start; str[end] != '\0'; end++) {

			// 3rd loop is for printing from
			// starting point to ending point
			for (int i = start; i <= end; i++) {
				printf("%c", str[i]);
			}

			// changing the line after printing
			// from starting point to ending point
			printf("\n");
		}
	}
}

int main()
{
	char str[] = { 'a', 'b', 'c', 'd', '\0' };
	printSubstrings(str);
	return 0;
}

Output

a
ab
abc
abcd
b
bc
bcd
c
cd
d

-------

Time complexity: O(N^3)

Space complexity: O(1), where N is the length of the input string
*/