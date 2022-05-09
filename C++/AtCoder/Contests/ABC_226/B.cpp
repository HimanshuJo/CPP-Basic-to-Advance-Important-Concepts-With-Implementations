#include<bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int N;
	cin>>N;
	set<vector<int>>st;
	for(int i=0; i<N; ++i){
		vector<int>curr;
		int L;
		cin>>L;
		curr.push_back(L);
		for(int i=0; i<L; ++i){
			int a;
			cin>>a;
			curr.push_back(a);
		}
		st.insert(curr);
	}
	cout<<st.size()<<"\n";
}
