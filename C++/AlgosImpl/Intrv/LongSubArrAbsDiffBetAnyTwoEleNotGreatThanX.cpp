// Longest subarray in which absolute difference between any two element 
// is not greater than X

/*
Given an integer array arr[] of size N and an integer X, the task is to find 
the longest sub-array where the absolute difference between any two elements 
is not greater than X.

Examples: 

Input: arr = { 8, 4, 2, 6, 7 }, X = 4 
Output: 4 2 6 
Explanation: 
The sub-array described by indexes [1, 3], i.e, { 4, 2, 6 } contains 
no such difference of two elements which is greater than 4.

Input: arr = { 15, 10, 1, 2, 4, 7, 2}, X = 5 
Output: 2 4 7 2 
Explanation: 
The sub-array described by indexes [3, 6], i.e, { 2, 4, 7, 2 } contains 
no such difference of two elements which is greater than 5. 
*/

/*
Naive Approach:

    Simple solution is to consider all subarrays one by one find the maximum and
        the minimum element of that subarray and check if their difference is
        not greater than X.

    Among all such sub-arrays print the longest sub-array

Time: O(n^3)
*/

/*
Efficient Approach:

    The idea is to use the 'Sliding Window Technique' to consider a sub-array
        and use a 'HashMap data structure' to find the maximum and minimum
        element in that sub-array

    At first the 'Start' and 'End' of the window points to the 0-th index

    At every iteration, the element at the 'End' is inserted in the Map if
        not already present or otherwise its count is incremented

    If the difference between the maximum and minimum element is not greater
        than X, then update the maximum length of the required sub-array
        and store the beginning of that sub-array in a variable

    Otherwise, increment the 'Start' of the window until the difference between
        the maximum and the minimum element is not greater than X

    When incrementing the 'Start', the size of the window decreases, remove the
        element at the 'Start' from the Map if and only if the count of that
        element becomes zero
*/

#include<bits/stdc++.h>
using namespace std;

void longestSubArray(int* A, int N, int X){
    // Initialize a variable to store length of the longest sub-array
    int maxLen=0;
    
    // Initialize a variable to store the beginning of the longest sub-array
    int begin=0;

    // Initialize a map to store the maximum and the minimum elements for
    // a given window
    map<int, int>window;

    // initialize the window
    int start=0, end=0;

    for (; end<N; ++end){
        // Incrementing the count of that element in the window
        window[A[end]]++;

        // Find the maximum and minimum element in the current window
        auto minimum=window.begin()->first;
        auto maximum=window.rbegin()->first;
        if (maximum-minimum<=X){
            // update the length of the longest sub-array and store the beginning
            // of the sub-array
            if (maxLen<end-start+1){
                maxLen=end-start+1;
                begin=start;
            }
        } else {
            while (start<end){
                // Removing the element at the start
                window[A[start]]--;
                // Remove the element from the window if its count is zero
                if (window[A[start]]==0){
                    window.erase(window.find(A[start]));
                }
                // Incrementing the start of the window
                start++;
                // Finding the maximum and the minimum element in the current
                // window
                auto minimum=window.begin()->first;
                auto maximum=window.rbegin()->first;
                // Stop decreasing the size of the window when the difference
                // is not greater
                if (maximum-minimum<=X){
                    break;
                }
            }
        }
    }
    for (int i=begin; i<begin+maxLen; ++i){
        cout<<A[i]<<" ";
    }
}

int main(){
    int arr[]={15,10,1,2,4,7,2}, X=5;
    int n=sizeof(arr)/sizeof(arr[0]);
    longestSubArray(arr, n, X);
    return 0;
}

/*
Time Complexity: O(N * log(N))
*/