#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
using ll=long long;
#define endl "\n"

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin>>t;
	while(t--){
		int n, q;
		cin>>n>>q;
		vector<int>ai(n), ki(q);
		for(int i=0; i<n; ++i){
			cin>>ai[i];
		}
		for(int i=0; i<q; ++i){
			cin>>ki[i];
		}
		vector<ll>aicmb;
		aicmb.push_back(0);
		for(int i=0; i<n; ++i){
			aicmb.push_back(aicmb.back()+ai[i]);
		}
		vector<ll>prefmaxx;
		for(int i=0; i<n; ++i){
			if(i==0){
				prefmaxx.push_back(ai[i]);
			} else{
				prefmaxx.push_back(max((ll)ai[i], prefmaxx.back()));
			}
		}
		vector<ll>ans(q);
		for(int i=0; i<q; ++i){
			auto it=upper_bound(prefmaxx.begin(), prefmaxx.end(), ki[i]);
			int idx=it-prefmaxx.begin();
			ans[i]=aicmb[idx];
		}
		for(auto &vals: ans){
			cout<<vals<<" ";
		}
		cout<<endl;
	}
}