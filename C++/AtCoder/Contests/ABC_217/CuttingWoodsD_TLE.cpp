#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int L, Q;
    cin>>L>>Q;
    map<int, int>mp;
    for(int i=1; i<=L; ++i){
        mp[i]=L;
    }
    vector<pair<int, int>>inp;
    for(int i=0; i<Q; ++i){
        int c, x;
        cin>>c>>x;
        inp.push_back(make_pair(c, x));
    }
    //vector<int>ans;
    for(auto &vals: inp){
        if(vals.first==2){
            cout<<mp[vals.second]<<"\n";
            //ans.push_back(mp[vals.second]);
        } else{
            int highToCt=vals.second;
            int lwFrH=0;
            for(int i=1; i<=highToCt; ++i){
                if(mp[i]==mp[highToCt]){
                    lwFrH=i;
                    break;
                }
            }
            int begin=lwFrH;
            int newVal=abs(begin-vals.second)+1;
            int prev=mp[highToCt];
            for(int i=begin; i<=vals.second; ++i){
                mp[i]=newVal;
            }
            if(prev==mp[L]){
                int rst=abs(mp[L]-newVal);
                for(int i=vals.second+1; i<=L; ++i){
                    mp[i]=rst;
                }
            } else{
                int nwEnd=0;
                for(int i=L; i>=1; --i){
                    if(mp[i]==prev){
                        nwEnd=i;
                        break;
                    }
                }
                int rst=abs(mp[nwEnd]-newVal);
                for(int i=vals.second+1; i<=nwEnd; ++i){
                    mp[i]=rst;
                }
            }
        }
    }
    // for(auto &vals: ans){
    //     std::cout<<vals<<"\n";
    // }
}