// 1957. Delete Characters to Make Fancy String
/*
A fancy string is a string where no three consecutive characters are equal.

Given a string s, delete the minimum possible number of characters from s to make it fancy.

Return the final string after the deletion. It can be shown that the answer will always be unique.

Example 1:

Input: s = "leeetcode"
Output: "leetcode"
Explanation:
Remove an 'e' from the first group of 'e's to create "leetcode".
No three consecutive characters are equal, so return "leetcode".
Example 2:

Input: s = "aaabaaaa"
Output: "aabaa"
Explanation:
Remove an 'a' from the first group of 'a's to create "aabaaaa".
Remove two 'a's from the second group of 'a's to create "aabaa".
No three consecutive characters are equal, so return "aabaa".
*/

/*
TLE: 242 / 306

class Solution {
public:
    string makeFancyString(string s) {
        int curchar='#';
        int curcount=1;
        int sz=s.size();
        for(int i=0; i<sz; ++i){
            if(s[i]==curchar){
                curcount++;
            } else{
                curcount=1;
            }
            curchar=s[i];
            if(curcount==3){
                s[i]='#';
                curcount=1;
                s.erase(remove(s.begin(), s.end(), '#'), s.end());
                sz=s.size();
                if(i-4>=0) i-=4;
                else i=-1;
                curchar='#';
                curcount=1;
            }
        }
        return s;
    }
};
*/

/*
TLE: 262 / 306

class Solution {
public:
    string makeFancyString(string s) {
        int curchar='#';
        int curcount=1;
        int sz=s.size();
        for(int i=0; i<sz; ++i){
            if(s[i]==curchar){
                curcount++;
            } else{
                curcount=1;
            }
            curchar=s[i];
            if(curcount==3){
                curcount=1;
                auto it=s.begin()+i;
                s.erase(it);
                sz=s.size();
                if(i-4>=0) i-=4;
                else i=-1;
                curchar='#';
                curcount=1;
            }
        }
        return s;
    }
};
*/

class Solution {
public:
    string makeFancyString(string s) {
        int sz=s.size();
        stack<pair<char, int>>stk;
        for(int i=0; i<sz; ++i){
            if(!stk.empty()&&stk.top().first==s[i]){
                stk.top().second++;
            } else{
                stk.push({s[i], 1});
            }
            if(stk.top().second==3){
                stk.top().second--;
            }
        }
        string res="";
        while(!stk.empty()){
            int count=stk.top().second;
            for(int i=0; i<count; ++i){
                res+=stk.top().first;
            }
            stk.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};