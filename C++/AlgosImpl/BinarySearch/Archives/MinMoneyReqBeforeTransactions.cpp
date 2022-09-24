// 2412. Minimum Money Required Before Transactions
/*
You are given a 0-indexed 2D integer array transactions, where transactions[i] = [costi, cashbacki].

The array describes transactions, where each transaction must be completed exactly once in some order. 
At any given moment, you have a certain amount of money. In order to complete transaction i, money >= costi 
must hold true. After performing a transaction, money becomes money - costi + cashbacki.

Return the minimum amount of money required before any transaction so that all of the transactions can be 
completed regardless of the order of the transactions.

Example 1:

Input: transactions = [[2,1],[5,0],[4,2]]
Output: 10
Explanation:
Starting with money = 10, the transactions can be performed in any order.
It can be shown that starting with money < 10 will fail to complete all transactions in some order.
Example 2:

Input: transactions = [[3,0],[0,3]]
Output: 3
Explanation:
- If transactions are in the order [[3,0],[0,3]], the minimum money required to complete the transactions is 3.
- If transactions are in the order [[0,3],[3,0]], the minimum money required to complete the transactions is 0.
Thus, starting with money = 3, the transactions can be performed in any order.
 

Constraints:

1 <= transactions.length <= 10^5
transactions[i].length == 2
0 <= costi, cashbacki <= 10^9
*/

class Solution {
public:
    
    bool isValid(long long mid, long long sm, vector<vector<int>>&transactions){
        for(auto &vals: transactions){
            if(mid-sm<vals[0]-vals[1]){
                return false;
            }
        }
        return true;
    }
    
    long long minimumMoney(vector<vector<int>>& transactions) {
        sort(transactions.begin(), transactions.end());
        long long left=0, right=2e18;
        long long ans=0;
        long long sm=0;
        for(auto &vals: transactions){
            long long curmax=max((long long)0, (long long) vals[0]-vals[1]);
            vals[1]=curmax;
            sm+=curmax;
        }
        while(left<=right){
            long long mid=left+(right-left)/2;
            if(isValid(mid, sm, transactions)){
                ans=mid;
                right=mid-1;
            } else{
                left=mid+1;
            }
        }
        return ans;
    }
};

// -------*******-------

struct custComp{
    bool operator()(const vector<int>&A, const vector<int>&B){
        int opt1=min(-A[0], -A[0]+A[1]-B[0]);
        int opt2=min(-B[0], -B[0]+B[1]-A[0]);
        if(opt1<opt2) return true;
        if(opt1>opt2) return false;
        return A[0]>B[0];
    }
};

class Solution2 {
public:
    
    bool isValid(long long mid, vector<vector<int>>&transactions){
        for(auto &vals: transactions){
            if(mid<vals[0]) return false;
            mid=mid-vals[0]+vals[1];
            if(mid<0) return false;
        }
        return true;
    }
    
    long long minimumMoney(vector<vector<int>>& transactions) {
        sort(transactions.begin(), transactions.end(), custComp());
        long long left=0, right=2e18;
        long long ans=0;
        while(left<=right){
            long long mid=left+(right-left)/2;
            if(isValid(mid, transactions)){
                ans=mid;
                right=mid-1;
            } else{
                left=mid+1;
            }
        }
        return ans;
    }
};