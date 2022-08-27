// GCD Sort of an Array
/*
You are given an integer array nums, and you can perform the following operation any number of times on nums:

Swap the positions of two elements nums[i] and nums[j] if gcd(nums[i], nums[j]) > 1 where gcd(nums[i], nums[j]) is the 
greatest common divisor of nums[i] and nums[j].
Return true if it is possible to sort nums in non-decreasing order using the above swap method, or false otherwise.

Example 1:

Input: nums = [7,21,3]
Output: true
Explanation: We can sort [7,21,3] by performing the following operations:
- Swap 7 and 21 because gcd(7,21) = 7. nums = [21,7,3]
- Swap 21 and 3 because gcd(21,3) = 3. nums = [3,7,21]
*/
#include<bits/stdc++.h>
using namespace std;

/*
The idea is that we create a sorted version of nums, let say sortedArr.
Then we compare each element belong nums and sortedArr, check if we can swap nums[i] to become sortedArr[i].
If we can't swap nums[i] to become sortedArr[i] then return False
Otherwise, if we can swap all pairs nums[i], sortedArr[i] then return True.
To check if we can swap(nums[i], sortedArr[i]), we need Union-Find to group numbers the same factors together.
Use sieve with time complexity O(N) to calculate spf[x] array, where spf[x] is the smallest prime factor of number x, where x >= 2.
Then iterate each element num in nums:
Get factors of num in O(logNum) since we use spf[x]. Otherwise if we brute force to get factors, time complexity will be O(sqrt(Num)).
Union num and their factors together.
*/
class UnionFind {
    vector<int> parent;
public:
    UnionFind(int n) {
        parent.resize(n);
        for (int i = 0; i < n; i++) parent[i] = i;
    }
    int find(int x) {
        if (x == parent[x]) return x;
        return parent[x] = find(parent[x]); // Path compression
    }
    void Union(int u, int v) {
        int pu = find(u), pv = find(v);
        if (pu != pv) parent[pu] = pv;
    }
};
class Solution {
public:
    vector<int> spf; // spf[x] is the smallest prime factor of number x, where x >= 2
    bool gcdSort(vector<int>& nums) {
        int maxNum = *max_element(nums.begin(), nums.end());
        sieve(maxNum + 1);

        UnionFind uf(maxNum+1);
        for (int x : nums)
            for (int f : getPrimeFactors(x))
                uf.Union(x, f);

        vector<int> sortedArr(nums);
        sort(sortedArr.begin(), sortedArr.end());
        for (int i = 0; i < nums.size(); ++i)
            if (uf.find(nums[i]) != uf.find(sortedArr[i]))
                return false; // can't swap nums[i] with sortedArr[i]
        return true;
    }
    void sieve(int n) { // O(Nlog(logN)) ~ O(N)
        spf.resize(n);
        for (int i = 2; i < n; ++i) spf[i] = i;
        for (int i = 2; i * i < n; i++) {
            if (spf[i] != i) continue; // skip if `i` is not a prime number
            for (int j = i * i; j < n; j += i)
                if (spf[j] > i) spf[j] = i; // update to the smallest prime factor of j
        }
    }
    vector<int> getPrimeFactors(int n) { // O(logN)
        vector<int> factors;
        while (n > 1) {
            factors.push_back(spf[n]);
            n /= spf[n];
        }
        return factors;
    }
};