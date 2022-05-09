/*
Solution 2:

// C++ program to print distinct
// subsequences of a given string
#include <bits/stdc++.h>
using namespace std;

// Create an empty set to store the subsequences
unordered_set<string> sn;

// Function for generating the subsequences
void subsequences(char s[], char op[], int i, int j)
{

	// Base Case
	if (s[i] == '\0') {
		op[j] = '\0';

		// Insert each generated
		// subsequence into the set
		sn.insert(op);
		return;
	}

	// Recursive Case
	else {
		// When a particular character is taken
		op[j] = s[i];
		subsequences(s, op, i + 1, j + 1);

		// When a particular character isn't taken
		subsequences(s, op, i + 1, j);
		return;
	}
}

int main()
{
	char str[] = "ggg";
	const int m = sizeof(str) / sizeof(char);
	int n = pow(2, m) + 1;

	// Output array for storing
	// the generating subsequences
	// in each call
	char op[m+1]; //extra one for having \0 at the end

	// Function Call
	subsequences(str, op, 0, 0);

	// Output will be the number
	// of elements in the set
	cout << sn.size()<<endl;
    for (auto &vals: sn){
        if (vals.compare("")==0){
            cout<<"null ";
        } else{
            cout<<vals<<" ";
        }
    }
	sn.clear();
	return 0;
}
*/

#include<iostream>
#include<vector>
#include<string>
#include<set>
using namespace std;

void genDistinctSubsequeUtil(string str, int idx, set<vector<char>>&res, 
                             vector<char>cursubseque){
	if(idx>=str.length()){
		res.insert(cursubseque);
		return;
	}
	cursubseque.push_back(str[idx]);
	genDistinctSubsequeUtil(str, idx+1, res, cursubseque);
	cursubseque.pop_back();
	genDistinctSubsequeUtil(str, idx+1, res, cursubseque);
}

set<vector<char>> genDistinctSubseque(string str){
	set<vector<char>>res;
	vector<char>cursubseque;
	genDistinctSubsequeUtil(str, 0, res, cursubseque);
	return res;
}

int main(){
	string str="abcd";
	set<vector<char>>allsubseque=genDistinctSubseque(str);
	for(auto &vals: allsubseque){
		if(vals.size()==0) cout<<"{}";
		else{
			for(char ch: vals){
				cout<<ch;
			}
		}
		cout<<endl;
	}
}