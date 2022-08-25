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
		for(int i=0; i<n; ++i){
			cin>>A[i];
		}
		sort(A.begin(), A.end());
		if(A.size()==1){
			cout<<A[0]<<"\n";
		} else{
			int ans=A[0];
			for(int i=0; i<A.size()-1; ++i){
				int curr=abs(A[i]-A[i+1]);
				ans=max(ans, curr);
			}
			cout<<ans<<"\n";
		}
	}
}
