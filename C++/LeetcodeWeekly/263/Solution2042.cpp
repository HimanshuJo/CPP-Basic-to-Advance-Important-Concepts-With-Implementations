#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    void tokenize(std::string const &str, const char delim, 
                  std::vector<std::string> &out) 
    { 
        std::stringstream ss(str); 
        std::string s; 
        while (std::getline(ss, s, delim)) { 
            out.push_back(s); 
        } 
    } 

    bool areNumbersAscending(string s) {
        vector<int>tmp;
        vector<std::string> out; 
        const char delim = ' '; 
        tokenize(s, delim, out);
        for (auto &s: out) {
            string curr=s;
            if(isdigit(s[0])){
                tmp.push_back(stoi(s));
            }
        }
        vector<int>res=tmp;
        sort(tmp.begin(), tmp.end());
        if(tmp==res){
            for(int i=0; i<tmp.size()-1; ++i){
                if(tmp[i]==tmp[i+1]){
                    return false;
                }
            }
            return true;
        }
        return false;
    }
};