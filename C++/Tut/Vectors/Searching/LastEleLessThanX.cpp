#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

int lastEleLessThanKey(vector<int>&in, int key){
	int ans=-1;
	auto iter=upper_bound(in.rbegin(), in.rend(), key, greater<int>());
	if(iter==in.rend()) return ans;
	else ans=*iter;
	return ans;
}

int main(){
	vector<int>in{1, 2, 3, 4, 5, 6, 7};
	int key=1;
	int ans=lastEleLessThanKey(in, key);
	cout<<ans;
}
