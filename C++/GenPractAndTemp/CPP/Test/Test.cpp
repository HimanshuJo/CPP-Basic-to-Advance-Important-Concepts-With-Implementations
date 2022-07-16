#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

string toBinary(int i){
	string res="";
	while(i!=1){
		int remain=i%2;
		res+=to_string(remain);
		i/=2;
	}
	res+="1";
	reverse(res.begin(), res.end());
	return res;
}

int main(){
	for(int i=1; i<=20; ++i){
		cout<<toBinary(i)<<" : "<<endl;
		//cout<<calOr(i, 2*i+1)<<endl;
		//cout<<calAnd(i, 3*i+1)<<endl;
		//cout<<calXOR(i, 4*i+1)<<endl;
	}
}