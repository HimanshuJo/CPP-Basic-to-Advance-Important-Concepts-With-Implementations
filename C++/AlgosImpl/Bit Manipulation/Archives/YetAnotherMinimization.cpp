// D. Yet Another Minimization Problem
/*
You are given two arrays a and b, both of length n.

You can perform the following operation any number of times (possibly zero): 
select an index i (1≤i≤n) and swap ai and bi.

Let's define the cost of the array a as ∑i=1 to n ∑j=i+1 to n (ai+aj)^2. 
Similarly, the cost of the array b is ∑i=1 to n ∑j=i+1 to n (bi+bj)^2.

Your task is to minimize the total cost of two arrays.

Input
Each test case consists of several test cases. 
The first line contains a single integer t (1≤t≤40) — the number of test cases. 
The following is a description of the input data sets.

The first line of each test case contains an integer n (1≤n≤100) — the length of both arrays.

The second line of each test case contains n integers a1,a2,…,an (1≤ai≤100) — elements of the first array.

The third line of each test case contains n integers b1,b2,…,bn (1≤bi≤100) — elements of the second array.

It is guaranteed that the sum of n over all test cases does not exceed 100.

Output
For each test case, print the minimum possible total cost.

Example
input
3
1
3
6
4
3 6 6 6
2 7 4 1
4
6 7 2 4
2 5 3 5

output
0
987
914
Note
In the second test case, in one of the optimal answers after all operations a=[2,6,4,6], b=[3,7,6,1].

The cost of the array a equals to (2+6)^2+(2+4)^2+(2+6)^2+(6+4)^2+(6+6)^2+(4+6)^2=508.

The cost of the array b equals to (3+7)^2+(3+6)^2+(3+1)^2+(7+6)^2+(7+1)^2+(6+1)^2=479.

The total cost of two arrays equals to 508+479=987.

*/
/*
Solution:

The cost of the array a equals to ∑i=1 to n ∑j=i+1 to n (ai+aj)^2=∑i=1 to n ∑j=i+1 to n (a^2i+a^2j+2aiaj).

Let s=∑i=1 to n ai.

Then cost=(n−1) ⋅ ∑i=1 to n a^2i + ∑i=1 to n (ai⋅(s−ai)) = (n−1) ⋅ ∑i=1 to n a^2i+s^2−∑i=1 to n a^2i
                                                        = (n−2) ⋅ ∑i=1 to n a^2i+(∑i=1 to n ai)^2

Then the total cost of two arrays equals to (n−2) ⋅ ∑i=1 to n (a^2i+b^2i)+(∑i=1 to n ai)^2+(∑i=1 to n bi)^2. 

The first term is a constant ⇒ we need to minimize (∑i=1 to n ai)^2+(∑i=1 to n bi)^2.

There are two continuations of the solution, 
but the idea of both is to iterate over all possible sum of the array a, 
then calculate the sum of the array b and update the answer using formula written above:

Let dpi,w is true if it's possible to make some operations so that the sum of first i elements in the array a equals to w, 
otherwise dpi,w is false. 

Then dp1,a1=dp1,b1= true. For i>1: dpi,w=dpi−1,w−ai or dpi−1,w−bi. 
Then to iterate over all possible sums of the array a you need to consider such s, that dpn,s= true.

Assume, that we have n items, where i-th item has a weight of |bi−ai|. 
By solving simple backpack problem let's find all possible sums of weights of these items. 
And if the sum contains i-th item, then we will assume that ai≥bi, otherwise ai≤bi. 
So if the sum of weights of some items equals to s, then the sum of the array a equals to 
∑i=1 to n min(ai,bi)+s. 

So all possible sums of the array a can be received from all possible sums of weights of these items.

Both solutions works in O(n^2⋅maxA) where maxA=100, 
and both solutions can be optimized with std::bitest, speeding up them by 64 times, but it wasn't necessary.
*/

/*TLE:
#include<iostream>
#include<vector>
#include<map>
using namespace std;

int dfs(vector<int>&a, vector<int>&b, int n, int idx, int curmin, int &minn, map<tuple<vector<int>, vector<int>, int>, int>&memo){
	if(idx>=n) return 0;
	tuple<vector<int>, vector<int>, int>tup1(a, b, idx);
	if(memo.find(tup1)!=memo.end()) return memo[tup1];
	int ans1=0, ans2=0;
	for(int x=0; x<=n-1; ++x){
		for(int y=x+1; y<n; ++y){
			ans1+=((a[x]+a[y])*(a[x]+a[y]));
		}
	}
	for(int x=0; x<=n-1; ++x){
		for(int y=x+1; y<n; ++y){
			ans2+=((b[x]+b[y])*(b[x]+b[y]));
		}
	}
	int curmintmp1=ans1+ans2;
	vector<int>tempa=a;
	vector<int>tempb=b;
	swap(tempa[idx], tempb[idx]);
	int ans1_=0, ans2_=0;
	for(int x=0; x<=n-1; ++x){
		for(int y=x+1; y<n; ++y){
			ans1_+=((tempa[x]+tempa[y])*(tempa[x]+tempa[y]));
		}
	}
	for(int x=0; x<=n-1; ++x){
		for(int y=x+1; y<n; ++y){
			ans2_+=((tempb[x]+tempb[y])*(tempb[x]+tempb[y]));
		}
	}
	int curmintmp2=ans1_+ans2_;
	minn=min(minn, min(curmintmp1, curmintmp2));
	curmin=min(dfs(a, b, n, idx+1, curmintmp1, minn, memo), dfs(tempa, tempb, n, idx+1, curmintmp2, minn, memo));
	return memo[tup1]=curmin;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		vector<int>a(n), b(n);
		for(int i=0; i<n; ++i)
			cin>>a[i];
		for(int i=0; i<n; ++i)
			cin>>b[i];
		int minn=INT_MAX, curmin=0;
		map<tuple<vector<int>, vector<int>, int>, int>memo;
		dfs(a, b, n, 0, curmin, minn, memo);
		cout<<minn<<"\n";
	}
}
*/

#include <bits/stdc++.h>
using namespace std;
 
constexpr int MAXSUM = 100 * 100 + 10;
 
int sqr(int x) {
    return x * x;
}
 
void solve() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (auto& u : a)
        cin >> u;
 
    for (auto& u : b)
        cin >> u;
 
    int sumMin = 0, sumMax = 0, sumSq = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] > b[i])
            swap(a[i], b[i]);
 
        sumSq += sqr(a[i]) + sqr(b[i]);
        sumMin += a[i];
        sumMax += b[i];
    }
 
    bitset<MAXSUM> dp;
    dp[0] = 1;
    for (int i = 0; i < n; i++)
        dp |= dp << (b[i] - a[i]);
 
    int ans = sqr(sumMin) + sqr(sumMax);
    for (int i = 0; i <= sumMax - sumMin; i++)
        if (dp[i])
            ans = min(ans, sqr(sumMin + i) + sqr(sumMax - i));
    cout << sumSq * (n - 2) + ans << '\n';
}
 
int main() {
    int t;
    cin >> t;
    while (t--)
        solve();
}