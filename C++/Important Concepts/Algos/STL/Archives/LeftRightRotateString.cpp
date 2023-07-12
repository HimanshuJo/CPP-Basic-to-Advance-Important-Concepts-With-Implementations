/*
Given a string of size n, write functions to perform the following operations on a string-

Left (Or anticlockwise) rotate the given string by d elements (where d <= n)
Right (Or clockwise) rotate the given string by d elements (where d <= n).

Examples:

Input : s = "GeeksforGeeks"
        d = 2
Output : Left Rotation  : "eksforGeeksGe"
         Right Rotation : "ksGeeksforGee"


Input : s = "qwertyu"
        d = 2
Output : Left rotation : "ertyuqw"
         Right rotation : "yuqwert"

*/
/*
A Simple Solution is to use a temporary string to do rotations.

	For left rotation,

		first, copy last n-d characters,

		then copy first d characters in order to the temporary string.

	For right rotation,

		first, copy last d characters,

		then copy n-d characters.

-------

Can we do both rotations in-place and O(n) time?

// Left rotate string s by d (Assuming d <= n)
leftRotate(s, d)
  reverse(s, 0, d-1); // Reverse substring s[0..d-1]
  reverse(s, d, n-1); // Reverse substring s[d..n-1]
  reverse(s, 0, n-1); // Reverse whole string.

// Right rotate string s by d (Assuming d <= n)
rightRotate(s, d)

  // We can also call above reverse steps
  // with d = n-d.
  leftRotate(s, n-d)

*/

#include<bits/stdc++.h>
using namespace std;

// In-place rotates s towards left by d
void leftrotate(string &s, int d)
{
	reverse(s.begin(), s.begin() + d);
	reverse(s.begin() + d, s.end());
	reverse(s.begin(), s.end());
}

// In-place rotates s towards right by d
void rightrotate(string &s, int d)
{
	leftrotate(s, s.length() - d);
}

int main()
{
	string str1 = "GeeksforGeeks";
	leftrotate(str1, 2);
	cout << str1 << endl;

	string str2 = "GeeksforGeeks";
	rightrotate(str2, 2);
	cout << str2 << endl;
	return 0;
}

/*
Output:

Left rotation:  eksforGeeksGe
Right rotation:  ksGeeksforGee
*/