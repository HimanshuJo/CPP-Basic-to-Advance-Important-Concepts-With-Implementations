// Longest Common Subpath

/*
There is a country of n cities numbered from 0 to n - 1. In this country, there is a road connecting every pair of cities.

There are m friends numbered from 0 to m - 1 who are traveling through the country. 
Each one of them will take a path consisting of some cities. 
Each path is represented by an integer array that contains the visited cities in order. 
The path may contain a city more than once, but the same city will not be listed consecutively.

Given an integer n and a 2D integer array paths where paths[i] is an integer array representing 
the path of the ith friend, return the length of the longest common subpath that is shared by every 
friend's path, or 0 if there is no common subpath at all.

A subpath of a path is a contiguous sequence of cities within that path.

Example 1:

Input: n = 5, paths = [[0,1,2,3,4],
                       [2,3,4],
                       [4,0,1,2,3]]
Output: 2
Explanation: The longest common subpath is [2,3].

'''
'''

Firstly for performing Binary Search we have to set up our left and the right boundary
	left boundary is: 0 for all the paths and right is min length among all the paths

Rolling Hash:

	For each of the array we'll be storing all the rolling hash with length middle in a set (for each list independent sets)

	Let say we've two sets, setA and setB, then we just need to find the intersection between these two sets

	The resultant intersection will be used for the intersection with the next set let's say setC

	Finally we check if there is anything in our intersection set

	-------

	For Rolling Hash, base should always be 
		as big as the max number in the constraint

		second we always want to choose a prime number
*/

/*
Time:

	For the helper:
		since the total number of paths 10^5, inner for loop runs O(n)

		outer for loop, for each run, we have an intersect (in Python that is min(hashSet1, hashSet2))

			inner loops runs parallel, so the time is still in the range of O(n)

	BS: log n

*/

/*
The idea is that, if we can find a subpath with length k, we can find a subpath 
with any length less than k

So, we can use a binary search to search for the maximum subpath length. 
To do that in O(n) for each string, we use a rolling hash approach. 
Collisions are possible, therefore we need to check the actual paths. 

In the solution below, we just pick hashing parameters to avoid collisions.
 Note that it may not work if new test cases are added afterwards
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    const long long p = 1299827;
    const long long mod = 1e11 + 7;
    long long n, m;

    bool check(vector<vector<int>> &paths, int len)
    {
        if (len == 0)
        {
            return true;
        }
        map<long long, int> freq;
        for (int i = 0; i < m; ++i)
        {
            long long currHash = 0, pow = 1;
            set<long long> foundHashes;
            for (int j = 0; j < len; ++j)
            {
                currHash = (currHash * p) % mod;
                currHash += paths[i][j];
                if (j != len - 1)
                    pow = (pow * p) % mod;
            }
            foundHashes.insert(currHash);
            for (int j = len; j < paths[i].size(); ++j)
            {
                currHash += mod;
                currHash -= (paths[i][j - len] * pow) % mod;
                currHash %= mod;
                currHash = currHash * p;
                currHash %= mod;
                currHash += paths[i][j];
                currHash %= mod;
                foundHashes.insert(currHash);
            }
            while (foundHashes.size())
            {
                long long h = *(foundHashes.begin());
                foundHashes.erase(foundHashes.begin());
                freq[h]++;
                if (freq[h] == m)
                {
                    return true;
                }
            }
        }
        return false;
    }

    int longestCommonSubpath(int elements, vector<vector<int>> &paths)
    {
        n = elements;
        m = paths.size();
        int minLen = INT_MAX;
        for (int i = 0; i < paths.size(); ++i)
        {
            minLen = min(minLen, (int)paths[i].size());
        }
        int start = 0, end = minLen, mid = 0;
        while (start <= end)
        {
            int mid = start + (end - start) / 2;
            if (check(paths, mid))
            {
                start = mid + 1;
            }
            else
            {
                end = mid - 1;
            }
        }
        return end;
    }
};