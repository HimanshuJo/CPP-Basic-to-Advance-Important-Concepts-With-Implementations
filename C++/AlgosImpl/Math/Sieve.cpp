#include<iostream>
#include<vector>
#define N 100
using namespace std;

int main(){
	vector<bool>primes(N+1, true);
	primes[0]=false;
	for(int i=2; i*i<=N; ++i){
		if(primes[i]){
			for(int j=i*i; j<=N; j+=i){
				primes[j]=false;
			}	
		}
	}
	for(int i=0; i<=N; ++i){
		if(primes[i]){
			cout<<i<<" ";
		}
	}
}