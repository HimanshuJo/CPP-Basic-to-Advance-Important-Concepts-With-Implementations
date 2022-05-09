// 2185. Counting Words With a Given Prefix
/*
You are given an array of strings words and a string pref.

Return the number of strings in words that contain pref as a prefix.

A prefix of a string s is any leading contiguous substring of s.

Example 1:

Input: words = ["pay","attention","practice","attend"], pref = "at"
Output: 2
Explanation: The 2 strings that contain "at" as a prefix are: "attention" and "attend".
Example 2:

Input: words = ["leetcode","win","loops","success"], pref = "code"
Output: 0
Explanation: There are no strings that contain "code" as a prefix.
 

Constraints:

1 <= words.length <= 100
1 <= words[i].length, pref.length <= 100
words[i] and pref consist of lowercase English letters.
*/

class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int ans=0;
        for(auto &word: words){
            if(word[0]==pref[0]){
                int len=pref.length();
                if(word.length()<len) continue;
                bool flag=false;
                for(int i=0; i<len; ++i){
                    if(word[i]!=pref[i]){
                        flag=true;
                        break;
                    }
                }
                if(!flag) ans++;
            }
        }
        return ans;
    }
};