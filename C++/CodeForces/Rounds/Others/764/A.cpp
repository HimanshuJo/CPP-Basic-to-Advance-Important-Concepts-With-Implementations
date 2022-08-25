// A. Plus One on the Subset
/*
Polycarp got an array of integers a[1…n] as a gift. Now he wants to perform a certain number of operations (possibly zero) 
so that all elements of the array become the same (that is, to become a1=a2=⋯=an).

In one operation, he can take some indices in the array and increase the elements of the array at those indices by 1.
For example, let a=[4,2,1,6,2]. He can perform the following operation: select indices 1, 2, and 4 and increase elements 
of the array in those indices by 1. As a result, in one operation, he can get a new state of the array a=[5,3,1,7,2].

What is the minimum number of operations it can take so that all elements of the array become equal to each other 
(that is, to become a1=a2=⋯=an)?

Example
input
3
6
3 4 2 4 1 2
3
1000 1002 998
2
12 11

output
3
4
1
*/
#include<iostream>
#include<vector>
#include<algorithm>
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
		sort(in.begin(), in.end());
		cout<<in[n-1]-in[0]<<"\n";
	}
}
