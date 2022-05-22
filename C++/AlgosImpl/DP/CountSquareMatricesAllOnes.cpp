/*
Problem Statement

A matrix ‘ARR’ with ‘N’ rows and ‘M’ columns is given.

Count the number of square submatrices in matrix ‘ARR’ that have all ones. 
A square matrix is a matrix with equal numbers of rows and columns.

For Example :
If N = 2, M = 2 and ARR = [ [1, 1], [1, 1] ],
Then we have four square submatrices of size 1*1 and one square submatrix of size 2*2. So, the answer is 5.
*/

#include<vector>
#include<iostream>
using namespace std;

// Brute Force
int countSquares1(int n, int m, vector<vector<int>> &arr) {
    int count=0;
    for(int i=0; i<n; ++i){
    	for(int j=0; j<m; ++j){
    		if(arr[i][j]==1) count++;
    		int counter=0;
    		while(true){
    			counter++;
    			if(i+counter==n||j+counter==m) break;
    			bool flag=false;
    			for(int rw=i; rw<=i+counter; ++rw){
    				for(int col=j; col<=j+counter; ++col){
    					if(arr[rw][col]!=1){
    						flag=true;
    						break;
    					}
    				}
    				if(flag) break;
    			}
    			if(!flag){
    				count++;
    			}
    		}
    	}
    }
    return count;
}

int countSquares2(int n, int m, vector<vector<int>> &arr) {
	vector<vector<int>>dp(n, vector<int>(m, 0));
	for(int i=0; i<n; ++i){
		dp[i][0]=arr[i][0];
	}
	for(int j=0; j<m; ++j){
		dp[0][j]=arr[0][j];
	}
	for(int i=1; i<n; ++i){
		for(int j=1; j<m; ++j){
			if(arr[i][j]==1){
				dp[i][j]=min(dp[i][j-1], min(dp[i-1][j-1], dp[i-1][j]))+1;
			}
		}
	}
	int ans=0;
	for(int i=0; i<n; ++i){
		for(int j=0; j<m; ++j){
			ans+=dp[i][j];
		}
	}
	return ans;
}


int main(){
	int rws=3, cols=3;
	vector<vector<int>>matrix{{1, 1, 1}, {1, 1, 1}, {1, 1, 1}};
	int ans=countSquare(rws, cols, matrix);
	cout<<ans<<endl;
}