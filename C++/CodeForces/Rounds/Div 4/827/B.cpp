// B. Increasing
/*
You are given an array a of n positive integers. Determine if, by rearranging the elements, you can 
make the array strictly increasing. In other words, determine if it is possible to 
rearrange the elements such that a1<a2<⋯<an holds.

Input
The first line contains a single integer t (1≤t≤100) — the number of test cases.

The first line of each test case contains a single integer n (1≤n≤100) — the length of the array.

The second line of each test case contains n integers ai (1≤ai≤109) — the elements of the array.

Output
For each test case, output "YES" (without quotes) if the array satisfies the condition, and "NO" (without quotes) otherwise.

You can output the answer in any case (for example, the strings "yEs", "yes", "Yes" and 
"YES" will be recognized as a positive answer).

Example
input
3
4
1 1 1 1
5
8 7 1 3 4
1
5

output
NO
YES
YES

Note
In the first test case any rearrangement will keep the array [1,1,1,1], which is not strictly increasing.

In the second test case, you can make the array [1,3,4,7,8].
*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define endl "\n"

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
		vector<int>temp=in;
		sort(temp.begin(), temp.end());
		int prev=temp[0];
		bool flag=false;
		for(int i=1; i<n; ++i){
			if(temp[i]<=prev){
				flag=true;
				break;
			}
			prev=temp[i];
		}
		if(flag){
			cout<<"No"<<endl;
		} else{
			cout<<"Yes"<<endl;
		}
	}
}