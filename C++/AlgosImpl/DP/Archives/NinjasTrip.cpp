// Ninja's Trip
/*
Problem Statement:

Ninja Is Willing To Take Some Time Off From His Training And Planning A Year-Long Tour.

You Are Given A DAYS Array Consisting Of ‘N’ Days When Ninjas Will Be Traveling During The Year. 
Each Day Is An Integer Between 1 To 365 (Both Inclusive).

Train Tickets Are Sold In Three Different Ways:

A 1-day pass is sold for 'COST'[0] coins,
A 7-day pass is sold for 'COST'[1] coins, and
A 30-day  pass is sold for 'COST'[2] coins.

The passes allow for many days of consecutive travel.

Your Task Is To Help The Ninja To Find The Minimum Number Of Coins Required To Complete His Tour.

For Example,

If Ninja gets a 7-day pass on day 2, then he can travel for 7 days: 2, 3, 4, 5, 6, 7, and 8.
*/

// TC: O(N)  N: number of calendar days
// SC: O(N)
int dfs(int n, vector<int>&days, vector<int>&cost, int idx, vector<int>&memo){
    if(idx>=n) return 0;
    if(memo[idx]!=-1) return memo[idx];
    int ans=INT_MAX;
    int pass1=cost[0]+dfs(n, days, cost, idx+1, memo);
    int i;
    for(i=idx; i<n&&days[i]<days[idx]+7; ++i);
    int pass2=cost[1]+dfs(n, days, cost, i, memo);
    int j;
    for(j=idx; j<n&&days[j]<days[idx]+30; ++j);
    int pass3=cost[2]+dfs(n, days, cost, j, memo);
    ans=min(ans, min(pass1, min(pass2, pass3)));
    return memo[idx]=ans;
}

int minimumCoins(int n, vector<int> days, vector<int> cost)
{
    vector<int>memo(n+1, -1);
    int ans=dfs(n, days, cost, 0, memo);
    return ans;
}