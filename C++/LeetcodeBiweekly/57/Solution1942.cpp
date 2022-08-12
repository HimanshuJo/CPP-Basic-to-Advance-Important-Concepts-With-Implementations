// 1942. The Number of the Smallest Unoccupied Chair
/*
There is a party where n friends numbered from 0 to n - 1 are attending. 

There is an infinite number of chairs in this party that are numbered from 0 to infinity. 
When a friend arrives at the party, they sit on the unoccupied chair with the smallest number.

For example, if chairs 0, 1, and 5 are occupied when a friend comes, they will sit on chair number 2.
When a friend leaves the party, their chair becomes unoccupied at the moment they leave. 
If another friend arrives at that same moment, they can sit in that chair.

You are given a 0-indexed 2D integer array times where times[i] = [arrivali, leavingi], 
indicating the arrival and leaving times of the ith friend respectively, and an integer 
targetFriend. All arrival times are distinct.

Return the chair number that the friend numbered targetFriend will sit on.

Example 1:

Input: times = [[1,4],[2,3],[4,6]], targetFriend = 1
Output: 1
Explanation: 
- Friend 0 arrives at time 1 and sits on chair 0.
- Friend 1 arrives at time 2 and sits on chair 1.
- Friend 1 leaves at time 3 and chair 1 becomes empty.
- Friend 0 leaves at time 4 and chair 0 becomes empty.
- Friend 2 arrives at time 4 and sits on chair 0.
Since friend 1 sat on chair 1, we return 1.
Example 2:

Input: times = [[3,10],[1,5],[2,6]], targetFriend = 0
Output: 2
Explanation: 
- Friend 1 arrives at time 1 and sits on chair 0.
- Friend 2 arrives at time 2 and sits on chair 1.
- Friend 0 arrives at time 3 and sits on chair 2.
- Friend 1 leaves at time 5 and chair 0 becomes empty.
- Friend 2 leaves at time 6 and chair 1 becomes empty.
- Friend 0 leaves at time 10 and chair 2 becomes empty.
Since friend 0 sat on chair 2, we return 2.
 

Constraints:

n == times.length
2 <= n <= 10^4
times[i].length == 2
1 <= arrivali < leavingi <= 10^5
0 <= targetFriend <= n - 1
Each arrivali time is distinct.
*/

class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        vector<vector<int>>timescmb;
        int sz=times.size();
        for(int i=0; i<sz; ++i){
            timescmb.push_back({times[i][0], times[i][1], i});
        }
        sort(timescmb.begin(), timescmb.end());
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>>occupiedSeats;
        priority_queue<int, vector<int>, greater<>>avlSeats;
        int ans=0;
        for(auto &vals: timescmb){
            int curfrnd=vals[2];
            int arrvT=vals[0];
            int deptT=vals[1];
            while(!occupiedSeats.empty()&&occupiedSeats.top().first<=arrvT){
                avlSeats.push(occupiedSeats.top().second);
                occupiedSeats.pop();
            }
            int seatTasgn=occupiedSeats.size(); 
            if(!avlSeats.empty()){
                seatTasgn=avlSeats.top();
                avlSeats.pop();
            }
            if(curfrnd==targetFriend){
                ans=seatTasgn;
                break;
            }
            occupiedSeats.push({deptT, seatTasgn});
        }
        return ans;
    }
};

// -------*******-------

class Solution2 {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        vector<vector<int>>arrvDeptCmb;
        int sz=times.size();
        int isArrival=1, isDeprt=0;
        /*
            Suppose array is [[1, 2], [2, 3], ...]
            new comb array will look like [[1, 1, 0], [2, 0, 0], [2, 1, 1], [3, 0, 1], ...]
            if a friend is leaving just after one minute and the next friend is also coming
            at the same minute, sorting will make sure that the departure subarray for the first
            friend comes first and later processing will free up his seat, so that it could be available
            for the next friend
        */
        for(int i=0; i<sz; ++i){
            arrvDeptCmb.push_back({times[i][0], isArrival, i});
            arrvDeptCmb.push_back({times[i][1], isDeprt, i});
        }
        sort(arrvDeptCmb.begin(), arrvDeptCmb.end());
        set<int>avlSeats;
        unordered_map<int, int>occupied;
        int curavlseat=0;
        for(auto &vals: arrvDeptCmb){
            if(vals[1]==1){
                if(avlSeats.size()>=1){
                    auto it=avlSeats.begin();
                    curavlseat=*it;
                    occupied[vals[2]]=curavlseat;
                    avlSeats.erase(it);
                } else{
                    curavlseat=occupied.size();
                    occupied[vals[2]]=curavlseat;
                }
            } else{
                int sttogv=occupied[vals[2]];
                occupied.erase(vals[2]);
                avlSeats.insert(sttogv);
            }
            if(vals[2]==targetFriend){
                return curavlseat;
            }
        }
        return -1;
    }
};