// https://codeforces.com/contest/1715
// https://codeforces.com/blog/entry/104261
/*
A. Crossmarket

Stanley and Megan decided to shop in the "Crossmarket" grocery store, which can be represented as a 
matrix with n rows and m columns.

Stanley and Megan can move to an adjacent cell using 1 unit of power. 
Two cells are considered adjacent if they share an edge. To speed up the shopping process, 
Megan brought her portals with her, and she leaves one in each cell she visits (if there is no portal yet). 

If a person (Stanley or Megan) is in a cell with a portal, that person can use 1 unit of power to teleport 
to any other cell with a portal, including Megan's starting cell.

They decided to split up: Stanley will go from the upper-left cell (cell with coordinates (1,1))
to the lower-right cell (cell with coordinates (n,m)), whilst Megan needs to get from the 
lower-left cell (cell with coordinates (n,1)) to the upper-right cell (cell with coordinates (1,m)).

What is the minimum total energy needed for them both to do that?

Note that they can choose the time they move. Time does not affect energy.

Example
input
7
7 5
5 7
1 1
100000 100000
57 228
1 5
5 1

output
15
15
0
299998
340
5
5
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
		long long n, m;
		cin>>n>>m;
		if(n==m&&n==1){
			cout<<0<<endl;
		} else{
			long long minn=min(n, m);
			long long ans=(m-1)+(n-1)+(minn-1)+1;
			cout<<ans<<endl;
		}
	}
}