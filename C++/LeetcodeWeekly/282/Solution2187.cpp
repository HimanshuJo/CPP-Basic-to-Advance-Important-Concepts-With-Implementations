// 2187. Minimum Time to Complete Trips
/*
You are given an array time where time[i] denotes the time taken by the ith bus to complete one trip.

Each bus can make multiple trips successively; that is, the next trip can start immediately 
after completing the current trip. Also, each bus operates independently; that is, the trips of 
one bus do not influence the trips of any other bus.

You are also given an integer totalTrips, which denotes the number of trips all buses should make in total. 
Return the minimum time required for all buses to complete at least totalTrips trips.

Example 1:

Input: time = [1,2,3], totalTrips = 5
Output: 3
Explanation:
- At time t = 1, the number of trips completed by each bus are [1,0,0]. 
  The total number of trips completed is 1 + 0 + 0 = 1.
- At time t = 2, the number of trips completed by each bus are [2,1,0]. 
  The total number of trips completed is 2 + 1 + 0 = 3.
- At time t = 3, the number of trips completed by each bus are [3,1,1]. 
  The total number of trips completed is 3 + 1 + 1 = 5.
So the minimum time needed for all buses to complete at least 5 trips is 3.
Example 2:

Input: time = [2], totalTrips = 1
Output: 2
Explanation:
There is only one bus, and it will complete its first trip at t = 2.
So the minimum time needed to complete 1 trip is 2.
 

Constraints:

1 <= time.length <= 10^5
1 <= time[i], totalTrips <= 10^7
*/

/*
TLE:

class Solution {
public:
    long long minimumTime(vector<int>& time, int totalTrips) {
        int sz=time.size();
        vector<int>temp1(sz, 0);
        vector<int>temp2(sz, 0);
        long long ans=0;
        bool flag=false;
        int counter=0;
        while(true){
            counter++;
            for(int i=0; i<sz; ++i){
                temp2[i]++;
                if(temp2[i]==time[i]){
                    temp2[i]=0;
                    temp1[i]++;
                }
            }
            int ans=0;
            for(auto &vals: temp1){
                ans+=vals;
            }
            if(ans>=totalTrips){
                break;
            }
        }
        return counter;
    }
};
*/

class Solution {
public:
    
    bool isValid(long long mid, vector<int>&time, int totaTrips){
        int sz=time.size();
        vector<long long>temp(sz, 0);
        for(int i=0; i<sz; ++i){
            temp[i]=mid/time[i];
        }
        long long res=0;
        for(auto &vals: temp){
            res+=vals;
        }
        return res>=totaTrips;
    }
    
    long long minimumTime(vector<int>& time, int totalTrips) {
        sort(time.begin(), time.end());
        int sz=time.size();
        vector<int>temp1(sz, 0);
        long long left=0, right=100000000000000;
        long long ans=0;
        while(left<=right){
            long long mid=left+(right-left)/2;
            if(isValid(mid, time, totalTrips)){
                ans=mid;
                right=mid-1;
            } else{
                left=mid+1;
            }
        }
        return ans;
    }
};