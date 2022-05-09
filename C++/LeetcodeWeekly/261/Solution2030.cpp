#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string smallestSubsequence(string s, int k, char letter, int repetition) {
        int n_letters=0;
        for(int i=0; i<s.length(); ++i){
            if(s[i]==letter)
                n_letters++;
        }
        stack<char>stk;
        for(int i=0; i<s.length(); ++i){
            char ch=s[i];
            while(!stk.empty()&&
                  stk.top()>ch&&
                  (s.length()-i+stk.size()>k)&&
                  (stk.top()!=letter||n_letters>repetition))
                {
                if(stk.top()==letter){
                    repetition++;
                }
                stk.pop();
            }
            if(stk.size()<k){
                if(ch==letter){
                    stk.push(ch);
                    repetition--;
                } else if(k-stk.size()>repetition){
                    stk.push(ch);
                }
            }
            if(ch==letter)n_letters--;
        }
        vector<char>tmp;
        while(!stk.empty()){
            tmp.push_back(stk.top());
            stk.pop();
        }
        reverse(tmp.begin(), tmp.end());
        string res="";
        for(auto &vals: tmp)
            res+=vals;
        return res;
    }
};