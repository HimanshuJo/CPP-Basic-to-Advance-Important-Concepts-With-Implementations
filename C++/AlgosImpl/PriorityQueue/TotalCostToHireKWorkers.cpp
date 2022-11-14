// 2462. Total Cost to Hire K Workers
/*
You are given a 0-indexed integer array costs where costs[i] is the cost of hiring the ith worker.

You are also given two integers k and candidates. We want to hire exactly k workers according to the following rules:

You will run k sessions and hire exactly one worker in each session.
In each hiring session, choose the worker with the lowest cost from either the first candidates workers 
or the last candidates workers. Break the tie by the smallest index.

For example, if costs = [3,2,7,7,1,2] and candidates = 2, then in the first hiring session, we will choose the 4th worker because they have the lowest cost [3,2,7,7,1,2].

In the second hiring session, we will choose 1st worker because they have the same lowest cost as 4th worker 
but they have the smallest index [3,2,7,7,2]. Please note that the indexing may be changed in the process.

If there are fewer than candidates workers remaining, choose the worker with the lowest cost among them. 
Break the tie by the smallest index.
A worker can only be chosen once.
Return the total cost to hire exactly k workers.

Example 1:

Input: costs = [17,12,10,2,7,2,11,20,8], k = 3, candidates = 4
Output: 11
Explanation: We hire 3 workers in total. The total cost is initially 0.
- In the first hiring round we choose the worker from [17,12,10,2,7,2,11,20,8]. The lowest cost is 2, and we break the tie by the smallest index, which is 3. The total cost = 0 + 2 = 2.
- In the second hiring round we choose the worker from [17,12,10,7,2,11,20,8]. The lowest cost is 2 (index 4). The total cost = 2 + 2 = 4.
- In the third hiring round we choose the worker from [17,12,10,7,11,20,8]. The lowest cost is 7 (index 3). The total cost = 4 + 7 = 11. Notice that the worker with index 3 was common in the first and last four workers.
The total hiring cost is 11.

Example 2:

Input: costs = [1,2,4,1], k = 3, candidates = 3
Output: 4
Explanation: We hire 3 workers in total. The total cost is initially 0.
- In the first hiring round we choose the worker from [1,2,4,1]. The lowest cost is 1, and we break the tie by the smallest index, which is 0. The total cost = 0 + 1 = 1. Notice that workers with index 1 and 2 are common in the first and last 3 workers.
- In the second hiring round we choose the worker from [2,4,1]. The lowest cost is 1 (index 2). The total cost = 1 + 1 = 2.
- In the third hiring round there are less than three candidates. We choose the worker from the remaining workers [2,4]. The lowest cost is 2 (index 0). The total cost = 2 + 2 = 4.
The total hiring cost is 4.
 

Constraints:

1 <= costs.length <= 10^5 
1 <= costs[i] <= 10^5
1 <= k, candidates <= costs.length
*/

struct custComp{
    bool operator()(const pair<int, int>&A, const pair<int, int>&B){
        return A.first==B.first?A.second>B.second:A.first>B.first;
    }
};

class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, custComp>pq1;
        priority_queue<pair<int, int>, vector<pair<int, int>>, custComp>pq2;
        vector<pair<int, int>>tmp;
        set<int>tmpseen;
        int sz=costs.size(), count1=candidates, count2=candidates;
        int i=0, j=sz-1;
        for(; i<sz; ++i){
            if(count1==0) break;
            if(tmpseen.find(i)==tmpseen.end()){
                pq1.push({costs[i], i});
                count1--;
                tmpseen.insert(i);   
            }
        }
        for(; j>=0; --j){
            if(count2==0) break;
            if(tmpseen.find(j)==tmpseen.end()){
                pq2.push({costs[j], j});
                count2--;   
                tmpseen.insert(j);
            }
        }
        for(int ii=i; ii<=j; ++ii){
            if(tmpseen.find(ii)==tmpseen.end()){
                tmp.push_back({costs[ii], ii});
            }
        }
        long long ans=0;
        set<int>seen;
        int idx=0, idx2=tmp.size()-1;
        while(true){
            bool flag=false;
            long long csttoadd=-1;
            pair<int, int>curr1, curr2;
            if(!pq1.empty())
                curr1=pq1.top();
            if(!pq2.empty())
                curr2=pq2.top();
            if(!pq1.empty()&&!pq2.empty()&&curr1.first!=curr2.first){
                if(curr1.first<curr2.first){
                    if(seen.find(curr1.second)==seen.end()){
                        seen.insert(curr1.second);
                        csttoadd=curr1.first;
                        pq1.pop();
                        flag=true;
                    } else{
                        pq1.pop();
                    }
                } else{
                    if(seen.find(curr2.second)==seen.end()){
                        seen.insert(curr2.second);
                        csttoadd=curr2.first;
                        pq2.pop();
                        flag=true;
                    } else{
                        pq2.pop();
                    }
                }
            } else if(!pq1.empty()&&!pq2.empty()&&curr1.first==curr2.first){
                if(curr1.second<curr2.second){
                    if(seen.find(curr1.second)==seen.end()){
                        seen.insert(curr1.second);
                        csttoadd=curr1.first;
                        pq1.pop();
                        flag=true;
                    } else{
                        pq1.pop();
                    }
                } else{
                    if(seen.find(curr2.second)==seen.end()){
                        seen.insert(curr2.second);
                        csttoadd=curr2.first;
                        pq2.pop();
                        flag=true;
                    } else{
                        pq2.pop();
                    }
                }
            }
            if(csttoadd==-1){
                if(pq1.empty()&&!pq2.empty()){
                    if(seen.find(pq2.top().second)==seen.end()){
                        seen.insert(pq2.top().second);
                        csttoadd=pq2.top().first;
                        pq2.pop();
                        flag=true;
                    } else{
                        pq2.pop();
                    }
                } else{
                    if(!pq1.empty()&&pq2.empty()){
                        if(seen.find(pq1.top().second)==seen.end()){
                            seen.insert(pq1.top().second);
                            csttoadd=pq1.top().first;
                            pq1.pop();
                            flag=true;
                        } else{
                            pq1.pop();
                        }
                    }
                }
            }
            if(csttoadd!=-1)
                ans+=csttoadd;
            if(flag) k--;
            if(k==0) break;
            if(pq1.size()!=candidates){
                if(!tmp.empty()){
                    while(pq1.size()!=candidates&&idx<=tmp.size()-1){
                        auto it=tmp.begin()+idx;
                        pq1.push(*it);
                        idx++;
                    }
                }
            }
            if(pq2.size()!=candidates){
                if(!tmp.empty()){
                    while(pq2.size()!=candidates&&!tmp.empty()&&idx2>=0){
                        auto it=tmp.begin()+idx2;
                        pq2.push(*it);
                        idx2--;
                    }
                }
            }
        }
        return ans;
    }
};