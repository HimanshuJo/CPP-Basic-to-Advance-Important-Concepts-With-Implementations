// 2139. Minimum Moves to Reach Target Score
/*
You are playing a game with integers. You start with the integer 1 and you want to reach the integer target.

In one move, you can either:

Increment the current integer by one (i.e., x = x + 1).
Double the current integer (i.e., x = 2 * x).
You can use the increment operation any number of times, however, you can only use the double operation at most maxDoubles times.

Given the two integers target and maxDoubles, return the minimum number of moves needed to reach target starting with 1.

Example 1:

Input: target = 5, maxDoubles = 0
Output: 4
Explanation: Keep incrementing by 1 until you reach target.

Example 2:

Input: target = 19, maxDoubles = 2
Output: 7
Explanation: Initially, x = 1
Increment 3 times so x = 4
Double once so x = 8
Increment once so x = 9
Double again so x = 18
Increment once so x = 19

Example 3:

Input: target = 10, maxDoubles = 4
Output: 4
Explanation: Initially, x = 1
Increment once so x = 2
Double once so x = 4
Increment once so x = 5
Double again so x = 10
 
Constraints:

1 <= target <= 10^9
0 <= maxDoubles <= 100
*/

/*
Solution dfs 2

class Solution {
public:
    
    int dfs(int bgn, int maxD, int end){
        if(bgn==end) return 1;
        if(bgn<end) return 0;
        if(maxD==0) return bgn;
        return (bgn%2==0&&maxD>0?1+dfs(bgn/2, maxD-1, end):1+dfs(bgn-1, maxD, end));
    }
    
    int minMoves(int target, int maxDoubles) {
        int ans=dfs(target, maxDoubles, 1);
        return ans-1;
    }
};
*/

class Solution {
public:
    
    int dfs(int bgn, int maxD, int end){
        if(bgn==end) return 1;
        if(maxD==0) return bgn;
        if(bgn<end) return 0;
        int ans=0;
        if(bgn%2!=0){
            ans=1+dfs(bgn-1, maxD, end);
        } else if(maxD>0){
            ans=1+dfs(bgn/2, maxD-1, end);
        }
        return ans;
    }
    
    int minMoves(int target, int maxDoubles) {
        int ans=dfs(target, maxDoubles, 1);
        return ans-1;
    }
};