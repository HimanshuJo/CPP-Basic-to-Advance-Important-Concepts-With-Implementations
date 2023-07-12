// 1910. Remove All Occurrences of a Substring

/*
Given two strings s and part, perform the following operation on s until all occurrences of the substring 
part are removed:

    Find the leftmost occurrence of the substring part and remove it from s.

Return s after removing all occurrences of part.

A substring is a contiguous sequence of characters in a string.

Example 1:

Input: s = "daabcbaabcbc", part = "abc"
Output: "dab"
Explanation: The following operations are done:
- s = "daabcbaabcbc", remove "abc" starting at index 2, so s = "dabaabcbc".
- s = "dabaabcbc", remove "abc" starting at index 4, so s = "dababc".
- s = "dababc", remove "abc" starting at index 3, so s = "dab".
Now s has no occurrences of "abc".

Example 2:

Input: s = "axxxxyyyyb", part = "xy"
Output: "ab"
Explanation: The following operations are done:
- s = "axxxxyyyyb", remove "xy" starting at index 4 so s = "axxxyyyb".
- s = "axxxyyyb", remove "xy" starting at index 3 so s = "axxyyb".
- s = "axxyyb", remove "xy" starting at index 2 so s = "axyb".
- s = "axyb", remove "xy" starting at index 1 so s = "ab".
Now s has no occurrences of "xy".

Constraints:

    1 <= s.length <= 1000
    1 <= part.length <= 1000
    's' and 'part' consists of lowercase English letters.

*/

/*
Approach:

    Initialize a stack to store the characters of the main string (let's say S1)

    Traverse the string S1 and perform the following operations:

        a. Push the current character in the stack

        b. If the size of the stack is at least M, then check if the top M characters of the stack form the 
            string s2 or not

            If found to be true, then remove those characters

*/

class Solution {
public:
    
    void returnNewS(string &s, string &part, int strsz, int prtsz, stack<char>&stk){
        for(int i=0; i<strsz; ++i){
            stk.push(s[i]);
            if(stk.size()>=prtsz){
                string curstr="";
                for(int x=prtsz-1; x>=0; --x){
                    char curr=stk.top();
                    if(curr==part[x]){
                        stk.pop();
                        curstr+=curr;
                    } else{
                        int len=curstr.size()-1;
                        while(len>=0){
                            stk.push(curstr[len--]);
                        }
                        break;
                    }
                }
            }
        }
    }
    
    string removeOccurrences(string s, string part) {
        int strsz=s.size();
        int prtsz=part.size();
        stack<char>stk;
        returnNewS(s, part, strsz, prtsz, stk);
        string ans="";
        while(!stk.empty()){
            ans+=stk.top();
            stk.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};