// 2392. Build a Matrix With Conditions
/*
You are given a positive integer k. You are also given:

a 2D integer array rowConditions of size n where rowConditions[i] = [abovei, belowi], and
a 2D integer array colConditions of size m where colConditions[i] = [lefti, righti].
The two arrays contain integers from 1 to k.

You have to build a k x k matrix that contains each of the numbers from 1 to k exactly once. 
The remaining cells should have the value 0.

The matrix should also satisfy the following conditions:

The number abovei should appear in a row that is strictly above the row at which the number belowi 
appears for all i from 0 to n - 1.

The number lefti should appear in a column that is strictly left of the column at which the number 
righti appears for all i from 0 to m - 1.

Return any matrix that satisfies the conditions. If no answer exists, return an empty matrix.

Input: k = 3, rowConditions = [[1,2],[3,2]], colConditions = [[2,1],[3,2]]
Output: [[3,0,0],[0,0,1],[0,2,0]]
Explanation: The diagram above shows a valid example of a matrix that satisfies all the conditions.
The row conditions are the following:
- Number 1 is in row 1, and number 2 is in row 2, so 1 is above 2 in the matrix.
- Number 3 is in row 0, and number 2 is in row 2, so 3 is above 2 in the matrix.
The column conditions are the following:
- Number 2 is in column 1, and number 1 is in column 2, so 2 is left of 1 in the matrix.
- Number 3 is in column 0, and number 2 is in column 1, so 3 is left of 2 in the matrix.
Note that there may be multiple correct answers.

Example 2:

Input: k = 3, rowConditions = [[1,2],[2,3],[3,1],[2,3]], colConditions = [[2,1]]
Output: []
Explanation: From the first two conditions, 3 has to be below 1 but the third conditions needs 3 to be above 1 to be satisfied.
No matrix can satisfy all the conditions, so we return the empty matrix.
 

Constraints:

2 <= k <= 400
1 <= rowConditions.length, colConditions.length <= 10^4
rowConditions[i].length == colConditions[i].length == 2
1 <= abovei, belowi, lefti, righti <= k
abovei != belowi
lefti != righti
*/

class Solution {
public:
    
    bool dfs2(vector<vector<int>>&gr, vector<int>&coloring, int curvert){
        coloring[curvert]=1;
        for(auto &nei: gr[curvert]){
            if(coloring[nei]==0){
                if(dfs2(gr, coloring, nei)) return true;
            } else if(coloring[nei]==1) return true;
        }
        coloring[curvert]=2;
        return false;
    }
    
    bool isCyclePresent(vector<vector<int>>&gr, int k){
        vector<int>coloring(k, 0);
        for(int i=0; i<k; ++i){
            if(coloring[i]==0&&dfs2(gr, coloring, i)) return true;
        }
        return false;
    }
    
    void dfs(vector<vector<int>>&gr, int k, int curvert, vector<int>&ans, vector<int>&seen){
        seen[curvert]=1;
        for(auto &nei: gr[curvert]){
            if(seen[nei]==-1){
                dfs(gr, k, nei, ans, seen);
            }
        }
        ans.push_back(curvert);
    }
    
    void toposort(vector<vector<int>>&gr, int k, vector<int>&ans){
        vector<int>seen(k, -1);
        for(int i=0; i<k; ++i){
            if(seen[i]==-1){
                dfs(gr, k, i, ans, seen);      
            }
        }
        reverse(ans.begin(), ans.end());
    }
    
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        vector<vector<int>>gr1(k);
        vector<vector<int>>gr2(k);
        for(auto &vals: rowConditions){
            gr1[vals[0]-1].push_back(vals[1]-1);
        }
        for(auto &vals: colConditions){
            gr2[vals[0]-1].push_back(vals[1]-1);
        }
        if(isCyclePresent(gr1, k)||isCyclePresent(gr2, k)) return {};
        vector<int>ans1, ans2;
        toposort(gr1, k, ans1);   
        toposort(gr2, k, ans2);
        map<int, int>mp;

        /*
            So after topological sort, we have:
                ans1 = {3,1,2}
                ans2 = {3,2,1}

                So, we can concluded that:
                In matrix column, 2 will be at left, then 1 will come, then 0. 
                This implies that result when we compare the column of every element, the possible answer can be:

                3 0 0      0 2 1    0 0 1
                0 2 0      3 0 0    0 2 0
                0 0 1      0 0 0    3 0 0

                This is what we are doing here
                value y-index
                
                3 0
                2 1
                1 2

            for(int i = 0; i < k; i++) {
                m[ans2[i]] = i;
            }
            
            The final answer now depends the row indexing of these values ie 3 should be at upper, 
            then 1 at middle then 2 {3,1,2} therefore the answer will be:

                3 0 0
                0 0 1
                0 2 0

            How final answer calculated?
            
            Carefully see this code now:

            for(int i = 0; i < k; i++) {
                ans[i][m[ans1[i]]] = ans1[i] + 1;
            }

            here ans[i] -> ith index where the value ans1[i] should be stored in row, m[ans1[i]] 
            is giving the y-th index of value ans1[i].
        */

        vector<vector<int>>ans(k, vector<int>(k));
        for(int i=0; i<k; ++i){
            mp[ans1[i]]=i;
        }
        for(int i=0; i<k; ++i){
            ans[i][mp[ans1[i]]]=ans1[i]+1;
        }
        return ans;
    }
};