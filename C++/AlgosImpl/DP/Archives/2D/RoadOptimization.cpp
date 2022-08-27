// C. Road Optimization
/*
The Government of Mars is not only interested in optimizing space flights, but also wants to improve the road system of the planet.

One of the most important highways of Mars connects Olymp City and Kstolop, the capital of Cydonia. 
In this problem, we only consider the way 
from Kstolop to Olymp City, but not the reverse path (i. e. the path from Olymp City to Kstolop).

The road from Kstolop to Olymp City is ℓ kilometers long. Each point of the road has a coordinate x (0<=x<=l), 
which is equal to the distance from Kstolop in kilometers. 
So, Kstolop is located in the point with coordinate 0, and Olymp City is located in the point with coordinate l.

There are n signs along the road, i-th of which sets a speed limit ai. This limit means that the next kilometer must 
be passed in ai minutes and is 
active until you encounter the next along the road. There is a road sign at the start of the road 
(i. e. in the point with coordinate 0), which sets the initial speed limit.

If you know the location of all the signs, it's not hard to calculate how much time it takes to drive from Kstolop to Olymp City. 
Consider an example:

Here, you need to drive the first three kilometers in five minutes each, then one kilometer in eight minutes, 
then four kilometers in three minutes each, 
and finally the last two kilometers must be passed in six minutes each. Total time is 3*5+1*8+4*3+2*6=47 minutes.

To optimize the road traffic, the Government of Mars decided to remove no more than k road signs. 
It cannot remove the sign at the start of the road, otherwise, 
there will be no limit at the start. By removing these signs, the Government also wants to make the time needed 
to drive from Kstolop to Olymp City as small as possible.

The largest industrial enterprises are located in Cydonia, so it's the priority task to optimize the road traffic from Olymp City. 
So, the Government of Mars wants you to remove the signs in the way described above.

Output
Print a single integer — minimal possible time to drive from Kstolop to Olymp City in minutes, 
if you remove no more than k road signs.

Examples
input
4 10 0
0 3 4 8
5 8 3 6

output
47

input
4 10 2
0 3 4 8
5 8 3 6

output
38
*/

#include<iostream>
#include<vector>
using namespace std;

int dfs(vector<int>&coordsSgn, vector<int>&spdLim, int n, vector<vector<int>>&memo, int idx, int currT, int k){
	if(idx==n) return 0;
	if(memo[idx][k]!=-1) return memo[idx][k];
	int minT=INT_MAX;
	for(int rem=0; rem<=k; ++rem){
		if(idx+rem>=n) break;
		int currDist=abs(coordsSgn[idx]-coordsSgn[idx+rem+1]);
		int fct=spdLim[idx];
		currT=(currDist*fct);
		minT=min(minT, currT+dfs(coordsSgn, spdLim, n, memo, idx+rem+1, currT, k-rem));
	}
	return memo[idx][k]=minT;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, l, k;
	cin>>n>>l>>k;
	vector<int>coordsSgn(n+1);
	for(int i=0; i<n; ++i)
		cin>>coordsSgn[i];
	coordsSgn[n]=l;
	vector<int>spdLim(n);
	vector<vector<int>>memo(n+1, vector<int>(n+1, -1));
	for(int i=0; i<n; ++i)
		cin>>spdLim[i];
	int currT=0;
	int ans=dfs(coordsSgn, spdLim, n, memo, 0, currT, k);
	cout<<ans<<"\n";
}
