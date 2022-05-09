#include<bits/stdc++.h>
#include <regex>
using namespace std;

class Solution {
public:

    void tokenize(string &str, char delim, vector<string> &out) 
    { 
        stringstream ss(str); 
        string s; 
        while (getline(ss, s, delim)) { 
            out.push_back(s); 
        } 
    }

    int countValidWords(string s) {
        if(s.length()==1){
            if(s[0]=='!'||s[0]=='.'||s[0]==','){
                return 1;
            } else if(isalpha(s[0])){
                return 1;
            } else return 0;
        }
        s = regex_replace(s, std::regex("^ +| +$|( ) +"), "$1");
        //cout<<s<<endl;
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
        for (char c: res) {
            res.erase(std::remove(res.begin(), res.end(), '&'), res.end());
        }
        vector<string>curr;
        tokenize(res, '$', curr);
        int ans=0;
        for(int x=0; x<curr.size(); ++x){
            string vals=curr[x];
            //cout<<vals.size()<<endl;
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


int main(){
    Solution obj;
    string sentence=" o6 t";
    obj.countValidWords(sentence);
}
