// B. Colourblindness
/*
Vasya has a grid with 2 rows and n columns. He colours each cell red, green, or blue.

Vasya is colourblind and can't distinguish green from blue. Determine if Vasya will 
consider the two rows of the grid to be coloured the same.

Input
The input consists of multiple test cases. The first line contains an integer t (1≤t≤100) — 
the number of test cases. The description of the test cases follows.

The first line of each test case contains an integer n (1≤n≤100) — the number of columns of the grid.

The following two lines each contain a string consisting of n characters, each of which is either R, G, or B, 
representing a red, green, or blue cell, respectively — the description of the grid.

Output
For each test case, output "YES" if Vasya considers the grid's two rows to be identical, and "NO" otherwise.

You can output the answer in any case (for example, the strings "yEs", "yes", "Yes" and "YES" will 
be recognized as a positive answer).

Example
input
6
2
RG
RB
4
GRBG
GBGB
5
GGGGG
BBBBB
7
BBBBBBB
RRRRRRR
8
RGBRRGBR
RGGRRBGR
1
G
G

output
YES
NO
YES
NO
YES
YES
Note
In the first test case, Vasya sees the second cell of each row as the same because the second cell of the 
first row is green and the second cell of the second row is blue, so he can't distinguish these two cells. 

The rest of the rows are equal in colour. Therefore, Vasya will say that the two rows are coloured the same, 
even though they aren't.

In the second test case, Vasya can see that the two rows are different.

In the third test case, every cell is green or blue, so Vasya will think they are the same.
*/

#include<iostream>
#include<vector>
#include<map>
#include<unordered_map>
#include<queue>
#define ll long long
#define endl "\n"
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin>>t;
	while(t--){
        int n;
        cin>>n;
        vector<vector<char>>in(2, vector<char>(n));
        for(int i=0; i<2; ++i){
            for(int j=0; j<n; ++j){
                cin>>in[i][j];
            }
        }
        vector<vector<char>>temp1=in;
        for(int i=0; i<2; ++i){
            for(int j=0; j<n; ++j){
                if(temp1[i][j]=='G'){
                    temp1[i][j]='B';
                }
            }
        }
        vector<char>frst=temp1[0];
        vector<char>sec=temp1[1];
        if(frst==sec){
            cout<<"YES\n";
        } else{
            vector<vector<char>>temp2=in;
            for(int i=0; i<2; ++i){
                for(int j=0; j<n; ++j){
                    if(temp2[i][j]=='B'){
                        temp2[i][j]='G';
                    }
                }
            }
            vector<char>frst_=temp2[0];
            vector<char>sec_=temp2[1];
            if(frst_==sec_){
                cout<<"YES\n";
            } else{
                cout<<"NO\n";
            }
        }
	}
}