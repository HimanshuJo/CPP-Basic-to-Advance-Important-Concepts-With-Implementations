#include<bits/stdc++.h>
using ll = long long;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n, k;
        cin>>n>>k;
        vector<ll>X(k);
        for(int i=0; i<k; ++i){
            cin>>X[i];
        }
        sort(X.begin(), X.end());
        int cnt=0;
        int res=0;
        while(true){
            cnt++;
            int currlst=X.back();
            currlst++;
            if(currlst==n){
                res++;
                X.pop_back();
                if(X.size()==0){
                    break;
                }
            } else{
                X[X.size()-1]++;
            }
            if(X[0]==cnt){
                auto it=X.begin();
                while(true){
                    X.erase(it);
                    if(X.size()==0){
                        break;
                    } else{
                        auto it=X.begin();
                        if((*it)!=cnt) break;
                    }
                }
            }
            if(X.size()==0){
                break;
            }
        }
        cout<<res<<"\n";
    }
}