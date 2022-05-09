// A. Sorting Parts
/*
You have an array a of length n. You can exactly once select an integer len between 1 and n−1 inclusively, 
and then sort in non-decreasing order the prefix of the array of length len and the suffix of the array of length n−len independently.

For example, if the array is a=[3,1,4,5,2], and you choose len=2, then after that the array will be equal to [1,3,2,4,5].

Could it be that after performing this operation, the array will not be sorted in non-decreasing order?

Input
There are several test cases in the input data. 
The first line contains a single integer t (1≤t≤100) — the number of test cases. This is followed by the test cases description.

The first line of each test case contains one integer n (2≤n≤10^4) — the length of the array.

The second line of the test case contains a sequence of integers a1,a2,…,an (1≤ai≤10^9) — the array elements.

It is guaranteed that the sum of n over all test cases does not exceed 104.

Output
For each test case of input data, output "YES" (without quotes), if the array may be not sorted in non-decreasing order, 
output "NO" (without quotes) otherwise. You can output each letter in any case (uppercase or lowercase).

Example
input
3
3
2 2 1
4
3 1 2 1
5
1 2 2 4 4

output
YES
YES
NO

Note
In the first test case, it's possible to select len=1, then after operation, 
the array will not be sorted in non-decreasing order and will be equal to [2,1,2].

In the second test case, it's possible to select len=3, then after operation, 
the array will not be sorted in non-decreasing order and will be equal to [1,2,3,1].

In the third test case, the array will be sorted in non-decreasing order for every possible len.
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
		vector<int>in(n);
		for(int i=0; i<n; ++i){
			cin>>in[i];
		}
		vector<int>temp=in;
		sort(temp.begin(), temp.end());
		if(temp==in){
			cout<<"NO\n";
		} else{
			cout<<"YES\n";
		}
	}
}
