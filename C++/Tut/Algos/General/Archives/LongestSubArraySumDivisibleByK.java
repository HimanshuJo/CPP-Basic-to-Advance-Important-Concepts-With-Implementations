/*
Given an arr[] containing n integers and a positive integer k

	The problem is to find the length of the longest subarray with sum of the elements
		divisible by the given value k

	E.g.

		Input: arr [] = {2, 7, 6, 1, 4, 5}

			   K = 3;

	    Output: 4

	    	The subarray is {7, 6, 1, 4} with sum 18
	    		which is divisible by 3

	-------

	Naive Approach:

		Consider all the subarrays and return the length of the sub-array with sum
			divisible by k and has the longest length

	Time Complexity:

		O(n^2)

	-------

	Efficient Approach:

		Create an array mod_arr[] where

			mod_arr[i] stores (sum(arr[0] + arr[1] + .... arr[i]) % k)

		Create a hash table having tuples as (ele, idx) where

			ele represents an element of mod_arr[]

			and idx represents the element's index of first occurrence in mod_arr[]

			Now we traverse mod_arr[] from i = 0 to n
				and follow the steps given below:

					1. If mod_arr[i] == 0 then update maxLen = (i + 1)

					2. else if mod_arr[i] is not present in the hash table

							create tuple (mod_arr[i], i) in the hash table

					3. else get the value associated with mod_arr[i] in the hash table

							let this be idx

					4. if maxLen < (i - idx) then update maxLen = (i - idx)

		Return maxLen
*/

import java.util.*;
import java.io.*;

class CFG {

	static int longSubarrayWithSumDivByK(int arr[], int n, int k) {

		HashMap<Integer, Integer> map = new HashMap<>();

		int mod_arr[] = new int[n];
		int max = 0;
		int curr_sum = 0;

		//traversing arr[] and building the array 'mod_arr[]'
		for (int i = 0; i < n; ++i) {
			curr_sum += arr[i];
			//as the sum can be negative, therefore taking modulo twice
			mod_arr[i] = ((curr_sum % k) + k) % k;
		}

		for (int i = 0; i < n; ++i) {

			//if true then sum(0..i) is divisible by k
			if (mod_arr[i] == 0)
				max = i + 1;

			//if value mod_arr[i] is not present in the map
			//then we can store it in the map with index of its first occurrence
			else if (map.containsKey(mod_arr[i]) == false)
				map.put(mod_arr[i], i);

			else
				//if true then update max
				// Based on the idea that, if at any index of mod_arr[]
				//first getting the index of that element and then
				//getting it's value from the map (which, if the number is divisible by x will be 0)
				//will always result in i getting bigger than map.get(mod_arr[i])
				//so in that case we have to update the value
				if (max < (i - map.get(mod_arr[i])))
					max = i - map.get(mod_arr[i]);
		}

		return max;
	}
}