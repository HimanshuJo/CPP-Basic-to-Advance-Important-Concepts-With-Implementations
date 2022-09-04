// A. Color the flag
/*
Today we will be playing a red and white colouring game
(no, this is not the Russian Civil War; these are just the colours of the Canadian flag).

You are given an n×m grid of "R", "W", and "." characters.
"R" is red, "W" is white and "." is blank.

The neighbours of a cell are those that share an edge with it
(those that only share a corner do not count).

Your job is to colour the blank cells red or white so that every red cell only has
white neighbours (and no red ones) and every white cell only has
red neighbours (and no white ones). You are not allowed to recolour already coloured cells.

Input

    The first line contains t(1≤t≤100), the number of test cases.

    In each test case, the first line will contain n(1≤n≤50) and m (1≤m≤50),
        the height and width of the grid respectively.

    The next n lines will contain the grid.

    Each character of the grid is either 'R', 'W', or '.'.

Output

For each test case, output "YES" if there is a valid grid or "NO" if there is not.

If there is, output the grid on the next n lines. If there are multiple answers, print any.

In the output, the "YES"s and "NO"s are case-insensitive, meaning that outputs such as
"yEs" and "nO" are valid. However, the grid is case-sensitive.

Example
Input

3
4 6
.R....
......
......
.W....
4 4
.R.W
....
....
....
5 1
R
W
R
W
R

Output

YES
WRWRWR
RWRWRW
WRWRWR
RWRWRW
NO
YES
R
W
R
W
R
*/

/*
    Hint: Brute force the color of the first square!

    Observation:
        There are only two valid grids, one where the top left cell is "R" and one where it's
            "W"

        We can just test these two grids and see whether they conforms with the requirements

    O(nm)
*/

/*
Solution 2:

#include<iostream>
#include<vector>
using namespace std;

const int MM = 55;

int t, n, m;
string s[MM];
char cc[] = {'R', 'W'};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while (t--)
    {
        cin >> n >> m;
        vector<int> r(2), w(2);
        for (int i = 0; i < n; i++)
        {
            cin >> s[i];
            for (int j = 0; j < m; j++)
            {
                if (s[i][j] == 'R')
                    r[i + j & 1] = 1;
                else if (s[i][j] == 'W')
                    w[i + j & 1] = 1;
            }
        }
        //
        //    If in the matrix two adjacent cells already have the same value apart from '.'
        //    the operation will have in both the indices or that particular color 1

        //    so if we perform 1 & 1 it will in result 1 and ans is "no"

        //    Therefore we have to compare for 1 being present in
        //    either of both the indices of r
        //    with 1 being present in
        //    either of both the indices of w and vice versa
        
        int v = r[1] || w[0];
        int vv = r[0] || w[1];
        if (v && vv)
        {
            cout << "NO\n";
            continue;
        }
        cout << "YES\n";
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                char c = cc[i + j + v & 1];
                cout << c;
                if (s[i][j] != '.') {}
            }
            cout << '\n';
        }
    }
}
*/

#include<iostream>
#include<vector>
#include<set>
#include<queue>
using namespace std;

void bfs(vector<vector<char>>&grd, int currx, int curry, int n, int m,
         set<pair<int, int>>&seen, bool &flag){
    queue<pair<int, int>>q;
    q.push({currx, curry});
    seen.insert({currx, curry});
    while(!q.empty()){
        int sz=q.size();
        while(sz--){
            pair<int, int>curfrnt=q.front();
            q.pop();
            if(curfrnt.first+1<=n-1){
                auto it=seen.find({curfrnt.first+1, curfrnt.second});
                if(it==seen.end()){
                    if(grd[curfrnt.first+1][curfrnt.second]=='.'){
                        grd[curfrnt.first+1][curfrnt.second]=grd[curfrnt.first][curfrnt.second]=='R'?'W':'R';
                        seen.insert({curfrnt.first+1, curfrnt.second});
                        q.push({curfrnt.first+1, curfrnt.second});
                    } else{
                        if((grd[curfrnt.first][curfrnt.second]=='R'&&grd[curfrnt.first+1][curfrnt.second]=='R')||
                            (grd[curfrnt.first][curfrnt.second]=='W'&&grd[curfrnt.first+1][curfrnt.second]=='W')){
                            flag=true;
                            break;
                        } else{
                            seen.insert({curfrnt.first+1, curfrnt.second});
                            q.push({curfrnt.first+1, curfrnt.second});
                        }
                    }
                }
            }
            if(curfrnt.first-1>=0){
                auto it=seen.find({curfrnt.first-1, curfrnt.second});
                if(it==seen.end()){
                    if(grd[curfrnt.first-1][curfrnt.second]=='.'){
                        grd[curfrnt.first-1][curfrnt.second]=grd[curfrnt.first][curfrnt.second]=='R'?'W':'R';
                        seen.insert({curfrnt.first-1, curfrnt.second});
                        q.push({curfrnt.first-1, curfrnt.second});
                    } else{
                        if((grd[curfrnt.first][curfrnt.second]=='R'&&grd[curfrnt.first-1][curfrnt.second]=='R')||
                            (grd[curfrnt.first][curfrnt.second]=='W'&&grd[curfrnt.first-1][curfrnt.second]=='W')){
                            flag=true;
                            break;
                        } else{
                            seen.insert({curfrnt.first-1, curfrnt.second});
                            q.push({curfrnt.first-1, curfrnt.second});
                        }
                    }
                }
            }
            if(curfrnt.second+1<=m-1){
                auto it=seen.find({curfrnt.first, curfrnt.second+1});
                if(it==seen.end()){
                    if(grd[curfrnt.first][curfrnt.second+1]=='.'){
                        grd[curfrnt.first][curfrnt.second+1]=grd[curfrnt.first][curfrnt.second]=='R'?'W':'R';
                        seen.insert({curfrnt.first, curfrnt.second+1});
                        q.push({curfrnt.first, curfrnt.second+1});
                    } else{
                        if((grd[curfrnt.first][curfrnt.second]=='R'&&grd[curfrnt.first][curfrnt.second+1]=='R')||
                            (grd[curfrnt.first][curfrnt.second]=='W'&&grd[curfrnt.first][curfrnt.second+1]=='W')){
                            flag=true;
                            break;
                        } else{
                            seen.insert({curfrnt.first, curfrnt.second+1});
                            q.push({curfrnt.first, curfrnt.second+1});
                        }
                    }
                }
            }
            if(curfrnt.second-1>=0){
                auto it=seen.find({curfrnt.first, curfrnt.second-1});
                if(it==seen.end()){
                    if(grd[curfrnt.first][curfrnt.second-1]=='.'){
                        grd[curfrnt.first][curfrnt.second-1]=grd[curfrnt.first][curfrnt.second]=='R'?'W':'R';
                        seen.insert({curfrnt.first, curfrnt.second-1});
                        q.push({curfrnt.first, curfrnt.second-1});
                    } else{
                        if((grd[curfrnt.first][curfrnt.second]=='R'&&grd[curfrnt.first][curfrnt.second-1]=='R')||
                            (grd[curfrnt.first][curfrnt.second]=='W'&&grd[curfrnt.first][curfrnt.second-1]=='W')){
                            flag=true;
                            break;
                        } else{
                            seen.insert({curfrnt.first, curfrnt.second-1});
                            q.push({curfrnt.first, curfrnt.second-1});
                        }
                    }
                }
            }
        }
        if(flag) break;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<char>>grd(n, vector<char>(m));
        for(int i=0; i<n; ++i){
            for(int j=0; j<m; ++j){
                cin>>grd[i][j];
            }
        }
        set<pair<int, int>>seen;
        bool flag=false;
        vector<vector<char>>grd_=grd;
        for(int i=0; i<n; ++i){
            for(int j=0; j<m; ++j){
                if(grd_[i][j]!='.'){
                    bfs(grd_, i, j, n, m, seen, flag);
                    if(flag) break;
                }
            }
            if(flag) break;
        }
        if(!flag){
            vector<vector<char>>tmp=grd;
            if(tmp[0][0]=='.'){
                char curr_='R';
                tmp[0][0]=curr_;
                seen.clear();
                bfs(tmp, 0, 0, n, m, seen, flag);
                if(!flag){
                    cout<<"YES\n";
                    for(int i=0; i<n; ++i){
                        for(int j=0; j<m; ++j){
                            cout<<tmp[i][j];
                        }
                        cout<<"\n";
                    }
                } else{
                    flag=false;
                    char curr__='W';
                    vector<vector<char>>tmp2=grd;
                    tmp2[0][0]=curr__;
                    seen.clear();
                    bfs(tmp2, 0, 0, n, m, seen, flag);
                    if(!flag){
                        cout<<"YES\n";
                        for(int i=0; i<n; ++i){
                            for(int j=0; j<m; ++j){
                                cout<<tmp2[i][j];
                            }
                            cout<<"\n";
                        }
                    } else{
                        cout<<"NO\n";
                    }
                }
            } else{
                seen.clear();
                bfs(tmp, 0, 0, n, m, seen, flag);
                if(!flag){
                    cout<<"YES\n";
                    for(int i=0; i<n; ++i){
                        for(int j=0; j<m; ++j){
                            cout<<tmp[i][j];
                        }
                        cout<<"\n";
                    }
                } else{
                    cout<<"NO\n";
                }
            }
        } else{
            cout<<"NO\n";
        }
    }
}