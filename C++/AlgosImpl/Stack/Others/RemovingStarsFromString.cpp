// 2390. Removing Stars From a String
/*
You are given a string s, which contains stars *.

In one operation, you can:

Choose a star in s.
Remove the closest non-star character to its left, as well as remove the star itself.
Return the string after all stars have been removed.

Note:

The input will be generated such that the operation is always possible.
It can be shown that the resulting string will always be unique.
 

Example 1:

Input: s = "leet**cod*e"
Output: "lecoe"
Explanation: Performing the removals from left to right:
- The closest character to the 1st star is 't' in "leet**cod*e". s becomes "lee*cod*e".
- The closest character to the 2nd star is 'e' in "lee*cod*e". s becomes "lecod*e".
- The closest character to the 3rd star is 'd' in "lecod*e". s becomes "lecoe".
There are no more stars, so we return "lecoe".
Example 2:

Input: s = "erase*****"
Output: ""
Explanation: The entire string is removed, so we return an empty string.
 

Constraints:

1 <= s.length <= 10^5
s consists of lowercase English letters and stars *.
The operation above can be performed on s.
*/

/*
TLE: 31 / 65

class Solution {
public:
    string removeStars(string s) {
        int sz=s.size();
        for(int i=0; i<sz; ++i){
            if(s[i]=='*'){
                s[i]='#';
                int curtr=i;
                while(true){
                    if(curtr-1<0||(s[curtr]!='*'&&s[curtr]!='#')) break;
                    else{
                        curtr-=1;
                    }
                }
                s[curtr]='#';
            }
        }
        s.erase(remove(s.begin(), s.end(), '#'), s.end());
        return s;
    }
};
*/

class Solution {
public:
    string removeStars(string s) {
        int sz=s.size();
        stack<char>stk;
        for(auto &ch: s){
            if(ch=='*'){
                if(!stk.empty()){
                    stk.pop();
                }
            } else{
                stk.push(ch);
            }
        }
        string res="";
        while(!stk.empty()){
            res+=stk.top();
            stk.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};

// -------*******-------

class Solution {
public:
    string removeStars(string s) {
        int curpnt=0;
        for(auto &ch: s){
            if(ch=='*'){
                --curpnt;
            } else{
                s[curpnt++]=ch;
            }
        }
        string res="";
        for(int i=0; i<curpnt; ++i){
            res+=s[i];
        }
        return res;
    }
};