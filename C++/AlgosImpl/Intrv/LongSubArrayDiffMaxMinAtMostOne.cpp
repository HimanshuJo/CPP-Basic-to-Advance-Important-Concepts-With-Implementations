// Longest subarray such that the difference of max and min is at-most one
/*
Given an array of n numbers where the difference between each number and the 
previous one doesn’t exceed one. Find the longest contiguous subarray such that the 
difference between the maximum and minimum number in the range doesn’t exceed one.

Examples: 

Input : {3, 3, 4, 4, 5, 6}
Output : 4
The longest subarray here is {3, 3, 4, 4}

Input : {7, 7, 7}
Output : 3
The longest subarray here is {7, 7, 7}

Input : {9, 8, 8, 9, 9, 10}
Output : 5
The longest subarray here is {9, 8, 8, 9, 9}
*/
/*
If the difference between the maximum and the minimum numbers in the sequence doesn't exceed one,
	then the sequence consisted of only one or two consecutive numbers.

	The idea is to traverse the array and keep track of the current element and the previous in the
		current sub-array.

	If we find an element which is not same as the current or previous, we will update the current and
		the previous.

	Update result if required
*/

#include<bits/stdc++.h>
using namespace std;

int longestSubArray(int input[], int length){
	int prev=-1;
	int curr, currNum;
	int prevCount=0, currCount=1;
	// longest constant range length
	int longest=1;
	// first number
	curr=input[0];
	for (int i=1; i<length; ++i){
		currNum=input[i];
		if (currNum==curr){
			currCount++;
		} 
		// if we see different number, but same as previous
		else if (currNum==prev){
			prevCount+=currCount;
			prev=curr;
			curr=currNum;
			currCount=1;
		}
		// if the number is neither same as previous nor as current
		else {
			longest=max(longest, currCount+prevCount);
			prev=curr;
			prevCount=currCount;
			curr=currNum;
			currCount=1;
		}
	}
	return max(longest, currCount+prevCount);
}

int main(){
	int input[]={5,5,6,7,6};
	int n=sizeof(input)/sizeof(int);
	cout<<longestSubArray(input, n);
	return 0;
}

/*
Time: O(n)
*/