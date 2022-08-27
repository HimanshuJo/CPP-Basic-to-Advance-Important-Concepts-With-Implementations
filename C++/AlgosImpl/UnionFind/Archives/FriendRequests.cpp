// 2076. Process Restricted Friend Requests
/*
You are given an integer n indicating the number of people in a network.
Each person is labeled from 0 to n - 1.

You are also given a 0-indexed 2D integer array restrictions,
where restrictions[i] = [xi, yi] means that person xi and
person yi cannot become friends, either directly or indirectly through other people.

Initially, no one is friends with each other. You are given a list of friend
requests as a 0-indexed 2D integer array requests,
where requests[j] = [uj, vj] is a friend request between person uj and person vj.

A friend request is successful if uj and vj can be friends. Each friend request is
processed in the given order
(i.e., requests[j] occurs before requests[j + 1]), and upon a successful request,
uj and vj become direct friends for all future friend requests.

Return a boolean array result, where each result[j] is true if the jth friend
request is successful or false if it is not.

Note: If uj and vj are already direct friends, the request is still successful.

Example 1:

Input: n = 3, restrictions = [[0,1]], requests = [[0,2],[2,1]]
Output: [true,false]
Explanation:
Request 0: Person 0 and person 2 can be friends, so they become direct friends.
Request 1: Person 2 and person 1 cannot be friends since person 0 and person 1 would
           be indirect friends (1--2--0).

Example 3:

Input: n = 5, restrictions = [[0,1],[1,2],[2,3]], requests = [[0,4],[1,2],[3,1],[3,4]]
Output: [true,false,true,false]
Explanation:
Request 0: Person 0 and person 4 can be friends, so they become direct friends.
Request 1: Person 1 and person 2 cannot be friends since they are directly restricted.
Request 2: Person 3 and person 1 can be friends, so they become direct friends.
Request 3: Person 3 and person 4 cannot be friends since person 0 and person
           1 would be indirect friends (0--4--3--1).
*/
#include<bits/stdc++.h>
using namespace std;

class UnionFind {
public:
    vector<int>parent;
    UnionFind(int n) {
        parent.resize(n + 1, -1);
    }

    int find(int x) {
        int root = x;
        while (parent[root] >= 0) {
            root = parent[root];
        }
        while (parent[x] >= 0) {
            int next = parent[x];
            parent[x] = root;
            x = next;
        }
        return root;
    }

    void doUnion(int x, int y) {
        int root1 = find(x);
        int root2 = find(y);
        if (root1 == root2) return;
        if (parent[root1] < parent[root2]) {
            parent[root1] += parent[root2];
            parent[root2] = root1;
        } else {
            parent[root2] += parent[root1];
            parent[root1] = root2;
        }
    }
};

class Solution {
public:
    vector<bool>friendRequests(int n, vector<vector<int>>&restrictions, vector<vector<int>>&requests) {
        int m = requests.size();
        vector<bool>ans(m, 0);
        UnionFind unionFind(n);
        for (int i = 0; i < m; ++i) {
            UnionFind temp = unionFind;
            temp.doUnion(requests[i][0], requests[i][1]);
            bool flag = true;
            for (vector<int>&vec : restrictions) {
                if (temp.find(vec[0]) == temp.find(vec[1])) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                ans[i] = true;
                unionFind.doUnion(requests[i][0], requests[i][1]);
            }
        }
        return ans;
    }
};