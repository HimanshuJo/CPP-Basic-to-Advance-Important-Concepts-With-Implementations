// 1916. Count Ways to Build Rooms in an Ant Colony
/*
You are an ant tasked with adding n new rooms numbered 0 to n-1 to your colony.
You are given the expansion plan as a 0-indexed integer array of length n, prevRoom,
where prevRoom[i] indicates that you must build room prevRoom[i] before building room i, and these two rooms
must be connected directly.

Room 0 is already built, so prevRoom[0] = -1. The expansion plan is given such that once all the rooms are built,
every room will be reachable from room 0.

You can only build one room at a time, and you can travel freely between rooms you have already built only
if they are connected.
You can choose to build any room as long as its previous room is already built.

Return the number of different orders you can build all the rooms in. Since the answer may be large,
return it modulo 10^9 + 7.

Input: prevRoom = [-1,0,1]
Output: 1
Explanation: There is only one way to build the additional rooms: 0 → 1 → 2

Input: prevRoom = [-1,0,0,1,2]
Output: 6
Explanation:
The 6 ways are:
0 → 1 → 3 → 2 → 4
0 → 2 → 4 → 1 → 3
0 → 1 → 2 → 3 → 4
0 → 1 → 2 → 4 → 3
0 → 2 → 1 → 3 → 4
0 → 2 → 1 → 4 → 3

Constraints:

    n == prevRoom.length
    2 <= n <= 10^5
    prevRoom[0] == -1
    0 <= prevRoom[i] < n for all 1 <= i < n
    Every room is reachable from room 0 once all the rooms are built.

'''

'''
Intuition:

	Since we have to build the previous room (prevRoom[i]) before building the room i, therefore it is a
	problem of Directed Graph

	Also every room is reachable from room 0, therefore it is tree problem

	Why not graph?

		because each room can only have one prevRoom (We can use Recursion to solve this problem)

	-------

	Initially thinking of a simple scenario, where a node has just two branches, and each branch is a chain
		(dfs(child) = 1)

		dfs(cur) is equivalent to count the number of ways to combine two arrays and maintain their original order

		Suppose the length of these two array is l+r

			hence the answer is: math.comb(l + r, l)

			another way of thinking this is to put 'l' item into 'l+r' spots and fill the remaining spots with the other
				'r' items

	Suppose the branch is not a chain
		e.g. dfs(leftChild) = x, and
			 dfs(rightChild) = y

			 We can just multiply them together

			 so the solution become x * y * math.comb(l+r, l)

	Suppose there are many branches, So we can combine them one by one:
		Take the leftmost branch first,
		get the merged branch
		merge it with the third branch and so on

	-------

	How to calculate 'n choose k without math.comb'

		For python users, math.comb comes in handy.

			But what if we have to calculate math.comb(n, k) without using any in-built function

			We can think like:

				caching fac(n) and calculating it as
					comb(n, k) = n! / (k! * (n-k)!)

					But this is not enough we've to incorporate mod into the whole equation

Approach:

	We can start from a very basic example, and then we can try to build the basic pieces and finally combined them to a more
		complicated scenario

	-------

	Suppose we have three nodes from a root node:

		0 -> T1
		  -> T2
		  -> T3

	  	So whenever we try to merge Tree (T3) with T1 and T2
	  		we will need a curNodeCnt, that will store the current node we've already processed

	  		and to merge with the current one, we've to do the combinations:
	  			it will be:
	  				Combinations = Factorial[curNodeCnt + \
	  				    subTreeNodeCnt] // Fact[curNodeCnt] // Fact[subTreeNodeCnt]

	  				same as: l+rCl

Note:

	nCk = n!/(n-k)! k!

	And in total we have 10^5 nodes, we cannot simply perform the factorial of 10^5

		Therefore we can perform modulo on-top of it

		This is a trick to calculate the factorial for a big number
			Basically:

			 (Factorial + Inverse of Factorial + Modulo)

*/

#include <bits/stdc++.h>
using ll = long long;
using namespace std;

class Solution
{
public:
	int waysToBuildRooms(vector<int> &prevRoom)
	{
		int n = prevRoom.size();

		// Construct tree.
		vector<vector<int>> g(n);
		for (int i = 1; i < n; ++i)
		{
			g[prevRoom[i]].push_back(i);
		}

		// Pre-process fac and inv fac.
		vector<ll> fac(n + 1, 1), ifac(n + 1, 1);
		for (int i = 2; i <= n; ++i)
		{
			fac[i] = fac[i - 1] * i % mod;
			ifac[i] = qpow(fac[i], mod - 2);
		}

		return dfs(g, fac, ifac, 0).first;
	}

private:
	static constexpr int mod = 1e9 + 7;

	ll qpow(ll x, size_t n)
	{
		ll ans = 1;
		for (auto i = n; i; i /= 2)
		{
			if (i % 2)
				ans = ans * x % mod;
			x = x * x % mod;
		}
		return ans;
	}

	pair<ll, ll> dfs(const vector<vector<int>> &g, const vector<ll> &fac, const vector<ll> &ifac, int cur)
	{
		if (g[cur].size() == 0)
			return {1, 1};
		ll ans = 1, l = 0;
		for (int nxt : g[cur])
		{
			pair<ll, ll> nextpair;
			nextpair = dfs(g, fac, ifac, nxt);
			ll comb = (((fac[l + nextpair.second] * ifac[l]) % mod) * ifac[nextpair.second]) % mod;
			ans = (ans * nextpair.first % mod) * comb % mod;
			l += nextpair.second;
		}
		return {ans, l + 1};
	}
};