/*
D. 2+ doors

The Narrator has an integer array a of length n, but he will only tell you the size n and q statements, 
each of them being three integers i,j,x, which means that ai∣aj=x, where | denotes the bitwise OR operation.

Find the lexicographically smallest array a that satisfies all the statements.

An array a is lexicographically smaller than an array b of the same length if and only if the following holds:

in the first position where a and b differ, the array a has a smaller element than the corresponding element in b.

Examples
input
4 3
1 2 3
1 3 2
4 1 2

output
0 3 2 2 

input
1 0

output
0 

input
2 1
1 1 1073741823

output
1073741823 0

Note
In the first sample, these are all the arrays satisfying the statements:

[0,3,2,2],
[2,1,0,0],
[2,1,0,2],
[2,1,2,0],
[2,1,2,2],
[2,3,0,0],
[2,3,0,2],
[2,3,2,0],
[2,3,2,2].
*/

#include<iostream>
#include<vector>
using namespace std;

bool get_bit(int &x, int &bt){
	return (x>>bt)&1;
}

void make_null(int &x, int &bt){
	x&=(~(1<<bt));
}

void make_one(int &x, int &bt){
	x|=(1<<bt);
}

bool solve_bit(vector<int>&ans, vector<vector<pair<int, int>>>&gr, int &bt){
	int sz=ans.size();
	for(int i=0; i<sz; ++i){
		for(auto &it: gr[i]){
			/*
				check if bit at current point of the current neighbor vertex of 
				the current vertex is set or not

				if it is not set, then unset bit at the current point of val at ans[current vertex]

				else, if bit at current point of val at ans[current vertex] is not set and
				bit at current point of val at ans[current neighbor vertex] is not set return false
			*/
			if(!get_bit(it.second, bt)){
				make_null(ans[i], bt);
			} else if(!get_bit(ans[i], bt)&&!get_bit(ans[it.first], bt)){
				return false;
			}
		}
	}
	for(int i=0; i<sz; ++i){
		/*
			check if bit at current point of val at ans[current vertex] is set or not

			if it is, then unset bit at the current point of val at ans[current neighbor vertex]
		*/
		if(get_bit(ans[i], bt)){
			make_null(ans[i], bt);
		}
		for(auto &it: gr[i]){
			/*
				check for any of the neighbor of the current vertex

					check if bit at the current point of val at ans[current neighbor vertex] is set or not
					if it is not set and 

					bit at the current point of the current neighbor vertex is set

					set bit at the current point of val at ans[current vertex]

					break
			*/
			if(!get_bit(ans[it.first], bt)&&get_bit(it.second, bt)){
				make_one(ans[i], bt);
				break;
			}
		}
	}
	return true;
}

void solve(){
	int n, m;
	cin>>n>>m;
	vector<vector<pair<int, int>>>gr(n);
	while(m--){
		int a, b, c;
		cin>>a>>b>>c;
		a--, b--;
		gr[a].push_back({b, c});
		gr[b].push_back({a, c});
		if(a, b) swap(a, b);
	}
	int pt=31;
	vector<int>ans(n, INT_MAX);
	for(int i=0; i<pt; ++i){
		if(!solve_bit(ans, gr, i)){
			cout<<"-1\n";
			return;
		}
	}
	for(auto &vals: ans){
		cout<<vals<<" ";
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	solve();
}