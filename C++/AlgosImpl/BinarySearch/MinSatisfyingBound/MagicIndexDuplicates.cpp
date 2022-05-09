#include<vector>
#include<iostream>
using namespace std;

int magicFind(vector<int>&arr, int left, int right){
	if(left>right) return -1;
	int mid=left+(right-left)/2;
	int midVal=arr[mid];
	if(midVal==mid) return mid;
	int leftIndx=min(mid-1, midVal);
	int leftVal=magicFind(arr, left, leftIndx);
	if(leftVal>=0) return leftVal;
	int rightIndx=max(mid+1, midVal);
	int rightVal=magicFind(arr, rightIndx, right);
	return rightVal;
}

int magicFind(vector<int>&arr){
	return magicFind(arr, 0, arr.size()-1);
}

int main(){
	vector<int>arr{10, -5, 2, 2, 2, 3, 4, 5, 9, 12, 13};
	cout<<magicFind(arr);
}
