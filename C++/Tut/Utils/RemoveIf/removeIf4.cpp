#include <algorithm>
#include <string>
#include <iostream>
#include <cctype>

using namespace std;

int main()
{
    string str1 = " Te x t with som e   spaces ";
    str1.erase(remove(str1.begin(), str1.end(), ' '), str1.end());
    cout << "str1 " << str1 << '\n';
    string str2 = " Te xt\n with\tsome \t  whitespaces\n \n ";
    string str3 = " Te xt\n with\tsome \t  whitespaces\n \n ";
    str2.erase(remove_if(str2.begin(),
                         str2.end(),
                         [](unsigned char x)
    { return std::isspace(x); }),
    str2.end());
    str3.erase(remove(str3.begin(), str3.end(), ' '), str3.end());
    //str3.erase(remove(str3.begin(), str3.end(), '\n'), str3.end());
    //str3.erase(remove(str3.begin(), str3.end(), '\t'), str3.end());
    cout << "str2 " << str2 << '\n';
    cout << "str3 " << str3 << "\n";
    return 0;
}

/*
Output
str1 Textwithsomespaces
str2 Textwithsomewhitespaces
str3 Text
with    some    whitespaces
*/