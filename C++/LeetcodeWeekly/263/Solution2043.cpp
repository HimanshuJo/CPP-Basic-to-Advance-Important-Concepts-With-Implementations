#include<bits/stdc++.h>
using namespace std;

class Bank {
public:
    map<int, long long>accnts;
    Bank(vector<long long>& balance) {
        for(int i=0; i<balance.size(); ++i){
            accnts[i+1]=balance[i];
        }
    }
    
    bool transfer(int account1, int account2, long long money) {
        auto it1=accnts.find(account1);
        auto it2=accnts.find(account2);
        if(it1==accnts.end()||it2==accnts.end()) return false;
        long long currMn=accnts[account1];
        if(currMn>=money){
            accnts[account1]-=money;
            accnts[account2]+=money;
            return true;
        }
        return false;
    }
    
    bool deposit(int account, long long money) {
        auto it=accnts.find(account);
        if(it!=accnts.end()){
            accnts[account]+=money;
            return true;
        }
        return false;
    }
    
    bool withdraw(int account, long long money) {
        auto it=accnts.find(account);
        if(it!=accnts.end()){
            long long currMn=accnts[account];
            if(currMn>=money){
                accnts[account]-=money;
                return true;
            } else{
                return false;
            }
        }
        return false;
    }
};

/**
 * Your Bank object will be instantiated and called as such:
 * Bank* obj = new Bank(balance);
 * bool param_1 = obj->transfer(account1,account2,money);
 * bool param_2 = obj->deposit(account,money);
 * bool param_3 = obj->withdraw(account,money);
 */