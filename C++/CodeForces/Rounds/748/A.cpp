#include<vector>
#include<iostream>
using ll=long long;
using namespace std;

bool allSame(vector<ll>in){
    ll toChk=in[0];
    int cnt=0;
    for(auto &nums: in){
        if(nums==toChk){
            cnt++;
        }
    }
    if(cnt==3){
        return true;
    }
    return false;
}

bool twoSameNdMaxx(vector<ll>in, int maxx){
    ll toChk=maxx;
    int cnt=0;
    for(auto &nums: in){
        if(nums==toChk){
            cnt++;
        }
    }
    if(cnt==2){
        return true;
    }
    return false;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        vector<ll>in(3);
        ll maxx=LONG_MIN;
        int idx=-1;
        for(int i=0; i<3; ++i){
            cin>>in[i];
            if(in[i]>=maxx){
                maxx=in[i];
                idx=i;
            }
        }
        if(allSame(in)){
            cout<<"1 1 1";
        } else if(twoSameNdMaxx(in, maxx)){
            for(int i=0; i<3; ++i){
                if(in[i]!=maxx){
                    cout<<((maxx-in[i])+1)<<" ";
                } else cout<<"1 ";
            }
        } else{
            for(int i=0; i<3; ++i){
                if(in[i]!=maxx){
                    cout<<((maxx-in[i])+1)<<" ";
                } else cout<<"0 ";
            }
        }
        cout<<"\n";
    }
}