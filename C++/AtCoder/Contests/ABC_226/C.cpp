#include<bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int N;
	cin>>N;
	vector<vector<int>>dt;
	for(int i=0; i<N; ++i){
		vector<int>curr;
		int T;
		cin>>T;
		curr.push_back(T);
		int K;
		cin>>K;
		curr.push_back(K);
		for(int i=0; i<K; ++i){
			int in;
			cin>>in;
			curr.push_back(in);
		}
		dt.push_back(curr);
	}
	set<int>seen;
	seen.insert(N-1);
	long long totTime=0;
	for(int i=dt.size()-1; i>=0; --i){
		vector<int>curr=dt[i];
		auto it=seen.find(i);
		if(it!=seen.end()){
			totTime+=curr[0];
			for(int j=2; j<curr.size(); ++j){
				seen.insert(curr[j]-1);
			}	
		}

	}
	cout<<totTime<<"\n";
}
