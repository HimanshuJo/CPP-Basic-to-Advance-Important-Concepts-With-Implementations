#include<iostream>
#include<vector>
#include<string>
using namespace std;

int main(){
	int N=7;
	vector<pair<string, vector<string>>>vec;
	vector<int>vecCatalan(N);
	vec.push_back({"res[0]", {"1"}});
	vec.push_back({"res[1]", {"1"}});
	vecCatalan[0]=1, vecCatalan[1]=1;
	for(int i=2; i<N; ++i){
		string curr="res["+to_string(i)+"]";
		vector<string>vecTmp;
		for(int j=0; j<i; ++j){
			vecCatalan[i]+=vecCatalan[j]*vecCatalan[i-j-1];
			string next="";
			next+="res["+to_string(j)+"]"+"*"+"res["+to_string(i-j-1)+"]";
			if(j!=i-1) next+=" + ";
			vecTmp.push_back(next);
		}
		vec.push_back({curr, vecTmp});	
	}
	for(auto &vals: vec){
		cout<<vals.first<<" = ";
		for(auto &entries: vals.second){
			cout<<entries<<" ";
		}
		cout<<endl;
	}
	cout<<"-------\n";
	for(int i=0; i<N; ++i){
		cout<<i<<" : "<<vecCatalan[i]<<endl;
	}
}

/*
Output:

res[0] = 1
res[1] = 1
res[2] = res[0]*res[1] +  res[1]*res[0]
res[3] = res[0]*res[2] +  res[1]*res[1] +  res[2]*res[0]
res[4] = res[0]*res[3] +  res[1]*res[2] +  res[2]*res[1] +  res[3]*res[0]
res[5] = res[0]*res[4] +  res[1]*res[3] +  res[2]*res[2] +  res[3]*res[1] +  res[4]*res[0]
res[6] = res[0]*res[5] +  res[1]*res[4] +  res[2]*res[3] +  res[3]*res[2] +  res[4]*res[1] +  res[5]*res[0]
-------
0 : 1
1 : 1
2 : 2
3 : 5
4 : 14
5 : 42
6 : 132
*/