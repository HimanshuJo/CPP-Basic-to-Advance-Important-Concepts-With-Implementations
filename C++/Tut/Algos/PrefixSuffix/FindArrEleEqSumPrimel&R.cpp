/*
Given an array arr[] of size N, the task is to find the index in the given array where
the sum of the prime numbers present to its left is equal to the sum of the
prime numbers present to its right.

Examples:

    Input: arr[] = {11, 4, 7, 6, 13, 1, 5}
    Output: 3
    Explanation: Sum of prime numbers to left of index 3 = 11 + 7 = 18
    Sum of prime numbers to right of index 3 = 13 + 5 = 18

    Input: arr[] = {5, 2, 1, 7}
    Output: 2
    Explanation: Sum of prime numbers to left of index 2 = 5 + 2 = 7
    Sum of prime numbers to right of index 2 = 7
*/
/*
Efficient Approach:

    The above approach can also be optimized using the Sieve of Eratosthenes and
    prefix sum technique to pre-store the sum of prime numbers left and right to an array element.

    Follow the steps below to solve the problem:

        Traverse through the array to find the maximum value present in the array.

        Use Sieve of Eratosthenes to find out the prime numbers which are less than or
        equal to the maximum value present in the array.

            Store these elements in a Map.

        Initialize an array, say first_array.
            Traverse the array and store the sum of all prime numbers up to i'th index at first_array[i].

        Initialize an array, say second_array. Traverse the array in reverse and store the 
        sum of all elements up to ith index at second_array[i].

        Traverse the arrays first_array and second_array and check if at any index, both their values are equal or not.
            If found to be true, return that index.
*/

#include <bits/stdc++.h>
using namespace std;

// Function to find an index in the
// array having sum of prime numbers
// to its left and right equal
int find_index(int arr[], int N)
{
    // Stores the maximum value
    // present in the array
    int max_value = INT_MIN;

    for (int i = 0; i < N; i++) {
        max_value = max(max_value, arr[i]);
    }

    // Stores all positive
    // elements which are <= max_value
    map<int, int> store;

    for (int i = 1; i <= max_value; i++) {
        store[i]++;
    }

    // If 1 is present
    if (store.find(1) != store.end()) {

        // Remove 1
        store.erase(1);
    }

    // Sieve of Eratosthenes to
    // store all prime numbers which
    // are <= max_value in the Map
    for (int i = 2; i <= sqrt(max_value); i++) {

        int multiple = 2;

        // Erase non-prime numbers
        while ((i * multiple) <= max_value) {

            if (store.find(i * multiple) != store.end()) {
                store.erase(i * multiple);
            }

            multiple++;
        }
    }

    // Stores the sum of
    // prime numbers from left
    int prime_sum_from_left = 0;

    // Stores the sum of prime numbers
    // to the left of each index
    int first_array[N];

    for (int i = 0; i < N; i++) {

        // Stores the sum of prime numbers
        // to the left of the current index
        first_array[i] = prime_sum_from_left;

        if (store.find(arr[i]) != store.end()) {

            // Add current value to
            // the prime sum if the
            // current value is prime
            prime_sum_from_left += arr[i];
        }
    }

    // Stores the sum of
    // prime numbers from right
    int prime_sum_from_right = 0;

    // Stores the sum of prime numbers
    // to the right of each index
    int second_array[N];

    for (int i = N - 1; i >= 0; i--) {

        // Stores the sum of prime
        // numbers to the right of
        // the current index
        second_array[i] = prime_sum_from_right;

        if (store.find(arr[i]) != store.end()) {

            // Add current value to the
            // prime sum if the
            // current value is prime
            prime_sum_from_right += arr[i];
        }
    }

    // Traverse through the two
    // arrays to find the index
    for (int i = 0; i < N; i++) {

        // Compare the values present
        // at the current index
        if (first_array[i] == second_array[i]) {

            // Return the index where
            // both the values are same
            return i;
        }
    }

    // No index is found.
    return -1;
}

int main()
{
    int arr[] = { 11, 4, 7, 6, 13, 1, 5 };
    int N = sizeof(arr) / sizeof(arr[0]);
    cout << find_index(arr, N);
    return 0;
}

/*
Output:

3

Time Complexity: O(N + max(arr[])loglog(max(arr[]))
Auxiliary Space: O(max(arr[]) + N)
*/