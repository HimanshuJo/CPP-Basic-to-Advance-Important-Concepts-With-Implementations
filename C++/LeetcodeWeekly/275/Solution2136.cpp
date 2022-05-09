// 2136. Earliest Possible Day of Full Bloom
/*
You have n flower seeds. Every seed must be planted first before it can begin to grow, then bloom. 
Planting a seed takes time and so does the growth of a seed. 
You are given two 0-indexed integer arrays plantTime and growTime, of length n each:

plantTime[i] is the number of full days it takes you to plant the ith seed. 
Every day, you can work on planting exactly one seed.
You do not have to work on planting the same seed on consecutive days, but the planting of a seed 
is not complete until you have worked plantTime[i] days on planting it in total.
growTime[i] is the number of full days it takes the ith seed to grow after being completely planted. 
After the last day of its growth, the flower blooms and stays bloomed forever.
From the beginning of day 0, you can plant the seeds in any order.

Return the earliest possible day where all seeds are blooming.

E.g.

Input: plantTime = [1,2,3,2], growTime = [2,1,2,1]
Output: 9
Explanation: The grayed out pots represent planting days, colored pots represent growing days, 
and the flower represents the day it blooms.
One optimal way is:
On day 1, plant the 0th seed. The seed grows for 2 full days and blooms on day 4.
On days 0 and 3, plant the 1st seed. The seed grows for 1 full day and blooms on day 5.
On days 2, 4, and 5, plant the 2nd seed. The seed grows for 2 full days and blooms on day 8.
On days 6 and 7, plant the 3rd seed. The seed grows for 1 full day and blooms on day 9.
Thus, on day 9, all the seeds are blooming.
*/
/*
Solution 2:

class Solution {
public:
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
        int n = plantTime.size();
        // growTime larger first
        vector<pair<int, int>> times(n);
        for (int i = 0; i < n; i++) {
            times[i].first = growTime[i];
            times[i].second = plantTime[i];
        }
        sort(times.rbegin(), times.rend());
        int tot = 0;
        int cur = 0;
        for (int i = 0; i < n; i++) {
        	// endTime=max(pi+gi, pi+pj+gj)
            tot = max(tot, cur + times[i].second + times[i].first);
            cur += times[i].second;
        }
        return tot;
    }
};
*/

/*
Proof:

It could be easier to prove it. 

Let's say we have plantTime = [p1, p2], and growTime = [g1, g2], where g1 >= g2.

Now, let's assume that we only plant and grow flower 1 and flower 2 is gone, then we need at least (p1 + g1) days.

Unfortunately and obviously flower 2 is not gone, we need plant it and let it grow and bloom. 
What is the best we achieve when we need plant two flowers? 

It is (p1 + p2 + g2), and we can't do better. This is because on (p1+p2)th day, 
if we plant flower 1, we need add g1 more days, and (p1 + p2 + g1) is no better than (p1 + p2 + g2).

Considering overall, the best we can do is max(p1 + g1, p1 + p2 + g2).

Now let's see how the greedy approach is consistent with above equation.

We first finish planting flower 1 and let it grow, flower 1 will bloom after (p1 + g1) days.

After we finish planting flower 2, we start to plant flower 2, and let it grow. 
Flower 2 will bloom after (p1 + p2 + g2) days.

Thus, all flowers will bloom after max(p1 + g1, p1 + p2 + g2) days, which is consistent with the analysis.

Three or more flowers are the same.
*/

/*
Grow that plant first that has the max growing time, if growing time is same for two plants
grow that plant that has the max planting time of the two
*/
struct custComp{
    const bool operator()(const pair<int, int>A, const pair<int, int>B){
        return(A.first==B.first?A.second>B.second:A.first>B.first);
    }
};


class Solution {
public:
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
        int n = plantTime.size();
        vector<pair<int, int>> times(n);
        for (int i = 0; i < n; i++) {
            times[i].first = growTime[i];
            times[i].second = plantTime[i];
        }
        sort(times.begin(), times.end(), custComp());
        int tot = 0;
        int cur = 0;
        for (int i = 0; i < n; i++) {
            tot = max(tot, cur + times[i].second + times[i].first);
            cur += times[i].second;
        }
        return tot;
    }
};