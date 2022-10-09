/*
Bubble Sort Complexity
Time Complexity	 
Best	O(n)
Worst	O(n^2)
Average	O(n^2)
Space Complexity	O(1)
Stability	Yes
*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void bubbleSort(vector<int>&nums){
	bool swapped=true;
	int n=nums.size();
	while(swapped){
		swapped=false;
		for(int i=0; i<n-1; ++i){
			if(nums[i]>nums[i+1]){
				swap(nums[i], nums[i+1]);
				swapped=true;
			}
		}
	}
}

int main(){
	vector<int>nums{7,6,5,4,3,2,1};
	bubbleSort(nums);
	for(auto &vals: nums)
		cout<<vals<<" ";
}