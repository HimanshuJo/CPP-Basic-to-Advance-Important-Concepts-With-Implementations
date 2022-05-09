// 2064. Minimized Maximum of Products Distributed to Any Store
/*
You are given an integer n indicating there are n specialty retail stores. 
There are m product types of varying amounts, which are given as a 0-indexed integer 
array quantities, where quantities[i] represents the number of products of the ith product type.

You need to distribute all products to the retail stores following these rules:

A store can only be given at most one product type but can be given any amount of it.
After distribution, each store will have been given some number of products (possibly 0). 
Let x represent the maximum number of products given to any store. You want x to be as small 
as possible, i.e., you want to minimize the maximum number of products that are given to any store.

Return the minimum possible x.

Example 1:

Input: n = 6, quantities = [11,6]
Output: 3
Explanation: One optimal way is:
- The 11 products of type 0 are distributed to the first four stores in these amounts: 2, 3, 3, 3
- The 6 products of type 1 are distributed to the other two stores in these amounts: 3, 3
The maximum number of products given to any store is max(2, 3, 3, 3, 3, 3) = 3.
*/

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

class Solution {
public:

	int genVal(int n, vector<int>&quantities, int div) {
		int res = 0;
		for (int q : quantities) {
			res += q / div + (q % div);
		}
		return res;
	}

	int minimizedMaximum(int n, vector<int>& quantities) {
		int maxx = 0;
		for (int q : quantities) {
			maxx = max(maxx, q);
		}
		int left = 1, right = maxx;
		int ans = 0;
		while (left <= right) {
			int mid = left + (right - left) / 2;
			int val = genVal(n, quantities, mid);
			if (val > n) {
				left = mid + 1;
			} else right = mid - 1;
		}
		return left;
	}
};