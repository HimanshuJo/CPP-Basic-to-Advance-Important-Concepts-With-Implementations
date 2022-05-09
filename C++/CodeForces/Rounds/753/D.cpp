#include<bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		vector<int>A(n);
		map<int, vector<int>>allInds;
		for(int i=0; i<n; ++i){
			cin>>A[i];
		}
		vector<char>colrs(n);
		vector<int>l, r;
		for(int i=0; i<n; ++i){
			cin>>colrs[i];
			if(colrs[i]=='B'){
				l.push_back(A[i]);
			} else{
				r.push_back(A[i]);
			}
		}
		sort(l.begin(), l.end());
		sort(r.begin(), r.end());
		vector<int>fn;
		for(auto &vals: l){
			fn.push_back(vals);
		}
		for(auto &vals: r){
			fn.push_back(vals);
		}
		sort(colrs.begin(), colrs.end());
		bool flag=true;
		for(int i=0; i<n; ++i){
			if(fn[i]<i+1){
				if(colrs[i]!='R'){
					flag=false;
					break;
				}
			} else if(fn[i]>i+1){
				if(colrs[i]!='B'){
					flag=false;
					break;
				}
			}
		}
		if(flag) cout<<"Yes\n";
		else cout<<"No\n";
	}
}
