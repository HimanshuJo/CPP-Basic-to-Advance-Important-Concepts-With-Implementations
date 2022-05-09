// Temple Offerings
/*
Consider a devotee wishing to give offerings to temples along with a mountain range. 
The temples are located in a row at different heights. Each temple should receive at 
least one offer. If two adjacent temples are at different altitudes, then the temple 
that is higher up should receive more offerings than the one that is lower down. 

If two adjacent temples are at the same height, then their offerings relative to each 
other do not matter. Given the number of temples and the heights of the temples in order, 
find the minimum number of offerings to bring.

Examples:

Input  : 3
         1 2 2
Output : 4
All temples must receive at-least one offering.
Now, the second temple is at a higher altitude
compared to the first one. Thus it receives one
extra offering. 
The second temple and third temple are at the 
same height, so we do not need to modify the 
offerings. Offerings given are therefore: 1, 2,
1 giving a total of 4.

Input  : 6
         1 4 3 6 2 1
Output : 10
We can distribute the offerings in the following
way, 1, 2, 1, 3, 2, 1. The second temple has to 
receive more offerings than the first due to its 
height being higher. The fourth must receive more
than the fifth, which in turn must receive more 
than the sixth. Thus the total becomes 10.
*/
// Time complexity: O(n) 

// Space complexity: O(n)

#include<iostream>
#include<vector>
using namespace std;

int templeOffering(vector<int>&in){
	int sz=in.size();
	vector<int>dp(sz, 1);
	for(int i=1; i<sz; ++i){
		if(in[i]>in[i-1]){
			dp[i]=max(dp[i], dp[i-1]+1);
		}
	}
	for(int i=sz-2; i>=0; --i){
		if(in[i]>in[i+1]){
			dp[i]=max(dp[i], dp[i+1]+1);
		}
	}
	int res=0;
	for(int i=0; i<sz; ++i){
		res+=dp[i];
	}
	return res;
}

int main(){
	vector<int>in{1, 4, 3, 6, 2, 1, 12};
	int res=templeOffering(in);
	cout<<res<<endl;
}