// 2240. Number of Ways to Buy Pens and Pencils
/*
You are given an integer total indicating the amount of money you have. 
You are also given two integers cost1 and cost2 indicating the price of a pen and 
pencil respectively. 

You can spend part or all of your money to buy multiple quantities (or none) of each kind of writing utensil.

Return the number of distinct ways you can buy some number of pens and pencils.

Example 1:

Input: total = 20, cost1 = 10, cost2 = 5
Output: 9
Explanation: The price of a pen is 10 and the price of a pencil is 5.
- If you buy 0 pens, you can buy 0, 1, 2, 3, or 4 pencils.
- If you buy 1 pen, you can buy 0, 1, or 2 pencils.
- If you buy 2 pens, you cannot buy any pencils.
The total number of ways to buy pens and pencils is 5 + 3 + 1 = 9.
Example 2:

Input: total = 5, cost1 = 10, cost2 = 10
Output: 1
Explanation: The price of both pens and pencils are 10, which cost more than total, 
so you cannot buy any writing utensils. Therefore, there is only 1 way: buy 0 pens and 0 pencils.
 

Constraints:

1 <= total, cost1, cost2 <= 10^6
*/

class Solution {
public:
    long long waysToBuyPensPencils(int total, int cost1, int cost2) {
        if(cost1>total&&cost2>total) return 1;
        long long ans=0;
        int maxx=max(cost1, cost2);
        int minn=min(cost1, cost2);
        int curval=total;
        while(true){
            long long curans=0;
            int tempcurval=curval;
            while(true){
                if(tempcurval<minn) break;
                else if(tempcurval%minn==0){
                    curans+=(tempcurval/minn);
                    tempcurval-=tempcurval;
                }
                else{
                    int quo=tempcurval/minn;
                    curans+=quo;
                    tempcurval-=(quo*minn);
                }
            }
            ans+=curans+1;
            curval-=maxx;
            if(curval>=0&&curval<maxx){
                long long curans_=0;
                int tempcurval_=curval;
                while(true){
                    if(tempcurval_<minn) break;
                    else{
                        curans_++;
                        tempcurval_-=minn;
                    }
                }
                ans+=curans_+1;   
                break;
            } else if(curval<0) break;
        }
        return ans;
    }
};

// Solution2

class Solution2 {
public:
    
    long long dfs(int total, int cost1, int cost2){
        return (total<0?0:1+total/cost2+dfs(total-cost1, cost1, cost2));
    }
    
    long long waysToBuyPensPencils(int total, int cost1, int cost2) {
        long long ans=dfs(total, cost1, cost2);
        return ans;
    }
};