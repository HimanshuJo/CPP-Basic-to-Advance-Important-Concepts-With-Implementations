#include<vector>
#include<iostream>
#include<unordered_map>
#include<map>
#include<queue>
#include<algorithm>
#define endl "\n"
using ll=long long;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--){
        int N, K;
        cin>>N>>K;
        vector<int>ks(K);
        for(int i=0; i<K; ++i){
            cin>>ks[i];
        }
        vector<int>prefs;
        int remCount=N-K;
        int tocomp=0;
        if(ks[0]<0){
            while(remCount>1){
                prefs.push_back(-1);
                remCount--;
                tocomp+=-1;
            }
        } else{
            while(remCount>1){
                if(ks[0]>=1){
                    prefs.push_back(-1);
                    remCount--;
                    tocomp+=-1;
                } else{
                    prefs.push_back(0);
                    remCount--;
                }
            }
        }
        int remaining=0;
        if(ks[0]<0){
            if(tocomp!=0){
                remaining=tocomp*-1;
				int oth=(ks[0]*-1)-remaining;
				prefs.push_back(oth*-1);
            }
        } else{
            if(tocomp!=0){
                remaining=tocomp*-1;
				if(remaining!=0)
					prefs.push_back(remaining);
            }
        }
        sort(prefs.begin(), prefs.end());
        if(ks[0]<0){
            prefs.push_back(0);
            for(int i=1; i<K; ++i){
                prefs.push_back(ks[i]-ks[i-1]);
            }
        } else{
            prefs.push_back(ks[0]);
            for(int i=1; i<K; ++i){
                prefs.push_back(ks[i]-ks[i-1]);
            }
        }
		for(auto &vals: prefs){
			cout<<vals<<" ";
		}
		cout<<endl;
        vector<int>temp=prefs;
        bool flag=false;
        sort(temp.begin(), temp.end());
        for(int i=0; i<temp.size(); ++i){
            if(temp[i]!=prefs[i]){
                flag=true;
                break;
            }
        }
        if(flag){
            cout<<"NO";
        } else{
            cout<<"YES";
        }
        cout<<endl;
    }
}