// A. Divide and Multiply
/*
William has array of n numbers a1,a2,…,an. He can perform the following sequence of operations any number of times:

Pick any two items from array ai and aj, where ai must be a multiple of 2
ai=ai2
aj=aj⋅2
Help William find the maximal sum of array elements, which he can get by performing the sequence of operations described above.

Example
input
5
3
6 4 2
5
1 2 3 4 5
1
10
3
2 3 4
15
8 8 8 8 8 8 8 8 8 8 8 8 8 8 8
output
50
46
10
26
35184372088846
*/
#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
using ll=long long;

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
		double sum=0;
		ll cnt=0;
		bool hasEven=false;
		for(int i=0; i<n; ++i){
			int vals=in[i];
			if(vals%2==0){
				hasEven=true;
				while(vals!=1){
					vals/=2;
					in[i]=vals;
					cnt++;
					if(vals%2!=0) break;
				}
			}
		}
		if(hasEven){
			int maxEle=INT_MIN, maxInd;
			for(int i=0; i<n; ++i){
				if(in[i]>maxEle){
					maxEle=in[i];
					maxInd=i;
				}
			}
			sum=pow(2, cnt)*maxEle;
			for(int i=0; i<n; ++i){
				if(i!=maxInd){
					sum+=in[i];
				}
			}
			cout<<((ll)sum)<<"\n";
		} else{
			for(auto &vals: in){
				sum+=vals;
			}
			cout<<sum<<"\n";
		}
	}
}
