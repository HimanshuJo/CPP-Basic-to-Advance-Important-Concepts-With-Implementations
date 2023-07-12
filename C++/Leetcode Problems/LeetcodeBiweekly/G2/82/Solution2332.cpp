// 2332. The Latest Time to Catch a Bus
/*
You are given a 0-indexed integer array buses of length n, where buses[i] represents 
the departure time of the ith bus. You are also given a 0-indexed integer array 
passengers of length m, where passengers[j] represents the arrival time of the jth passenger. 

All bus departure times are unique. All passenger arrival times are unique.

You are given an integer capacity, which represents the maximum number of passengers that can get on each bus.

The passengers will get on the next available bus. You can get on a bus that will depart 
at x minutes if you arrive at y minutes where y <= x, and the bus is not full. 

Passengers with the earliest arrival times get on the bus first.

Return the latest time you may arrive at the bus station to catch a bus. You cannot 
arrive at the same time as another passenger.

Note: The arrays buses and passengers are not necessarily sorted.


Example 1:

Input: buses = [10,20], passengers = [2,17,18,19], capacity = 2
Output: 16
Explanation: 
The 1st bus departs with the 1st passenger. 
The 2nd bus departs with you and the 2nd passenger.
Note that you must not arrive at the same time as the passengers, 
which is why you must arrive before the 2nd passenger to catch the bus.

Example 2:

Input: buses = [20,30,10], passengers = [19,13,26,4,25,11,21], capacity = 2
Output: 20
Explanation: 
The 1st bus departs with the 4th passenger. 
The 2nd bus departs with the 6th and 2nd passengers.
The 3rd bus departs with the 1st passenger and you.
 

Constraints:

n == buses.length
m == passengers.length
1 <= n, m, capacity <= 10^5
2 <= buses[i], passengers[i] <= 10^9
Each element in buses is unique.
Each element in passengers is unique
*/

/*
TLE: 42 / 63

class Solution {
public:
    
    bool isValid(vector<int>&buses, vector<int>&passengers, int capacity, int mid){
        passengers.push_back(mid);
        sort(passengers.begin(), passengers.end());
        for(int i=0; i<buses.size(); ++i){
            int temp=capacity;
            for(int j=0; j<passengers.size(); ++j){
                if(passengers[j]<=buses[i]){
                    temp--;
                    passengers[j]=-1;
                    if(temp==0) break;
                }
            }
            passengers.erase(remove(passengers.begin(), passengers.end(), -1), passengers.end());
        }
        for(auto &vals: passengers){
            if(vals==mid) return false;
        }
        return true;
    }
    
    int latestTimeCatchTheBus(vector<int>& buses, vector<int>& passengers, int capacity) {
        sort(buses.begin(), buses.end());
        sort(passengers.begin(), passengers.end());
        int sz1=buses.size(), sz2=passengers.size();
        int left=buses[0], right=buses[sz1-1];
        int ans=1;
        vector<int>temp_;
        unordered_map<int, int>mp;
        for(auto &vals: passengers){
            mp[vals]=vals;
        }
        for(int i=1; i<=right; ++i){
            auto it=mp.find(i);
            if(it==mp.end()){
                temp_.push_back(i);
            }
        }
        int sz_=temp_.size();
        left=0, right=sz_-1;
        while(left<=right){
            int mid=left+(right-left)/2;
            vector<int>temp=passengers;
            if(isValid(buses, temp, capacity, temp_[mid])){
                ans=temp_[mid];
                left=mid+1;
            } else{
                right=mid-1;
            }   
        }
        if(ans==passengers[passengers.size()-1]-1){
            if(passengers[passengers.size()-1]<buses[buses.size()-1]){
                if(capacity>passengers.size())
                    ans=buses[buses.size()-1]; 
            }
        }
        return ans;
    }
};
*/

// TC: O(N*M)  N: buses length, M: passengers length
class Solution1 {
public:
    int latestTimeCatchTheBus(vector<int>& buses, vector<int>& passengers, int capacity) {
        sort(buses.begin(), buses.end());
        sort(passengers.begin(), passengers.end());
        queue<int>q;
        set<int>st;
        for(auto &vals: passengers){
            st.insert(vals);
            q.push(vals);
        }
        int ans=0;
        for(auto &vals: buses){
            int curbus=vals;
            int cap=0;
            int temp;
            while(!q.empty()&&cap<capacity&&q.front()<=vals){
                temp=q.front();
                q.pop();
                auto it=st.find(temp-1);
                if(it==st.end()){
                    ans=temp-1;
                }
                cap++;
            }
            if(cap<capacity){
                while(true){
                    auto it=st.find(curbus);
                    if(it==st.end()) break;
                    curbus--;
                }
                ans=max(ans, curbus);
            }
        }
        return ans;
    }
};

// -------*******-------

class Solution2 {
public:
    int latestTimeCatchTheBus(vector<int>& buses, vector<int>& passengers, int capacity) {
        sort(buses.begin(), buses.end());
        sort(passengers.begin(), passengers.end());
        set<int>st;
        for(auto &vals: passengers){
            st.insert(vals);
        }
        int ans=0;
        int i=0;
        for(auto &vals: buses){
            int curbus=vals;
            int cap=0;
            while(i<=passengers.size()-1&&cap<capacity&&passengers[i]<=curbus){
                auto it=st.find(passengers[i]-1);
                if(it==st.end()){
                    ans=passengers[i]-1;
                }
                i++;
                cap++;
            }
            if(cap<capacity){
                while(true){
                    auto it=st.find(curbus);
                    if(it==st.end()) break;
                    curbus--;
                }
                ans=max(ans, curbus);
            }
        }
        return ans;
    }
};