// 2402. Meeting Rooms III
/*
You are given an integer n. There are n rooms numbered from 0 to n - 1.

You are given a 2D integer array meetings where meetings[i] = [starti, endi] means that a meeting will 
be held during the half-closed time interval [starti, endi). All the values of starti are unique.

Meetings are allocated to rooms in the following manner:

Each meeting will take place in the unused room with the lowest number.
If there are no available rooms, the meeting will be delayed until a room becomes free. 
The delayed meeting should have the same duration as the original meeting.
When a room becomes unused, meetings that have an earlier original start time should be given the room.

Return the number of the room that held the most meetings. If there are multiple rooms, return the 
room with the lowest number.

A half-closed interval [a, b) is the interval between a and b including a and not including b.

Example 1:

Input: n = 2, meetings = [[0,10],[1,5],[2,7],[3,4]]
Output: 0
Explanation:
- At time 0, both rooms are not being used. The first meeting starts in room 0.
- At time 1, only room 1 is not being used. The second meeting starts in room 1.
- At time 2, both rooms are being used. The third meeting is delayed.
- At time 3, both rooms are being used. The fourth meeting is delayed.
- At time 5, the meeting in room 1 finishes. The third meeting starts in room 1 for the time period [5,10).
- At time 10, the meetings in both rooms finish. The fourth meeting starts in room 0 for the time period [10,11).
Both rooms 0 and 1 held 2 meetings, so we return 0. 
Example 2:

Input: n = 3, meetings = [[1,20],[2,10],[3,5],[4,9],[6,8]]
Output: 1
Explanation:
- At time 1, all three rooms are not being used. The first meeting starts in room 0.
- At time 2, rooms 1 and 2 are not being used. The second meeting starts in room 1.
- At time 3, only room 2 is not being used. The third meeting starts in room 2.
- At time 4, all three rooms are being used. The fourth meeting is delayed.
- At time 5, the meeting in room 2 finishes. The fourth meeting starts in room 2 for the time period [5,10).
- At time 6, all three rooms are being used. The fifth meeting is delayed.
- At time 10, the meetings in rooms 1 and 2 finish. The fifth meeting starts in room 1 for the time period [10,12).
Room 0 held 1 meeting while rooms 1 and 2 each held 2 meetings, so we return 1. 
 

Constraints:

1 <= n <= 100
1 <= meetings.length <= 10^5
meetings[i].length == 2
0 <= starti < endi <= 5 * 10^5
All the values of starti are unique.
*/

struct custComp{
    bool operator()(const vector<long long>&A, const vector<long long>&B){
        return A[0]==B[0]?A[1]>B[1]:A[0]>B[0];
    }  
};

class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        int sz=meetings.size();
        vector<vector<int>>allcombs;
        for(int i=0; i<sz; ++i){
            vector<int>temp;
            temp.push_back(meetings[i][0]);
            temp.push_back(meetings[i][1]);
            temp.push_back(i);
            allcombs.push_back(temp);
        }
        sort(allcombs.begin(), allcombs.end());
        priority_queue<int, vector<int>, greater<>>avlroms;
        for(int i=0; i<n; ++i){
            avlroms.push(i);
        }
        unordered_map<int, set<long long>>rmsmeets;
        priority_queue<vector<long long>, vector<vector<long long>>, custComp>curgmeetngs;
        vector<long long>ans(n+1, 0);
        for(int i=0; i<sz; ++i){
            if(!curgmeetngs.empty()){
                while(true){
                    if(!curgmeetngs.empty()){
                        vector<long long>curr=curgmeetngs.top();
                        if(curr[0]<=allcombs[i][0]){
                            curgmeetngs.pop();
                            int currm=curr[1];
                            long long cursz=rmsmeets[currm].size();
                            ans[currm]=max(ans[currm], cursz);
                            avlroms.push(currm);
                        } else break;    
                    } else break;  
                }
            }
            if(!avlroms.empty()){
                int currm=avlroms.top();
                avlroms.pop();
                rmsmeets[currm].insert(allcombs[i][2]);
                long long cursz=rmsmeets[currm].size();
                ans[currm]=max(ans[currm], cursz);
                vector<long long>temp;
                temp.push_back(allcombs[i][1]);
                temp.push_back(currm);
                temp.push_back(allcombs[i][2]);
                curgmeetngs.push(temp);
            } else{
                if(!curgmeetngs.empty()){
                    vector<long long>curr=curgmeetngs.top();
                    curgmeetngs.pop();
                    int currm_=curr[1];
                    avlroms.push(currm_);
                    int currm=avlroms.top();
                    avlroms.pop();
                    rmsmeets[currm].insert(allcombs[i][2]);
                    long long cursz=rmsmeets[currm].size();
                    ans[currm]=max(ans[currm], cursz);
                    long long curt=curr[0];
                    curt+=(allcombs[i][1]-allcombs[i][0]);
                    vector<long long>temp;
                    temp.push_back(curt);
                    temp.push_back(currm);
                    temp.push_back(allcombs[i][2]);
                    curgmeetngs.push(temp);
                }
            }
        }
        vector<long long>temp__=ans;
        sort(temp__.begin(), temp__.end(), greater<long long>());
        long long bggst=temp__[0];
        int fnans=0;
        for(int i=0; i<n; ++i){
            if(ans[i]==bggst){
                fnans=i;
                break;
            }
        }
        return fnans;
    }
};