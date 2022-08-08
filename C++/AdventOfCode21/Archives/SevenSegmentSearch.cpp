#include<iostream>
#include<vector>
#include<string>
#include<sstream>
#include<cstring>
using namespace std;
using ll=long long;

vector<string> splitString(string str, char delimiter) { 
	vector<string> res; 
	stringstream ss(str); 
	string tok; 
	while(getline(ss, tok, delimiter)) { 
		res.push_back(tok); 
	} 
	return res;  
}


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n=400;
	vector<string>in;
	for(int i=0; i<n; ++i){
		char temp[500];
		gets(temp);
		//cout<<temp;
		if(i&1){
			in.push_back(temp);
		}
		//cout<<"\n-------\n";
	}
	ll ans=0;
	for(auto &vals: in){
		vector<string>currWrk=splitString(vals, '$');
		for(auto &vals_: currWrk){
			if(vals_.size()==2||vals_.size()==4||vals_.size()==3||vals_.size()==7){
				ans++;
			}
		}
		//cout<<vals<<endl;
	}
	cout<<"-------\n";
	cout<<ans<<"\n";
}
