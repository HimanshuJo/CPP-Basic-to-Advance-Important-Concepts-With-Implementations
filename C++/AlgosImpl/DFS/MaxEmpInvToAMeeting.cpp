// 2127. Maximum Employees to Be Invited to a Meeting
/*
A company is organizing a meeting and has a list of n employees, waiting to be invited. 
They have arranged for a large circular table, capable of seating any number of employees.

The employees are numbered from 0 to n - 1. Each employee has a favorite person and they will attend the 
meeting only if they can sit next to their favorite person at the table. 

The favorite person of an employee is not themself.

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

class Solution{
	int max_loop_sz, max_comb_sz;

	public:
	
	void dfs(int i, int &depth, vector<bool>&seen, const vector<int>&favorite, const vector<int>&maxChain){
		if(seen[i]){
			if(depth<=2){
				max_comb_sz+=depth+maxChain[i]+maxChain[favorite[i]];
			} else{
				max_loop_sz=max(max_loop_sz, depth);
			}
			return;
		}
		seen[i]=true;
		dfs(favorite[i], ++depth, seen, favorite, maxChain);
	}

	int maximumInvitations(vector<int>&favorite){
		int n=favorite.size();
		vector<int>indeg(n);
		for(auto &itr: favorite)
			indeg[itr]++;
		queue<int>q;
		for(int i=0; i<n; ++i)
			if(!indeg[i]) q.push(i);
		vector<int>maxChain(n, 0);
		int l=1;
		while(!q.empty()){
			int sz=q.size();
			while(sz--){
				int curr=q.front();
				q.pop();
				if(--indeg[favorite[curr]]==0){
					q.push(favorite[curr]);
				}
				maxChain[favorite[curr]]=max(maxChain[favorite[curr]], l);
			}
			++l;
		}
		max_loop_sz=0, max_comb_sz=0;
		vector<bool>seen(n, false);
		for(int i=0; i<n; ++i){
			int d=0;
			if(indeg[i]&&!seen[i])
				dfs(i, d, seen, favorite, maxChain);
		}
		return max(max_loop_sz, max_comb_sz);
	}
};

// -------*******-------

class Solution2 {
public:
    
    int dfs1(vector<vector<int>>&gr, int seen[100001], int u){
        seen[u]=1;
        int d=0;
        for(auto &v: gr[u]){
            if(seen[v]!=1){
                int res=1+dfs1(gr, seen, v);
                d=max(d, res);
            }
        }
        return d;
    }

    pair<int, int> dfs2(vector<vector<int>>&gr, int seen[100001], int u, int start){
        if(start==u) return {1, 0};
        if(seen[u]==1) return {0, 0};
        seen[u]=1;
        pair<int, int>res;
        for(auto &v: gr[u]){
            pair<int, int>retVal=dfs2(gr, seen, v, start==-1?u:start);
            if(retVal.first==1){
                int depth=1+retVal.second;
                res.second=max(depth, res.second);
            } else{
                retVal.first=0, retVal.second=0;
            }
            if(res.second>0) res.first=1;
            else res.first=0;
        }
        if(res.second==0) return {0, 0};
        return res;
    }

    int maximumInvitations(vector<int>& favorite) {
        int n=favorite.size();
        vector<vector<int>>gr(n);
        for(int i=0; i<n; ++i){
            gr[favorite[i]].push_back(i);
        }
        int seen[100001];
        for(int i=0; i<100001; ++i)
            seen[i]=-1;
        // Case 1: Two nodes likes each other and there could be max path going across two node
        int res1=0;
        for(int i=0; i<n; ++i){
            if(seen[i]==1) continue;
            if(i==favorite[favorite[i]]){
                seen[favorite[i]]=1, seen[i]=1;
                // max path from i to its likers
                int a=dfs1(gr, seen, i);
                // max path from favorite[i] to its likers
                int b=dfs1(gr, seen, favorite[i]);
                res1+=a+b+2;
            }
        }
        // case 2: max result from a cycle
        int res2=0;
        for(int i=0; i<100001; ++i)
            seen[i]=-1;
        for(int i=0; i<n; ++i){
            if(seen[i]==1) continue;
            res2=max(res2, dfs2(gr, seen, i, -1).second);
        }
        return max(res1, res2);
    }
};