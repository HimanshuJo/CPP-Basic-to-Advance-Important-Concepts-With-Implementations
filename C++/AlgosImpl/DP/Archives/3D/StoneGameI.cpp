// 877. Stone Game
/*
Alice and Bob play a game with piles of stones. There are an even number of piles arranged in a row, 
and each pile has a positive integer number of stones piles[i].

The objective of the game is to end with the most stones. The total number of stones across all the 
piles is odd, so there are no ties.

Alice and Bob take turns, with Alice starting first. Each turn, a player takes the entire 
pile of stones either from the beginning or from the end of the row. This continues until there are no 
more piles left, at which point the person with the most stones wins.

Assuming Alice and Bob play optimally, return true if Alice wins the game, or false if Bob wins.

Example 1:

Input: piles = [5,3,4,5]
Output: true
Explanation: 
Alice starts first, and can only take the first 5 or the last 5.
Say she takes the first 5, so that the row becomes [3, 4, 5].
If Bob takes 3, then the board is [4, 5], and Alice takes 5 to win with 10 points.
If Bob takes the last 5, then the board is [3, 4], and Alice takes 4 to win with 9 points.
This demonstrated that taking the first 5 was a winning move for Alice, so we return true.
Example 2:

Input: piles = [3,7,2,3]
Output: true
 

Constraints:

2 <= piles.length <= 500
piles.length is even.
1 <= piles[i] <= 500
sum(piles[i]) is odd.
*/

class Solution {
public:
    
    bool dfs(vector<int>&piles, int sz, int curbgn, int curend, int alsm, int bsm, bool flag,
            vector<vector<vector<int>>>&memo){
        if(curbgn>=sz||curend<0){
            return alsm>bsm;
        }
        if(memo[curbgn][curend][flag]!=-1) return memo[curbgn][curend][flag];
        bool pkfrst, pklst;
        if(flag){
            int temp1=alsm, temp2=alsm;
            temp1+=piles[curbgn], temp2+=piles[curend];
            pkfrst=dfs(piles, sz, curbgn+1, curend, temp1, bsm, false, memo);
            if(pkfrst) return true;
            pklst=dfs(piles, sz, curbgn, curend-1, temp2, bsm, false, memo);
            if(pklst) return true;
        }
        if(!flag){
            int temp1=bsm, temp2=bsm;
            temp1+=piles[curbgn], temp2+=piles[curend];
            pkfrst=dfs(piles, sz, curbgn+1, curend, alsm, temp1, true, memo);
            if(!pkfrst) return true;
            pklst=dfs(piles, sz, curbgn, curend-1, alsm, temp2, true, memo);
            if(!pklst) return true;
        }
        return memo[curbgn][curend][flag]=pkfrst||pklst;
    }
    
    bool stoneGame(vector<int>& piles) {
        int sz=piles.size();
        int curbgn=0, curend=sz-1, alsm=0, bsm=0;
        vector<vector<vector<int>>>memo(sz+1, vector<vector<int>>(sz+1, vector<int>(2, -1)));
        return dfs(piles, sz, curbgn, curend, alsm, bsm, true, memo);
    }
};