// 2246. Longest Path With Different Adjacent Characters
/*
You are given a tree (i.e. a connected, undirected graph that has no cycles) 
rooted at node 0 consisting of n nodes numbered from 0 to n - 1. 

The tree is represented by a 0-indexed array parent of size n, where parent[i] is the 
parent of node i. Since node 0 is the root, parent[0] == -1.

You are also given a string s of length n, where s[i] is the character assigned to node i.

Return the length of the longest path in the tree such that no pair of adjacent nodes 
on the path have the same character assigned to them

Input: parent = [-1,0,0,1,1,2], s = "abacbe"
Output: 3
Explanation: The longest path where each two adjacent nodes have different 
characters in the tree is the path: 0 -> 1 -> 3. The length of this path is 3, so 3 is returned.

It can be proven that there is no longer path that satisfies the conditions.

Input: parent = [-1,0,0,0], s = "aabc"
Output: 3
Explanation: The longest path where each two adjacent nodes have different characters is the 
path: 2 -> 0 -> 3. The length of this path is 3, so 3 is returned.

-------

Constraints:

n == parent.length == s.length
1 <= n <= 10^5
0 <= parent[i] <= n - 1 for all i >= 1
parent[0] == -1
parent represents a valid tree.
s consists of only lowercase English letters.
*/

/*
Solution2:

class Solution {
public:
    
    unordered_map<int, vector<int>>gr;
    unordered_map<int, int>vis;
    int fnans=0;
    
    int dfs(int node){
        if(vis[node]==1) return 0;
        vis[node]=1;
        vector<int>ans={0, 0};
        for(auto &child: gr[node]){
            if(vis[child]==0){
                ans.push_back(dfs(child));
            }
        }
        sort(ans.begin(), ans.end());
        int curans=1+ans.back()+ans[ans.size()-2];
        fnans=max(fnans, curans);
        return 1+ans.back();
    }
    
    int longestPath(vector<int>& parent, string s) {
       int sz=parent.size();
       for(int i=0; i<sz; ++i){
           if(parent[i]!=-1&&s[i]!=s[parent[i]]){
               gr[i].push_back(parent[i]);
               gr[parent[i]].push_back(i);
           }
       }
       for(int i=0; i<sz; ++i){
           dfs(i);
       }
        return fnans;
    }
};
*/

class Solution {
public:
    
    int dfs(unordered_map<int, vector<int>>&gr, int curnode, int &ans, unordered_set<int>&seen, string &s){
        seen.insert(curnode);
        int count1=0, count2=0;
        for(auto &child: gr[curnode]){
            if(seen.find(child)==seen.end()){
                int cur=dfs(gr, child, ans, seen, s);
                if(s[child]!=s[curnode]){
                    if(cur>count2){
                        count2=cur;
                    }
                    if(count2>count1) swap(count1, count2);
                }
            }
        }
        ans=max(ans, count1+count2+1);
        return count1+1;
    }
    
    int longestPath(vector<int>& parent, string s) {
        if(parent.size()==1) return 1;
        int ans=0;
        int sz=parent.size();
        unordered_map<int, vector<int>>gr;
        for(int i=1; i<sz; ++i){
            gr[parent[i]].push_back(i);
        }
        unordered_set<int>seen;
        ans=1;
        ans=max(ans, dfs(gr, 0, ans, seen, s));
        return ans;
    }
};