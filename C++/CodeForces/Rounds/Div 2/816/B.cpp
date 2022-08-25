/*
B. Beautiful Array

Stanley defines the beauty of an array a of length n, which contains non-negative integers, as follows:

		∑i=1n⌊ai/k⌋,

which means that we divide each element by k, round it down, and sum up the resulting values.

Stanley told Sam the integer k and asked him to find an array a of n non-negative integers, 
such that the beauty is equal to b and the sum of elements is equal to s. 

Help Sam — find any of the arrays satisfying the conditions above.

Example
input
8
1 6 3 100
3 6 3 12
3 6 3 19
5 4 7 38
5 4 7 80
99978 1000000000 100000000 1000000000000000000
1 1 0 0
4 1000000000 1000000000 1000000000000000000

output
-1
-1
0 0 19
0 3 3 3 29
-1
-1
0
0 0 0 1000000000000000000
*/

#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin>>t;
	while(t--){
		long long n, k, b, s;
		cin>>n>>k>>b>>s;
		vector<long long>ans(n, 0);
		long long tochk=k*b;
		s-=tochk;
		if(s<0){
			cout<<-1<<endl;
		} else{
			ans[0]=tochk;
			for(int i=0; i<n; ++i){
				long long curr=min(k-1, s);
				ans[i]+=curr;
				s-=curr;
			}
			if(s>0) cout<<-1<<"\n";
			else{
				for(auto &vals: ans){
					cout<<vals<<" ";
				}
				cout<<endl;
			}
		}
	}
}