// 2080. Range Frequency Queries
/*
Design a data structure to find the frequency of a given value in a given subarray.

The frequency of a value in a subarray is the number of occurrences of that value in the subarray.

Implement the RangeFreqQuery class:

RangeFreqQuery(int[] arr) Constructs an instance of the class with the given 0-indexed integer array arr.
int query(int left, int right, int value) Returns the frequency of value in the subarray arr[left...right].

A subarray is a contiguous sequence of elements within an array. arr[left...right] 
denotes the subarray that contains the elements of nums between indices left and right (inclusive).

Example 1:

Input
["RangeFreqQuery", "query", "query"]
[[[12, 33, 4, 56, 22, 2, 34, 33, 22, 12, 34, 56]], [1, 2, 4], [0, 11, 33]]
Output
[null, 1, 2]

Explanation
RangeFreqQuery rangeFreqQuery = new RangeFreqQuery([12, 33, 4, 56, 22, 2, 34, 33, 22, 12, 34, 56]);
rangeFreqQuery.query(1, 2, 4); // return 1. The value 4 occurs 1 time in the subarray [33, 4]
rangeFreqQuery.query(0, 11, 33); // return 2. The value 33 occurs 2 times in the whole array.
 

Constraints:

1 <= arr.length <= 10^5
1 <= arr[i], value <= 10^4
0 <= left <= right < arr.length
At most 10^5 calls will be made to query
*/

/*
Solution2:

#include<vector>
#include<map>
using namespace std;

class RangeFreqQuery {
public:
    unordered_map<int, vector<int>>mp;
    RangeFreqQuery(vector<int>& arr) {
        for(int i=0; i<arr.size(); ++i){
            mp[arr[i]].push_back(i);
        }
    }
    
    int query(int left, int right, int value) {
        int a=lower_bound(mp[value].begin(), mp[value].end(), left)-mp[value].begin();
        int b=upper_bound(mp[value].begin(), mp[value].end(), right)-mp[value].begin();
        return b-a;
    }
};

*/

class RangeFreqQuery {
public:
    
    int n;
    map<int, int> segTree[400001];
    
    int getMid(int left, int right){
        return (left+(right-left)/2);
    }
    
    int queryUtil(int ss, int se, int qs, int qe, int sidx, int value){
        if(ss>qe||se<qs) return 0;
        if(ss>=qs&&se<=qe){
            return segTree[sidx][value];
        }
        int mid=getMid(ss, se);
        int ans=0;
        ans+=queryUtil(ss, mid, qs, qe, 2*sidx+1, value);
        ans+=queryUtil(mid+1, se, qs, qe, 2*sidx+2, value);
        return ans;
    }
    
    void constructSt(vector<int>&arr, int ss, int se, int sidx){
        if(ss==se){
            segTree[sidx][arr[ss]]=1;
            return;
        }
        int mid=getMid(ss, se);
        constructSt(arr, ss, mid, 2*sidx+1);
        constructSt(arr, mid+1, se, 2*sidx+2);
        segTree[sidx]=segTree[2*sidx+1];
        for(auto it: segTree[2*sidx+2]){
            segTree[sidx][it.first]+=it.second;
        }
    }
    
    RangeFreqQuery(vector<int>& arr) {
       n=arr.size();
       int ss=0, se=n, sidx=0;
       constructSt(arr, ss, se, sidx);
    }
    
    int query(int left, int right, int value) {
        int ss=0, se=n, qs=left, qe=right, sidx=0;
        int ans=queryUtil(ss, se, qs, qe, sidx, value);
        return ans;
    }
};

/**
 * Your RangeFreqQuery object will be instantiated and called as such:
 * RangeFreqQuery* obj = new RangeFreqQuery(arr);
 * int param_1 = obj->query(left,right,value);
 */