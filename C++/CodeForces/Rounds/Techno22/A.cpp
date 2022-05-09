#include<iostream>
#include<vector>
using namespace std;

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
		bool flag=false;
		for(int i=0; i<n-1; ++i){
			if(in[i]==0&&in[i+1]==0){
				flag=true;
				cout<<-1<<"\n";
				break;
			}
		}
		if(!flag){
			int res=1;
			vector<bool>seen(n, false);
			for(int i=0; i<n; ++i){
				if(!seen[i]){
					res+=in[i];
					seen[i]=true;
				}
				if(i+1<=n-1&&in[i]==1&&in[i+1]==1){
					res+=5;
					seen[i+1]=true;
				}
			}
			cout<<res<<"\n";
		}
	}
}
