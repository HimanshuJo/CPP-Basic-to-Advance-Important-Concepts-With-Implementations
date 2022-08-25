#include <bits/stdc++.h>
using namespace std;

class StockRecord {
    public:
        int timestamp;
        int price;
    
    public:
        StockRecord(){}
};

struct custComp1{
    bool operator()(StockRecord& s1, StockRecord& s2){
        return s1.price<s2.price;
    }
};

struct custComp2{
    bool operator()(StockRecord& s1, StockRecord& s2){
        return s1.price>s2.price;
    }
};

class StockPrice {
public:
    map<int, int>mp;
    priority_queue<StockRecord, vector<StockRecord>, custComp1>maxPq;
    priority_queue<StockRecord, vector<StockRecord>, custComp2>minPq;
    StockRecord obj;
    StockPrice() {
        obj.price=0;
        obj.timestamp=0;
    }
    
    void update(int timestamp, int price) {
        if(timestamp>=obj.timestamp){
            obj.timestamp=timestamp;
            obj.price=price;
        }
        StockRecord sr;
        sr.timestamp=timestamp;
        sr.price=price;
        mp[timestamp]=price;
        maxPq.push(sr);
        minPq.push(sr);
    }
    
    int current() {
        return obj.price;
    }
    
    int maximum() {
        StockRecord sp;
        while(true){
            sp=maxPq.top();
            if(sp.price!=mp[sp.timestamp]){
                maxPq.pop();
            } else break;
        }
        return sp.price;
    }
    
    int minimum() {
        StockRecord sp;
        while(true){
            sp=minPq.top();
            if(sp.price!=mp[sp.timestamp]){
                minPq.pop();
            } else break;
        }
        return sp.price;
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