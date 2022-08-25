// 2124. Check if All A's Appears Before All B's
/*
Given a string s consisting of only the characters 'a' and 'b', return true if every 'a' appears before every 'b' 
in the string. Otherwise, return false.

Example 1:

Input: s = "aaabbb"
Output: true
Explanation:
The 'a's are at indices 0, 1, and 2, while the 'b's are at indices 3, 4, and 5.
Hence, every 'a' appears before every 'b' and we return true.
Example 2:

Input: s = "abab"
Output: false
Explanation:
There is an 'a' at index 2 and a 'b' at index 1.
Hence, not every 'a' appears before every 'b' and we return false.
Example 3:

Input: s = "bbb"
Output: true
Explanation:
There are no 'a's, hence, every 'a' appears before every 'b' and we return true.
 

Constraints:

1 <= s.length <= 100
s[i] is either 'a' or 'b'.
*/

class Solution {
public:
    bool checkString(string s) {
        int len=s.length();
        if(len==2) return s[0]=='a';
        int cntA=0;
        for(int i=0; i<len; ++i){
            if(s[i]=='a') cntA++;
        }
        bool flag=false;
        int currCnt=0;
        for(int i=0; i<len; ++i){
            if(i-1>=0&&i+1<len&&s[i]=='a'&&s[i-1]=='b'&&s[i+1]=='b') return false;
            if(s[i]=='b'&&!flag&&cntA!=0) return false;
            if(s[i]=='a'){
                flag=flag==false?true:flag;
                currCnt++;
            }
            if(s[i]=='b'&&flag==true&&currCnt!=cntA) return false;
        }
        return true;
    }
};