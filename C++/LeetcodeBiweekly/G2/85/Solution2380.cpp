// 2380. Time Needed to Rearrange a Binary String
/*
You are given a binary string s. In one second, all occurrences of "01" are simultaneously 
replaced with "10". This process repeats until no occurrences of "01" exist.

Return the number of seconds needed to complete this process.

Example 1:

Input: s = "0110101"
Output: 4
Explanation: 
After one second, s becomes "1011010".
After another second, s becomes "1101100".
After the third second, s becomes "1110100".
After the fourth second, s becomes "1111000".
No occurrence of "01" exists any longer, and the process needed 4 seconds to complete,
so we return 4.
Example 2:

Input: s = "11100"
Output: 0
Explanation:
No occurrence of "01" exists in s, and the processes needed 0 seconds to complete,
so we return 0.
 

Constraints:

1 <= s.length <= 1000
s[i] is either '0' or '1'
*/

/*
We count "zeros" so far. If we have a string 00001, we need 4 seconds (as we have 4 zeros) to make it 10000.

We also track seconds we need to rearrange first i letters.

If i + 1 letter is 1, we need at least seconds + 1 seconds, but not less than zero seconds.

Here is calculation for the "100111110001000001" test case:

For i == 11 (yellow), the result is 7 as we need 6 seconds for i - 1.
For i == 17 (green), the result is 10 as we have 10 zeros, even though we need 7 seconds for i - 1.
*/

class Solution {
public:
    int secondsToRemoveOccurrences(string s) {
        int sz=s.size(), countZ=0, seconds=0;
        int ans=0;
        for(int i=0; i<sz; ++i){
            if(s[i]=='0'){
                countZ++;
            }
            if(s[i]=='1'&&countZ>0)
                seconds=max(seconds+1, countZ);
        }
        return seconds;
    }
};

// -------*******-------

class Solution2 {
public:
    int secondsToRemoveOccurrences(string s) {
        int sz=s.size();
        int ans=0;
        while(true){
            int idx=0;
            bool flag=false;
            vector<pair<int, int>>chngs;
            for(int idx=0; idx<sz; ++idx){
                 if(idx+1<=sz-1){
                    if(s[idx]=='0'&&s[idx+1]=='1'){
                        flag=true;
                        chngs.push_back({idx, idx+1});
                        idx+=1;
                    }
                } else break;   
            }
            for(auto &vals: chngs){
                s[vals.first]='1', s[vals.second]='0';
            }
            if(!flag) break;
            ans++;
        }
        return ans;
    }
};