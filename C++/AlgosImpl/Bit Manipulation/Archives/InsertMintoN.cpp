/*
	Given Two 32 bit numbers, N and M and two bit positions i and j.
	Insert M into N such that M starts at bit j and ends at bit i.
	Bit j through i have enough space to fit all of M.

	E.g. N=1024 (binary: 100'000'000'00) M=19 (binary: 10011), i=2, j=6
	     Output: 1100 (binary: 10001001100)
*/

#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
using ll=long long;

string toBinary(ll num){
	string res="";
	while(num>1){
		if(num%2==0){
			res+="0";
		} else res+="1";
		num/=2;
	}
	res+="1";
	reverse(res.begin(), res.end());
	/*if(res.size()<32){
		int sz=res.size();
		for(int i=sz; i<32; ++i){
			res.insert(0, "0");
		}
	}*/
	return res;
}

ll toDecimal(string num){
	int sz=num.size();
	int end=sz-1;
	ll ans=0;
	for(int i=0; i<sz; ++i){
		ans+=(num[i]-'0')*pow(2, end--);
	}
	return ans;
}

int update(ll N, ll M, int i, int j){
	if(i>j||i<0||j>=32) return 0;
	int allOnes=~0;
	cout<<"all ones "<<toBinary(allOnes)<<endl;
	// 1's before postiion j, then 0s. e.g. left= 11100000
	int left=j<31?(allOnes<<(j+1)):0;
	cout<<"left "<<toBinary(left)<<endl;
	// 1's after position i. e.g. right=00000011
	int right=((1<<i)-1);
	cout<<"right "<<toBinary(right)<<endl;
	// all 1's except for 0's between i and j. e.g. mask=111000111
	int mask=left|right;
	cout<<"mask "<<toBinary(mask)<<endl;
	// clearing bits j through i and putting M in there
	ll nCleared=N&mask;
	cout<<"nCleared "<<toBinary(nCleared)<<endl;
	int MShifted=M<<i;
	cout<<"mShifted "<<toBinary(MShifted)<<endl;
	cout<<"nCleared|MShifted "<<toBinary(nCleared|MShifted)<<endl;
	cout<<"nCleared|MShifted "<<toDecimal(toBinary(nCleared|MShifted))<<endl;
	return nCleared|MShifted;
}


int main(){
	ll N=100'000'000'00, M=10011;
	int i=2, j=6;
	update(toDecimal(to_string(N)), toDecimal(to_string(M)), i, j);
}