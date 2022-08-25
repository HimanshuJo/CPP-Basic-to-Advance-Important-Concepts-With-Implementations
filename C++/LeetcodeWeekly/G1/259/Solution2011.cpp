#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        unordered_map<string, int>mp;
        mp["++X"]=1;
        mp["X++"]=1;
        mp["--X"]=-1;
        mp["X--"]=-1;
        int ans=0;
        for(string str: operations){
            ans+=mp[str];
        }
        return ans;
    }
};