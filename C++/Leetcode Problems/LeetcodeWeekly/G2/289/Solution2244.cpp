// 2244. Minimum Rounds to Complete All Tasks
/*
You are given a 0-indexed integer array tasks, where tasks[i] represents the 
difficulty level of a task. In each round, you can complete either 2 or 3 tasks of the same difficulty level.

Return the minimum rounds required to complete all the tasks, or -1 if it is not possible to complete all the tasks.

Example 1:

Input: tasks = [2,2,3,3,2,4,4,4,4,4]
Output: 4
Explanation: To complete all the tasks, a possible plan is:
- In the first round, you complete 3 tasks of difficulty level 2. 
- In the second round, you complete 2 tasks of difficulty level 3. 
- In the third round, you complete 3 tasks of difficulty level 4. 
- In the fourth round, you complete 2 tasks of difficulty level 4.  
It can be shown that all the tasks cannot be completed in fewer than 4 rounds, so the answer is 4.
Example 2:

Input: tasks = [2,3,3]
Output: -1
Explanation: There is only 1 task of difficulty level 2, but in each round, 
you can only complete either 2 or 3 tasks of the same difficulty level. Hence, you cannot 
complete all the tasks, and the answer is -1.
 

Constraints:

1 <= tasks.length <= 10^5
1 <= tasks[i] <= 10^9
*/

/*
Solution2:

var minimumRounds = function(tasks) {
    function dfs(x, count){
        if(x===0) return 0;
        if(x<2) return Number.MAX_VALUE;
        if(count[x]) return count[x];
        let left=1+dfs(x-3, count);
        let right=1+dfs(x-2, count);
        count[x]=Math.min(left, right);
        return count[x];
    }
    
    let mp={};
    for(let x of tasks){
        mp[x]=mp[x]?mp[x]+1:1;
    }
    var ans=0;
    for(let x of Object.values(mp)){
        let temp=dfs(x, {});
        if(temp===Number.MAX_VALUE){
            ans=-1;
            break;
        } else{
            ans+=temp;
        }
    }
    return ans;
};
*/

class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        unordered_map<int, int>mp;
        for(auto &vals: tasks){
            mp[vals]++;
        }
        int ans=0;
        for(auto &entries: mp){
            if(entries.second==1) return -1;
            int curval=entries.second;
            if(curval==2) ans+=1;
            else if(curval==3) ans+=1;
            else if(curval%3==0) ans+=curval/3;
            else{
                while(curval!=0){
                    int remain=curval-3;
                    if(remain>=2){
                        curval-=3;
                        ans++;
                    } else{
                        curval-=2;
                        ans++;
                    }
                    if(curval==0) break;
                    else if(curval==1) return -1;   
                }
            }
        }
        return ans;
    }
};