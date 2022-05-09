#include<unordered_map>
#include<string>
#include<vector>
using namespace std;

class Solution {
public:
    int countWords(vector<string>& words1, vector<string>& words2) {
        unordered_map<string, int>mp1;
        unordered_map<string, int>mp2;
        for(auto &word: words1)
            mp1[word]++;
        for(auto &word: words2)
            mp2[word]++;
        int ans=0;
        for(auto &entry: mp1){
            if(entry.second==1){
                if(mp2.find(entry.first)!=mp2.end()){
                    if(mp2[entry.first]==1){
                        ans++;
                    }  
                }
            }
        }
        return ans;
    }
};

int main(){}
