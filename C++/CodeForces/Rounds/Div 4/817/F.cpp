// F. L-shapes
/*
An L-shape is a figure on gridded paper that looks like the first four pictures below. 
An L-shape contains exactly three shaded cells (denoted by *), which can be rotated in any way.

You are given a rectangular grid. Determine if it contains L-shapes only, where L-shapes can't touch an 
edge or corner. More formally:

Each shaded cell in the grid is part of exactly one L-shape, and
no two L-shapes are adjacent by edge or corner.
For example, the last two grids in the picture above do not satisfy the condition because the two L-shapes 
touch by corner and edge, respectively.

Input
The input consists of multiple test cases. The first line contains an integer t (1≤t≤100) — 
the number of test cases. The description of the test cases follows.

The first line of each test case contains two integers n and m (1≤n,m≤50) — the number of rows and columns 
in the grid, respectively.

Then n lines follow, each containing m characters. Each of these characters is either '.' or '*' — 
an empty cell or a shaded cell, respectively.

Output
For each test case, output "YES" if the grid is made up of L-shape that don't share edges or corners, 
and "NO" otherwise.

You can output the answer in any case (for example, the strings "yEs", "yes", "Yes" and "YES" 
will be recognized as a positive answer).

Example
input
10
6 10
........**
.**......*
..*..*....
.....**...
...*.....*
..**....**
6 10
....*...**
.**......*
..*..*....
.....**...
...*.....*
..**....**
3 3
...
***
...
4 4
.*..
**..
..**
..*.
5 4
.*..
**..
....
..**
..*.
3 2
.*
**
*.
2 3
*..
.**
3 2
..
**
*.
3 3
.**
*.*
**.
3 3
..*
.**
..*

output
YES
NO
NO
NO
YES
NO
NO
YES
NO
NO
*/

/*
The problem is mainly a tricky implementation problem. Let's denote the elbow of an L-shape as 
the square in the middle (the one that is side-adjacent to two other squares). 

Every elbow is part of exactly one L-shape, and every L-shape has exactly one elbow.

Iterate through the grid and count the number of side-adjacent neighbors they have. 
If there is a cell with more than 2, or if there is a cell with exactly two neighbors on opposite sides, 
then the answer is NO. Otherwise, if there are exactly 2 neighbors, this cell is an elbow. Mark all three 
cells of this L-shape with a unique number (say, mark the first one you find with 1, the second with 2, and so on.) 

If you ever remark a cell that already has a number, then two elbows are adjacent, and you can output NO.

After all elbows are marked, check if all shaded cells have a number. If some don't, then 
they are not part of an L-shape, so you can output NO.

Finally, we should check that L-shapes don't share edge or corner. Just check, for each number, 
if it is only diagonally adjacent to other numbers equal to it or unshaded cells. 

If it is diagonally adjacent to other unequal numbers, then the answer is NO, because two L-shapes 
share an edge or corner then.

Otherwise the answer is YES.

There are many other solutions, all of which are various ways to check the conditions. 

The complexity is O(mn) per testcase
*/

#include<iostream>
#include<vector>
using namespace std;

const int MAX=200007;

const int dx[3]={-1, 0, 1}, dy[3]={-1, 0, 1};

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        char gr[n][m];
        int id[n][m];
        for(int i=0; i<n; ++i){
            for(int j=0; j<m; ++j){
                cin>>gr[i][j];
                id[i][j]=0;
            }
        }
        int curr=1;
        bool flag=false;
        for(int i=0; i<n; ++i){
            for(int j=0; j<m; ++j){
            	/*
            		We need two other stars
            		the current star will either be a part of vertical hand or horizontal hand
            	*/
                if(gr[i][j]=='*'){
                    vector<pair<int, int>>adjh, adjv;
                    if(i>0&&gr[i-1][j]=='*'){
                        adjh.push_back({i-1, j});
                    }
                    if(i<n-1&&gr[i+1][j]=='*'){
                        adjh.push_back({i+1, j});
                    }
                    if(j>0&&gr[i][j-1]=='*'){
                        adjv.push_back({i, j-1});
                    }
                    if(j<m-1&&gr[i][j+1]=='*'){
                        adjv.push_back({i, j+1});
                    }
                    if(adjh.size()==1&&adjv.size()==1){
                        if(id[i][j]==0){
                            id[i][j]=curr;
                        } else{
                            cout<<"NO\n";
                            flag=true;
                            break;
                        }
                        if(flag) break;
                        if(id[adjh[0].first][adjh[0].second]==0){
                            id[adjh[0].first][adjh[0].second]=curr;
                        } else{
                            cout<<"NO\n";
                            flag=true;
                            break;
                        }
                        if(flag) break;
                        if(id[adjv[0].first][adjv[0].second]==0){
                            id[adjv[0].first][adjv[0].second]=curr;
                        } else{
                            cout<<"NO\n";
                            flag=true;
                            break;
                        }
                        if(flag) break;
                        curr++;
                    } else if(adjh.size()>1||adjv.size()>1){
                        cout<<"NO\n";
                        flag=true;
                        break;
                    }
                }
            }
            if(flag) break;
        }
        if(!flag){
            for(int i=0; i<n; ++i){
                for(int j=0; j<m; ++j){
                    if(gr[i][j]=='*'){
                        if(id[i][j]==0){
                            cout<<"NO\n";
                            flag=true;
                            break;
                        } else{
                            for(int x=0; x<3; ++x){
                                for(int y=0; y<3; ++y){
                                    if(0<=i+dx[x]&&i+dx[x]<n){
                                        if(0<=j+dy[y]&&j+dy[y]<m){
                                            if(id[i+dx[x]][j+dy[y]]!=id[i][j]&&id[i+dx[x]][j+dy[y]]!=0){
                                                cout<<"NO\n";
                                                flag=true;
                                                break;
                                            }
                                        }
                                    }
                                }
                                if(flag) break;
                            }
                        }
                    }
                }
                if(flag) break;
            }
        }
        if(!flag)
            cout<<"YES\n";
    }
}