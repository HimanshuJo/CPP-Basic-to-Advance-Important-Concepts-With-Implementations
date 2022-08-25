#include<vector>
#include<iostream>
using namespace std;

bool isCond(vector<int>&in, int i, int j){
	return ((in[i]^j)>(in[j]^i));
}

void dfs(vector<int>&in, int n, int i, int &ans, vector<int>&memo){
	if(i<0||i>=in.size()) return;
	memo.push_back(1);
	for(int j=i-1; j>=max(0, i-512); --j){
		if(isCond(in, i, j)){
			memo.back()=max(memo.back(), 1+memo[j+1]);
		}
	}
	ans=max(ans, memo.back());
	dfs(in, n, i-1, ans, memo);
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
		int ans=INT_MIN;
		vector<int>memo(1);
		dfs(in, n, n-1, ans, memo);
		cout<<ans<<endl;
	}
}