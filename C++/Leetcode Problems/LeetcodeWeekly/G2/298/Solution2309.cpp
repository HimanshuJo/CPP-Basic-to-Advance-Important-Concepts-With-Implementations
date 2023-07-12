// 2309. Greatest English Letter in Upper and Lower Case
/*
Given a string of English letters s, return the greatest English letter which occurs as 
both a lowercase and uppercase letter in s. The returned letter should be in uppercase. 

If no such letter exists, return an empty string.

An English letter b is greater than another letter a if b appears after a in the English alphabet.

Example 1:

Input: s = "lEeTcOdE"
Output: "E"
Explanation:
The letter 'E' is the only letter to appear in both lower and upper case.
Example 2:

Input: s = "arRAzFif"
Output: "R"
Explanation:
The letter 'R' is the greatest letter to appear in both lower and upper case.
Note that 'A' and 'F' also appear in both lower and upper case, but 'R' is greater than 'F' or 'A'.
Example 3:

Input: s = "AbCdEfGhIjK"
Output: ""
Explanation:
There is no letter that appears in both lower and upper case.
 

Constraints:

1 <= s.length <= 1000
s consists of lowercase and uppercase English letters.
*/

class Solution {
public:
    string greatestLetter(string s) {
        string res="";
        map<char, char>mp1;
        map<char, char>mp2;
        for(char ch='A'; ch<='Z'; ++ch){
            mp1[ch]=tolower(ch);
        }
        for(char ch='a'; ch<='z'; ++ch){
            mp2[ch]=toupper(ch);
        }
        sort(s.begin(), s.end());
        int len=s.length();
        for(int i=len-1; i>=0; --i){
            char ch=s[i];
            auto it=mp1.find(ch);
            if(it!=mp1.end()){
                char tochk=mp1[ch];
                string temp="";
                temp+=tochk;
                auto it_=s.find(temp);
                if(it_!=string::npos){
                    res+=ch;
                    break;
                }
            } else{
                char tochk=mp1[ch];
                string temp="";
                temp+=tochk;
                auto it_=s.find(temp);
                if(it_!=string::npos){
                    res+=mp2[ch];
                    break;
                }
            }
        }
        return res;
    }
};