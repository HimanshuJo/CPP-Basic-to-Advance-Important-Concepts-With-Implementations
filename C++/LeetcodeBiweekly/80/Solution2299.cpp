// 2299. Strong Password Checker II
/*
A password is said to be strong if it satisfies all the following criteria:

It has at least 8 characters.
It contains at least one lowercase letter.
It contains at least one uppercase letter.
It contains at least one digit.
It contains at least one special character. The special characters are the characters 
in the following string: "!@#$%^&*()-+".

It does not contain 2 of the same character in adjacent positions 
(i.e., "aab" violates this condition, but "aba" does not).

Given a string password, return true if it is a strong password. Otherwise, return false.

Example 1:

Input: password = "IloveLe3tcode!"
Output: true
Explanation: The password meets all the requirements. Therefore, we return true.
Example 2:

Input: password = "Me+You--IsMyDream"
Output: false
Explanation: The password does not contain a digit and also contains 2 of the same character 
in adjacent positions. Therefore, we return false.
Example 3:

Input: password = "1aB!"
Output: false
Explanation: The password does not meet the length requirement. Therefore, we return false.

Constraints:

1 <= password.length <= 100
password consists of letters, digits, and special characters: "!@#$%^&*()-+".
*/

class Solution {
public:
    bool strongPasswordCheckerII(string password) {
        if(password.length()<8) return false;
        map<char, char>mp1;
        map<char, char>mp2;
        map<int, int>mp3;
        map<char, char>mp4;
        for(char ch='A'; ch<='Z'; ++ch){
            mp1[ch]=ch;
        }
        for(char ch='a'; ch<='z'; ++ch){
            mp2[ch]=ch;
        }
        for(int i=0; i<=9; ++i){
            mp3[i]=i;
        }
        mp4['!']='!';
        mp4['@']='@';
        mp4['#']='#';
        mp4['$']='$';
        mp4['%']='%';
        mp4['^']='^';
        mp4['&']='&';
        mp4['*']='*';
        mp4['(']='(';
        mp4[')']=')';
        mp4['-']='-';
        mp4['+']='+';
        int len=password.length();
        bool lwc=false, upc=false, dg=false, spc=false;
        for(int i=0; i<len; ++i){
            if(i+1<=len-1){
                if(password[i]==password[i+1]){
                    return false;
                }
            }
            if(mp4.find(password[i])!=mp4.end()) spc=true;
            if(mp3.find(password[i]-'0')!=mp3.end()) dg=true;
            if(mp2.find(password[i])!=mp2.end()) lwc=true;
            if(mp1.find(password[i])!=mp1.end()) upc=true;
        }
        if(lwc==false||upc==false||dg==false||spc==false) return false;
        return true;
    }
};