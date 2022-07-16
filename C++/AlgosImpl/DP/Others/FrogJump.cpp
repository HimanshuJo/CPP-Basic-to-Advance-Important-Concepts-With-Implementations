// Frog Jump
/*
Problem Statement:

	There is a frog on the 1st step of an N stairs long staircase. 
	The frog wants to reach the Nth stair. 

	HEIGHT[i] is the height of the (i+1)th stair.

	If Frog jumps from ith to jth stair, the energy lost in the jump is given by 
	|HEIGHT[i-1] - HEIGHT[j-1] |.

	In the Frog is on ith staircase, he can jump either to (i+1)th stair or to (i+2)th stair. 
	Your task is to find the minimum total energy used by the frog to reach from 1st stair to Nth stair.

	For Example
		
		If the given ‘HEIGHT’ array is [10,20,30,10], 
		the answer 20 as the frog can jump from 1st stair to 2nd stair (|20-10| = 10 energy lost) and 
		then a jump from 2nd stair to last stair (|10-20| = 10 energy lost). 

		So, the total energy lost is 20.
*/

#include<climits>

// TC: O(N*2)
// SC: O(N)+ auxiliary space
int dfs(int n, vector<int>&heigths, int idx, vector<int>&memo){
    if(idx<=0) return 0;
    if(memo[idx]!=-1) return memo[idx];
    int ans=INT_MAX;
    for(int i=1; i<=2; ++i){
        if(idx-i>=0){
            int jmp=abs(heigths[idx-i]-heigths[idx])+dfs(n, heigths, idx-i, memo);
            ans=min(ans, jmp);
        }
    }
    return memo[idx]=ans;
}

// TC: O(N*2)
// SC: O(N)+ auxiliary space
int dfs2(int n, vector<int>&heigths, int idx, vector<int>&memo){
    if(idx<=0) return 0;
    if(memo[idx]!=-1) return memo[idx];
    int jmp=INT_MAX, fj=0, sj=0;
    if(idx-1>=0){
        fj+=abs(heigths[idx]-heigths[idx-1])+dfs(n, heigths, idx-1, memo);
    }
    if(idx-2>=0){
        sj+=abs(heigths[idx]-heigths[idx-2])+dfs(n, heigths, idx-2, memo);
    }
    jmp=min(jmp, min(fj, sj));
    return memo[idx]=jmp;
}

int frogJump1(int n, vector<int> &heights)
{
    vector<int>memo(n, -1);
    int ans=dfs(n, heights, n-1, memo);
    return ans;
}

// TC: O(N*K)
// SC: O(N)
int frogJump2(int n, vector<int> &heights)
{
    vector<int>dp(n, 0);
    for(int i=0; i<n; ++i){
        int ans=INT_MAX;
        for(int j=1; j<=2; ++j){
            if(i-j>=0){
                int jmp=abs(heights[i-j]-heights[i])+dp[i-j];
                ans=min(ans, jmp);
            }
        }
        if(ans!=INT_MAX)
            dp[i]=ans;
    }
    return dp[n-1];
}