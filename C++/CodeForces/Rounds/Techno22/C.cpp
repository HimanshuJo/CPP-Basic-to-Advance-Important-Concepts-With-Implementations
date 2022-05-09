// C. Minimize Distance
/*
A total of n depots are located on a number line. Depot i lies at the point xi for 1<=i<=n.

You are a salesman with n bags of goods, attempting to deliver one bag to each of the n depots. 
You and the n bags are initially at the origin 0. You can carry up to k bags at a time. You must collect the required number of goods from the origin, 
deliver them to the respective depots, and then return to the origin to collect your next batch of goods.

Calculate the minimum distance you need to cover to deliver all the bags of goods to the depots. You do not have to return to the origin after you have delivered all the bags.

Example
input
4
5 1
1 2 3 4 5
9 3
-5 -10 -15 6 5 8 3 7 4
5 3
2 2 3 3 3
4 2
1000000000 1000000000 1000000000 1000000000
output
25
41
7
3000000000
*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
using ll=long long;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin>>t;
	while(t--){
		int n, k;
		cin>>n>>k;
		vector<int>in(n);
		ll sum_pos=0, sum_neg=0;
		for(int i=0; i<n; ++i){
			cin>>in[i];
			if(in[i]>0) sum_pos++;
			if(in[i]<0) sum_neg++;
		}
		sort(in.begin(), in.end());
		int last_neg=-1;
		for(int i=0; i<n; ++i){
			if(in[i]<0){
				last_neg=i;
			}
		}
		ll dist=0;
		ll ind=n-1;
		while(ind>=0&&in[ind]>0){
			dist+=2*in[ind];
			ind-=k;
		}
		ind=0;
		while(ind<n&&in[ind]<0){
			dist+=2*abs(in[ind]);
			ind+=k;
		}
		dist-=max(abs(in[0]), abs(in[n-1]));
		cout<<dist<<"\n";
	}
}

