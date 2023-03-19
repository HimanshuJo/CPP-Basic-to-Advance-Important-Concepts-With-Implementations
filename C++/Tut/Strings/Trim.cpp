/*
Remove all white spaces:

string s1 = "hem n shh";
s1.erase(remove(s1.begin(), s1.end(), ' '), s1.end());

Output:

    hemnshh
*/

// Using regex

#include <iostream>
#include <string>
#include <regex>
#include <algorithm>
using namespace std;

class RemoveWhiteSpacesUsingRegex{

    public:
    string ltrim(const string &s) {
        return regex_replace(s, regex("^\\s+"), string(""));
    }
    
    string rtrim(const string &s) {
        return regex_replace(s, regex("\\s+$"), string(""));
    }

    string mtrim(const string &s) {
        return regex_replace(s, regex("\\s+"), string(" "));
    }
    
    string trim(const string &s) {
        return mtrim(ltrim(rtrim(s)));
    }
};

class RemoveWhiteSpacesUsingFindIf{
    
    public:
    string& ltrim(string &s)
    {
        auto it = find_if(s.begin(), s.end(),
                        [](char c) {
                            return !isspace<char>(c, locale::classic());
                        });
        s.erase(s.begin(), it);
        return s;
    }
    
    string& rtrim(string &s)
    {
        auto it = find_if(s.rbegin(), s.rend(),
                        [](char c) {
                            return !isspace<char>(c, locale::classic());
                        });
        s.erase(it.base(), s.end());
        return s;
    }
    
    string& trim(string &s) {
        return ltrim(rtrim(s));
    }
};

int main()
{
    string s = " \t\n  Hello             World  ";
    cout<<"prev: "<<s<<endl;
    RemoveWhiteSpacesUsingRegex regobj;
    string nwStr=regobj.trim(s);
    cout<<"next: "<<nwStr<<endl;
    cout<<"-------\n";
    string s2 = "\n\t\t\t\tHello World  ";
    cout<<"prev: "<<s2<<endl;
    RemoveWhiteSpacesUsingFindIf findifobj;
    string nwStr2=findifobj.trim(s2);
    cout<<"next: "<<s2<<endl;
    return 0;
}

/*
Output:

prev:  
  Hello             World  
next: Hello World
-------
prev: 
                                Hello World  
next: Hello World
*/
