// 2434. Using a Robot to Print the Lexicographically Smallest String
/*
You are given a string s and a robot that currently holds an empty string t. 
Apply one of the following operations until s and t are both empty:

Remove the first character of a string s and give it to the robot. The robot will append this character to the string t.
Remove the last character of a string t and give it to the robot. The robot will write this character on paper.
Return the lexicographically smallest string that can be written on the paper.

 

Example 1:

Input: s = "zza"
Output: "azz"
Explanation: Let p denote the written string.
Initially p="", s="zza", t="".
Perform first operation three times p="", s="", t="zza".
Perform second operation three times p="azz", s="", t="".
Example 2:

Input: s = "bac"
Output: "abc"
Explanation: Let p denote the written string.
Perform first operation twice p="", s="c", t="ba". 
Perform second operation twice p="ab", s="c", t="". 
Perform first operation p="ab", s="", t="c". 
Perform second operation p="abc", s="", t="".
Example 3:

Input: s = "bdda"
Output: "addb"
Explanation: Let p denote the written string.
Initially p="", s="bdda", t="".
Perform first operation four times p="", s="", t="bdda".
Perform second operation four times p="addb", s="", t="".
 

Constraints:

1 <= s.length <= 10^5
s consists of only English lowercase letters.
*/

/*
TLE: 36 / 61

class Solution {
public:
    string robotWithString(string s) {
        multimap<char, int>mmp;
        int sz=s.size();
        for(int i=0; i<sz; ++i){
            mmp.insert(pair<char, int>(s[i], i));
        }
        set<int>seen;
        string ans="";
        for(auto &entries: mmp){
            if(seen.find(entries.second)==seen.end()){
                char curr=entries.first;
                seen.insert(entries.second);
                string tofnd="";
                tofnd+=curr;
                if(s.find(tofnd)!=string::npos){
                    sz=s.size();
                    string temp="";
                    for(int i=0; i<sz; ++i){
                        temp+=s[i];
                        seen.insert(i);
                        if(s[i]==curr){
                            s[i]='#';
                            break;
                        }
                        s[i]='#';
                    }
                    s.erase(remove(s.begin(), s.end(), '#'), s.end());
                    reverse(temp.begin(), temp.end());
                    char tmpfrst=temp[0];
                    if(ans.size()!=0){
                        int sz_=ans.size();
                        int lastidx=-1;
                        for(int i=sz_-1; i>=0; --i){
                            if(ans[i]>tmpfrst){
                                lastidx=i;
                            }
                        }
                        if(lastidx!=-1){
                            ans.insert(lastidx, temp);
                        } else{
                            ans+=temp;
                        }   
                    } else{
                        ans+=temp;
                    }
                }
            }
        }
        return ans;
    }
};
*/

class Solution {
public:
    
    char currAvlLowest(unordered_map<char, int>&chrFreqTb){
        for(char ch='a'; ch<='z'; ++ch){
            if(chrFreqTb[ch]!=0){
                return ch;
            }
        }
        return 'a';
    }
    
    string robotWithString(string s) {
        unordered_map<char, int>chrFreqTb;
        for(char &ch: s){
            chrFreqTb[ch]++;
        }
        stack<char>stk;
        string ans="";
        for(auto &ch: s){
            stk.push(ch);
            chrFreqTb[ch]--;
            while(!stk.empty()&&stk.top()<=currAvlLowest(chrFreqTb)){
                ans+=stk.top();
                stk.pop();
            }
        }
        while(!stk.empty()){
            ans+=stk.top();
            stk.pop();
        }
        return ans;
    }
};