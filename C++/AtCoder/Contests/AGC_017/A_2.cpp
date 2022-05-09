#include<iostream>
#include<vector>
using namespace std;

long long dfs(vector<int>&vec, vector<int>&memo, int currSm, int P){
	if((currSm-P)%2!=0)

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int N, P;
	cin>>N>>P;
	vector<int>vec(N);
	for(int i=0; i<N; ++i){
		cin>>vec[i];
	}
	vector<int>memo;
	long long ans=dfs(vec, memo, 0, P);
	cout<<ans<<"\n";
}
