#include<bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin>>t;
	while(t--){
		int n; 
		cin>>n;
		bool flag=true;
		for(int i=1; i<=n; ++i){
			int x; cin>>x;
			bool found=false;
			for(int j=i+1; j>=2; --j){
				if(x%j){
					found=true;
					break;
				}
			}
			if(!found){
				flag=false;
				break;
			}
		}
		if(flag){
			cout<<"Yes\n";
			flag=true;
		}
		else{
			cout<<"No\n";
			flag=true;
		}
	}
}
