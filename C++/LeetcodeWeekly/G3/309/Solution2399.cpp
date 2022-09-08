// 2399. Check Distances Between Same Letters
/*
You are given a 0-indexed string s consisting of only lowercase English letters, 
where each letter in s appears exactly twice. You are also given a 0-indexed integer array distance of length 26.

Each letter in the alphabet is numbered from 0 to 25 (i.e. 'a' -> 0, 'b' -> 1, 'c' -> 2, ... , 'z' -> 25).

In a well-spaced string, the number of letters between the two occurrences of the ith 
letter is distance[i]. If the ith letter does not appear in s, then distance[i] can be ignored.

Return true if s is a well-spaced string, otherwise return false.


Example 1:

Input: s = "abaccb", distance = [1,3,0,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0]
Output: true
Explanation:
- 'a' appears at indices 0 and 2 so it satisfies distance[0] = 1.
- 'b' appears at indices 1 and 5 so it satisfies distance[1] = 3.
- 'c' appears at indices 3 and 4 so it satisfies distance[2] = 0.
Note that distance[3] = 5, but since 'd' does not appear in s, it can be ignored.
Return true because s is a well-spaced string.
Example 2:

Input: s = "aa", distance = [1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0]
Output: false
Explanation:
- 'a' appears at indices 0 and 1 so there are zero letters between them.
Because distance[0] = 1, s is not a well-spaced string.
 

Constraints:

2 <= s.length <= 52
s consists only of lowercase English letters.
Each letter appears in s exactly twice.
distance.length == 26
0 <= distance[i] <= 50
*/

class Solution {
public:
    bool checkDistances(string s, vector<int>& distance) {
        map<char, vector<int>>mp;
        unordered_map<char, int>mp2;
        int idx=0;
        for(char ch='a'; ch<='z'; ++ch){
            mp2[ch]=idx;
            idx++;
        }
        int sz=s.size();
        for(int i=0; i<sz; ++i){
            mp[s[i]].push_back(i);
        }
        bool flag=false;
        set<char>seen;
        for(int i=0; i<sz; ++i){
            if(seen.find(s[i])==seen.end()){
                vector<int>curr=mp[s[i]];
                int diff=abs(curr[0]-curr[1]);
                diff-=1;
                int idx_=mp2[s[i]];
                if(distance[idx_]!=diff){
                    flag=true;
                    break;
                }
                seen.insert(s[i]);
            }
        }
        if(!flag){
            return true;
        }
        return false;
    }
};