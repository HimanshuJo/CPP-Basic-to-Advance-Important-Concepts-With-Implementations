// B. Madoka and Underground Competitions
/*
Madoka decided to participate in an underground sports programming competition. 
And there was exactly one task in it:

A square table of size n×n, where n is a multiple of k, is called good if only the characters '.' 
and 'X' are written in it, as well as in any subtable of size 1×k or k×1, there is at 
least one character 'X'. In other words, among any k consecutive vertical or horizontal cells, there 
must be at least one containing the character 'X'.

Output any good table that has the minimum possible number of characters 'X', and also the symbol 'X' 
is written in the cell (r,c). Rows are numbered from 1 to n from top to bottom, columns are numbered from 
1 to n from left to right.

Input
The input consists of multiple test cases. The first line contains a single integer t (1≤t≤100) — 
the number of test cases. Description of the test cases follows.

The first and the only line of each test case contains four integers n, k, r, c (1≤n≤500,1≤k≤n,1≤r,c≤n) — 
the size of the table, the integer k and the coordinates of the cell, which must contain the character 'X'. 
It is guaranteed that n is a multiple of k.

It is guaranteed that the sum of n over all test cases does not exceed 500.

Output
For each test case, output n lines, each consisting of n characters '.' and 'X', — the desired table. 
If there are several answers, then you can output anyone.

Example
input
3
3 3 3 2
2 1 1 2
6 3 4 2

output
X..
..X
.X.
XX
XX
.X..X.
X..X..
..X..X
.X..X.
X..X..
..X..X
*/

/*
Notice that the answer to the problem is at least n^2/k, because you can split the square into so many 
non-intersecting rectangles of dimensions 1×k. So let's try to paint exactly so many cells and see if maybe 
it's always possible.

For simplicity, let's first solve the problem without necessarily painting (r,c). 
In this case, we're looking for something like a chess coloring, which is a diagonal coloring.

Let's number the diagonals from the "lowest" to the "highest". Notice that every 1×k and k×1 
sub-rectangle intersects exactly k consecutive diagonals, so we can paint every k-th diagonal to 
obtain the required answer: every such sub-rectangle will contain exactly one painted cell.

To add the (r,c) requirement back, notice that (r,c) lies on the diagonal number r+c. 
(Because if you trace any path from (0,0) to (r,c) with non-decreasing coordinates, going one 
cell upwards or rightwards increases exactly one of the coordinates by one, and also increases the 
number of the diagonal by one). 

Therefore, all we need to do is paint the cells whose coordinates satisfy (x+y)%k=(r+c)%k
*/

#include<iostream>
#include<vector>
#include<queue>
#include<set>
#define endl "\n"
using namespace std;

bool isValid(int currx, int curry, int n, set<pair<int, int>>&seen){
    auto it=seen.find({currx, curry});
    if(it!=seen.end()) return false;
    return currx>=0&&curry>=0&&currx<=n-1&&curry<=n-1;
}

void bfs(vector<vector<char>>&grd, set<pair<int, int>>&seen, int currx, int curry, int n, int k){
    grd[currx][curry]='X';
    queue<pair<int, int>>q;
    q.push({currx, curry});
    seen.insert({currx, curry});
    while(!q.empty()){
        int sz=q.size();
        while(sz--){
            pair<int, int>curr=q.front();
            q.pop();
            int frnwx=curr.first-k, frnwy=curr.second;
            if(isValid(frnwx, frnwy, n, seen)){
                grd[frnwx][frnwy]='X';
                q.push({frnwx, frnwy});
                seen.insert({frnwx, frnwy});
            }
            int secnwx=curr.first+k, secnwy=curr.second;
            if(isValid(secnwx, secnwy, n, seen)){
                grd[secnwx][secnwy]='X';
                q.push({secnwx, secnwy});
                seen.insert({secnwx, secnwy});
            }
            int thrdnwx=curr.first, thrdnwy=curr.second-k;
            if(isValid(thrdnwx, thrdnwy, n, seen)){
                grd[thrdnwx][thrdnwy]='X';
                q.push({thrdnwx, thrdnwy});
                seen.insert({thrdnwx, thrdnwy});
            }
            int frthnwx=curr.first, frthnwy=curr.second+k;
            if(isValid(frthnwx, frthnwy, n, seen)){
                grd[frthnwx][frthnwy]='X';
                q.push({frthnwx, frthnwy});
                seen.insert({frthnwx, frthnwy});
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--){
        int n, k, r, c;
        cin>>n>>k>>r>>c;
        vector<vector<char>>grd(n, vector<char>(n, '.'));
        set<pair<int, int>>seen;
        bfs(grd, seen, r-1, c-1, n, k);
        for(int i=0; i<n; ++i){
            for(int j=0; j<n; ++j){
                if((i+j)%k==((r-1)+(c-1))%k){
                    grd[i][j]='X';
                }
            }
        }
        for(int i=0; i<n; ++i){
            for(int j=0; j<n; ++j){
                cout<<grd[i][j];
            }
            cout<<endl;
        }
    }
}