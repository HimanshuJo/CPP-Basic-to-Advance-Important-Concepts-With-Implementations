/*
Complexity Analysis: 

    Time Complexity: O(3^(n^2)). 
    As there are N^2 cells from each cell there are 3 unvisited neighbouring cells. 
    So the time complexity O(3^(N^2).

    Auxiliary Space: O(3^(n^2)). 
    As there can be atmost 3^(n^2) cells in the answer so the space complexity is O(3^(n^2)).
*/
/*
Solution2:

#include<vector>
#include<iostream>
using namespace std;

bool isValid(vector<vector<int>>&in, vector<vector<int>>&seen, int i, int j, int rws, int cols){
	return (i>=0&&j>=0&&i<rws&&j<cols&&in[i][j]==1&&seen[i][j]==-1);
}

bool dfs(vector<vector<int>>&in, vector<string>&res, vector<vector<int>>&seen,
        string curPath, int i, int j, int rws, int cols){
	if(i==rws-1&&j==cols-1&&in[i][j]==1){
		res.push_back(curPath);
		return true;
	}
	if(isValid(in, seen, i+1, j, rws, cols)){
		seen[i+1][j]=1;
		curPath+='D';
		dfs(in, res, seen, curPath, i+1, j, rws, cols);
		seen[i+1][j]=-1;
		curPath.pop_back();
	}
	if(isValid(in, seen, i, j+1, rws, cols)){
		seen[i][j+1]=1;
		curPath+='R';
		dfs(in, res, seen, curPath, i, j+1, rws, cols);
		seen[i][j+1]=-1;
		curPath.pop_back();
	}
	if(isValid(in, seen, i-1, j, rws, cols)){
		seen[i-1][j]=1;
		curPath+='U';
		dfs(in, res, seen, curPath, i-1, j, rws, cols);
		seen[i-1][j]=-1;
		curPath.pop_back();
	}
	if(isValid(in, seen, i, j-1, rws, cols)){
		seen[i][j-1]=1;
		curPath+='L';
		dfs(in, res, seen, curPath, i, j-1, rws, cols);
		seen[i][j-1]=-1;
		curPath.pop_back();
	}
	return false;
}


int main(){
	vector<vector<int>>in{ { 1, 0, 0, 0, 0 },
                        { 1, 1, 1, 1, 1 },
                        { 1, 1, 1, 0, 1 },
                        { 0, 0, 0, 0, 1 },
                        { 0, 0, 0, 0, 1 } };
	int rws=in.size(), cols=in[0].size();
	vector<vector<int>>seen(rws, vector<int>(cols, -1));
	vector<string>res;
	string curPath="";
	int i=0, j=0;
	seen[0][0]=1;
	dfs(in, res, seen, curPath, i, j, rws, cols);
	int counter=1;
	for(auto &vals: res){
		cout<<counter++<<" : ";
		cout<<vals<<endl;
	}
}
*/

#include<vector>
#include<iostream>
using namespace std;

bool isValid(vector<vector<int>>&in, vector<vector<int>>&seen, int i, int j, int rws, int cols){
	return (i>=0&&j>=0&&i<rws&&j<cols&&in[i][j]==1&&seen[i][j]==-1);
}

bool dfs(vector<vector<int>>&in, vector<string>&res, vector<vector<int>>&seen,
        string curPath, int i, int j, int rws, int cols){
	if(i==rws-1&&j==cols-1&&in[i][j]==1){
		res.push_back(curPath);
		return true;
	}
	seen[i][j]=1;
	if(isValid(in, seen, i+1, j, rws, cols)){
		curPath+='D';
		dfs(in, res, seen, curPath, i+1, j, rws, cols);
		curPath.pop_back();
	}
	if(isValid(in, seen, i, j+1, rws, cols)){
		curPath+='R';
		dfs(in, res, seen, curPath, i, j+1, rws, cols);
		curPath.pop_back();
	}
	if(isValid(in, seen, i-1, j, rws, cols)){
		curPath+='U';
		dfs(in, res, seen, curPath, i-1, j, rws, cols);
		curPath.pop_back();
	}
	if(isValid(in, seen, i, j-1, rws, cols)){
		curPath+='L';
		dfs(in, res, seen, curPath, i, j-1, rws, cols);
		curPath.pop_back();
	}
	seen[i][j]=-1;
	return false;
}

int main(){
	vector<vector<int>>in{ { 1, 0, 0, 0, 0 },
	                       { 1, 1, 1, 1, 1 },
	                       { 1, 1, 1, 0, 1 },
	                       { 0, 0, 0, 0, 1 },
	                       { 0, 0, 0, 0, 1 } };
	int rws=in.size(), cols=in[0].size();
	vector<vector<int>>seen(rws, vector<int>(cols, -1));
	vector<string>res;
	string curPath="";
	int i=0, j=0;
	seen[0][0]=1;
	dfs(in, res, seen, curPath, i, j, rws, cols);
	int counter=1;
	for(auto &vals: res){
		cout<<counter++<<" : ";
		cout<<vals<<endl;
	}
}