// 2212. Maximum Points in an Archery Competition
/*
Alice and Bob are opponents in an archery competition. The competition has set the following rules:

Alice first shoots numArrows arrows and then Bob shoots numArrows arrows.
The points are then calculated as follows:
The target has integer scoring sections ranging from 0 to 11 inclusive.
For each section of the target with score k (in between 0 to 11), say Alice and Bob 
have shot ak and bk arrows on that section respectively. If ak >= bk, then Alice takes k points. 
If ak < bk, then Bob takes k points.
However, if ak == bk == 0, then nobody takes k points.

For example, if Alice and Bob both shot 2 arrows on the section with score 11, then Alice takes 11 points. 
On the other hand, if Alice shot 0 arrows on the section with score 11 and Bob shot 2 arrows on that 
same section, then Bob takes 11 points.

You are given the integer numArrows and an integer array aliceArrows of size 12, 
which represents the number of arrows Alice shot on each scoring section from 0 to 11. 
Now, Bob wants to maximize the total number of points he can obtain.

Return the array bobArrows which represents the number of arrows Bob shot on each scoring 
section from 0 to 11. The sum of the values in bobArrows should equal numArrows.

If there are multiple ways for Bob to earn the maximum total points, return any one of them.

Input: numArrows = 9, aliceArrows = [1,1,0,1,0,0,2,1,0,1,2,0]
Output: [0,0,0,0,1,1,0,0,1,2,3,1]
Explanation: The table above shows how the competition is scored. 
Bob earns a total point of 4 + 5 + 8 + 9 + 10 + 11 = 47.
It can be shown that Bob cannot obtain a score higher than 47 points.

Input: numArrows = 3, aliceArrows = [0,0,1,0,0,0,0,0,0,0,0,2]
Output: [0,0,0,0,0,0,0,0,1,1,1,0]
Explanation: The table above shows how the competition is scored.
Bob earns a total point of 8 + 9 + 10 = 27.
It can be shown that Bob cannot obtain a score higher than 27 points

Constraints:

1 <= numArrows <= 10^5
aliceArrows.length == bobArrows.length == 12
0 <= aliceArrows[i], bobArrows[i] <= numArrows
sum(aliceArrows[i]) == numArrows
*/

/*
class Solution {
public:

    vector<int>fnres;
    int currMaxSum=0;

    void dfs(int n, int numArrows, vector<int>&aliceArrows, int currSm, vector<int>&res){
        if(n==-1||numArrows<=0){
            if(currSm>currMaxSum){
                currMaxSum=currSm;
                if(numArrows>0){
                    res[0]+=numArrows;
                }
                fnres=res;
            }
            return;
        }
        int req=aliceArrows[n]+1;
        if(req<=numArrows){
            res[n]=req;
            dfs(n-1, numArrows-req, aliceArrows, currSm+n, res);
            res[n]=0;
        }
        dfs(n-1, numArrows, aliceArrows, currSm, res);
        return;
    }

    vector<int> maximumBobPoints(int numArrows, vector<int>& aliceArrows) {
        vector<int>res(12, 0);
        int currSm=0;
        dfs(11, numArrows, aliceArrows, currSm, res);
        return fnres;
    }
};
*/

class Solution {
public:

    int dfs(int k, int numArrows, vector<int>&aliceArrows, vector<vector<int>>&memo){
        if(k==12||numArrows<=0) return 0;
        if(memo[k][numArrows]!=-1) return memo[k][numArrows];
        int maxScore=dfs(k+1, numArrows, aliceArrows, memo);
        if(numArrows>aliceArrows[k]){
            maxScore=max(maxScore, dfs(k+1, numArrows-aliceArrows[k]-1, aliceArrows, memo)+k);
        }
        return memo[k][numArrows]=maxScore;
    }

    vector<int> maximumBobPoints(int numArrows, vector<int>& aliceArrows) {
        int remainBobArrows=numArrows;
        vector<int>ans(12, 0);
        vector<vector<int>>memo(12, vector<int>(100001, -1));
        for(int k=0; k<12; ++k){
            if(dfs(k, numArrows, aliceArrows, memo)!=dfs(k+1, numArrows, aliceArrows, memo)){
                ans[k]=aliceArrows[k]+1;
                numArrows-=ans[k];
                remainBobArrows-=ans[k];
            }
        }
        ans[0]+=remainBobArrows;
        return ans;
    }
};