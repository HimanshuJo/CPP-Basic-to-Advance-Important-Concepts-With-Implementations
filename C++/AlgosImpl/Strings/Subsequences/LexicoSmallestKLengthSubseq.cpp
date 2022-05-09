#include<bits/stdc++.h>
using namespace std;

void smallestSubsequence(string &s, int k){
	int N=s.size();
	stack<char>stk;
	for(int i=0; i<N; ++i){
		if(stk.empty()){
			stk.push(s[i]);
		} else{
			while(!stk.empty()&&s[i]<stk.top()&&stk.size()-1+N-i>=k){
				if(stk.empty()||stk.size()<k){
					stk.push(s[i]);
				}
			}
		}
	}
	string res;
	while(!stk.empty()){
		res.push_back(stk.top());
		stk.pop();
	}
	reverse(res.begin(), res.end());
	cout<<res<<endl;
}

int main(){
	string s="hemnshh";
	smallestSubsequence(s, 3);
}