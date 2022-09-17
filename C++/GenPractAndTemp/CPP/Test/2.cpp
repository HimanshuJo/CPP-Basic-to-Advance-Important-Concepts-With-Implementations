#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<string>
#include<queue>
#include<unordered_map>
#include<map>
#include<unordered_set>
#include<set>
#define endl "\n"
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string s;
        cin>>s;
        unordered_map<int, char>mp;
        char bgn='a';
        for(int i=1; i<=26; ++i){
            mp[i]=bgn++;
        }
        string res="";
        int sz=s.size();
        int idx=sz-1;
        while(idx>=0){
            if(s[idx]!='0'){
                string temp="";
                temp+=s[idx];
                res+=mp[stoi(temp)];
            } else{
                string temp="";
                idx--;
                temp+=s[idx];
                idx--;
                temp+=s[idx];
                reverse(temp.begin(), temp.end());
                res+=mp[stoi(temp)];
            }
            idx--;
        }
        reverse(res.begin(), res.end());
        cout<<res<<endl;
    }
}