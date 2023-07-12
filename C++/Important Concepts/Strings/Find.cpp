/*
String find is used to find the first occurrence of sub-string in the
specified string being called upon.

It returns the index of the first occurrence of the sub-string in the string from
given starting position.

The default value of starting position is 0.

-------

Function Template:

    size_t find (const string& str, size_t pos = 0);
    size_t find (const char* s, size_t pos = 0);

Function parameters:

    str : The sub-string to be searched.
    s : The sub-string to be searched, given as C style string.
    pos : The initial position from where the string search is to begin.

-------

Function Return:

    The function returns the index of the first occurrence of sub-string,
        if the sub-string is not found
        it returns string::npos(string::pos is static member with value as the highest
        possible for the size_t data structure).
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Vari1
{
public:
    void stringOccurrences()
    {
        string str = "geeksforgeeks a computer science";
        string str1 = "geeks";

        // Find first occurrence of "geeks"
        size_t found = str.find(str1);
        if (found != string::npos)
            cout << "First occurrence is " << found << endl;

        // Find next occurrence of "geeks". Note here we pass
        // "geeks" as C style string.
        char arr[] = "geeks";
        found = str.find(arr, found + 1);
        if (found != string::npos)
            cout << "Next occurrence is " << found << endl;
    }
};

/*
Output:
First occurrence is 0
Next occurrence is 8
*/

/*
We can also use it to find occurrence of a character:
In below syntax, note that c is a character.

    size_t find (const char c, size_t pos = 0);
*/

class Vari2
{
public:
    void stringOccurrences()
    {
        string str = "geeksforgeeks a computer science";
        char c = 'g';

        // Find first occurrence of 'g'
        size_t found = str.find(c);
        if (found != string::npos)
            cout << "First occurrence is " << found << endl;

        // Find next occurrence of 'g'
        found = str.find(c, found + 1);
        if (found != string::npos)
            cout << "Next occurrence is " << found << endl;
    }
};
/*
Output:
First occurrence is 0
Next occurrence is 8
*/

/*
We can also search for a partial string
In below syntax, note that n is number of characters to match.

    size_t find (const char *str, size_t pos, size_t n);
*/

class Vari3
{
public:
    void stringOccurrences()
    {
        string str = "geeksforgeeks a computer science";

        // Only search first 5 characters of "geeks.practice"
        size_t found = str.find("geeks.practice", 0, 5);
        if (found != string::npos)
            cout << found << endl;
    }
};

/*
Output:
0
*/

/*
Find all occurrences of a string in a larger string
*/

class Vari4
{
public:
    vector<int> allOccurrences(string str)
    {
        size_t found = 0;
        int cnt = 0;
        vector<int> res;
        while (found != string::npos)
        {
            found = str.find("geeks", found + cnt++);
            if (found == string::npos)
                break;
            res.push_back(found);
        }
        return res;
    }
};

/*
Output: 0 8 33 43
*/

int main()
{
    string str = "geeksforgeeks a computer science geeks for geeks";
    Vari4 obj4;
    vector<int> res = obj4.allOccurrences(str);
    for (auto &vals : res)
        cout << vals << " ";
}