// C. Stripes
/*
On an 8×8 grid, some horizontal rows have been painted red, and some vertical columns have 
been painted blue, in some order. The stripes are drawn sequentially, one after the other. 
When the stripe is drawn, it repaints all the cells through which it passes.

Determine which color was used last.

Input
The first line of the input contains a single integer t (1≤t≤4000) — the number of test cases. 
The description of test cases follows. There is an empty line before each test case.

Each test case consists of 8 lines, each containing 8 characters. Each of these characters is 
either 'R', 'B', or '.', denoting a red square, a blue square, and an unpainted square, respectively.

It is guaranteed that the given field is obtained from a colorless one by drawing horizontal 
red rows and vertical blue columns.

At least one stripe is painted.

Output
For each test case, output 'R' if a red stripe was painted last, and 'B' if a blue stripe was painted last (without quotes).

Example
input
4

....B...
....B...
....B...
RRRRRRRR
....B...
....B...
....B...
....B...

RRRRRRRB
B......B
B......B
B......B
B......B
B......B
B......B
RRRRRRRB

RRRRRRBB
.B.B..BB
RRRRRRBB
.B.B..BB
.B.B..BB
RRRRRRBB
.B.B..BB
.B.B..BB

........
........
........
RRRRRRRR
........
........
........
........

output
R
B
B
R

Note
The first test case is pictured in the statement.

In the second test case, the first blue column is painted first, then the first and last red rows, 
and finally the last blue column. Since a blue stripe is painted last, the answer is B.
*/

/*
Note that if a stripe is painted last, then the entire stripe appears in the final picture (because no other stripe is covering it).

Since rows are only painted red and columns are only painted blue, we can just check if any row contains 8 Rs. 
If there is such a row, then red was painted last; otherwise, blue was painted last.
*/

#include<iostream>
#include<vector>
#include<queue>
#include<set>
using namespace std;
#define endl "\n"

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin>>t;
	while(t--){
		vector<vector<char>>in(8, vector<char>(8, '.'));
		for(int i=0; i<8; ++i){
			for(int j=0; j<8; ++j){
				cin>>in[i][j];
			}
		}
		bool flag=false;
		for(int i=0; i<8; ++i){
			int curcount=0;
			for(int j=0; j<8; ++j){
				if(in[i][j]=='R'){
					curcount++;
				} else break;
			}
			if(curcount==8){
				flag=true;
				break;
			}
		}
		cout<<(flag?"R":"B")<<endl;
	}
}
