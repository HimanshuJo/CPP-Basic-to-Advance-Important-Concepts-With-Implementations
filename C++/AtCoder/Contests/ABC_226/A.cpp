#include<bits/stdc++.h>
using namespace std;

int main(){
	float X;
	cin>>X;
	string toChk=to_string(X);
	int idx=0;
	for(int i=0; i<toChk.length(); ++i){
		if(toChk[i]=='.'){
			idx=i+1;
			break;
		}
	}
	int numToChk=toChk[idx]-'0';
	int curr=0;
	string temp="";
	for(int i=0; i<idx-1; ++i){
		temp+=toChk[i];
	}
	curr=stoi(temp);
	if(numToChk>=5){
		cout<<(curr+1)<<"\n";
	}
	else{
		cout<<curr<<"\n";
	}
}
