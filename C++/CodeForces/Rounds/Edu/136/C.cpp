// C. Card Game
/*
Consider a game with n cards (n is even). Each card has a number written on it, between 1 and n. 
All numbers on the cards are different. We say that a card with number x is stronger than a card with number y if x>y.

Two players, Alex and Boris, play this game. In the beginning, each of them receives exactly n2 cards, 
so each card belongs to exactly one player. 

Then, they take turns. Alex goes first, then Boris, then Alex again, and so on.

On a player's turn, he must play exactly one of his cards. Then, if the opponent doesn't have 
any cards stronger than the card played, the opponent loses, and the game ends. 
Otherwise, the opponent has to play a stronger card (exactly one card as well). 
These two cards are removed from the game, and the turn ends. If there are no cards left, 
the game ends in a draw; otherwise it's the opponent's turn.

Consider all possible ways to distribute the cards between two players, so that each of them receives exactly 
half of the cards. You have to calculate three numbers:

the number of ways to distribute the cards so that Alex wins;
the number of ways to distribute the cards so that Boris wins;
the number of ways to distribute the cards so that the game ends in a draw.
You may assume that both players play optimally (i.e. if a player can win no matter how his opponent plays, he wins). 
Two ways to distribute the cards are different if there is at least one card such that, in one of these ways, 
it is given to Alex, and in the other way, it is given to Boris.

For example, suppose n=4, Alex receives the cards [2,3], and Boris receives the cards [1,4]. 
Then the game may go as follows:

if Alex plays the card 2, then Boris has to respond with the card 4. Then, Alex's turn ends, and Boris' turn starts. 
Boris has only one card left, which is 1; he plays it, and Alex responds with the card 3. So, the game ends in a draw;

if Alex plays the card 3, then Boris has to respond with the card 4. Then, Alex's turn ends, and Boris' turn starts. 
Boris has only one card left, which is 1; he plays it, and Alex responds with the card 2. So, the game ends in a draw.
So, in this case, the game ends in a draw.

Input
The first line contains one integer t (1≤t≤30) — the number of test cases.

Then, t lines follow. The i-th line contains one even integer n (2≤n≤60).

Output
For each test case, print three integers:

the number of ways to distribute the cards so that Alex wins;
the number of ways to distribute the cards so that Boris wins;
the number of ways to distribute the cards so that the game ends in a draw.
Since the answers can be large, print them modulo 998244353.

Example
input
5
2
4
6
8
60

output
1 0 1
3 2 1
12 7 1
42 27 1
341102826 248150916 1

Note
In the first test case, Alex wins if he receives the card 2 (he plays it, and Boris cannot respond). 
If Alex receives the card 1, the game ends in a draw.

In the second test case:

Alex wins if he receives the cards [3,4], [2,4] or [1,4];
Boris wins if Alex receives the cards [1,2] or [1,3];
the game ends in a draw if Alex receives the cards [2,3].
*/

/*
TLE:

#include<vector>
#include<iostream>
#include<unordered_map>
#include<map>
#include<queue>
#include<algorithm>
#include<set>
#define endl "\n"
using ll=long long;
using namespace std;

int whoWin(vector<int>&curr, vector<int>&next){
    int sz=curr.size();
    int counter=0;
    for(int i=0; i<sz; ++i){
        if(counter%2==0){
            if(next[i]<curr[i]){
                return 0;
            } else{
                counter++;
            }
        } else{
            if(curr[i]<next[i]){
                return 1;
            } else{
                counter++;
            }
        }
    }
    return 2;
}

void backtrack(int N, vector<vector<int>>&res, vector<int>&tmpList){
	if(tmpList.size()==N){
        vector<int>nwtmp;
        for(int x=0; x<N/2; ++x){
            nwtmp.push_back(tmpList[x]);
        }
        sort(nwtmp.begin(), nwtmp.end(), greater<>());
        auto it=find(res.begin(), res.end(), nwtmp);
        if(it==res.end()){
            res.push_back(nwtmp);
        }
	} else{
		for(int i=1; i<=N; ++i){
			auto it=find(tmpList.begin(), tmpList.end(), i);
			if(it!=tmpList.end()) continue;
			tmpList.push_back(i);
			backtrack(N, res, tmpList);
			tmpList.pop_back();
		}
	}
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        long long awn=0, bwn=0, drw=0;
        vector<vector<int>>res;
	    vector<int>tmpList;
        backtrack(N, res, tmpList);
        for(auto &entries: res){
            vector<int>curr=entries;
            vector<int>nw;
            for(int i=1; i<=N; ++i){
                auto it=find(curr.begin(), curr.end(), i);
                if(it==curr.end()){
                    nw.push_back(i);
                }
            }
            sort(nw.begin(), nw.end(), greater<>());
            int cures=whoWin(curr, nw);
            if(cures==0){
                awn++;
            } else if(cures==1){
                bwn++;
            } else{
                drw++;
            }
        }
        cout<<awn<<" "<<bwn<<" "<<drw<<endl;
    }
}
*/