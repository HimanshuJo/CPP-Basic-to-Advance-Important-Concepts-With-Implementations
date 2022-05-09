// 1763. Longest Nice Substring
/*
A string s is nice if, for every letter of the alphabet that s contains, it appears both in uppercase and lowercase. 
For example, "abABB" is nice because 'A' and 'a' appear, and 'B' and 'b' appear. 
However, "abA" is not because 'b' appears, but 'B' does not.

Given a string s, return the longest substring of s that is nice. 
If there are multiple, return the substring of the earliest occurrence. If there are none, return an empty string.

Example 1:

Input: s = "YazaAay"
Output: "aAa"
Explanation: "aAa" is a nice string because 'A/a' is the only letter of the alphabet in s, and both 'A' and 'a' appear.
"aAa" is the longest nice substring.
Example 2:

Input: s = "Bb"
Output: "Bb"
Explanation: "Bb" is a nice string because both 'B' and 'b' appear. The whole string is a substring.
Example 3:

Input: s = "c"
Output: ""
Explanation: There are no nice substrings.
 

Constraints:

1 <= s.length <= 100
s consists of uppercase and lowercase English letters.
*/

class Solution {
public:
    string longestNiceSubstring(string s) {
        int sz=s.length();
        map<int, vector<string>>mp;
        for(int i=0; i<sz; ++i){
            string curr="";
            for(int j=i; j<sz; ++j){
                curr+=s[j];
                if(curr.size()>=2){
                    bool flag=false;
                    for(char ch: curr){
                        if(islower(ch)){
                            char temp=toupper(ch);
                            size_t it=curr.find(temp);
                            if(it==string::npos){
                                flag=true;
                                break;
                            }
                        }
                        if(isupper(ch)){
                            char temp=tolower(ch);
                            size_t it=curr.find(temp);
                            if(it==string::npos){
                                flag=true;
                                break;
                            }
                        }
                    }
                    if(!flag){
                        int nsz=curr.size();
                        mp[nsz].push_back(curr);
                    }
                }
            }
        }
        if(mp.size()==0) return "";
        auto it=mp.end();
        it--;
        return it->second[0];
    }
};