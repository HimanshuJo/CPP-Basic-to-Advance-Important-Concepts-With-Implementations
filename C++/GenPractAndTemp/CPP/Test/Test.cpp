#include<vector>
#include<iostream>
using namespace std;

bool isValid(vector<int>&in, vector<int>&cursubseq){
	int sz=cursubseq.size();
	for(int i=0; i<sz-1; ++i){
		int left=in[cursubseq[i]]^cursubseq[i+1];
		int right=in[cursubseq[i+1]]^cursubseq[i];
		if(left>right) return false;
	}
	return true;
}

void dfs(vector<int>&in, int n, int idx,vector<int>cursubseq, int &ans){
	if(idx>=n){
		if(isValid(in, cursubseq)){
			int sz_=cursubseq.size();
			ans=max(ans, sz_);
		}
		return;
	}
	cursubseq.push_back(idx);
	dfs(in, n, idx+1, cursubseq, ans);
	cursubseq.pop_back();
	dfs(in, n, idx+1, cursubseq, ans);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		vector<int>in(n);
		for(int i=0; i<n; ++i){
			cin>>in[i];
		}
		vector<int>cusubseq;
		int ans=INT_MIN;
		dfs(in, n, 0, cusubseq, ans);
		cout<<ans<<endl;
	}
}