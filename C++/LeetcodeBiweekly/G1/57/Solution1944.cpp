// 1944. Number of Visible People in a Queue
/*
There are n people standing in a queue, and they numbered from 0 to n - 1 
in left to right order. You are given an array heights of distinct integers 
where heights[i] represents the height of the ith person.

A person can see another person to their right in the queue if everybody in 
between is shorter than both of them. More formally, the ith person can see the 
jth person if i < j and min(heights[i], heights[j]) > max(heights[i+1], heights[i+2], 
..., heights[j-1]).

Return an array answer of length n where answer[i] is the number of people the 
ith person can see to their right in the queue.

Input: heights = [10,6,8,5,11,9]
Output: [3,1,2,1,1,0]
Explanation:
Person 0 can see person 1, 2, and 4.
Person 1 can see person 2.
Person 2 can see person 3 and 4.
Person 3 can see person 4.
Person 4 can see person 5.
Person 5 can see no one since nobody is to the right of them.
*/

/*
TLE: 31 / 42 

class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& heights) {
        stack<int>stk;
        int sz=heights.size();
        vector<int>ans(sz, 0);
        for(int i=sz-1; i>=0; --i){
            int curans=0;
            if(stk.size()>=1){
                int curr=stk.top();
                stack<int>tmpstk=stk;
                while(!tmpstk.empty()){
                    int currtp=tmpstk.top();
                    if(curr<=currtp){
                        curans++;
                        curr=currtp;
                        if(curr>heights[i]) break;
                    }
                    tmpstk.pop();
                }
            }
            ans[i]=curans;
            stk.push(heights[i]);
        }
        return ans;
    }
};
*/

class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& heights) {
        int sz=heights.size();
        vector<int>res(sz, 0);
        stack<int>stk;
        for(int i=0; i<sz; ++i){
            while(!stk.empty()&&heights[stk.top()]<=heights[i]){
                res[stk.top()]++;
                stk.pop();
            }
            if(!stk.empty()){
                res[stk.top()]++;
            }
            stk.push(i);
        }
        return res;
    }
};