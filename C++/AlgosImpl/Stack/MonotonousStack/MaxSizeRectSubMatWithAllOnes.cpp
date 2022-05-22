/*
Problem Statement

You are given an 'N' * 'M' sized binary-valued matrix 'MAT, where 'N' is the 
number of rows and 'M' is the number of columns. 

You need to return the maximum size (area) of the submatrix which consists of all 1’s i.e. 
the maximum area of a submatrix in which each cell has only the value ‘1’.
*/

#include<bits/stdc++.h>
using namespace std;

int getMaxHistogramHeight(vector<int>&heights){
	int sz=heights.size();
	vector<int>tempheights(sz+1, 0);
	for(int i=0; i<sz; ++i){
		tempheights[i]=heights[i];
	}
	tempheights[sz]=0;
	stack<int>stk;
	int maxwidth=0, top_=0;
	for(int i=0; i<=sz; ++i){
		if(stk.empty()||tempheights[stk.top()]<=tempheights[i]){
			stk.push(i);
		} else{
			while(!stk.empty()&&tempheights[stk.top()]>tempheights[i]){
				top_=stk.top();
				stk.pop();
				maxwidth=max(maxwidth, tempheights[top_]*(i-top_));
			}
			stk.push(top_);
			tempheights[top_]=tempheights[i];
		}
	}
	return maxwidth;
}

int maximalAreaOfSubMatrixOfAll1(vector<vector<int>> &mat, int n, int m){
	int rws=mat.size(), cols=mat[0].size();
	vector<int>heights(cols, 0);
	int ans=INT_MIN;
	for(int i=0; i<rws; ++i){
		for(int j=0; j<cols; ++j){
			if(mat[i][j]==1){
				heights[j]++;
			} else heights[j]=0;
		}
		int curmaxheight=getMaxHistogramHeight(heights);
		ans=max(ans, curmaxheight);
	}
	return ans;
}