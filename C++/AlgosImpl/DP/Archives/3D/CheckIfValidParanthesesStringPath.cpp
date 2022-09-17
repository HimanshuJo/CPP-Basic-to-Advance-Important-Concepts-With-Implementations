// 2267. Check if There Is a Valid Parentheses String Path
/*
A parentheses string is a non-empty string consisting only of '(' and ')'. 

It is valid if any of the following conditions is true:

It is ().
It can be written as AB (A concatenated with B), where A and B are valid parentheses strings.
It can be written as (A), where A is a valid parentheses string.

You are given an m x n matrix of parentheses grid. 

A valid parentheses string path in the grid is a path satisfying all of the following conditions:

The path starts from the upper left cell (0, 0).
The path ends at the bottom-right cell (m - 1, n - 1).
The path only ever moves down or right.
The resulting parentheses string formed by the path is valid.

Return true if there exists a valid parentheses string path in the grid. Otherwise, return false.

Input: grid = [["(","(","("],[")","(",")"],["(","(",")"],["(","(",")"]]
Output: true
Explanation: The above diagram shows two possible paths that form valid parentheses strings.
The first path shown results in the valid parentheses string "()(())".
The second path shown results in the valid parentheses string "((()))".
Note that there may be other valid parentheses string paths.

Input: grid = [[")",")"],["(","("]]
Output: false
Explanation: The two possible paths form the parentheses strings "))(" and ")((". 
Since neither of them are valid parentheses strings, we return false.

Constraints:

m == grid.length
n == grid[i].length
1 <= m, n <= 100
grid[i][j] is either '(' or ')'.
*/
/*
TLE: 17/81

class Solution {
public:
    
    bool isValidCoord(int currw, int curcol, int rws, int cols){
        return (currw>=0&&currw<rws&&curcol>=0&&curcol<cols);
    }
    
    bool isValidString(string &str){
        stack<char>stk;
        if(str[0]!='(') return false;
        stk.push(str[0]);
        if(str.size()>1){
            int sz=str.size();
            for(int i=1; i<sz; ++i){
                if(str[i]=='('){
                    stk.push(str[i]);
                } else{
                    if(!stk.empty()){
                        stk.pop();
                    } else return false;
                }
            }
        }
        if(!stk.empty()) return false;
        return true;
    }
    
    bool dfs(vector<vector<char>>&grid, int currw, int curcol, int rws, int cols, string &curr, map<tuple<int, int, string>, bool>&memo){
        if(currw>=rws||curcol>=cols||currw<0||curcol<0) return false;
        if(memo.find(make_tuple(currw, curcol, curr))!=memo.end()) return memo[make_tuple(currw, curcol, curr)];
        if(currw==rws-1&&curcol==cols-1){
            if(isValidString(curr)) return true;
            return false;
        }
        if(isValidCoord(currw+1, curcol, rws, cols)){
            string temp=curr;
            temp+=grid[currw+1][curcol];
            if(dfs(grid, currw+1, curcol, rws, cols, temp, memo)) return true;
        }
        if(isValidCoord(currw, curcol+1, rws, cols)){
            string temp=curr;
            temp+=grid[currw][curcol+1];
            if(dfs(grid, currw, curcol+1, rws, cols, temp, memo)) return true;
        }
        return memo[make_tuple(currw, curcol, curr)]=false;
    }
    
    bool hasValidPath(vector<vector<char>>& grid) {
        int rws=grid.size(), cols=grid[0].size();
        if(((rws+cols)-1)%2!=0) return false;
        if((rws*cols)%2!=0) return false;
        map<tuple<int, int, string>, bool>memo;
        string curr="";
        if(rws>1){
            curr+=grid[0][0];
            curr+=grid[1][0];
            bool temp=dfs(grid, 1, 0, rws, cols, curr, memo);
            if(temp) return true;   
        }
        if(cols>1){
            curr="";
            curr+=grid[0][0];
            curr+=grid[0][1];
            bool temp_=dfs(grid, 0, 1, rws, cols, curr, memo);
            if(temp_) return true;   
        }
        return false;
    }
};
*/

class Solution {
public:
    
    int memo[101][101][201];
    
    bool dfs(vector<vector<char>>&grid, int currw, int curcol, const int rws, const int cols, int open){
        if(currw<0||curcol<0||currw>=rws||curcol>=cols||open<0) return false;
        if(memo[currw][curcol][open]!=-1) return memo[currw][curcol][open];
        if(currw==rws-1&&curcol==cols-1){
            if(grid[currw][curcol]=='(') open++;
            else open--;
            if(open==0) return true;
            return false;
        }
        if(grid[currw][curcol]=='('){
            if(dfs(grid, currw+1, curcol, rws, cols, open+1)||
               dfs(grid, currw, curcol+1, rws, cols, open+1)) return true;
        } else{
             if(dfs(grid, currw+1, curcol, rws, cols, open-1)||
               dfs(grid, currw, curcol+1, rws, cols, open-1)) return true;
        }
        return memo[currw][curcol][open]=false;
    }
    
    bool hasValidPath(vector<vector<char>>& grid) {
        int rws=grid.size(), cols=grid[0].size();
        int open=0;
        memset(memo, -1, sizeof(memo));
        if(grid[0][0]==')') return false;
        bool temp=dfs(grid, 0, 0, rws, cols, open);
        if(temp) return true; 
        return false;
    }
};

// -------*******-------

class Solution2 {
public:
    
    int memo[101][101][201];
    vector<vector<int>>dir={{1, 0}, {0, 1}};
    
    bool bfs(vector<vector<char>>&grid, int rws, int cols){
        queue<tuple<int, int, int>>q;
        q.push({0, 0, 1});
        memo[0][0][1]=1;
        while(!q.empty()){
            int sz=q.size();
            while(sz--){
                auto [currw, curcol, brac]=q.front();
                q.pop();
                if(brac<0) continue;
                if(currw==rws-1&&curcol==cols-1){
                    if(brac==0) return true;
                }
                for(auto &d: dir){
                    int nwr=currw+d[0], nwc=curcol+d[1];
                    if(brac<0) continue;
                    if(nwr>=0&&nwc>=0&&nwr<rws&&nwc<cols&&memo[nwr][nwc][brac]==-1){
                        if(brac>=0&&brac<=rws*cols) memo[nwr][nwc][brac]=1;
                        if(grid[nwr][nwc]=='('){
                            q.push({nwr, nwc, brac+1});
                        } else{
                            q.push({nwr, nwc, brac-1});
                        }
                    } 
                }
            }
        }
        return false;
    }
    
    bool hasValidPath(vector<vector<char>>& grid) {
        int rws=grid.size(), cols=grid[0].size();
        if(grid[0][0]==')') return false;
        memset(memo, -1, sizeof(memo));
        return (bfs(grid, rws, cols));
    }
};