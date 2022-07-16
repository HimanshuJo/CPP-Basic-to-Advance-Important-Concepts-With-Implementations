// 2127. Maximum Employees to Be Invited to a Meeting
/*
A company is organizing a meeting and has a list of n employees, waiting to be invited. 
They have arranged for a large circular table, capable of seating any number of employees.

The employees are numbered from 0 to n - 1. Each employee has a favorite person and they will attend the 
meeting only if they can sit next to their favorite person at the table. 

The favorite person of an employee is not themselves.

Given a 0-indexed integer array favorite, where favorite[i] denotes the favorite person of the ith employee, 
return the maximum number of employees that can be invited to the meeting.

Input: favorite = [2,2,1,2]
Output: 3
Explanation:
The above figure shows how the company can invite employees 0, 1, and 2, and seat them at the round table.
All employees cannot be invited because employee 2 cannot sit beside employees 0, 1, and 3, simultaneously.
Note that the company can also invite employees 1, 2, and 3, and give them their desired seats.
The maximum number of employees that can be invited to the meeting is 3. 
Example 2:

Input: favorite = [1,2,0]
Output: 3
Explanation: 
Each employee is the favorite person of at least one other employee, and the only way the company can invite them is if they invite every employee.
The seating arrangement will be the same as that in the figure given in example 1:
- Employee 0 will sit between employees 2 and 1.
- Employee 1 will sit between employees 0 and 2.
- Employee 2 will sit between employees 1 and 0.
The maximum number of employees that can be invited to the meeting is 3.

Input: favorite = [3,0,1,4,1]
Output: 4
Explanation:
The above figure shows how the company will invite employees 0, 1, 3, and 4, and seat them at the round table.
Employee 2 cannot be invited because the two spots next to their favorite employee 1 are taken.
So the company leaves them out of the meeting.
The maximum number of employees that can be invited to the meeting is 4.
 

Constraints:

n == favorite.length
2 <= n <= 10^5
0 <= favorite[i] <= n - 1
favorite[i] != i
*/

/*
Solution:

    Case 1:

        If two nodes are interdependent, we can DFS from these two nodes
        backwards to find the longest two arms.

        Suppose their length are 'a' and 'b', then we can form a free component of length (a+b+2)

        -------

        There can be multiple free components, we can put them together in the final result

            Therefore we should sum all the free components together

        -------

                    6-->5-->3-->1-->2<--7<--8   ans=3+2+2=7
                            ^   ^   |
                            |   |___|
                            4   

    -------

    Case 2:

        There is a cyclic dependency

            The answer is the length of the cycle

                    7-->4-->1-->2-->3   ans=4
                        ^           |
                        |___________|
                        |
                        5<--6

        -------

        Assuming we are doing dfs from node 5->4->1->2->3 and then 4 again

            The second time we meet node 4, we know that node 4 is the entry point,
            so at this point we'll start backtracking

            During the backtracking process:

                Before we visit the node 4 again, we are within the cycle, so we'll keep
                on incrementing the depth

                When we visit the node 4 again, we mark cycle visited as True

                Beyond node 4(e.g. node 5), we're outside of the cycle, so we just leave the depth
                of the node as 0, because this node should be ignored

    -------

    Final ans=max(case 1, case 2)
*/

// TC: O(N^2)
// SC: O(N+Aux stack space)
class Solution1 {
public:
    
    int maxLpSz, maxCombSz;
    
    void dfs(int curNode, int &depth, vector<bool>&seen, vector<int>&maxChain, vector<int>&favorite){
        if(seen[curNode]){
            if(depth<=2){
                maxCombSz+=depth+maxChain[curNode]+maxChain[favorite[curNode]];
            } else{
                maxLpSz=max(maxLpSz, depth);
            }
            return;
        }
        seen[curNode]=1;
        depth=depth+1;
        dfs(favorite[curNode], depth, seen, maxChain, favorite);
    }
    
    int maximumInvitations(vector<int>& favorite) {
        int sz=favorite.size();
        vector<int>indeg(sz, 0);
        queue<int>q;
        for(int i=0; i<sz; ++i){
            indeg[favorite[i]]++;
        }
        for(int i=0; i<sz; ++i){
            if(indeg[i]==0){
                q.push(i);
            }
        }
        vector<int>maxChain(sz, 0);
        int l=1;
        while(!q.empty()){
            int sz=q.size();
            while(sz--){
                int curr=q.front();
                q.pop();
                int currFav=favorite[curr];
                if(--indeg[currFav]==0){
                    q.push(currFav);
                }
                maxChain[currFav]=max(maxChain[currFav], l);
            }
            l++;
        }
        vector<bool>seen(sz, 0);
        maxLpSz=0, maxCombSz=0;
        for(int i=0; i<sz; ++i){
            int depth=0;
            if(indeg[i]&&!seen[i]){
                dfs(i, depth, seen, maxChain, favorite);
            }
        }
        return max(maxLpSz, maxCombSz);
    }
};

// -------*******-------

class Solution2 {
public:
    
    int dfs1(vector<vector<int>>&adj, int seen[], int curNode){
        seen[curNode]=1;
        int d=0;
        for(auto &favOfNode: adj[curNode]){
            if(seen[favOfNode]!=1){
                int res=1+dfs1(adj, seen, favOfNode);
                d=max(d, res);
            }   
        }
        return d;
    }
    
    int* dfs2(vector<vector<int>>&adj, int seen[100001], int curNode, int start){
        if(start==curNode){
            static int r[2]{1, 0};
            return r;
        }
        if(seen[curNode]==1){
            static int r[2]{0, 0};
            return r;
        }
        seen[curNode]=1;
        int res[2]={0, 0};
        for(auto &favOfNode: adj[curNode]){
            int *ret=dfs2(adj, seen, favOfNode, start==-1?curNode:start);
            if(ret[0]==1){
                int depth=1+ret[1];
                res[1]=max(depth, res[1]);
            }
            if(res[1]>0) res[0]=1;
        }
        if(res[1]==0){
            static int r[2]{0, 0};
            return r;
        }
        return res;
    }
    
    int maximumInvitations(vector<int>& favorite) {
        int sz=favorite.size();
        vector<vector<int>>adj(sz+1);
        for(int i=0; i<sz; ++i){
            adj[favorite[i]].push_back(i);
        }
        int seen[100001];
        memset(seen, -1, sizeof(seen));
        /* Case 1: 
                Two nodes likes each other and there could be max path going across those two nodes
        */
        int res1=0;
        for(int i=0; i<sz; ++i){
            if(seen[i]==1) continue;
            if(i==favorite[favorite[i]]){
                seen[favorite[i]]=1, seen[i]=1;
                // max path from i to its likers(all the people who likes the curnode)
                int a=dfs1(adj, seen, i);
                // max path from favorite[i] to its likers(all the people who likes the favorite of curnode)
                int b=dfs1(adj, seen, favorite[i]);
                res1+=a+b+2;
            }
        }
        /*
            Case 2:
                Maximum result from cycle
        */
        int res2=0;
        memset(seen, -1, sizeof(seen));
        for(int i=0; i<sz; ++i){
            if(seen[i]==1) continue;
            res2=max(res2, dfs2(adj, seen, i, -1)[1]);
        }
        return max(res1, res2);
    }
};