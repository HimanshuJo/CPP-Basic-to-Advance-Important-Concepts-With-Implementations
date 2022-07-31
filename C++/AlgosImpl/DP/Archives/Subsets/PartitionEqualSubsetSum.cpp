// Partition Equal Subset Sum
/*
Given an array arr[] of size N, check if it can be partitioned into two parts such 
that the sum of elements in both parts is the same.

Example 1:

Input: N = 4
arr = {1, 5, 11, 5}
Output: YES
Explanation: 
The two parts are {1, 5, 5} and {11}.
Example 2:

Input: N = 3
arr = {1, 3, 5}
Output: NO
Explanation: This array can never be 
partitioned into two such parts.

Your Task:
You do not need to read input or print anything. Your task is to complete the function 
equalPartition() which takes the value N and the array as input parameters and returns 1 
if the partition is possible. 

Otherwise, returns 0.

Expected Time Complexity: O(N*sum of elements)
Expected Auxiliary Space: O(N*sum of elements)

Constraints:
1 ≤ N ≤ 100
1 ≤ arr[i] ≤ 1000
*/

class Solution{
public:

    int dfs(int N, int arr[], int idx, int target, vector<vector<int>>&memo){
        if(idx>=N) return 0;
        if(target<0) return 0;
        if(target==0) return 1;
        if(memo[idx][target]!=-1) return memo[idx][target];
        int ntpk=dfs(N, arr, idx+1, target, memo);
        if(ntpk) return 1;
        int pk=dfs(N, arr, idx+1, target-arr[idx], memo);
        if(pk) return 1;
        return memo[idx][target]=ntpk||pk;
    }

    // TC: O(N*Sum of elements)
    // SC: O(N*Sum of elements) + Aux. stack space
    int equalPartition(int N, int arr[])
    {
        int sm=0;
        for(int i=0; i<N; ++i){
            sm+=arr[i];
        }
        if(sm%2!=0) return 0;
        int target=sm/2;
        vector<vector<int>>memo(N+1, vector<int>(target+1, -1));
        return dfs(N, arr, 0, target, memo);
    }

    // TC: O(N*Sum of elements)
    // SC: O(N*Sum of elements)
    int equalPartitionTab(int N, int arr[]){
        int sm=0;
        for(int i=0; i<N; ++i){
            sm+=arr[i];
        }
        if(sm%2!=0) return 0;
        int target=sm/2;
        vector<vector<int>>dp(N+1, vector<int>(target+1, 0));
        for(int i=0; i<=N; ++i){
            dp[i][0]=1;
        }
        for(int i=N-1; i>=0; --i){
            for(int j=0; j<=target; ++j){
                int ntpk=dp[i+1][j];
                int pk=0;
                if(j-arr[i]>=0){
                    pk=dp[i+1][j-arr[i]];
                }
                dp[i][j]=pk||ntpk;
            }
        }
        return dp[0][target];
    }

    // TC: O(N*Sum of elements)
    // SC: O(Sum of elements)
    int equalPartitionTab2(int N, int arr[]){
        int sm=0;
        for(int i=0; i<N; ++i){
            sm+=arr[i];
        }
        if(sm%2!=0) return 0;
        int target=sm/2;
        vector<int>curr(target+1, 0), next(target+1, 0);
        curr[0]=1, next[0]=1;
        for(int i=N-1; i>=0; --i){
            for(int j=0; j<=target; ++j){
                int ntpk=next[j];
                int pk=0;
                if(j-arr[i]>=0){
                    pk=next[j-arr[i]];
                }
                curr[j]=pk||ntpk;
            }
            next=curr;
        }
        return curr[target];
    }
};

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}