// C. Corners
/*
You are given a matrix consisting of n rows and m columns. Each cell of this matrix contains 0 or 1.

Let's call a square of size 2×2 without one corner cell an L-shape figure. In one operation you can 
take one L-shape figure, with at least one cell containing 1 and replace all numbers in it with zeroes.

Find the maximum number of operations that you can do with the given matrix.

Example
input
4
4 3
101
111
011
110
3 4
1110
0111
0111
2 2
00
00
2 2
11
11

output
8
9
0
2
*/

#include<iostream>
#include<vector>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin>>t;
	while(t--){
		int n, m;
		cin>>n>>m;
		vector<vector<char>>in(n, vector<char>(m));
		int zcount=0;
		for(int i=0; i<n; ++i){
			for(int j=0; j<m; ++j){
				cin>>in[i][j];
				zcount+=in[i][j]-'0';
			}
		}
		int minn=INT_MAX;
		for(int i=0; i<n-1; ++i){
			for(int j=0; j<m-1; ++j){
				int count=0;
				count+=(in[i][j]-'0')+(in[i+1][j]-'0')+(in[i+1][j+1]-'0')+(in[i][j+1]-'0');
				if(count==0) continue;
				minn=min(minn, max(1, count-1));
			}
		}
		if(zcount==0) cout<<"0\n";
		else cout<<1+zcount-minn<<endl;
	}
}