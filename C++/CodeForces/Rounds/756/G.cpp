// G. Robot and Candies
/*
Polycarp has a rectangular field of n×m cells (the size of the n⋅m field does not exceed 106 cells, m>=2), in each cell of which there can be candy. 
There are n rows and m columns in the field.

Let's denote a cell with coordinates x vertically and y horizontally by (x,y). Then the top-left cell will be denoted as (1,1), and the bottom-right cell will be denoted as (n,m).

If there is candy in the cell, then the cell is marked with the symbol '1', otherwise — with the symbol '0'.

Polycarp made a Robot that can collect candy. The Robot can move from (x,y) either to (x+1,y+1), or to (x+1,y−1). 
If the Robot is in a cell that contains candy, it takes it.

While there is at least one candy on the field, the following procedure is executed:

Polycarp puts the Robot in an arbitrary cell on the topmost row of the field. He himself chooses in which cell to place the Robot.
It is allowed to put the Robot in the same cell multiple times.
The Robot moves across the field and collects candies. He controls the Robot.
When the Robot leaves the field, Polycarp takes it. If there are still candies left, Polycarp repeats the procedure.
Find the minimum number of times Polycarp needs to put the Robot on the topmost row of the field in order to collect all the candies. 
It is guaranteed that Polycarp can always collect all the candies.

Example
input
4

2 2
00
00

3 3
100
000
101

4 5
01000
00001
00010
10000

3 3
111
111
111
output
0
2
2
4
*/

#include <bits/stdc++.h>
 
using namespace std;
 
#define forn(i, n) for (int i = 0; i < int(n); i++)
#define sz(v) (int)v.size()
 
const int N = 1e6 + 50;
string a[N];
 
int n,m;
int ans;
 
void solve(int sum0) {
    vector<int> v;
    for (int sum = sum0, ad = 0, pref = 0; sum < n + m; sum += 2, ad++) {
        vector<int> cur;
        int li = max(0, sum - m + 1), ri = min(n - 1, sum);
        if (li > ri) continue;
 
        for (int i = li; i <= ri; i++) {
            int j = sum - i;
 
            if (a[i][j] == '1')
                cur.emplace_back(i);
        }
 
        while (pref != sz(v) && v[pref] + ad > ri) {
            pref++;
        }
        for (int i = pref; i < sz(v); i++) {
            int new_val = v[i];
            while (!cur.empty() && cur.back() - ad >= v[i]) {
                new_val = max(new_val, cur.back() - ad);
                cur.pop_back();
            }
            v[i] = new_val;
        }
        if (!cur.empty()) {
            v.emplace_back(cur.back() - ad);
            ans++;
        }
    }
}
 
int main() {
    int t;
    cin >> t;
 
    forn(tt, t) {
        cin >> n >> m;
 
        forn(i, n) {
            string s; 
            cin >> a[i];
        }
 
        ans = 0;
        solve(0);
        solve(1);
        
        cout << ans << '\n';
    }
}
