#include<vector>
#include<unordered_map>
#include<iostream>
using namespace std;

class Solution {
public:
    bool matchReplacement(string s, string sub, vector<vector<char>>& mappings) {
        unordered_map<char, unordered_map<char, char>>mp;
        for(auto &entries: mappings){
			mp[entries[0]][entries[1]]=1;
        }
        int sz1=s.length(), sz2=sub.length();
        for(int i=0; i<sz1; ++i){            
            bool flag=false;
            string temp=sub;
            int idx=i;
            for(int j=0; j<sz2; ++j){
                if(s[idx]!=temp[j]){
                    bool flag2=false;
                    if(mp.find(temp[j])!=mp.end()){
						if(mp[temp[j]][s[idx]]==1){
							temp[j]=s[idx];
							j=-1;
							idx=i;
						}
                    } else{
                        flag=true;
                        break;
                    }
                } else{
                    idx++;
                }
            }
            if(!flag) return true;
        }
        return false;
    }
};