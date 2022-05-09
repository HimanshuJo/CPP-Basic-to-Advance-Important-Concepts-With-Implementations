#include<iostream>
#include<vector>
using namespace std;

void dfs(vector<int>&fnarr, string &res, vector<int>&left, vector<int>&right, int idx, int sz, bool flag){
	cout<<idx<<endl;
	if(idx>=sz) return;
	int sz_=left.size();
	if((left==right)&&(sz_==sz/2)) return;
	if(!flag){
		left.push_back(fnarr[idx]);
		res+="L";
		dfs(fnarr, res, left, right, idx+1, sz, true);
	} else{
		right.push_back(fnarr[idx]);
		res+="R";
		dfs(fnarr, res, left, right, idx+1, sz, false);
	}
	left.pop_back();
	res.pop_back();
	if(!flag){
		right.push_back(fnarr[idx]);
		res+="R";
		dfs(fnarr, res, left, right, idx+1, sz, true);
	} else{
		left.push_back(fnarr[idx]);
		res+="L";
		dfs(fnarr, res, left, right, idx+1, sz, false);
	}
	return;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int m;
	cin>>m;
	vector<int>fnarr;
	while(m--){
		int n;
		cin>>n;
		vector<int>in(n);
		for(int i=0; i<n; ++i){
			cin>>in[i];
			fnarr.push_back(in[i]);
		}
	}
	string res="";
	int sz=fnarr.size();
	vector<int>left, right;
	dfs(fnarr, res, left, right, 0, sz, false);
	cout<<res<<"\n";
}
