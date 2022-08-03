/*
	Shuffling a deck of cards. In other words, each of the 52! permutations of the deck has to be equally likely
*/

/*
Algo:

	We will shuffle the first n-1 elements

	Then we would take the nth element and randomly swap it with an element in the array
*/

#include<iostream>
#include<vector>
#include<random>
#include<stdlib.h>
using namespace std;

class Solution1{
public:
	vector<int> dfs(vector<int>&cards, int i){
		if(i==0) return cards;
		// shuffling elements 0 through index-1
		dfs(cards, i-1);
		// random number [0, i]
		int randNum=rand()%(i+1);
		int temp=cards[randNum];
		cards[randNum]=cards[i];
		cards[i]=temp;
		return cards;
	}

	vector<int> shuffleArray(vector<int>&cards, int i){
		return dfs(cards, i);
	}
};

// -------*******-------

class Solution2{
public:
	void shuffleArray(vector<int>&cards){
		for(int i=0; i<cards.size(); ++i){
			// random number [0, i]
			int randNum=rand()%(i+1);
			int temp=cards[randNum];
			cards[randNum]=cards[i];
			cards[i]=temp;
		}
	}
};

int main(){
	Solution1 obj1;
	Solution2 obj2;
	vector<int>cards;
	for(int i=0; i<4; ++i){
		for(int j=2; j<=10; ++j){
			cards.push_back(j);
		}
		for(int i=0; i<4; ++i){
			cards.push_back(13);
		}
	}
	//obj1.shuffleArray(cards, cards.size());
	obj2.shuffleArray(cards);
	for(auto &vals: cards){
		cout<<vals<<endl;
	}
}