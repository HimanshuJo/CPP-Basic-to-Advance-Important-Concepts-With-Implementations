// 1938. Maximum Genetic Difference Query
/*
There is a rooted tree consisting of n nodes numbered 0 to n - 1. Each node's number denotes its unique genetic value
(i.e. the genetic value of node x is x). The genetic difference between two genetic values is defined as
the bitwise-XOR of their values.

You are given the integer array parents, where parents[i] is the parent for node i. If node x is the root
of the tree, then parents[x] == -1.

You are also given the array queries where queries[i] = [nodei, vali].
For each query i, find the maximum genetic difference between vali and pi,
where pi is the genetic value of any node that is on the path between nodei and the root (including nodei and the root).
More formally, you want to maximize vali XOR pi.

Return an array ans where ans[i] is the answer to the ith query.

Input: parents = [3,7,-1,2,0,7,0,2], queries = [[4,6],[1,15],[0,5]]
Output: [6,14,7]
Explanation: The queries are processed as follows:
- [4,6]: The node with the maximum genetic difference is 0, with a difference of 6 XOR 0 = 6.
- [1,15]: The node with the maximum genetic difference is 1, with a difference of 15 XOR 1 = 14.
- [0,5]: The node with the maximum genetic difference is 2, with a difference of 5 XOR 2 = 7.

Constraints:

    2 <= parents.length <= 10^5
    0 <= parents[i] <= parents.length - 1 for every node i that is not the root.
    parents[root] == -1
    1 <= queries.length <= 3 * 10^4
    0 <= nodei <= parents.length - 1
    0 <= vali <= 2 * 10^5
*/

/*
DFS from root to its children, so we can have the path from root down to current node.
Build Binary Trie, so we can get the maximum XOR result between a value val and a number
in our Trie in O(1), our Trie will keep all elements in the path from root down to the current node.
When visit the node, we add it into our Trie.
After finishing visit the node, we remove it from our Trie.

-------

How to get the maximum XOR result between a value val and a number in our Trie in O(1)

    Our Trie will store numbers in form of their 18 bit presentation, store the most significant bit near the root.

    Why store 18 bits? Because 17th bit (zero-based indexing) is 2^17=131072 can present the maximum number which is 10^5.

    Since in XOR operator, 2 bit is different will result bit 1, that is 1^0=1, 0^1=1, otherwise will be 0.

    * Traversing trie from root to one of the path to any of the leaf will result in one of the valid sequence

        To find the maximum XOR of a value val with numbers in our Trie, we traverse 18 bits of val with the most significant bit first.
        If the current bit of val is 1, we check if exist a number with bit 0 in the Trie, if exist then the bit result is 1.
        If the current bit of val is 0, we check if exist a number with bit 1 in the Trie, if exist then the bit result is 1.
        Else the bit result is 0.

*/

#include<bits/stdc++.h>
using namespace std;

struct TrieNode
{
    TrieNode *child[2] = {};
    int go = 0; // Number of elements goes through this node

    void increase(int number, int d)
    {
        TrieNode *cur = this;
        for (int i = 17; i >= 0; --i)
        {
            int bit = (number >> i) & 1;
            if (cur->child[bit] == nullptr)
                cur->child[bit] = new TrieNode();
            cur = cur->child[bit];
            cur->go += d;
        }
    }

    int findMax(int number)
    {
        TrieNode *cur = this;
        int ans = 0;
        for (int i = 17; i >= 0; --i)
        {
            int bit = (number >> i) & 1;
            if (cur->child[1 - bit] != nullptr && cur->child[1 - bit]->go > 0)
            {
                cur = cur->child[1 - bit];
                ans |= (1 << i);
            }
            else
                cur = cur->child[bit];
        }
        return ans;
    }
};

class Solution
{
public:
    TrieNode trieRoot;
    vector<int> maxGeneticDifference(vector<int> &parents, vector<vector<int>> &qs)
    {
        int n = parents.size(), m = qs.size(), root = -1;
        vector<vector<int>> graph(n);
        for (int i = 0; i < n; ++i)
            if (parents[i] == -1)
                root = i;
            else
                graph[parents[i]].push_back(i);
        vector<vector<pair<int, int>>> queryByNode(n);
        for (int i = 0; i < m; ++i)
            queryByNode[qs[i][0]].push_back(make_pair(qs[i][1], i)); // node -> list of pairs (val, idx)

        vector<int> ans(m);
        dfs(root, graph, queryByNode, ans);
        return ans;
    }

    void dfs(int u, vector<vector<int>> &graph, vector<vector<pair<int, int>>> &queryByNode, vector<int> &ans)
    {
        trieRoot.increase(u, 1);
        for (auto &p : queryByNode[u])
            ans[p.second] = trieRoot.findMax(p.first);
        for (int &v : graph[u])
            dfs(v, graph, queryByNode, ans);
        trieRoot.increase(u, -1);
    }
};