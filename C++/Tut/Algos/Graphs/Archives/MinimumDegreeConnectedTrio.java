/*
You are given an undirected graph.

You are given an integer n which is the number of nodes in the graph and an array edges,
	where each edges[i] = [ui, vi] indicates that there is an undirected edge between ui and vi.

A connected trio is a set of three nodes where there is an edge between every pair of them.

The degree of a connected trio is the number of edges where one endpoint is in the trio, and the other is not.

Return the minimum degree of a connected trio in the graph, or -1 if the graph has no connected trios.

-------

Intuition:

	Straight Forward

		At the beginning we will just create a graph (not directed)

		For each of the node we will try to find the trio that includes the current node

			We can utilize a nested for loop here

			-------

			For each of the node, we will try all the possible neighbors
				e.g. a node say 1 can be connected to 4, 3, and 2

				so here we have to try all the combinations of these neighbors

				we have to form a trio, therefore if node 1 is n1
					then basically we will try to find all the combinations of
					node2 (n2) and node3 (n3) among n1's neighbors

				For each of the combinations, we will check
					if n2 is the neighbor of n3

-------

class Solution:
	def minTrioDegree(self, n: int, edges: List[List[int]]) -> int:
		graph = defaultdict(set)
		degree = defaultdict(int)
		for u, v in edges:
			graph[min(u, v)].add(max(u, v))
			degree[u] += 1
			degree[v] += 1
		ans = sys.maxsize
		for n1 in range(1, n + 1):
			# for each of the node, we will be enumerating all the combinations of the neighbors
			for n2 in graph[n1]:
				for n3 in graph[n1]:
					if n3 in graph[n2]:
						ans = min(ans, degree[n1] + degree[n2] + degree[n3] - 6)
		return ans if ans < sys.maxsize else -1

*/

public class Solution {
	public int minTrioDegree(int n, int[][] edges) {
		int min = Integer.MAX_VALUE;
		Map<Integer, Integer> degrees = new HashMap<>();
		boolean[][] isEdge = new boolean[n + 1][n + 1];
		for (int[] edge : edges) {
			degrees.put(edge[0], degrees.getOrDefault(edge[0], 0) + 1);
			degrees.put(edge[1], degrees.getOrDefault(edge[1], 0) + 1);
			isEdge[edge[0]][edge[1]] = true;
			isEdge[edge[1]][edge[0]] = true;
		}
		for (int[] edge : edges) {
			for (int i = 1; i <= n; ++i) {
				if (isEdge[i][edge[0]] && isEdge[i][edge[1]]) {
					// here we have to subtract 6 because we don't want to count the inner edges of a trio
					int degree = degrees.get(i) + degrees.get(edge[0]) + degrees.get(edge[1]) - 6;
					min = Math.min(min, degree);
				}
			}
		}
		if (min == Integer.MAX_VALUE) {
			return -1;
		} return min;
	}
}