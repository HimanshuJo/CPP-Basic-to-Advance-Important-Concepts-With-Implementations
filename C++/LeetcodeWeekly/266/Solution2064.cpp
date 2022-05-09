#include<bits/stdc++.h>
using namespace std;

class Solution {
	public:
		int BinarySearch(int left, int right, vector<int>&quantities, const int n){
			if(left>=right) return left;
			int mid=left+(right-left)/2;
			int sum=0;
			for(auto &vals: quantities)
				sum+=(vals+mid-1)/mid;
			if(sum>n) BinarySearch(mid+1, right, quantities, n);
			else BinarySearch(left, mid, quantities, n);
			return left;
		}

		int minimizedMaximum(int n, vector<int>& quantities) {
			int left=1, right=1e5;
			left=BinarySearch(left, right, quantities, n);
			return left;
		}	
};

int main(){
	Solution obj;
	vector<int>quantities{15,10,10};
	obj.minimizedMaximum(7, quantities);
}
