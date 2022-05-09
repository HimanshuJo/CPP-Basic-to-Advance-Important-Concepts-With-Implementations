/*
Given a set of prime numbers somewhere in between an array, 
find the first and the last prime number in that range.

E.g: arr=[1, 4, 6, 8, 2, 7, 13, 23, 44, 88]
	 Output: [2, 23]

	 Prime range=[2, 7, 13, 23]
	 First in the range: 2
	 Last in the range: 23
*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<bool>isPrime(101, true);

void genPrime(){
	isPrime[0]=false, isPrime[1]=false;
	for(int i=2; i*i<=100; ++i){
		if(isPrime[i]){
			for(int j=i*i; j<=100; j+=i){
				isPrime[j]=false;
			}
		}
	}
}

bool isValid(int val){
	if(isPrime[val]) return true;
	return false;
}

int main(){
	genPrime();
	vector<int>vec{1, 4, 6, 8, 2, 7, 13, 23, 44, 88};
	int l=0, r=vec.size()-1;
	int leftBound=0, leftBIdx=0;
	while(l<=r){
		int mid=l+(r-l)/2;
		if(isValid(vec[mid])){
			leftBound=vec[mid];
			leftBIdx=mid;
			r=mid-1;
		} else{
			l=mid+1;
		}
	}
	l=leftBIdx, r=vec.size()-1;
	int rightBound=r;
	while(l<=r){
		int mid=l+(r-l)/2;
		if(isValid(vec[mid])){
			rightBound=vec[mid];
			l=mid+1;
		} else{
			r=mid-1;
		}
	}
	cout<<leftBound<<" "<<rightBound;
}