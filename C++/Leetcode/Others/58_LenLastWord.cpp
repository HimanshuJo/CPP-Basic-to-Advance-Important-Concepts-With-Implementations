/*

Given a string s consists of some words separated by spaces, return the length of the last word in the string. 
If the last word does not exist, return 0.

A word is a maximal substring consisting of non-space characters only.

Example 1:

Input: s = "Hello World"
Output: 5

Example 2:

Input: s = " "
Output: 0

/**/

#include<string>
#include<vector>
#include<regex>

using namespace std;

class Solution
{
public:
    int lengthOfLastWord(string s)
    {
        if (s.length() == 0)
            return 0;

        std::regex ws_re("\\s+");

        std::vector<std::string> str{std::sregex_token_iterator(s.begin(), s.end(), ws_re, -1), {}};

        vector<string> list;

        for (string str_ : str)
        {
            list.push_back(str_);
        }

        return (list.at(list.size() - 1).length());
    }
};