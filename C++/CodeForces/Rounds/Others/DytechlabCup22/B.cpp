// B. Ela's Fitness and the Luxury Number
/*
Since she started engaging in sports activities, Ela switches to trying a new sport on days she considers 
being "Luxury" days. She counts the days since she started these activities, in which the day she starts 
is numbered as day 1. A "Luxury" day is the day in which the number of this day is a luxurious number.

An integer x is called a luxurious number if it is divisible by ⌊√x⌋.

Here ⌊r⌋ denotes the "floor" of a real number r. In other words, it's the largest integer not greater than r.

For example: 8, 56, 100 are luxurious numbers, since 8 is divisible by ⌊√8⌋=⌊2.8284⌋=2,56 
is divisible ⌊√56⌋=⌊7.4833⌋=7, and 100 is divisible by ⌊√100⌋=⌊10⌋=10, respectively. 

On the other hand 5, 40 are not, since 5 are not divisible by ⌊√5⌋=⌊2.2361⌋=2, and 40 are not divisible by ⌊√40⌋=⌊6.3246⌋=6.

Being a friend of Ela, you want to engage in these fitness activities with her to keep her and 
yourself accompanied (and have fun together, of course). 

Between day l and day r, you want to know how many times she changes the activities.

Input
Each test contains multiple test cases. The first line has the number of test cases t (1≤t≤10 000). 
The description of the test cases follows.

The only line of each test case contains two integers l and r (1≤l≤r≤10^18) — 
the intervals at which you want to know how many times Ela changes her sports.

Output
For each test case, output an integer that denotes the answer.

Example
input
5
8 19
8 20
119 121
1 100000000000000000
1234567891011 1000000000000000000

output
5
6
2
948683296
2996666667
Note
In the first test case, 5 luxury numbers in range [8,19] are: 8,9,12,15,16.
*/

#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
#define endl "\n"
using ll=long long;
using namespace std;

ll bs_sqrt(ll num){
	ll left=0, right=1414213562;
	while(left<right){
		ll mid=left+(right-left)/2;
		if(num<mid*mid){
			right=mid;
		} else{
			left=mid+1;
		}
	}
	return left-1;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin>>t;
	while(t--){
		ll L, R;
		cin>>L>>R;
		ll sql=bs_sqrt(L), sqr=bs_sqrt(R);
		ll ans;
		if(sql==sqr){
			ans=0;
			for(int i=0; i<3; ++i){
				if(L<=sql*(sql+i)&&sql*(sql+i)<=R){
					ans++;
				}
			}
		} else{
			ans=(sqr-sql-1)*3;
			for(int i=0; i<3; ++i){
				if(L<=sql*(sql+i)&&sql*(sql+i)<=R){
					ans++;
				}
				if(L<=sqr*(sqr+i)&&sqr*(sqr+i)<=R){
					ans++;
				}
			}
		}
		cout<<ans<<endl;
	}
}