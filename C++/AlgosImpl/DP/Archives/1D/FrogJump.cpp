/*
Problem Statement:

Given a number of stairs and a frog, the frog wants to climb from the 0th stair to the
(N-1)th stair. At a time the frog can climb either one or two steps.

A height[N] array is also given. Whenever the frog jumps from a stair i to stair j,
the energy consumed in the jump is abs(height[i]-height[j]),
where abs() means the absolute difference.

We need to return the minimum energy that can be used by the frog to jump from
stair 0 to stair N-1.
*/
/*
First, we will see why a greedy approach will not work?

	The total energy required by the frog depends upon the path taken by the frog.
	If the frog just takes the cheapest path in every stage it can happen that it eventually
	takes a costlier path after a certain number of jumps
*/

#include <bits/stdc++.h>

using namespace std;

/*
Time Complexity: O(N)

	Reason: The overlapping subproblems will return the answer in constant time O(1).
	        Therefore the total number of new subproblems we solve is ‘n’.
	        Hence total time complexity is O(N).

Space Complexity: O(N)

	Reason: We are using a recursion stack space(O(N)) and an array (again O(N)).
	        Therefore total space complexity will be O(N) + O(N) ≈ O(N)
*/

/*
Tabulation:

#include <bits/stdc++.h>
using namespace std;

int main() {
  vector<int>height{30,10,60,10,60,50};
  int n=height.size();
  vector<int>dp(n,-1);
  dp[0]=0;
  for(int ind=1; ind<n; ind++){
      int jumpTwo=INT_MAX;
        int jumpOne=dp[ind-1]+abs(height[ind]-height[ind-1]);
        if(ind>1)
            jumpTwo=dp[ind-2]+abs(height[ind]-height[ind-2]);
        dp[ind]=min(jumpOne, jumpTwo);
  }
  cout<<dp[n-1];
}
*/


int solve(int ind, vector<int>& height, vector<int>& dp) {
	if (ind == 0) return 0;
	if (dp[ind] != -1) return dp[ind];
	int jumpTwo = INT_MAX;
	int jumpOne = solve(ind - 1, height, dp) + abs(height[ind] - height[ind - 1]);
	if (ind > 1)
		jumpTwo = solve(ind - 2, height, dp) + abs(height[ind] - height[ind - 2]);

	return dp[ind] = min(jumpOne, jumpTwo);
}


int main() {
	vector<int> height{30, 10, 60, 10, 60, 50};
	int n = height.size();
	vector<int> dp(n, -1);
	cout << solve(n - 1, height, dp);
}