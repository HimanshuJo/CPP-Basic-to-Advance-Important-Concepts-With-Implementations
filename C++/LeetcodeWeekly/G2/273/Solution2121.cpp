// 2121. Intervals Between Identical Elements
/*
You are given a 0-indexed array of n integers arr.

The interval between two elements in arr is defined as the absolute difference between their indices. 
More formally, the interval between arr[i] and arr[j] is |i - j|.

Return an array intervals of length n where intervals[i] is the sum of intervals between arr[i] and each 
element in arr with the same value as arr[i].

Note: |x| is the absolute value of x.

Example 1:

Input: arr = [2,1,3,1,2,3,3]
Output: [4,2,7,2,4,4,5]
Explanation:
- Index 0: Another 2 is found at index 4. |0 - 4| = 4
- Index 1: Another 1 is found at index 3. |1 - 3| = 2
- Index 2: Two more 3s are found at indices 5 and 6. |2 - 5| + |2 - 6| = 7
- Index 3: Another 1 is found at index 1. |3 - 1| = 2
- Index 4: Another 2 is found at index 0. |4 - 0| = 4
- Index 5: Two more 3s are found at indices 2 and 6. |5 - 2| + |5 - 6| = 4
- Index 6: Two more 3s are found at indices 2 and 5. |6 - 2| + |6 - 5| = 5
Example 2:

Input: arr = [10,5,10,10]
Output: [5,0,3,4]
Explanation:
- Index 0: Two more 10s are found at indices 2 and 3. |0 - 2| + |0 - 3| = 5
- Index 1: There is only one 5 in the array, so its sum of intervals to identical elements is 0.
- Index 2: Two more 10s are found at indices 0 and 3. |2 - 0| + |2 - 3| = 3
- Index 3: Two more 10s are found at indices 0 and 2. |3 - 0| + |3 - 2| = 4
 

Constraints:

n == arr.length
1 <= n <= 10^5
1 <= arr[i] <= 10^5
*/

/*
Approach 2:

Consider 1's at different postions of an array. 
x  y  z   p   q
1  1  1   1   1

consider 1 at index z: |z - x| + |z - y| + |z - p| + |z - q|

when we are looping from left to right we are storing sum and count of previous indices of num in maps.

|z - x| + |z - y| = z - x + z - y, since z is greater than x and y.

z - x + z - y = 2z - (x + y) = (count) * (currentIndex) - (sum).

Similarly we can calculate the |z - p| + |z - q| when we loop from right to left.

class Solution {
    public long[] getDistances(int[] arr) {
        long[] output = new long[arr.length];
        Map<Integer, Long> sumMap = new HashMap<>();
        Map<Integer, Integer> countMap = new HashMap<>();
        for (int i = 0; i < arr.length; ++i) {
            if (!sumMap.containsKey(arr[i])) {
                sumMap.put(arr[i], 0l);
                countMap.put(arr[i], 0);
            }
            
            output[i] += i * (long) countMap.get(arr[i]) - sumMap.get(arr[i]);
            sumMap.put(arr[i], sumMap.get(arr[i]) + i);
            countMap.put(arr[i], countMap.get(arr[i]) + 1);
        }
        
        sumMap = new HashMap<>();
        countMap = new HashMap<>();
        int len = arr.length;
        for (int i = len - 1; i >= 0; --i) {
            if (!sumMap.containsKey(arr[i])) {
                sumMap.put(arr[i], 0l);
                countMap.put(arr[i], 0);
            }
            
            output[i] += (len - i - 1) * (long) countMap.get(arr[i]) - sumMap.get(arr[i]);
            sumMap.put(arr[i], sumMap.get(arr[i]) + (len - i - 1));
            countMap.put(arr[i], countMap.get(arr[i]) + 1);
        }
        
        return output;
    }
}
*/

using ll=long long;

class Solution {
public:
    vector<long long> getDistances(vector<int>& arr) {
        int sz=arr.size();
        unordered_map<int, vector<int>>mp;
        vector<ll>pref(sz, 0), suff(sz, 0);
        for(int i=0; i<sz; ++i){
            mp[arr[i]].push_back(i);
        }
        for(auto &entries: mp){
            vector<int>idxs=entries.second;
            int cursz=idxs.size();
            for(int i=1; i<cursz; ++i){
                pref[idxs[i]]=pref[idxs[i-1]]+i*(ll)(idxs[i]-idxs[i-1]);
            }
        }
        for(auto &entries: mp){
            vector<int>idxs=entries.second;
            int cursz=idxs.size();
            for(int i=cursz-2; i>=0; --i){
                suff[idxs[i]]=suff[idxs[i+1]]+(cursz-1-i)*(ll)(idxs[i+1]-idxs[i]);
            }
        }
        vector<ll>ans(sz);
        for(int i=0; i<sz; ++i)
            ans[i]=pref[i]+suff[i];
        return ans;
    }
};