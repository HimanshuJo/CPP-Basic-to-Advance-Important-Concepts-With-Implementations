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
Explanation: You need three jumps from index 0 --> 4 --> 3 --> 9. Note that index 9 is the last index of the array.

-------

First intuition to solve this problem would by dp

	e.g. for dp[i] -> to reach this state we have number of ways

			we can reach this state either via previous jump or the next jump

			Since we can move either backward or forward

				dp[i] = min(dp[i - 1], dp[i + 1], some other dp places where the value is same as our current 'i')

			Hence a dp solution won't work in this case
				One of the pre-conditions/pre-requisites for the dp problems is that,

					each of the current state should be independent

						the current state should never be affected by any of the future states

			However, for this problem the current state is dependent on previous as well as next and some other
				dp state where the value at both the indices are same

	-------

	Since we can jump from the current state to the previous and the next state and also to any of the state which
		has the same value as the current state, so this is kind of a graph problem

			from current i we can jump to:

				i - 1
				i + 1
				...
				all the k's where the value of k == s[i]

		And since we also have to find the minimum steps, so BFS will work here

			Basically the minimum distance from the index 0 to the index n - 1

				because from 0 to n- 1 there are bunch of ways to reach to n - 1
					and we just need to find the minimum one, and BFS guarantees the optimal path

------

How to build the graph

	for each of the number we will be creating a map, that stores for that particular number
		which are the indices that has the same value as the current index

		suppose we have an array like:

			7 7 7 7 7 7.......11

			The first time when we process 7 here, not only we'll be adding the values at i + 1, i - 1 but also
				all the indices that has the value 7

			once we have process all these 7's we will be removing all those 7's from the map
				so that next time when we see a 7 at let's say index 3, then
				even though we have a visited array to control our traverse so that we shouldn't be re-visiting a node again,
				we don't have to process anything at this index

-------
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

/*
Complexity

    Time & Space: O(N)

Explain Time O(N):

	In the case where each index has the same value, the algorithm goes to the neighbor (the same value)
		once then breaks all the edge by using:

			next.clear()

So the algorithm will traverse up to N edges for j and 2N edges for (i+1, i-1).

That's why time complexity is O(3N) ~ O(N)

-------

class Solution:
	def minJumps(self, arr: List[int]) -> int:
		n = len(arr)
		valueToIndices = defaultdict(list)
		#initially we will build the indices
		for i, num in enumerate(arr):
			valueToIndices[num].append(i)  #key is the number and the value is the indices
		queue = collections.deque([0])
		seen = set()
		seen.add(0)
		ans = 0
		while queue:
			for _ in range(len(queue)):
				node = queue.popleft()
				if node == n - 1:
					return ans
				next = []
				if node > 0:
					next.append(node - 1)
				if node < n - 1:
					next.append(node + 1)
				if arr[node] in valueToIndices:
					next.extend(valueToIndices[arr[node]])
					del valueToIndices[arr[node]]
				for neighbor in next:
					if neighbor not in seen:
						queue.append(neighbor)
						seen.add(neighbor)
			ans += 1

-------

import java.util.ArrayList;
import java.util.HashMap;
import java.util.HashSet;
import java.util.LinkedList;
import java.util.List;
import java.util.Set;

class Solution {
	public int minJumps(int[] arr) {
		int len = arr.length;
		HashMap<Integer, ArrayList<Integer>> valueToIndices = new HashMap<>();
		for (int i = 0; i < arr.length; ++i) {
			if (valueToIndices.containsKey(arr[i])) {
				valueToIndices.get(arr[i]).add(i);
			} else {
				valueToIndices.put(arr[i], new ArrayList<>());
				valueToIndices.get(arr[i]).add(i);
			}
		}
		LinkedList<Integer> queue = new LinkedList<Integer>();
		queue.add(0);
		Set<Integer> seen = new HashSet<>();
		seen.add(0);
		int ans = 0;
		while (!queue.isEmpty()) {
			int queueSize = queue.size();
			for (int i = 0; i < queueSize; ++i) {
				int node = queue.pop();
				if (node == len - 1) {
					return ans;
				}
				LinkedList<Integer> next = new LinkedList<>();
				if (node > 0) {
					next.add(node - 1);
				}
				if (node < len - 1) {
					next.add(node + 1);
				}
				if (valueToIndices.containsKey(arr[node])) {
					List<Integer> temp = valueToIndices.get(arr[node]);
					for (int num : temp) {
						next.addLast(num);
					}
					valueToIndices.remove(arr[node]);
				}
				for (int neighbor : next) {
					if (!seen.contains(neighbor)) {
						queue.add(neighbor);
						seen.add(neighbor);
					}
				}
			}
			ans++;
		}
		return ans;
	}
}
*/