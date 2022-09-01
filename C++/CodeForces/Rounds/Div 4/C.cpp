// C. Word Game
/*
Three guys play a game: first, each person writes down n distinct words of length 3. 
Then, they total up the number of points as follows:

if a word was written by one person — that person gets 3 points,
if a word was written by two people — each of the two gets 1 point,
if a word was written by all — nobody gets any points.
In the end, how many points does each player have?
Input
The input consists of multiple test cases. The first line contains an integer t (1≤t≤100) — 
the number of test cases. The description of the test cases follows.

The first line of each test case contains an integer n (1≤n≤1000) — the number of words written by each person.

The following three lines each contain n distinct strings — the words written by each person. 
Each string consists of 3 lowercase English characters.

Output
For each test case, output three space-separated integers — the number of points each of the 
three guys earned. You should output the answers in the same order as the input; the i-th integer 
should be the number of points earned by the i-th guy.

Example
input
3
1
abc
def
abc
3
orz for qaq
qaq orz for
cod for ces
5
iat roc hem ica lly
bac ter iol ogi sts
bac roc lly iol iat

output
1 3 1 
2 2 6 
9 11 5 
Note
In the first test case:

The word abc was written by the first and third guys — they each get 1 point.
The word def was written by the second guy only — he gets 3 points.
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
        unordered_map<string, vector<int>>mp;
        vector<string>in;
        for(int i=0; i<3; ++i){
            for(int j=0; j<n; ++j){
                string s;
                cin>>s;
                mp[s].push_back(i);
            }
        }
        vector<int>res(3, 0);
        for(auto &entries: mp){
            int sz=entries.second.size();
            vector<int>temp=entries.second;
            if(entries.second.size()==1){
                int idx=temp[0];
                res[idx]+=3;
            } else if(sz<3){
                for(auto &vals: temp){
                    int idx=vals;
                    res[idx]+=1;
                }
            }
        }
        cout<<res[0]<<" "<<res[1]<<" "<<res[2]<<endl;
	}
}