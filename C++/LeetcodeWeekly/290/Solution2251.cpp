//2251. Number of Flowers in Full Bloom
/*
You are given a 0-indexed 2D integer array flowers, where flowers[i] = [starti, endi] 
means the ith flower will be in full bloom from starti to endi (inclusive). 

You are also given a 0-indexed integer array persons of size n, where persons[i] is the time 
that the ith person will arrive to see the flowers.

Return an integer array answer of size n, where answer[i] is the number of flowers 
that are in full bloom when the ith person arrives.

Input: flowers = [[1,6],[3,7],[9,12],[4,13]], persons = [2,3,7,11]
Output: [1,2,2,2]
Explanation: The figure above shows the times when the flowers are in full bloom and when the people arrive.
For each person, we return the number of flowers in full bloom during their arrival.

Input: flowers = [[1,10],[3,3]], persons = [3,3,2]
Output: [2,2,1]
Explanation: The figure above shows the times when the flowers are in full bloom and when the people arrive.
For each person, we return the number of flowers in full bloom during their arrival.

Constraints:

1 <= flowers.length <= 5 * 10^4
flowers[i].length == 2
1 <= starti <= endi <= 10^9
1 <= persons.length <= 5 * 10^4
1 <= persons[i] <= 10^9
*/
/*
Solution2:

class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& persons) {
        map<int, int>mp;
        for(auto &f: flowers){
            mp[f[0]]++, mp[f[1]+1]--;
        }
        for(auto sum=0; auto &[k, v]: mp){
            v=(sum+=v);
        }
        for(auto &p: persons){
            auto it=mp.upper_bound(p);
            if(it==mp.begin()){
                p=0;
            } else{
                p=prev(it)->second;
            }
        }
        return persons;
    }
};
*/

/*
Solution3:

class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& persons) {
        int sz=persons.size();
        vector<int>startf, endf;
        for(auto &vals: flowers){
            startf.push_back(vals[0]);
            endf.push_back(vals[1]);
        }
        sort(startf.begin(), startf.end());
        sort(endf.begin(), endf.end());
        vector<int>res(sz, 0);
        int idx=0;
        for(auto &p: persons){
            int startv=upper_bound(startf.begin(), startf.end(), p)-startf.begin();
            int endv=lower_bound(endf.begin(), endf.end(), p)-endf.begin();
            res[idx++]=startv-endv;
        }
        return res;
    }
};
*/

struct Event{
    int startT;
    bool isStartOfT;
    
    Event(int strtT, bool isST){
        startT=strtT;
        isStartOfT=isST;
    }
};

struct custComp{
    bool operator()(Event &A, Event &B){
        return (A.startT==B.startT?!A.isStartOfT:A.startT>B.startT);
    }
};

class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& persons) {
        vector<int>pCpy=persons;
        sort(persons.begin(), persons.end());
        priority_queue<Event, vector<Event>, custComp>pq;
        for(vector<int>&f: flowers){
            pq.push(Event(f[0], true));
            pq.push(Event(f[1], false));
        }
        unordered_map<int, int>mp;
        int count=0;
        int sz=persons.size();
        for(int i=0; i<sz; ++i){
            int time=persons[i];
            while(pq.size()>0&&(pq.top().startT<time||(pq.top().startT==time&&pq.top().isStartOfT))){
                if(pq.top().isStartOfT){
                    count++;
                } else{
                    count--;
                }
                pq.pop();
            }
            mp[time]=count;
        }
        for(auto &p: pCpy){
            p=mp[p];
        }
        return pCpy;
    }
};