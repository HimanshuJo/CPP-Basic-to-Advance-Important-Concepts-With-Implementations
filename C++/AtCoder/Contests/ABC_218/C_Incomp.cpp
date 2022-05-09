// Shapes
/*
Problem Statement
We have two figures S and T on a two-dimensional grid with square cells.

S lies within a grid with N rows and N columns, and consists of the cells where 
Si,j is #.

T lies within the same grid with N rows and N columns, and consists of the cells where
Ti,j is #.

Determine whether it is possible to exactly match S and T by 90-degree rotations and
translations.

Sample Input 1 
5
.....
..#..
.###.
.....
.....
.....
.....
....#
...##
....#
Sample Output 1 
Yes
We can match S to T by rotating it 90-degrees counter-clockwise and translating it.

Sample Input 2 
5
#####
##..#
#..##
#####
.....
#####
#..##
##..#
#####
.....
Sample Output 2 
No
It is impossible to match them by 90-degree rotations and translations.

Sample Input 3 
4
#...
..#.
..#.
....
#...
#...
..#.
....
Sample Output 3 
Yes
Each of S and T may not be connected.

Sample Input 4 
4
#...
.##.
..#.
....
##..
#...
..#.
....
Sample Output 4 
No
Note that it is not allowed to rotate or translate just a part of a figure; it is only allowed to rotate or translate a whole figure.
*/

/*
If S and T have different number of #s, then the answer is obviously No. We consider the other cases.

We brute force through all 4 possibility of 90-degree rotation of S. If we newly denote by S the shape after the rotation is applied, then we want to determine if S and T can be matched by translations.

In order to match them, the leftmost and uppermost square of S and the leftmost and uppermost square of T should match. Once we have such squares, we can uniquely determine how much we should translate the squares, so it is sufficient to check if the translation actually matches them.

Therefore, we could solve it in a total of O(N^2) time.
*/

#include<bits/stdc++.h>
using namespace std;

vector<vector<char>> rott(vector<vector<char>>S, int N){
    vector<vector<char>>res;
    for(int i=0; i<N; ++i){
        vector<char>tmp;
        for(int j=N-1; j>=0; --j){
            tmp.push_back(S[i][j]);
        }
        res.push_back(tmp);
    }
    return res;
}

pair<int, int>find_left_top(vector<vector<char>>S, int N){
    pair<int, int>tmp;
    bool flag=false;
    for(int i=0; i<N; ++i){
        for(int j=0; j<N; ++j){
            if(S[i][j]=='#'){
                tmp.first=i;
                tmp.second=j;
                flag=true;
                break;
            }
        }
        if(flag){
            break;
        }
    }
    return tmp;
}

bool isSame(vector<vector<char>>S, vector<vector<char>>T, int N){
    pair<int, int>tmpS=find_left_top(S, N);
    pair<int, int>tmpT=find_left_top(T, N);
    int offset_i=tmpT.first-tmpS.first;
    int offset_j=tmpT.second-tmpS.second;
    for(int i=0; i<N; ++i){
        for(int j=0; j<N; ++j){
            int ii=i+offset_i;
            int jj=j+offset_j;
            if(0<=ii&&ii<N&&0<=jj&&jj<N){
                if(S[i][j]!=T[ii][jj]){
                    return false;
                }
            } else{
                if(S[i][j]=='#'){
                    return false;
                }
            }
        }
    }
    return true;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    cin>>N;
    vector<string>ss;
    vector<string>tt;
    for(int i=0; i<N; ++i){
        string temp;
        cin>>temp;
        ss.push_back(temp);
    }
    for(int i=0; i<N; ++i){
        string temp;
        cin>>temp;
        tt.push_back(temp);
    }
    vector<vector<char>>S(N, vector<char>(N, '.'));
    vector<vector<char>>T(N, vector<char>(N, '.'));
    int countHshS=0;
    int countHshT=0;
    for(int i=0; i<N; ++i){
        string curr=ss[i];
        for(int j=0; j<N; ++j){
            S[i][j]=curr[j];
            if(S[i][j]=='#'){
                countHshS++;
            }
        }
    }
    for(int i=0; i<N; ++i){
        string curr=tt[i];
        for(int j=0; j<N; ++j){
            T[i][j]=curr[j];
            if(T[i][j]=='#'){
                countHshT++;
            }
        }
    }
    if(S==T){
        cout<<"Yes";
    } else if(countHshS!=countHshT) {
        cout<<"NO";
    }
    bool flag=true;
    for(int i=0; i<4; ++i){
        if(isSame(S, T, N)){
            cout<<"Yes";
            flag=false;
            break;
        }
        vector<vector<char>>tmp_;
        tmp_=S;
        S.clear();
        S=rott(tmp_, N);
    }
    if(flag){
        cout<<"No";
    }
}