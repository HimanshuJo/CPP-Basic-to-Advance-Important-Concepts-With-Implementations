/*
Given an array of integers arr, you are initially positioned at the first index of the array.

In one step you can jump from index i to index:

    i + 1 where: i + 1 < arr.length.
    i - 1 where: i - 1 >= 0.
    j where: arr[i] == arr[j] and i != j.

Return the minimum number of steps to reach the last index of the array.

Notice that you can not jump outside of the array at any time.

Example 1:

Input: arr = [100,-23,-23,404,100,23,23,23,3,404]
Output: 3
Explanation: You need three jumps from index 0 --> 4 --> 3 --> 9.
Note that index 9 is the last index of the array.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minJumps(vector<int> &arr)
    {
        int n = arr.size();
        unordered_map<int, vector<int>> indicesOfValue;
        for (int i = 0; i < n; i++)
            indicesOfValue[arr[i]].push_back(i);
        vector<bool> visited(n);
        visited[0] = true;
        queue<int> q;
        q.push(0);
        int step = 0;
        while (!q.empty())
        {
            for (int size = q.size(); size > 0; --size)
            {
                int i = q.front();
                q.pop();
                if (i == n - 1) {
                    cout << step;
                    return step;
                }
                vector<int> &next = indicesOfValue[arr[i]];
                next.push_back(i - 1);
                next.push_back(i + 1);
                for (int j : next)
                {
                    if (j >= 0 && j < n && !visited[j])
                    {
                        visited[j] = true;
                        q.push(j);
                    }
                }
                next.clear(); // avoid later lookup indicesOfValue arr[i]
            }
            step++;
        }
        return 0;
    }
};

int main()
{
    Solution obj;
    vector<int> arr = {100, -23, -23, 404, 100, 23, 23, 23, 3, 404};
    obj.minJumps(arr);
}