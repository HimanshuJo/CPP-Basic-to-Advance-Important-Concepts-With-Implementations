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
		vector<int>in(N+1);
		for(int i=N-K+1; i<=N; ++i){
			cin>>in[i];
		}
		if(K==1) cout<<"Yes"<<endl;
		else{
			vector<long long>seq(N+1);
			for(int i=N-K+2; i<=N; ++i){
				seq[i]=in[i]-in[i-1];
			}
			if(!is_sorted(seq.begin()+N-K+2, seq.end())){
				cout<<"No"<<endl;
			} else{
				if(in[N-K+1]>seq[N-K+2]*(N-K+1)){
					cout<<"No"<<endl;
				} else{
					cout<<"Yes"<<endl;
				}
			}
		}
    }
}