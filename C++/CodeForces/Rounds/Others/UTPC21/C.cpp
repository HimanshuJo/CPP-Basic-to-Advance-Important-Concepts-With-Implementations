#include<bits/stdc++.h>
using namespace std;

int main(){	
		int N;
		cin>>N;
		vector<int>bdngs(N);
		int ans=0;
		for(int i=0; i<N; ++i){
				cin>>bdngs[i];
		}
		for(int i=0; i<N-1; ++i){
				ans+=abs(bdngs[i]-bdngs[i+1]);
		}
		cout<<ans;
}
		
