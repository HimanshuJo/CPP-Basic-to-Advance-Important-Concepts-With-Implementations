// 1982. Find Array Given Subset Sums
/*
You are given an integer n representing the length of an unknown array that you are trying to recover.
You are also given an array sums containing the values of all 2n subset sums of the unknown array
(in no particular order).

Return the array ans of length n representing the unknown array. If multiple answers exist, return any of them.

An array sub is a subset of an array arr if sub can be obtained from arr by deleting some
(possibly zero or all) elements of arr. The sum of the elements in sub is one possible subset sum of arr.
The sum of an empty array is considered to be 0.

Note: Test cases are generated such that there will always be at least one correct answer.

Example 1:

Input: n = 3, sums = [-3,-2,-1,0,0,1,2,3]
Output: [1,2,-3]
Explanation: [1,2,-3] is able to achieve the given subset sums:
- []: sum is 0
- [1]: sum is 1
- [2]: sum is 2
- [1,2]: sum is 3
- [-3]: sum is -3
- [1,-3]: sum is -2
- [2,-3]: sum is -1
- [1,2,-3]: sum is 0
Note that any permutation of [1,2,-3] and also any permutation of [-1,-2,3] will also be accepted.

Constraints:

1 <= n <= 15
sums.length == 2^n
-10^4 <= sums[i] <= 10^4
*/

/*

Solution 1.
Intuition: If all the numbers in the unknown array are non-negative, it's easy to solve because A[0]
must be 0 (empty set) and A[1] must be a number in the unknown array.

Hint:

Step 1: Solve the problem knowning that the unknown array only has non-negative numbers.
Step 2: Find a subset in the answer array whose sum is the minimal value in A, and turn all the numbers
in this subset negative

Algorithm:

Let mn be the minimal number in A. We offset all the numbers in A by -mn, making all the numbers in A non-negative.

Step 1:

We store all the numbers in a multiset<int> s.

Now we can repeat the following process to get the unknown array:

Take the 2nd smallest element (say num) as a number in the answer ans.

Keep moving the first element (say first) from s to a new multiset<int> tmp, and removing first + num from s,
until s becomes empty.

Now tmp contains all the subset sums that are formed with the rest of the unknown numbers. This tmp becomes the new s.

We repeat this process n times to fill n numbers into ans.

Now we get an array ans corresponding to the unknown array of the original A with offset -mn.

Step 2:

We know that mn is the sum of all the negative numbers, so now our goal is to find a subset in ans
whose sum is -mn. And then we just need to make all the numbers in the subset negative.
We can solve this using a backtracking DFS.

Complexity Analysis

O(2^N) time for getting the minimal numbers in A and offsetting every number in A by -mn.

Initiallizing multiset<int> s takes O(2^N * log(2^N)) = O(2^N * N) time, and O(2^N) space.

Within the for loop, we at most go through 2^N elements in s and take O(log(2^N)) = O(N)
time to move/remove an element from the multiset. So each round takes O(2^N * N) times.

Since we need to repeat N times, the overall time complexity is O(2^N * N^2).

The step 2 takes O(2^N) time and O(N) space, because we have N numbers and each of which has
two options, inverting or not.

So, overall this algorithm has time complexity O(2^N * N^2) and space complexity O(2^N).
*/

class Solution {
    bool dfs(vector<int> &ans, int target, int i) {
        if (i == ans.size()) return target == 0;
        int n = ans[i];
        if (dfs(ans, target, i + 1)) return true; // if we don't invert this number
        ans[i] = -n;
        if (dfs(ans, target - n, i + 1)) return true; // if we invert this number
        ans[i] = n;
        return false;
    }

public:

    vector<int> recoverArray(int n, vector<int>& A) {
        int mn = *min_element(begin(A), end(A)); // `mn` must be the sum of all the negative numbers in `A`.
        for (int &n : A) n += -mn; // offset all the numbers by -mn, so that all the numbers in `A` are non-negative.
        multiset<int> s(begin(A), end(A)), tmp;
        vector<int> ans;
        for (int i = 0; i < n; ++i) {
            tmp.clear();
            int num = *next(s.begin()); // the 2nd number in the sorted subset sums must be a number in the answer
            ans.push_back(num);
            while (s.size()) {
                int first = *s.begin(); // `first` is a subset sum without `num`. We leave it for the next round.
                tmp.insert(first);
                s.erase(s.begin());
                s.erase(s.find(first + num)); // `first + num` is a subset sum with `num` which should be ignored going forward.
            }
            swap(s, tmp);
        }
        dfs(ans, -mn, 0); // Find a subset in `ans` whose sum is `-mn`. Invert all the numbers in this subset.
        return ans;
    }
};
