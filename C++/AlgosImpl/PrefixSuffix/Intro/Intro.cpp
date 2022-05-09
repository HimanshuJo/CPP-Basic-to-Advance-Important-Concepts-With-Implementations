#include<iostream>
#include<vector>
using namespace std;

int main(){
	vector<int>nums{1, 2, 3, 4, 5};
	int n=nums.size();
	vector<unsigned int>prefix_sum(n, 0);
	vector<unsigned int>suffix_sum(n, 0);
	prefix_sum[0] = nums[0];
	for (int i=1; i<n; i++) {
		prefix_sum[i]=prefix_sum[i - 1]+nums[i];
	}
	suffix_sum[n-1]=nums[n-1];
	for(int i=n-2; i>=0; --i){
		suffix_sum[i]=suffix_sum[i+1]+nums[i];
	}
	cout<<"prefix Sum\n";
	for(auto &vals: prefix_sum)
		cout<<vals<<" ";
	cout<<"\n-------\n";
	cout<<"suffix Sum\n";
	for(auto &vals: suffix_sum)
		cout<<vals<<" ";
	cout<<"\n-------\n";
}