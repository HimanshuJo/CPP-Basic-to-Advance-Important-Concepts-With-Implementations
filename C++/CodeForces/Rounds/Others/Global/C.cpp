// C. Even Number Addicts
/*
Alice and Bob are playing a game on a sequence a1,a2,…,an of length n. They move in turns and Alice moves first.

In the turn of each player, he or she should select an integer and remove it from the sequence. 
The game ends when there is no integer left in the sequence.

Alice wins if the sum of her selected integers is even; otherwise, Bob wins.

Your task is to determine who will win the game, if both players play optimally.

Input
Each test contains multiple test cases. The first line contains an integer t (1≤t≤100) — the number of test cases. 
The following lines contain the description of each test case.

The first line of each test case contains an integer n (1≤n≤100), indicating the length of the sequence.

The second line of each test case contains n integers a1,a2,…,an (−109≤ai≤109), indicating the elements of the sequence.

Output
For each test case, output "Alice" (without quotes) if Alice wins and "Bob" (without quotes) otherwise.

Example
input
4
3
1 3 5
4
1 3 5 7
4
1 2 3 4
4
10 20 30 40

output
Alice
Alice
Bob
Alice

Note
In the first and second test cases, Alice always selects two odd numbers, so the sum of her selected numbers is always even. 
Therefore, Alice always wins.

In the third test case, Bob has a winning strategy that he always selects a number with the same parity as Alice selects 
in her last turn. Therefore, Bob always wins.

In the fourth test case, Alice always selects two even numbers, so the sum of her selected numbers is always even. 
Therefore, Alice always wins.
*/

/*
We only need to consider the case that ai= 0 or 1.

Suppose there are a 0's and b 1's in total. Consider the following cases:

numOnes≡0(mod4).

	Alice has a winning strategy: Choose 0 first; after that, choose the number that Bob chooses in his last move. 
	This strategy keeps the invariant that Alice and Bob have the same number of 1's after Alice's each move. 
	The only exception that Alice cannot go on with this strategy is that there is no 0. 
	In this case, there must be an even number of 1's (and no 0's) remaining. 
	Therefore, each of Alice and Bob will choose half of the remaining 1's. 
	At last, Alice and Bob have the same number numOnes/2 of 1's, which is even.

numOnes≡1(mod4).

	If any of Alice and Bob chooses the first 1, the game is reduced to a 0's and numOnes−1 1's with its opponent moving first, 
	resulting in the case of numOnes≡0(mod4) and its opponent wins. 
	Therefore, the one who chooses the first 1 loses. With this observation, Alice will lose if there are an 
	even number of 0's, i.e., a≡0(mod2); and Alice will win if a≡1(mod2).

numOnes≡2(mod4).

	Bob has a winning strategy: Always choose the number that Alice chooses in her last move. 
	This strategy keeps the invariant that Alice and Bob have the same number of 1's after Bob's each move. 
	The only exception that Bob cannot go on with this strategy is that Alice takes the last 0. 
	In this case, there must be an even number of 1's (and no 0's) remaining. 
	Therefore, each of Alice and Bob will choose half of the remaining 1's. 
	At last, Alice and Bob have the same number numOnes/2 of 1's, which is odd.

numOnes≡3(mod4).

	Alice has a winning strategy: Choose 1 first.
	After this move, the game is reduced to a 0's and numOnes−1 1's with Bob taking the first turn and Bob wins if 
	he has an even number of 1's at last. 
	This reduced game is indeed the case of numOnes≡2(mod4) which we have already proved that Bob always loses.
*/

#include<iostream>
#include<vector>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin>>t;
	while(t--){
		int N;
		cin>>N;
		vector<int>in(N);
		vector<int>count(2);
		for(int i=0; i<N; ++i){
			cin>>in[i];
			if(in[i]%2==0){
				count[0]++;
			} else{
				count[1]++;
			}
		}
		int countZ=count[0]%4, countOn=count[1]%4;
		if(countOn==0){
			cout<<"Alice"<<endl;
		} else if(countOn==2){
			cout<<"Bob"<<endl;
		} else if(countOn==3){
			cout<<"Alice"<<endl;
		} else{
			if(countZ%2==0){
				cout<<"Bob"<<endl;
			} else{
				cout<<"Alice"<<endl;
			}
		}
	}
}