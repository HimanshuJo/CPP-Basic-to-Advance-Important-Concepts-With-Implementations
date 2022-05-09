// 1871. Jump Game VII
/*
You are given a 0-indexed binary string s and two integers minJump and maxJump. 
In the beginning, you are standing at index 0, which is equal to '0'. 

You can move from index i to index j if the following conditions are fulfilled:

i + minJump <= j <= min(i + maxJump, s.length - 1), and
s[j] == '0'.
Return true if you can reach index s.length - 1 in s, or false otherwise.

Example 1:

Input: s = "011010", minJump = 2, maxJump = 3
Output: true
Explanation:
In the first step, move from index 0 to index 3. 
In the second step, move from index 3 to index 5.
Example 2:

Input: s = "01101110", minJump = 2, maxJump = 3
Output: false
 

Constraints:

2 <= s.length <= 10^5
s[i] is either '0' or '1'.
s[0] == '0'
1 <= minJump <= maxJump < s.length
*/

class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int len=s.length();
        if(s[len-1]=='1') return false;
        queue<int>q;
        q.push(0);
        int currmax=0;
        while(!q.empty()){
            int sz=q.size();
            while(sz--){
                int currIdx=q.front();
                q.pop();
                if(currIdx==len-1) return true;
                for(int i=max(currmax, currIdx+minJump); i<=min(currIdx+maxJump, len-1); ++i){
                    if(s[i]=='0'){
                        q.push(i);
                    }
                }
                currmax=min(currIdx+maxJump, len-1);
            }
        }
        return false;
    }
};