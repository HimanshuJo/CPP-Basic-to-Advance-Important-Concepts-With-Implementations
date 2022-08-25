#include <bits/stdc++.h>
using namespace std;

struct custComp1{
    bool operator()(pair<int, int>&s1, pair<int, int>& s2){
        return s1.first<s2.first;
    }
};

struct custComp2{
    bool operator()(pair<int, int>& s1, pair<int, int>& s2){
        return s1.first>s2.first;
    }
};


class StockPrice {
public:
    int price;
    int timestamp;
    map<int, int>mp;
    priority_queue<pair<int, int>, vector<pair<int, int>>>maxPq; // or custComp1
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>>minPq; // or custComp2
    StockPrice() {
        price=0;
        timestamp=0;
    }
    
    void update(int timestamp, int price) {
        mp[timestamp]=price;
        maxPq.push({price, timestamp});
        minPq.push({price, timestamp});
    }
    
    int current() {
        return mp.rbegin()->second;
    }
    
    int maximum() {
        int ans=0;
        while(true){
            auto sp=maxPq.top();
            int currTmstp=sp.second;
            if(sp.first!=mp[currTmstp]){
                maxPq.pop();
            } else if(sp.first==mp[currTmstp]){
                ans=sp.first;
                break;
            }
        }
        return ans;
    }
    
    int minimum() {
        int ans=0;
        while(true){
            auto sp=minPq.top();
            int currTmstp=sp.second;
            if(sp.first!=mp[currTmstp]){
                minPq.pop();
            } else if(sp.first==mp[currTmstp]){
                ans=sp.first;
                break;
            }
        }
        return ans;
    }
};

/**
 * Your StockPrice object will be instantiated and called as such:
 * StockPrice* obj = new StockPrice();
 * obj->update(timestamp,price);
 * int param_2 = obj->current();
 * int param_3 = obj->maximum();
 * int param_4 = obj->minimum();
 */