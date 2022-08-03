// 1039. Minimum Score Triangulation of Polygon
/*
You have a convex n-sided polygon where each vertex has an integer value. 
You are given an integer array values where values[i] is the value of the 
ith vertex (i.e., clockwise order).

You will triangulate the polygon into n - 2 triangles. 
For each triangle, the value of that triangle is the product of the values 
of its vertices, and the total score of the triangulation is the 
sum of these values over all n - 2 triangles in the triangulation.

Return the smallest possible total score that you can achieve with some triangulation of the polygon.

Input: values = [1,2,3]
Output: 6
Explanation: The polygon is already triangulated, and the score of the only triangle is 6.

Input: values = [3,7,4,5]
Output: 144
Explanation: There are two triangulations, with possible scores: 3*7*5 + 4*5*7 = 245, or 3*4*5 + 3*4*7 = 144.
The minimum score is 144.

Input: values = [1,3,1,4,1,5]
Output: 13
Explanation: The minimum score triangulation has score 1*1*3 + 1*1*4 + 1*1*5 + 1*1*1 = 13.

Constraints:

n == values.length
3 <= n <= 50
1 <= values[i] <= 100
*/

class Solution1 {
public:
    
    int dfs(vector<int>&values, int i, int j, vector<vector<int>>&memo){
        if(i+1==j) return 0;
        if(memo[i][j]!=-1) return memo[i][j];
        int ans=INT_MAX;
        for(int k=i+1; k<j; ++k){
            ans=min(ans, values[i]*values[j]*values[k]+dfs(values, i, k, memo)+dfs(values, k, j, memo));
        }
        return memo[i][j]=ans;
    }
    
    int minScoreTriangulation(vector<int>& values) {
        int sz=values.size();
        vector<vector<int>>memo(sz+1, vector<int>(sz+1, -1));
        return dfs(values, 0, sz-1, memo);
    }
};

// -------*******-------

class Solution2 {
public:
    int minScoreTriangulation(vector<int>& values) {
        int sz=values.size();
        vector<vector<int>>dp(sz+1, vector<int>(sz+1, 0));
        for(int i=sz-2; i>=0; --i){
            for(int j=2; j<sz; ++j){
                int ans=INT_MAX;
                for(int k=i+1; k<j; ++k){
                    ans=min(ans, values[i]*values[j]*values[k]+dp[i][k]+dp[k][j]);
                    dp[i][j]=ans;
                }
            }
        }
        return dp[0][sz-1];
    }
};