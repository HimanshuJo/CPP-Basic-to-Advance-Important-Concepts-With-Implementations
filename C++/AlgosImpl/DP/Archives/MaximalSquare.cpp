// 221. Maximal Square
/*
	Given an m x n binary matrix filled with 0's and 1's, find the largest square containing only 1's 
	and return its area.

	Example: 

		Input: matrix = [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
		Output: 4
*/

/*
Brute Force:

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int rws=matrix.size(), cols=matrix[0].size();
        int fnsqr=0;
        for(int i=0; i<rws; ++i){
            for(int j=0; j<cols; ++j){
                if(matrix[i][j]=='1'){
                    int curlen=0;
                    int cursqr=1;
                    bool flag=false;
                    while(i+curlen<rws&&j+curlen<cols){
                        int tmprw=i+curlen, tmpcol=j+curlen, count=0;
                        for(int x=i; x<=tmprw; ++x){
                            count++;
                            for(int y=j; y<=tmpcol; ++y){
                                if(matrix[x][y]!='1'){
                                    flag=true;
                                    break;
                                }
                            }
                            if(flag) break;
                        }
                        if(!flag){
                            cursqr=count*count;
                            fnsqr=max(fnsqr, cursqr);
                            curlen++;
                        } else break;
                    }
                }
            }
        }
        return fnsqr;
    }
};

*/

class Solution {
public:
    
    bool isNotValidBoundary(vector<vector<char>>&matrix, int rw, int col){
        return (rw<0||col<0||rw>=matrix.size()||col>=matrix[0].size());
    }
    
    int dfs(vector<vector<char>>&matrix, int rw, int col, vector<vector<int>>&memo){
        if(isNotValidBoundary(matrix, rw, col)) return 0;
        if(memo[rw][col]!=-1) return memo[rw][col];
        if(matrix[rw][col]=='0'){
            memo[rw][col]=0;
            return memo[rw][col];
        }
        int curres1=dfs(matrix, rw+1, col, memo);
        int curres2=dfs(matrix, rw, col+1, memo);
        int curres3=dfs(matrix, rw+1, col+1, memo);
        int minn=min(curres1, min(curres2, curres3));
        if(minn>0){
            memo[rw][col]=1+minn;
        } else memo[rw][col]=1;
        return memo[rw][col];
    }
    
    int maximalSquare(vector<vector<char>>& matrix) {
        int rws=matrix.size();
        int cols=matrix[0].size();
        vector<vector<int>>memo(rws, vector<int>(cols, -1));
        int res=0;
        for(int i=0; i<rws; ++i){
            for(int j=0; j<cols; ++j){
                if(matrix[i][j]=='1'&&memo[i][j]==-1){
                    dfs(matrix, i, j, memo);
                }
            }
        }
        for(auto &vals: memo){
            res=max(res, *max_element(vals.begin(), vals.end()));
        }
        return res*res;
    }
};