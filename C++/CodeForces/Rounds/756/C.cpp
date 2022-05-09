#include<iostream>
#include<algorithm>
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
        int maxInd=-1;
		int maxn=INT_MIN;
        for(int i=0; i<n; ++i){
            if(in[i]>maxn){
                maxn=in[i];
                maxInd=i;
            }
        }
		if(maxInd!=n-1){
            if(maxInd!=0){
                cout<<"-1\n";
                continue;
            }
		}
		reverse(in.begin(), in.end());
		for(auto &vals: in)
			cout<<vals<<" ";
		cout<<"\n";
	}
}

