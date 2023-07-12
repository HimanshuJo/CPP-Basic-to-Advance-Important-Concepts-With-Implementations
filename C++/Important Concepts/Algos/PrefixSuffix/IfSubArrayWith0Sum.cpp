/*
Given an array of positive and negative numbers, find if there is a subarray (of size at-least one) with 0 sum.

Examples :

    Input: {4, 2, -3, 1, 6}
    Output: true
    Explanation:
    There is a subarray with zero sum from index 1 to 3.

    Input: {4, 2, 0, 1, 6}
    Output: true
    Explanation:
    There is a subarray with zero sum from index 2 to 2.

    Input: {-3, 2, 3, 1, 6}
    Output: false
*/
/*
We can also use hashing.

The idea is to iterate through the array and for every element arr[i],
calculate the sum of elements from 0 to i (this can simply be done as sum += arr[i]).
If the current sum has been seen before, then there is a zero-sum array.
Hashing is used to store the sum values so that we can quickly store sum and
find out whether the current sum is seen before or not.

Example :

arr[] = {1, 4, -2, -2, 5, -4, 3}

If we consider all prefix sums, we can notice that there is a subarray with 0 sum when :
1) Either a prefix sum repeats or
2) Or prefix sum becomes 0.

Prefix sums for above array are:
1, 5, 3, 1, 6, 2, 5

Since prefix sum 1 repeats, we have a subarray with 0 sum.
*/

#include <bits/stdc++.h>
using namespace std;

int finalInd;

bool subArrayExists(int arr[], int n)
{
    unordered_set<int> sumSet;

    // Traverse through array
    // and store prefix sums
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];

        // If prefix sum is 0 or
        // it is already present
        if (sum == 0 || sumSet.find(sum) != sumSet.end()) {
            finalInd = i;
            return true;
        }

        sumSet.insert(sum);
    }
    return false;
}

int main()
{
    int arr[] = { -3, 2, -2, 3, 6 };
    int n = sizeof(arr) / sizeof(arr[0]);
    if (subArrayExists(arr, n)) {
        cout << "Found a subarray with 0 sum " << "ending at index: " << finalInd;;
    }
    else {
        cout << "No Such Sub Array Exists!";
    }
    return 0;
}

/*
Output:

Found a subarray with 0 sum ending at index: 2

-------

Time Complexity of this solution can be considered as O(n) under
the assumption that we have good hashing function that allows insertion
and retrieval operations in O(1) time.

Space Complexity: O(n) .Here we required extra space for unordered_set to insert array elements.
*/