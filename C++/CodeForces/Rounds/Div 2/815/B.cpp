// B. Interesting Sum
/*
You are given an array a that contains n integers. 

You can choose any proper subsegment al,al+1,…,ar of this array, meaning you can choose 
any two integers 1≤l≤r≤n, where r−l+1<n. We define the beauty of a given subsegment as the 
value of the following expression:

max(a1,a2,…,al−1,ar+1,ar+2,…,an)−min(a1,a2,…,al−1,ar+1,ar+2,…,an)+max(al,…,ar)−min(al,…,ar).

Please find the maximum beauty among all proper subsegments.

Output
For each testcase print a single integer — the maximum beauty of a proper subsegment.

Example
input
4
8
1 2 2 3 1 5 6 1
5
1 2 3 100 200
4
3 3 3 3
6
7 8 3 1 1 8

output
9
297
0
14
Note
In the first test case, the optimal segment is l=7, r=8. The beauty of this segment equals to (6−1)+(5−1)=9.

In the second test case, the optimal segment is l=2, r=4. The beauty of this segment equals (100−2)+(200−1)=297.
*/

#include<iostream>
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
		int ans=INT_MIN, curmax=INT_MIN, curmin=INT_MAX, curmaxidx=0, curminidx=0;
		for(int i=0; i<n; ++i){
			if(in[i]>curmax){
				curmaxidx=i;
				curmax=max(curmax, in[i]);
			}
			if(in[i]<curmin){
				curminidx=i;
				curmin=min(curmin, in[i]);
			}
		}
		int secmax=INT_MIN, secmin=INT_MAX;
		for(int i=0; i<n; ++i){
			if(i!=curmaxidx&&in[i]>secmax){
				secmax=max(secmax, in[i]);
			}
			if(i!=curminidx&&in[i]<secmin){
				secmin=min(secmin, in[i]);
			}
		}
		ans=secmax-secmin+curmax-curmin;
		cout<<ans<<endl;
	}
}