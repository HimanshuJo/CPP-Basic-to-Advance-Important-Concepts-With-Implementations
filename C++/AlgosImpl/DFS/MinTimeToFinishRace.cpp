// 2188. Minimum Time to Finish the Race
/*
You are given a 0-indexed 2D integer array tires where tires[i] = [fi, ri] 
indicates that the ith tire can finish its xth successive lap in fi * ri^(x-1) seconds.

For example, if fi = 3 and ri = 2, then the tire would finish its 1st lap in 3 seconds, 
its 2nd lap in 3 * 2 = 6 seconds, its 3rd lap in 3 * 2^2 = 12 seconds, etc.
You are also given an integer changeTime and an integer numLaps.

The race consists of numLaps laps and you may start the race with any tire. 
You have an unlimited supply of each tire and after every lap, you may change to 
any given tire (including the current tire type) if you wait changeTime seconds.

Return the minimum time to finish the race.

Example 1:

Input: tires = [[2,3],[3,4]], changeTime = 5, numLaps = 4
Output: 21
Explanation: 
Lap 1: Start with tire 0 and finish the lap in 2 seconds.
Lap 2: Continue with tire 0 and finish the lap in 2 * 3 = 6 seconds.
Lap 3: Change tires to a new tire 0 for 5 seconds and then finish the lap in another 2 seconds.
Lap 4: Continue with tire 0 and finish the lap in 2 * 3 = 6 seconds.
Total time = 2 + 6 + 5 + 2 + 6 = 21 seconds.
The minimum time to complete the race is 21 seconds.
Example 2:

Input: tires = [[1,10],[2,2],[3,4]], changeTime = 6, numLaps = 5
Output: 25
Explanation: 
Lap 1: Start with tire 1 and finish the lap in 2 seconds.
Lap 2: Continue with tire 1 and finish the lap in 2 * 2 = 4 seconds.
Lap 3: Change tires to a new tire 1 for 6 seconds and then finish the lap in another 2 seconds.
Lap 4: Continue with tire 1 and finish the lap in 2 * 2 = 4 seconds.
Lap 5: Change tires to tire 0 for 6 seconds then finish the lap in another 1 second.
Total time = 2 + 4 + 6 + 2 + 4 + 6 + 1 = 25 seconds.
The minimum time to complete the race is 25 seconds. 
 

Constraints:

1 <= tires.length <= 10^5
tires[i].length == 2
1 <= fi, changeTime <= 10^5
2 <= ri <= 10^5
1 <= numLaps <= 1000
*/
/*
class Solution {
public:
    
    int dfs(int changeTime, int numLaps, int maxLaps, vector<int>&memo, vector<int>&best){
        if(numLaps==0) return -changeTime;
        if(!memo[numLaps]){
            memo[numLaps]=INT_MAX;
            for(int i=1; i<=min(numLaps, maxLaps); ++i){
                memo[numLaps]=min(memo[numLaps], best[i]+changeTime+dfs(changeTime, numLaps-i, maxLaps, memo, best));
            }
        }
        return memo[numLaps];
    }
    
    int minimumFinishTime(vector<vector<int>>& tires, int changeTime, int numLaps) {
        vector<int>memo(1001, 0), best(20, 0);
        int maxLaps=0;
        for(auto &vals: tires){
            long long laptime=vals[0], laptimeTemp=vals[0];
            for(int lap=1; lap<=numLaps&&(laptime<vals[0]+changeTime); ++lap){
                maxLaps=max(maxLaps, lap);
                if(best[lap]==0||best[lap]>laptimeTemp){
                    best[lap]=laptimeTemp;
                }
                laptime*=vals[1];
                laptimeTemp+=laptime;
            }
        }
        return dfs(changeTime, numLaps, maxLaps, memo, best);
    }
};
*/

/*
Observation:

    Given changeTime <= 10^5, it won't be optimal if we use any tire consecutively 
    without change for larger than 18 laps.

Let's consider the extreme case, when f_i == 1 and r_i == 2

consecutive laps        1   2   3   4   5   6   7   8   9   10
time on the last lap    1   2   4   8   16  32  64  128 256 512

consecutive laps        11      12      13      14      15      16      17      18
time on the last lap    1024    2048    4096    8192    16384   32768   65536   131072

it is obvious that at the 18-th consecutive lap, it is alway better to change a tire 
(even when f_i and r_i are given their smallest possible values).

this observation leads to two lemmas

-------

Lemma 1.

    If numLaps >= 18, we must change tire in some point of time in any optimal way.

Lemma 2.

    After changing a tire, an optimal way won't have the tire running for more than 18 consecutive laps.

Algorithm:

    from the above discussion, we can form a dp like:
    
    dp[x] := the minimum time to finish x laps
    
    base case: dp[1] = min(f_i) among all tires
    
    transition: dp[x] = min(dp[j] + changeTime + dp[x-j]) among all possible js
        
        meaning: the minimum time to finish x laps is the minimum time to finish j laps first and 
        change a tire at the end of j-th lap, plus the minimum time to finish the last x-j laps.

        which js are possible ?
            
            from Lemma 2. we know j >= x-18 must hold.
            
            It leads to a constant time transition.
            
            note that if x < 18, it's possible that an optimal solution never changes a tire.
*/

class Solution {
public:
    int minimumFinishTime(vector<vector<int>>& tires, int changeTime, int numLaps) {
        int sz=tires.size();
        /*
        To handle the cases where numLaps is small,
        withoutChange[i][j]-> total time to run j laps consecutively with tire i
        */
        vector<vector<int>>withoutChange(sz, vector<int>(20, INT_MAX));
        for(int i=0; i<sz; ++i){
            withoutChange[i][1]=tires[i][0];
            for(int j=2; j<20; ++j){
                if((long long)withoutChange[i][j-1]*tires[i][1]>=INT_MAX) break;
                withoutChange[i][j]=withoutChange[i][j-1]*tires[i][1];
            }
            /*
            Since we define it as the total time, rather than just the time for the
            j'th lap, we have to make it prefixSum
            */
            for(int j=2; j<20; ++j){
                if((long long)withoutChange[i][j-1]+withoutChange[i][j]>=INT_MAX) break;
                withoutChange[i][j]+=withoutChange[i][j-1];
            }
        }
        /*
        dp[x]->min time to finish x laps
        */
        vector<int>dp(numLaps+1, INT_MAX);
        for(int i=0; i<sz; ++i){
            dp[1]=min(dp[1], tires[i][0]);
        }
        for(int x=1; x<=numLaps; ++x){
            /*
            If x is small enough, an optimal solution might never change tires
            */
            if(x<20){
                for(int i=0; i<sz; ++i){
                    dp[x]=min(dp[x], withoutChange[i][x]);
                }
            }
            for(int j=x-1; j>0&&j>=x-18; --j){
                dp[x]=min(dp[x], dp[j]+changeTime+dp[x-j]);
            }
        }
        return dp[numLaps];
    }
};