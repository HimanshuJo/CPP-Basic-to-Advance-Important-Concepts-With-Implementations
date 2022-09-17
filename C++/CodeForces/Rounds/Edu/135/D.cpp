// D. Letter Picking
/*
Alice and Bob are playing a game. Initially, they are given a non-empty string s, consisting of 
lowercase Latin letters. The length of the string is even. Each player also has a string of their own, initially empty.

Alice starts, then they alternate moves. In one move, a player takes either the first or 
the last letter of the string s, removes it from s and prepends (adds to the beginning) it to their own string.

The game ends when the string s becomes empty. The winner is the player with a 
lexicographically smaller string. If the players' strings are equal, then it's a draw.

A string a is lexicographically smaller than a string b if there exists such position i that aj=bj for all j<i and ai<bi.

What is the result of the game if both players play optimally (e.g. both players try to win; 
if they can't, then try to draw)?

Input
The first line contains a single integer t (1≤t≤1000) — the number of testcases.

Each testcase consists of a single line — a non-empty string s, consisting of lowercase Latin letters. 
The length of the string s is even.

The total length of the strings over all testcases doesn't exceed 2000.

Output
For each testcase, print the result of the game if both players play optimally. If Alice wins, print "Alice". 
If Bob wins, print "Bob". If it's a draw, print "Draw".

Example
input
2
forces
abba

output
Alice
Draw

Note
One of the possible games Alice and Bob can play in the first testcase:

Alice picks the first letter in s: s="orces", a="f", b="";
Bob picks the last letter in s: s="orce", a="f", b="s";
Alice picks the last letter in s: s="orc", a="ef", b="s";
Bob picks the first letter in s: s="rc", a="ef", b="os";
Alice picks the last letter in s: s="r", a="cef", b="os";
Bob picks the remaining letter in s: s="", a="cef", b="ros".
Alice wins because "cef" < "ros". Neither of the players follows any strategy in this particular example game, 
so it doesn't show that Alice wins if both play optimally.
*/

/*
What do we do, when the array loses elements only from the left or from the right and the 
constraints obviously imply some quadratic solution? Well, apply dynamic programming, of course.

The classic dp[l][r] — what is the outcome if only the letters from positions l to r 
(non-inclusive) are left. 

dp[0][n] is the answer. dp[i][i] is the base case — the draw (both strings are empty). 
Let −1 mean that Alice wins, 0 be a draw and 1 mean that Bob wins.

How to recalculate it? Let's consider a move of both players at the same time. 
From some state [l;r), first, Alice goes, then Bob. The new state becomes [l′,r′), Alice picked some letter c, 
Bob picked some letter d. What's that pick exactly? So, they both got a letter, prepended it to their own string. 

Then continued the game on a smaller string s and prepended even more letters to the string. 

Thus, if we want to calculate [l,r) from [l′,r′), we say that we append letters c and d. 
Now it's easy. If dp[l′][r′] is not a draw, then the new letters change nothing — the result is still the same. 

Otherwise, the result of the game is the same as the comparison of letters c and d.

How to perform both moves at once? First, we iterate over the Alice's move: 
whether she picks from l or from r. After that we iterate over the Bob's move: whether he picks from l or from r. 
Since we want dp[l][r] to be the best outcome for Alice, we do the following. 

For any Alice move, we choose the worse of the Bob moves — the maximum of dp[l′][r′]. 
Among the Alice's moves we choose the better one — the minimum one.

Overall complexity: O(n^2) per testcase.
*/

#include<iostream>
#include<vector>
using namespace std;

class Solution1{
public:
	template<class T>
	int calSign(T x){
		return (x>0)-(x<0);
	}

	void break_tie(string &s, int &curjnmove, int am, int bm){
		if(curjnmove==1){
			curjnmove=calSign(s[am]-s[bm])+1;
		}
	}

	int dfs(string &s, int sz, int l, int r, vector<vector<int>>&memo){
		if(l>r) return 1;
		if(memo[l][r]!=-1) return memo[l][r];
		int albl=dfs(s, sz, l+2, r, memo);
		/*
			If it's a break check char at left and right
			
			If char at left > char at right
				the person who has left move wins, so
					calSign(s[l]-s[r]) returns a pos val

			If char at right > char at left
				the person who has the right move wins, so
					calSign(s[l]-s[r]) return a neg val

			If char at both left and right is same
				the current val remains same
		*/
		break_tie(s, albl, l, l+1);
		int albr=dfs(s, sz, l+1, r-1, memo);
		break_tie(s, albr, l, r);
		int alonlyl=max(albl, albr);
		int arbl=dfs(s, sz, l+1, r-1, memo);
		break_tie(s, arbl, r, l);
		int arbr=dfs(s, sz, l, r-2, memo);
		break_tie(s, arbr, r, r-1);
		int alonlyr=max(arbl, arbr);
		return memo[l][r]=min(alonlyl, alonlyr);
	}
};

// -------*******-------

class Solution2{
public:

	int comp(const char A, const char B){
		return A<B?-1:(A>B?1:0);
	}

	void letterPicking(vector<vector<int>>&dp, string &s, int sz){
		for(int len=2; len<=sz; len+=2){
			for(int l=0; l<sz-len+1; ++l){
				int r=l+len;
				dp[l][r]=1;
				int res=-1;
				// One left one right (Alice left, Bob right)
				if(dp[l+1][r-1]!=0){
					res=max(res, dp[l+1][r-1]);
				} else{
					res=max(res, comp(s[l], s[r-1]));
				}
				// Both playing left
				if(dp[l+2][r]!=0){
					res=max(res, dp[l+2][r]);
				} else{
					res=max(res, comp(s[l], s[l+1]));
				}
				dp[l][r]=min(dp[0][r], res);
				res=-1;
				// One left one right (Bob left, Alice right)
				if(dp[l+1][r-1]!=0){
					res=max(res, dp[l+1][r-1]);
				} else{
					res=max(res, comp(s[r-1], s[l]));
				}
				// Both playing right
				if(dp[l][r-2]!=0){
					res=max(res, dp[l][r-2]);
				} else{
					res=max(res, comp(s[r-1], s[r-2]));
				}
				dp[l][r]=min(dp[l][r], res);
			}
		}
		if(dp[0][sz]==-1) cout<<"Alice\n";
		else if(dp[0][sz]==0) cout<<"Draw\n";
		else cout<<"Bob\n";
	}
};

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin>>t;
	Solution2 obj2;
	Solution1 obj1;
	while(t--){
		string s;
		cin>>s;
		int sz=s.size();
		vector<vector<int>>dp(sz+1, vector<int>(sz+1));
		obj2.letterPicking(dp, s, sz);
		// -------*******-------
		vector<vector<int>>memo(sz+1, vector<int>(sz+1, -1));
		int ans=obj1.dfs(s, sz, 0, sz-1, memo);
		cout<<(ans==0?"Alice\n":ans==1?"Draw\n":"BOB\n");
	}
}