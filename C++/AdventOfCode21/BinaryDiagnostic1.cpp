#include<algorithm>
#include<string>
#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;
#define D(e) cerr<<e<<endl
#define E(e) #e<<" = "<<(e)
#define COMMA <<", "

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int samples=0, length=0;
	string num;
	vector<int>bits(0, 0);
	while(samples!=12){
		cin>>num;
		D(E(num));
		int l=num.length();
		if(l>length){
			bits.resize(length=l);
		}
		reverse(begin(num), end(num));
		for(int i=0; i<l; ++i){
			if(num[i]&1){
				++bits[i];
			}
		}
		samples++;
	}
	D(E(samples));
	for(int i=0; i<length; ++i){
		D(E(bits[i]));
	}
	int threshold=(samples+1)/2;
	int gamma=0, epsilon=0;
	for(int i=0, bit=1; i<length; ++i, bit+=bit){
		if(bits[i]>=threshold){
			gamma|=bit;
		} else{
			epsilon|=bit;
		}
	}
	D(E(samples) COMMA E(length) COMMA E(epsilon) COMMA E(gamma));
	cout<<(long(epsilon)*gamma)<<endl;
	return EXIT_SUCCESS;
}
