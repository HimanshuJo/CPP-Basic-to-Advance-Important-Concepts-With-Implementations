// 2043. Simple Bank System
/*
You have been tasked with writing a program for a popular bank that will automate all 
its incoming transactions (transfer, deposit, and withdraw). 

The bank has n accounts numbered from 1 to n. The initial balance of each account is 
stored in a 0-indexed integer array balance, with the (i + 1)th account having an initial balance of balance[i].

Execute all the valid transactions. A transaction is valid if:

The given account number(s) are between 1 and n, and
The amount of money withdrawn or transferred from is less than or equal to the balance of the account.
Implement the Bank class:

Bank(long[] balance) 

    Initializes the object with the 0-indexed integer array balance.

boolean transfer(int account1, int account2, long money) 

    Transfers money dollars from the account numbered account1 to the account numbered account2. 
    
    Return true if the transaction was successful, false otherwise.

boolean deposit(int account, long money) 

    Deposit money dollars into the account numbered account. 
    
    Return true if the transaction was successful, false otherwise.

boolean withdraw(int account, long money) 

    Withdraw money dollars from the account numbered account. 
    
    Return true if the transaction was successful, false otherwise.
*/

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