/*
Given a string check if it is a permutation of a palindrome.

E.g. string="tact coa"
     output: true ("taco cat" or "atco cta")

     string="mmdaa"
     output: true ("madam")
*/

#include<iostream>
#include<string>
#include<vector>
using namespace std;

bool checkMaxOneOdd(vector<int>&tb){
	bool haveFound=false;
	for(auto &vals: tb){
		if(vals%2!=0){
			if(haveFound) return false;
			haveFound=true;
		}
	}
	return true;
}

int getCharNum(char ch){
	int a=(int)'a';
	int z=(int)'z';
	int val=(int)ch;
	if(a<=val&&val<=z){
		return val-a;
	}
	return -1;
}

vector<int> buildCharFrequency(string in){
	vector<int>table((int)'z'-(int)'a'+1, 0);
	for(char ch: in){
		int x=getCharNum(ch);
		if(x!=-1){
			table[x]++;
		}
	}
	return table;
}

bool isPermutationOfPalindrome1(string in){
	vector<int>tb=buildCharFrequency(in);
	int sz=tb.size();
	/*for(int i=0; i<sz; ++i){
		cout<<(char)(i+97)<<" : "<<tb[i]<<endl;
	}*/
	return checkMaxOneOdd(tb);
}

/*
Space Optimized:
*/

bool isPermutationOfPalindrome2(string in){
	int countOdd=0;
	vector<int>tb((int)'z'-(int)'a'+1, 0);
	for(char ch: in){
		int x=getCharNum(ch);
		if(x!=-1){
			tb[x]++;
			if(tb[x]%2==1){
				countOdd++;
			} else{
				countOdd--;
			}
		}
	}
	return countOdd<=1;
}

int main(){
	string in="mmdaa";
	bool res1=isPermutationOfPalindrome1(in);
	bool res2=isPermutationOfPalindrome2(in);
	cout<<(res1==1?"true":"false")<<endl;
	cout<<(res2==1?"true":"false");
}