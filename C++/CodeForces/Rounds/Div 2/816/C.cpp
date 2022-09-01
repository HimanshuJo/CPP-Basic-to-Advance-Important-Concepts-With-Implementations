// C. Monoblock
/*
Stanley has decided to buy a new desktop PC made by the company "Monoblock", 
and to solve captcha on their website, he needs to solve the following task.

The awesomeness of an array is the minimum number of blocks of consecutive identical 
numbers in which the array could be split. For example, the awesomeness of an array

[1,1,1] is 1;

[5,7] is 2, as it could be split into blocks [5] and [7];

[1,7,7,7,7,7,7,7,9,9,9,9,9,9,9,9,9] is 3, as it could be split into blocks [1], [7,7,7,7,7,7,7], and [9,9,9,9,9,9,9,9,9].

You are given an array a of length n. There are m queries of two integers i, x. 
A query i, x means that from now on the i-th element of the array a is equal to x.

After each query print the sum of awesomeness values among all subsegments of array a. 
In other words, after each query you need to calculate

		∑l=1n∑r=lng(l,r),

where g(l,r) is the awesomeness of the array b=[al,al+1,…,ar].

Example
input
5 5
1 2 3 4 5
3 2
4 2
3 1
2 1
2 2

output
29
23
35
25
35
Note

After the first query a is equal to [1,2,2,4,5], and the answer is 29 because we 
can split each of the subsegments the following way:

[1;1]: [1], 1 block;
[1;2]: [1]+[2], 2 blocks;
[1;3]: [1]+[2,2], 2 blocks;
[1;4]: [1]+[2,2]+[4], 3 blocks;
[1;5]: [1]+[2,2]+[4]+[5], 4 blocks;
[2;2]: [2], 1 block;
[2;3]: [2,2], 1 block;
[2;4]: [2,2]+[4], 2 blocks;
[2;5]: [2,2]+[4]+[5], 3 blocks;
[3;3]: [2], 1 block;
[3;4]: [2]+[4], 2 blocks;
[3;5]: [2]+[4]+[5], 3 blocks;
[4;4]: [4], 1 block;
[4;5]: [4]+[5], 2 blocks;
[5;5]: [5], 1 block;
which is 1+2+2+3+4+1+1+2+3+1+2+3+1+2+1=29 in total.
*/

/*
TLE

#include<iostream>
#include<vector>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int t=1;
	while(t--){
		int n, m;
		cin>>n>>m;
		vector<int>in(n);
		for(int i=0; i<n; ++i){
			cin>>in[i];
		}
		long long ans=0;
		for(int i=0; i<m; ++i){
			int idx, val;
			cin>>idx>>val;
			idx--;
			if(idx>0&&ans>0){
				if(in[idx]!=in[idx-1]){
					ans-=idx*(n-idx);
				}
				if(in[idx]!=in[idx+1]){
					ans-=idx*(n-idx);
				}
			}
			in[idx]=val;
			if(in[idx]!=in[idx-1]){
				ans+=idx*(n-idx);
			}
			if(in[idx]!=in[idx+1]){
				ans+=idx*(n-idx);
			}
			cout<<ans<<endl;
		}
	}
}
*/

#include<iostream>
#include<vector>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int t=1;
	while(t--){
		long long n, m;
		cin>>n>>m;
		vector<long long>in(n+2);
		for(int i=1; i<=n; ++i){
			cin>>in[i];
		}
		long long ans=0;
		for(int i=1; i<=n; ++i){
			if(in[i]!=in[i+1]){
				ans+=(i*(n-(i+1)+1));
			}
		}
		for(int i=0; i<m; ++i){
			int idx, val;
			cin>>idx>>val;
			if(in[idx]!=in[idx-1]){
				ans-=((idx-1)*(n-idx+1));
			}
			if(in[idx]!=in[idx+1]){
				ans-=(idx*(n-(idx+1)+1));
			}
			in[idx]=val;
			if(in[idx]!=in[idx-1]){
				ans+=((idx-1)*(n-idx+1));
			}
			if(in[idx]!=in[idx+1]){
				ans+=(idx*(n-(idx+1)+1));
			}
			cout<<ans+n*(n+1)/2<<endl;
		}
	}
}