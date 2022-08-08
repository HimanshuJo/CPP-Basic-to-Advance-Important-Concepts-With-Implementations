#include<iostream>
#include<vector>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n=2000;
	vector<int>in(n);
	for(int i=0; i<n; ++i){
		cin>>in[i];
	}
	vector<int>tempSum;
	for(int i=0; i<n; ++i){
		if(i+2<=n-1){
			int currSum=0;
			for(int x=i; x<=i+2; ++x){
				currSum+=in[x];
			}
			tempSum.push_back(currSum);
		}
	}
	int ans=0;
	int curr=tempSum[0];
	int m=tempSum.size();	
	for(int i=0; i<m; ++i){
		if(tempSum[i]>curr){
			ans++;
		}
		curr=tempSum[i];
	}
	cout<<"-------\n";
	cout<<ans<<"\n";
}
