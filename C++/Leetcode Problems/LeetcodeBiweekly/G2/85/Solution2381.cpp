// 2381. Shifting Letters II
/*
You are given a string s of lowercase English letters and a 2D integer array shifts where 
shifts[i] = [starti, endi, directioni]. For every i, shift the characters in s from 
the index starti to the index endi (inclusive) forward if directioni = 1, or shift the characters 
backward if directioni = 0.

Shifting a character forward means replacing it with the next letter in the alphabet 
(wrapping around so that 'z' becomes 'a'). Similarly, shifting a character backward means 
replacing it with the previous letter in the alphabet (wrapping around so that 'a' becomes 'z').

Return the final string after all such shifts to s are applied.

Example 1:

Input: s = "abc", shifts = [[0,1,0],[1,2,1],[0,2,1]]
Output: "ace"
Explanation: Firstly, shift the characters from index 0 to index 1 backward. Now s = "zac".
Secondly, shift the characters from index 1 to index 2 forward. Now s = "zbd".
Finally, shift the characters from index 0 to index 2 forward. Now s = "ace".
Example 2:

Input: s = "dztz", shifts = [[0,0,0],[1,1,1]]
Output: "catz"
Explanation: Firstly, shift the characters from index 0 to index 0 backward. Now s = "cztz".
Finally, shift the characters from index 1 to index 1 forward. Now s = "catz".
 

Constraints:

1 <= s.length, shifts.length <= 5 * 10^4
shifts[i].length == 3
0 <= starti <= endi < s.length
0 <= directioni <= 1
s consists of lowercase English letters.
*/

/*
TLE: 32 / 39

class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        map<char, char>mpprev;
        map<char, char>mpnxt;
        char bgn='a', bgn2='b';
        mpprev['a']='z';
        for(char ch='b'; ch<='z'; ++ch){
            mpprev[ch]=bgn++;
        }
        mpnxt['z']='a';
        for(char ch='a'; ch<='y'; ++ch){
            mpnxt[ch]=bgn2++;
        }
        for(auto &vals: shifts){
            int bgn=vals[0], end=vals[1], dir=vals[2];
            for(int i=bgn; i<=end; ++i){
                if(dir==0){
                    s[i]=mpprev[s[i]];
                } else{
                    s[i]=mpnxt[s[i]];
                }
            }
        }
        return s;
    }
};
*/

class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int sz=s.size(), sm=0;
        vector<int>prefSm(sz+1, 0);
        for(int i=0; i<shifts.size(); ++i){
            int strt=shifts[i][0], end=shifts[i][1], dir=shifts[i][2];
            if(dir==0){
                prefSm[strt]--, prefSm[end+1]++;
            } else{
                prefSm[strt]++, prefSm[end+1]--;
            }
        }
        for(int i=0; i<sz; ++i){
            sm+=prefSm[i];
            int k=sm%26;
            int tshifts=(s[i]-'a'+k+26)%26;
            s[i]=char('a'+tshifts);
        }
        return s;
    }
};