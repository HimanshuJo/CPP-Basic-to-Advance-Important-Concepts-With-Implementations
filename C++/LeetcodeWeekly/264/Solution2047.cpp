// 2047. Number of Valid Words in a Sentence
/*
A sentence consists of lowercase letters ('a' to 'z'), 
digits ('0' to '9'), hyphens ('-'), punctuation marks ('!', '.', and ','), 
and spaces (' ') only. Each sentence can be broken down into one or more tokens separated by one or more spaces ' '.

A token is a valid word if all three of the following are true:

It only contains lowercase letters, hyphens, and/or punctuation (no digits).

There is at most one hyphen '-'. If present, it must be surrounded by lowercase 
characters ("a-b" is valid, but "-ab" and "ab-" are not valid).
There is at most one punctuation mark. If present, it must be at the end of the 
token ("ab,", "cd!", and "." are valid, but "a!b" and "c.," are not valid).
Examples of valid words include "a-b.", "afad", "ba-c", "a!", and "!".

Given a string sentence, return the number of valid words in sentence.

Example 1:

Input: sentence = "cat and  dog"
Output: 3
Explanation: The valid words in the sentence are "cat", "and", and "dog".

Example 2:

Input: sentence = "!this  1-s b8d!"
Output: 0
Explanation: There are no valid words in the sentence.
"!this" is invalid because it starts with a punctuation mark.
"1-s" and "b8d" are invalid because they contain digits.

Example 3:

Input: sentence = "alice and  bob are playing stone-game10"
Output: 5
Explanation: The valid words in the sentence are "alice", "and", "bob", "are", and "playing".
"stone-game10" is invalid because it contains digits.
 

Constraints:

1 <= sentence.length <= 1000
sentence only contains lowercase English letters, digits, ' ', '-', '!', '.', and ','.
There will be at least 1 token.
*/

#include<bits/stdc++.h>
#include <regex>
using namespace std;

class Solution {
public:
    
    vector<string> tokenizeString(string &str){
        vector<string>splitted;
        char *cstr=new char[str.length()+1];
        strcpy(cstr, str.c_str());
        char *ptr;
        ptr=strtok(cstr, " ");
        while(ptr!=NULL){
            splitted.push_back(ptr);
            ptr=strtok(NULL, " ");
        }
        delete[] cstr;
        return splitted;
    }
    
    string removeExtraSpaces(string &s){
        return regex_replace(s, regex("\\s+"), string(" "));
    }
    
    bool isPunctuation(char ch){
        return (ch=='!'||ch==','||ch=='.');
    }
    
    int countValidWords(string sentence) {
        string str=removeExtraSpaces(sentence);
        vector<string>vec=tokenizeString(str);
        int sz=vec.size();
        int ans=0;
        unordered_map<char, char>mp;
        for(char ch='A'; ch<='Z'; ++ch){
            mp[ch]=ch;
        }
        for(int i=0; i<sz; ++i){
            int curlen=vec[i].length();
            bool flag=false;
            int hyphencnt=0, puncnt=0;
            for(int x=0; x<curlen; ++x){
                if(vec[i][x]=='!'||vec[i][x]=='.'||vec[i][x]==','){
                    puncnt++;
                    if(puncnt>1){
                        flag=true;
                        break;
                    }
                    if(x!=curlen-1){
                        flag=true;
                        break;
                    }
                }
                if(vec[i][x]=='-'){
                    hyphencnt++;
                    if(hyphencnt>1){
                        flag=true;
                        break;
                    }
                    if(x==0||x==curlen-1){
                        flag=true;
                        break;
                    }
                    if(isPunctuation(vec[i][x-1])||isPunctuation(vec[i][x+1])){
                        flag=true;
                        break;
                    }
                }
                if(isdigit(vec[i][x])){
                    flag=true;
                    break;
                }
                if(mp.find(vec[i][x])!=mp.end()){
                    flag=true;
                    break;
                }
            }
            if(!flag){
                ans++;
            }
        }
        return ans;
    }
};

/*
Solution 2:

class Solution {
public:

    void tokenize(string &str, char delim, vector<string>&out){ 
        stringstream ss(str); 
        string s; 
        while(getline(ss, s, delim)){ 
            out.push_back(s); 
        } 
    }

    int countValidWords(string s){
        if(s.length()==1){
            if(s[0]=='!'||s[0]=='.'||s[0]==','){
                return 1;
            } else if(isalpha(s[0])){
                return 1;
            } else return 0;
        }
        s = regex_replace(s, std::regex("^ +| +$|( ) +"), "$1");
        string res="";
        for(int i=0; i<s.length(); ++i){
            if(s[i]==' '){
                res+='$';
            } else{
                res+=s[i];
            }
        }
        for(int i=0; i<res.length(); ++i){
            if(res[i]=='$'){
                if(i+1<=res.length()-1){
                    for(int x=i+1; x<res.length(); ++x){
                        if(res[x]=='$'){
                            res[x]='&';
                        } else{
                            break;
                        }
                    }
                }
            }
        }
        for(char c: res){
            res.erase(std::remove(res.begin(), res.end(), '&'), res.end());
        }
        vector<string>curr;
        tokenize(res, '$', curr);
        int ans=0;
        for(int x=0; x<curr.size(); ++x){
            string vals=curr[x];
            bool flag_=false;
            if(vals[0]=='-'||vals[vals.length()-1]=='-'){
                continue;
            }
            if(vals[0]=='!'&&vals.size()!=1) continue;
            for(int i=0; i<vals.length(); ++i){
                if(isdigit(vals[i])){
                    flag_=true;
                    break;
                }
                else if(vals[i]=='!'){
                    if(i!=vals.length()-1){
                        flag_=true;
                        break;
                    }
                    if(i-1>=0){
                        if(vals[i-1]=='-'){
                            flag_=true;
                            break;
                        }   
                    }
                }
                else if(vals[i]=='.'){
                    if(i!=vals.length()-1){
                        flag_=true;
                        break;
                    } 
                }
                else if(vals[i]==','){
                    if(i!=vals.length()-1){
                        flag_=true;
                        break;
                    }
                    if(i-1>=0){
                        if(vals[i-1]=='-'){
                            flag_=true;
                            break;
                        }   
                    }
                }
                else if(vals[i]=='-'){
                    bool flag=false;
                    for(int j=0; j<i; ++j){
                        if(isdigit(vals[j])){
                            flag=true;
                            flag_=true;
                            break;
                        }
                    }
                    for(int j=i+1;j<vals.length()-1; ++j){
                        if(isdigit(vals[j])){
                            flag=true;
                            flag_=true;
                            break;
                        }
                    }
                    int cnt=0;
                    for(int j=0; j<vals.length(); ++j){
                        if(vals[j]=='-'){
                            cnt++;
                        }
                    }
                    if(cnt>1){
                        flag=true;
                        flag_=true;
                        break;
                    }
                    if(flag) break;
                }
            }
            if(!flag_)
                ans++;
        }
        return ans;
    }
};
*/

int main(){
    Solution obj;
    string sentence=" o6 t";
    obj.countValidWords(sentence);
}
