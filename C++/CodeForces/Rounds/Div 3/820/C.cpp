// C. Jumping on Tiles
/*
Polycarp was given a row of tiles. Each tile contains one lowercase letter of the Latin alphabet. 
The entire sequence of tiles forms the string s.

In other words, you are given a string s consisting of lowercase Latin letters.

Initially, Polycarp is on the first tile of the row and wants to get to the last tile by jumping on the tiles. 
Jumping from i-th tile to j-th tile has a cost equal to |index(si)−index(sj)|, where index(c) is the 
index of the letter c in the alphabet (for example, index('a')=1, index('b')=2, ..., index('z')=26) .

Polycarp wants to get to the n-th tile for the minimum total cost, but at the same 
time make maximum number of jumps.

In other words, among all possible ways to get to the last tile for the minimum total cost, 
he will choose the one with the maximum number of jumps.

Polycarp can visit each tile at most once.

Polycarp asks you to help — print the sequence of indices of string s on which he should jump.

Input
The first line of the input contains an integer t (1≤t≤10^4) — the number of test cases in the test.

Each test case is given by the string s (2≤|s|≤2⋅10^5), where |s| — is the length of string s. 
The string s consists of lowercase Latin letters.

It is guaranteed that the sum of string lengths s over all test cases does not exceed 2⋅10^5.

Output
The answer to each test case consists of two lines.

In the first line print two integers cost, m, where cost is the minimum total cost of the path, 
and m is the maximum number of visited tiles Polycarp can make to get to n-th tiles for the 
minimum total cost cost (i.e. the number of jumps is m−1).

In the next line print m different numbers j1,j2,…,jm (1≤ji≤|s|) — the sequence of indices 
of the tiles Polycarp will jump on. The first number in the sequence must be 1 (that is, j1=1) and 
the last number must be the value of |s| (that is, jm=|s|).

If there are multiple answers, print any of them.

Example
input
6
logic
codeforces
bca
aaaaaaaaaaa
adbaadabad
to

output
9 4
1 4 3 5
16 10
1 8 3 4 9 5 2 6 7 10
1 2
1 3
0 11
1 8 10 4 3 5 7 2 9 6 11
3 10
1 9 5 4 7 3 8 6 2 10
5 2
1 2
*/

/*
It's worth knowing that ways like ('a' -> 'e') and ('a' -> 'c' -> 'e') have the same cost. 
That is, first you need to understand the letter on the first tile and the last one 
(conditionally, the letters first and last).

Then you just need to find all such tiles on which the letters are between the 
letters first and last inclusive.

We go through each letter from first to last and for each letter we visit every tile that 
has a given letter (but we must not forget to start exactly at tile 1 and end at tile n).
*/

#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<string>
#include<queue>
#include<unordered_map>
#include<map>
#include<unordered_set>
#include<set>
#define endl "\n"
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        int sz=s.size();
        unordered_map<char, vector<int>>mp;
        for(int i=0; i<sz; ++i){
            mp[s[i]].push_back(i);
        }
        int dir=s[0]<s[sz-1]?1:-1;
        vector<int>ans;
        for(char ch=s[0]; ch!=s[sz-1]+dir; ch+=dir){
            for(auto &vals: mp[ch]){
                ans.push_back(vals);
            }
        }
        int fncost=0;
        int anssz=ans.size();
        for(int i=1; i<anssz; ++i){
            fncost+=abs(s[ans[i]]-s[ans[i-1]]);
        }
        cout<<fncost<<" "<<ans.size()<<endl;
        for(int i=0; i<anssz; ++i){
            cout<<ans[i]+1<<" ";
        }
        cout<<endl;
    }
}