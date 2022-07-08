// C - 1111gal password
/*
Problem Statement
Given an integer N, find the number of integers X that satisfy all of the following conditions, modulo 998244353.

X is an N-digit positive integer.

Let X1 ,X2,…,XN be the digits of X from top to bottom. They satisfy all of the following:

1≤Xi≤9 for all integers 1≤i≤N;

∣Xi−Xi+1∣≤1 for all integers 1≤i≤N−1.

Constraints
N is an integer.
2≤N≤10^6

Input
Input is given from Standard Input in the following format:

N

Output
Print the answer as an integer.

Sample Input 1 
4

Sample Output 1 
203

Some of the 4-digit integers satisfying the conditions are 1111,1234,7878,6545.

Sample Input 2 
2

Sample Output 2 
25

Sample Input 3 
1000000

Sample Output 3 
248860093

Be sure to find the count modulo 998244353
*/
/*
Solution:

First, let us consider how to enumerate all N-digit flat numbers.

Let list[D][r]= (the set of D-digit flat numbers ending with r), which we will find in the increasing order of D

Obviously, list[1][i]={i}, so we will start from here.

We will consider obtaining list[D+1] from list[D] by appending a digit to each element.

Clearly, if “X is a (D+1)-digit flat number”, then “the first D digits of X forms a flat number.” 
That’s why each element of list[D+1] can be obtained by appending a digit to an
element of list[D]. 

We can also see that a D-digit flat number succeeded by a digit becomes a (D+1)-digit 
flat number if and only if the difference between the final digit of the D-digit flat number 
and the digit to be appended is at most 1.

Therefore, what we have to do is as follows.

For each integer 1≤i≤9, do the following operation.

	For each integer max(1,i−1)≤j≤min(9,i+1), do the following operation.

	For every element E in list[D][i], add E succeeded by j to list[D+1][j].

For example, we have list[2][9]={89,99}, 
so we will add to list[3][8] every element of list[2][9] succeeded by 8, that is, {898,998}. 

This kind of operations are done in the increasing order of D.

The set of N-digit flat numbers is entire list[N].

Here, obviously but importantly, if the elements of list[D] are pairwise distinct, 
then those of list[D+1] are pairwise distinct too.
Therefore, we could enumerate all the flat numbers exhaustively without duplicates.

However, we cannot store all the elements of the sets, both in terms of space complexity 
and time complexity, so we will find only the number of integers satisfying the conditions instead.

Let us consider computing dp[D][r]= (the number of D-digit flat numbers ending with r) one by one.

This can be obtained in the same way as before, but instead of enumerating each element, 
we only have to count the numbers. It is essentially the same as the generation of list, 
so we will omit the details.
*/

#include<iostream>
using namespace std;

int mod=998244353;
int dp[1048576][10]={0};

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int N; cin>>N;
	for(int i=1; i<=9; ++i){
		dp[1][i]=1;
	}
	for(int d=2; d<=N; ++d){
		for(int i=1; i<=9; ++i){
			for(int j=max(1, i-1); j<=min(9, i+1); ++j){
				dp[d][j]+=dp[d-1][i];
				dp[d][j]%=mod;
			}
		}
	}
	int res=0;
	for(int i=1; i<=9; ++i){
		res+=dp[N][i];
		res%=mod;
	}
	cout<<res<<"\n";
}