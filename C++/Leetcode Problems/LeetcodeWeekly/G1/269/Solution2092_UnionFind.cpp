// 2092. Find All People With Secret
/*
You are given an integer n indicating there are n people numbered from 0 to n - 1. 
You are also given a 0-indexed 2D integer array meetings where meetings[i] = [xi, yi, timei] indicates that person xi and person yi have a meeting at timei.
A person may attend multiple meetings at the same time. Finally, you are given an integer firstPerson.

Person 0 has a secret and initially shares the secret with a person firstPerson at time 0. This secret is then shared every time a meeting takes place with a
person that has the secret. More formally, for every meeting, if a person xi has the secret at timei, then they will share the secret with person yi, and vice versa.

The secrets are shared instantaneously. That is, a person may receive the secret and share it with people in other meetings within the same time frame.

Return a list of all the people that have the secret after all the meetings have taken place. You may return the answer in any order.

Example 4:

Input: n = 6, meetings = [[0,2,1],[1,3,1],[4,5,1]], firstPerson = 1
Output: [0,1,2,3]
Explanation:
At time 0, person 0 shares the secret with person 1.
At time 1, person 0 shares the secret with person 2, and person 1 shares the secret with person 3.
Thus, people 0, 1, 2, and 3 know the secret after all the meetings.
*/

#include<vector>
#include<iostream>
using namespace std;

class UnionFind {
    vector<int> id, rank;
public:
    UnionFind(int n) : id(n), rank(n, 0) {
        iota(begin(id), end(id), 0);
    }

    void connect(int a, int b) {
        int p = find(a), q = find(b);
        if (p == q) return;
        if (rank[p] > rank[q]) id[p] = q;
        else {
            id[q] = p;
            if (rank[p] == rank[q]) rank[p]++;
        }
    }

    int find(int a) {
        return id[a] == a ? a : (id[a] = find(id[a]));
    }

    bool connected(int a, int b) {
        return find(a) == find(b);
    }

    void reset(int a) { id[a] = a; }
};

class Solution{
	public:
	vector<int> findAllPeople(int n, vector<vector<int>>&meetings, int firstPerson){
		sort(begin(meetings), end(meetings), [](auto &a, auto &b){return a[2]<b[2];});
		int i=0, sz=meetings.size();
		UnionFind uf(n);
		uf.connect(0, firstPerson);
		vector<int>ppl;
		while(i<sz){
			ppl.clear();
			int time=meetings[i][2];
			while(i<sz&&meetings[i][2]==time){
				uf.connect(meetings[i][0], meetings[i][1]);
				ppl.push_back(meetings[i][0]);
				ppl.push_back(meetings[i][1]);
				++i;
			}
			for(int people: ppl){
				if(!uf.connected(0, people)){
					uf.reset(people);
				}
			}
		}
		vector<int>ans;
		for(int i=0; i<n; ++i){
			if(uf.connected(0, i)){
				ans.push_back(i);
			}
		}
		return ans;
	}
};
