#include<iostream>
#include<vector>
using namespace std;

constexpr int MAX_SIDE=1000;
int tree_pref[MAX_SIDE+1][MAX_SIDE+1];
int forest[MAX_SIDE+1][MAX_SIDE+1];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int N, Q;
	cin>>N>>Q;
	for(int i=0; i<N; ++i){
		for(int j=0; j<N; ++j){
			char a;
			cin>>a;
			forest[i+1][j+1]+=a=='*';
		}
	}
	for(int i=1; i<=N; ++i){
		for(int j=1; j<=N; ++j){
			tree_pref[i][j]=forest[i][j]+tree_pref[i-1][j]+tree_pref[i][j-1]-tree_pref[i-1][j-1];
		}
	}
	for(int q=0; q<Q; ++q){
		int from_rw, to_rw, from_col, to_col;
		cin>>from_rw>>from_col>>to_rw>>to_col;
		cout<<tree_pref[to_rw][to_col]-tree_pref[from_rw-1][to_col]-
		      tree_pref[to_rw][from_col-1]+tree_pref[from_rw-1][from_col-1]<<"\n";
	}
}