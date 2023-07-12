/*
Given an array arr[] consisting of N positive integers, the task is to find the
prefix factorials of a prefix sum array of the given array i.e.,

prefix[i] = (\sum_{0}^{i}arr[i])!

Examples:

    Input: arr[] = {1, 2, 3, 4}
    Output: 1 6 720 3628800
    Explanation:
    The prefix sum of the given array is {1, 3, 6, 10}. Therefore, prefix factorials of the obtained prefix sum array is {1!, (1+2)!, (1+2+3)!, (1+2+3+4)!} = {1!, 3!, 6!, 10!} = {1 6 720 3628800}.

    Input: arr[] = {2, 4, 3, 1}
    Output: 2 720 362880 3628800

*/
/*
Precalculating the factorial of sum of the array elements so that the factorial
calculation at each index is can be calculated in O(1) time
*/

#include <bits/stdc++.h>
using namespace std;

// Function to find the factorial of
// prefix sum at every possible index
void prefixFactorialArray(int A[], int N)
{
    // Find the prefix sum array
    for (int i = 1; i < N; i++) {
        A[i] += A[i - 1];
    }

    // Stores the factorial of all the
    // element till the sum of array
    // based on prefix array largest num, and independent of array sorted or unsorted
    int fact[A[N - 1] + 1];
    fact[0] = 1;

    // Find the factorial array
    for (int i = 1; i <= A[N - 1]; i++) {
        fact[i] = i * fact[i - 1];
    }

    // Find the factorials of
    // each array element
    for (int i = 0; i < N; i++) {
        A[i] = fact[A[i]];
    }

    // Print the resultant array
    for (int i = 0; i < N; i++) {
        cout << A[i] << " ";
    }
}

int main()
{
    int arr[] = { 1, 2, 3, 4 };
    int N = sizeof(arr) / sizeof(arr[0]);
    prefixFactorialArray(arr, N);

    return 0;
}

/*
Output:

1 6 720 3628800

-------

Time Complexity: O(N + M), where M is the sum of the array elements.
Auxiliary Space: O(M), where M is the sum of the array elements.
*/