// C. Meximum Array
/*
Mihai has just learned about the MEX concept and since he liked it so much, he decided to use it right away.

Given an array a of n non-negative integers, Mihai wants to create a new array b that is formed in the following way:

While a is not empty:

Choose an integer k (1≤k≤|a|).
Append the MEX of the first k numbers of the array a to the end of array b and erase them from the array a, 
shifting the positions of the remaining numbers in a.
But, since Mihai loves big arrays as much as the MEX concept, he wants the new array b to be 
the lexicographically maximum. 

So, Mihai asks you to tell him what the maximum array b that can be created by constructing the array optimally is.

An array x is lexicographically greater than an array y if in the first position where x and y 
differ xi>yi or if |x|>|y| 
and y is a prefix of x (where |x| denotes the size of the array x).

The MEX of a set of non-negative integers is the minimal non-negative integer such that it is not in the set. 

For example, MEX({1,2,3}) =0 and MEX({0,1,2,4,5}) =3.

Input
The first line of the input contains a single integer t (1≤t≤100) — the number of test cases. 
The description of test cases follows.

The first line of each test case contains a single integer n (1≤n≤2⋅10^5) — the number of elements in the array a.

The second line of each test case contains n non-negative integers a1,…,an (0≤ai≤n), 
where ai is the i-th integer from the array a.

It is guaranteed that the sum of n over all test cases does not exceed 2⋅10^5.

Output
For each test case print m — the length of the maximum array b Mihai can create, followed by m 
integers denoting the elements of the array b.

Example
input
6
5
1 0 2 0 3
8
2 2 3 4 0 1 2 0
1
1
5
0 1 2 3 4
4
0 1 1 0
10
0 0 2 1 1 1 0 0 1 1

output
1
4 
2
5 1 
1
0 
1
5 
2
2 2 
4
3 2 2 0 

Note
In the first test case, the lexicographically maximum array b is obtained by selecting k=5, 
resulting in the MEX of the whole array a. It is lexicographically maximum because an array starting with a 
smaller number than 4 is lexicographically smaller, and choosing a k<5 would result in an array 
starting with a number smaller than 4.

In the second test case, there are two ways to obtain the maximum array: first selecting k=6, then k=2, 
or first selecting k=7 and then k=1.

*/
/* Brute Force:

#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;

int calMx(vector<int>&in){
	set<int>tmp;
	for(auto &vals: in){
		tmp.insert(vals);
	}
	int x=0;
	for(auto &vals: tmp){
		if(vals!=x) return x;
		x++;
	}
	return tmp.size();
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		vector<int>in(n);
		int currMx=-1;
		for(int i=0; i<n; ++i){
			cin>>in[i];
		}
		if(in.size()==1){
			cout<<1<<"\n";
			if(in[0]==0){
				cout<<1<<"\n";
				continue;
			} else{
				cout<<0<<"\n";
				continue;
			}
		}
		vector<int>mexSuff(n);
		mexSuff[n-1]=in[n-1]==0?1:0;
		for(int i=n-2; i>=0; --i){
			vector<int>curr;
			for(int x=i; x<n; ++x){
				curr.push_back(in[x]);
			}
			int mexx=calMx(curr);
			mexSuff[i]=mexx;
		}
		vector<int>res;
		for(int i=0; i<n; ++i){
			int currMx=mexSuff[i];
			vector<int>tmp_;
			for(int j=i; j<n; ++j){
				tmp_.push_back(in[j]);
				int nwMex=calMx(tmp_);
				if(currMx==nwMex){
					res.push_back(currMx);
					i=j;
					break;
				}
			}
		}
		cout<<res.size()<<"\n";
		for(auto &vals: res)
			cout<<vals<<" ";
		cout<<"\n";
	}
}
*/

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
		int arr[n];
		vector<int>vec[n+1];
		for(int i=0; i<n; ++i){
			cin>>arr[i];
		}
		for(int i=n-1; i>=0; --i){
			vec[arr[i]].push_back(i);
		}	
		int idx=0;
		vector<int>ans;
		while(idx!=n){
			int mxIdx=idx;
			for(int i=0; i<=n; ++i){
				while(vec[i].size()>0&&vec[i].back()<idx){
					vec[i].pop_back();
				}
				if(vec[i].size()>0){
					mxIdx=max(mxIdx, vec[i].back());
				} else{
					ans.push_back(i);
					idx=mxIdx+1;
					break;
				}
			}
		}
		cout<<ans.size()<<"\n";
		for(auto &vals: ans){
			cout<<vals<<" ";
		}
		cout<<"\n";
	}
}