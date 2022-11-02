/*
Given weights and values of n items, put these items in a knapsack of capacity W
to get the maximum total value in the knapsack.

In other words, given two integer arrays val[0..n-1] and wt[0..n-1] which
represent values and weights associated with n items respectively.

Also given an integer W which represents knapsack capacity, find out the maximum value
subset of val[] such that sum of the weights of this subset is smaller than or equal to W.

You cannot break an item, either pick the complete item or don’t pick it (0-1 property).

Example:

int val[]{60, 100, 120, 130, 45, 12, 34, 56, 77, 89, 34, 122};
int wts[]{10, 20, 30, 34, 56, 12, 34, 33, 67, 78, 45, 45};
int knapSackWt=250;

Output: 677
*/

#include<iostream>
using namespace std;

int dfs(int val[], int wts[], int knapSackWt, int N, int idx, int **memo){
    if(idx>=N||knapSackWt<=0) return 0;
    if(memo[idx][knapSackWt]!=-1) return memo[idx][knapSackWt];
    if(wts[idx]>knapSackWt){
        return memo[idx][knapSackWt]=dfs(val, wts, knapSackWt, N, idx+1, memo);
    } else{
        return memo[idx][knapSackWt]=max(dfs(val, wts, knapSackWt, N, idx+1, memo),
                                         val[idx]+dfs(val, wts, knapSackWt-wts[idx], N, idx+1, memo));
    }
    return 0;
}

int zeroOneKnapSack(int val[], int wts[], int knapSackWt, int N, int idx, int **memo){
    return dfs(val, wts, knapSackWt, N, idx, memo);
}

int main(){
    int val[]{60, 100, 120, 130, 45, 12, 34, 56, 77, 89, 34, 122};
    int wts[]{10, 20, 30, 34, 56, 12, 34, 33, 67, 78, 45, 45};
    int knapSackWt=250;
    int N=sizeof(val)/sizeof(val[0]);
    int **memo=new int*[N];
    for(int i=0; i<N; ++i){
        memo[i]=new int[knapSackWt+1];
    }
    for(int i=0; i<N; ++i){
        for(int j=0; j<=knapSackWt; ++j){
            memo[i][j]=-1;
        }
    }
    int idx=0;
    cout<<zeroOneKnapSack(val, wts, knapSackWt, N, idx, memo);
}