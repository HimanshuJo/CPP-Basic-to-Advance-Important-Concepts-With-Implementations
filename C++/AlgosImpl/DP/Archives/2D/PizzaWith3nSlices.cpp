// 1388. Pizza With 3n Slices
/*
There is a pizza with 3n slices of varying size, you and your friends will take slices 
of pizza as follows:

You will pick any pizza slice.
Your friend Alice will pick the next slice in the anti-clockwise direction of your pick.
Your friend Bob will pick the next slice in the clockwise direction of your pick.
Repeat until there are no more slices of pizzas.

Given an integer array slices that represent the sizes of the pizza slices in a clockwise direction, 
return the maximum possible sum of slice sizes that you can pick.

Input: slices = [1,2,3,4,5,6]
Output: 10

Explanation: Pick pizza slice of size 4, Alice and Bob will pick slices with size 3 and 5 respectively. 
Then Pick slices with size 6, finally Alice and Bob will pick slice of size 2 and 1 respectively. Total = 4 + 6.

Input: slices = [8,9,8,6,1,1]
Output: 16
Explanation: Pick pizza slice of size 8 in each turn. If you pick slice with size 9 your partners 
will pick slices of size 8.
 
Constraints:

3 * n == slices.length
1 <= slices.length <= 500
1 <= slices[i] <= 1000
*/

// TC: O(N*N)
// SC: O(N*N) + aux stack space
class Solution {
public:
    
    int dfs(vector<int>&slices, int bgn, int end, int k, vector<vector<int>>&memo){
        if(bgn>end||k<=0) return 0;
        if(memo[bgn][k]!=-1) return memo[bgn][k];
        int pk=slices[bgn]+dfs(slices, bgn+2, end, k-3, memo);
        int ntpk=dfs(slices, bgn+1, end, k, memo);
        return memo[bgn][k]=max(pk, ntpk);
    }
    
    int maxSizeSlices(vector<int>& slices) {
        int sz=slices.size();
        vector<vector<int>>memo(sz+1, vector<int>(sz+1, -1));
        int ans1=dfs(slices, 0, sz-2, sz, memo);
        memo.clear();
        memo.resize(sz+1, vector<int>(sz+1, -1));
        int ans2=dfs(slices, 1, sz-1, sz, memo);
        return max(ans1, ans2);
    }
};

// -------*******-------

// TC: O(N*N)
// SC: O(N*N)
class Solution2 {
public:
    
    int maxSizeSlices(vector<int>& slices) {
        int sz=slices.size();
        vector<vector<int>>dp(sz+1, vector<int>(sz+1, 0));
        for(int i=sz-2; i>=0; --i){
        	// we can always take three slices else, j=1 to sz works
            for(int j=3; j<=sz; j++){
                int pk=slices[i]+dp[i+2][j-3];      
                int ntpk=dp[i+1][j];
                dp[i][j]=max(pk, ntpk);
            }
        }
        int cs1=dp[0][sz];
        vector<vector<int>>dp2(sz+3, vector<int>(sz+1, 0));
        for(int i=sz-1; i>=1; --i){
            for(int j=3; j<=sz; j++){
                int pk=slices[i]+dp2[i+2][j-3];      
                int ntpk=dp2[i+1][j];
                dp2[i][j]=max(pk, ntpk);
            }
        }
        int cs2=dp2[1][sz];
        return max(cs1, cs2);
    }
};

// -------*******-------

// TC: O(N*N)
// SC: O(3N)
class Solution {
public:
    
    int maxSizeSlices(vector<int>& slices) {
        int sz=slices.size();
        vector<int>curr(sz+1, 0), next1(sz+1, 0), next2(sz+1, 0);
        for(int i=sz-2; i>=0; --i){
            for(int j=3; j<=sz; j++){
                int pk=slices[i]+next2[j-3];      
                int ntpk=next1[j];
                curr[j]=max(pk, ntpk);
            }
            next2=next1;
            next1=curr;
        }
        int cs1=curr[sz];
        vector<int>curr_(sz+1, 0), next1_(sz+1, 0), next2_(sz+1, 0);
        for(int i=sz-1; i>=1; --i){
            for(int j=3; j<=sz; j++){
                int pk=slices[i]+next2_[j-3];      
                int ntpk=next1_[j];
                curr_[j]=max(pk, ntpk);
            }
            next2_=next1_;
            next1_=curr_;
        }
        int cs2=curr_[sz];
        return max(cs1, cs2);
    }
};