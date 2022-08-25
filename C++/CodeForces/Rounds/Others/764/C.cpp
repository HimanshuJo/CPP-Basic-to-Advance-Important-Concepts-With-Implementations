// C. Division by Two and Permutation
/*
You are given an array a consisting of n positive integers. You can perform operations on it.

In one operation you can replace any element of the array ai with ⌊ai/2⌋, that is, by an integer part of dividing ai by 2 (rounding down).

See if you can apply the operation some number of times (possible 0) to make the array a become a permutation of numbers 
from 1 to n —that is, so that it contains all numbers from 1 to n, each exactly once.

For example, if a=[1,8,25,2], n=4, then the answer is yes. You could do the following:

Replace 8 with ⌊8/2⌋=4, then a=[1,4,25,2].
Replace 25 with ⌊25/2⌋=12, then a=[1,4,12,2].
Replace 12 with ⌊12/2⌋=6, then a=[1,4,6,2].
Replace 6 with ⌊6/2⌋=3, then a=[1,4,3,2].

Example
input
6
4
1 8 25 2
2
1 1
9
9 8 3 4 2 7 1 5 6
3
8 2 1
4
24 7 16 7
5
22 6 22 4 22

output
YES
NO
YES
NO
NO
YES
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
		vector<int>tCmp;
		vector<int>seen(n+1, 0);
		for(int i=1; i<=n; ++i){
			tCmp.push_back(i);
		}
		sort(in.begin(), in.end());
		bool flag=false;
		for(auto &vals: in){
			while(true){
				auto it=find(tCmp.begin(), tCmp.end(), vals);
				if(it!=tCmp.end()){
					if(seen[vals]==0){
						seen[vals]=1;
						break;
					}
				}
				if(vals==1){
					if(seen[1]==0){
						seen[1]=1;
						break;
					} else{
						flag=true;
						break;
					}
				}
				if(flag) break;
				vals/=2;
			}
			if(flag) break;
		}
		if(flag) cout<<"NO\n";
		else cout<<"YES\n";
	}
}

