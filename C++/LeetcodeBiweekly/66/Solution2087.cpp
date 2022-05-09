// 2087. Minimum Cost Homecoming of a Robot in a Grid
/*
There is an m x n grid, where (0, 0) is the top-left cell and (m - 1, n - 1) is the bottom-right cell. 
You are given an integer array startPos where startPos = [startrow, startcol] indicates that initially, a robot is at the cell 
(startrow, startcol). You are also given an integer array homePos where homePos = [homerow, homecol] indicates that its home is at the cell (homerow, homecol).

The robot needs to go to its home. It can move one cell in four directions: left, right, up, or down, and it can not move outside the boundary. Every move incurs some cost. 
You are further given two 0-indexed integer arrays: rowCosts of length m and colCosts of length n.

If the robot moves up or down into a cell whose row is r, then this move costs rowCosts[r].
If the robot moves left or right into a cell whose column is c, then this move costs colCosts[c].
Return the minimum total cost for this robot to return home.

Example:
Input: startPos = [1, 0], homePos = [2, 3], rowCosts = [5, 4, 3], colCosts = [8, 2, 6, 7]
Output: 18
Explanation: One optimal path is that:
Starting from (1, 0)
-> It goes down to (2, 0). This move costs rowCosts[2] = 3.
-> It goes right to (2, 1). This move costs colCosts[1] = 2.
-> It goes right to (2, 2). This move costs colCosts[2] = 6.
-> It goes right to (2, 3). This move costs colCosts[3] = 7.
The total cost is 3 + 2 + 6 + 7 = 18
*/
#include<vector>
#include<iostream>
#include<queue>
#include<set>
using namespace std;

class Solution {
public:
    int minCost(vector<int>& startPos, vector<int>& homePos, vector<int>& rowCosts, vector<int>& colCosts) {
      int x1=startPos[0], x2=homePos[0];
	  int y1=startPos[1], y2=homePos[1];
	  int ans=0;
	  if(x1==x2&&y1==y2) return 0;
	  if(x1<x2){
		  for(int i=x1+1; i<=x2; ++i){
			  ans+=rowCosts[i];
		  }
	  } else if(x1>x2){
		  for(int i=x2; i<=x1-1; ++i){
			  ans+=rowCosts[i];
		  }
	  }
	  if(y1<y2){
		  for(int i=y1+1; i<=y2; ++i){
			  ans+=colCosts[i];
		  }
	  } else if(y1>y2){
		  for(int i=y2; i<=y1-1; ++i){
			  ans+=colCosts[i];
		  }
	  }
	  return ans;
    }
};

int main(){}
