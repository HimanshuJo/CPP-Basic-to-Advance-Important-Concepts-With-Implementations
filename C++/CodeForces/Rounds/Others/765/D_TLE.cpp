#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#define prntVals cout<<vals<<" "
#define prntNums cout<<nums<<" "
#define sep1 cout<<"\n-------\n"
#define sep2 cout<<"\n***---***\n"
using namespace std;

void dfs(vector<int>&in, vector<vector<int>>&res, vector<int>&curr, set<int>&seen, int idx, int k, int n){
	if(idx>=n) return;
	for(int i=0; i<n; ++i){
		if(seen.find(i)==seen.end()){
			int nxtNum=in[i];
			bool flag=false;
			for(auto &vals: curr){
				int xortmp=in[vals]^nxtNum;
				if(xortmp<k){
					flag=true;
					break;
				}
			}
			if(!flag){
				curr.push_back(i);
				seen.insert(i);
				dfs(in, res, curr, seen, i+1, k, n);
			}
		}
	}
	return;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, k;
	cin>>n>>k;
	vector<int>in(n);
	for(int i=0; i<n; ++i){
		cin>>in[i];
	}
	vector<vector<int>>res;
	for(int i=0; i<n; ++i){
		vector<int>curr;
		set<int>seen;
		int currNum=in[i];
		seen.insert(i);
		curr.push_back(i);
		dfs(in, res, curr, seen, i, k, n);
		if(curr.size()>=2)
			res.push_back(curr);
	}
	int sz=INT_MIN;
	vector<int>ans;
	for(auto &vals: res){
		int n_=vals.size();
		if(n_>sz){
			sz=n_;
			ans=vals;
		}
	}
	if(sz==INT_MIN){
		cout<<"-1\n";
		return 0;
	}
	cout<<sz<<"\n";
	for(auto &vals: ans)
		cout<<vals+1<<" ";
	cout<<"\n";
}

