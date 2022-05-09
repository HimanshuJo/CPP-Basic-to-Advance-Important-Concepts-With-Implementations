#include<iostream>
#include<vector>
using namespace std;
using ll=long long;

bool isValid(int val, int a, int b){
	ll sum=a+b;
	ll currVal=val;
	currVal*=4;
	if(currVal>sum){
        return false;
    }
	int minVal=min(a, b);
	if(minVal<val){
        return false;
    }
	return true;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin>>t;
	while(t--){
		int a, b;
		cin>>a>>b;
		int ans=0;
		int left=1, right=1e9;
		while(left<right){
			int mid=left+(right-left)/2;
			if(isValid(mid, a, b)){
				left=mid+1;
			} else{
				right=mid;
			}
		}
		cout<<(left-1)<<"\n";
	}
}

