// 2327. Number of People Aware of a Secret
/*
On day 1, one person discovers a secret.

You are given an integer delay, which means that each person will share the secret with a 
new person every day, starting from delay days after discovering the secret. 

You are also given an integer forget, which means that each person will forget the secret forget 
days after discovering it. A person cannot share the secret on the same day they forgot it, or on any day afterwards.

Given an integer n, return the number of people who know the secret at the end of day n. 
Since the answer may be very large, return it modulo 109 + 7.

Example 1:

Input: n = 6, delay = 2, forget = 4
Output: 5
Explanation:
Day 1: Suppose the first person is named A. (1 person)
Day 2: A is the only person who knows the secret. (1 person)
Day 3: A shares the secret with a new person, B. (2 people)
Day 4: A shares the secret with a new person, C. (3 people)
Day 5: A forgets the secret, and B shares the secret with a new person, D. (3 people)
Day 6: B shares the secret with E, and C shares the secret with F. (5 people)
Example 2:

Input: n = 4, delay = 1, forget = 3
Output: 6
Explanation:
Day 1: The first person is named A. (1 person)
Day 2: A shares the secret with B. (2 people)
Day 3: A and B share the secret with 2 new people, C and D. (4 people)
Day 4: A forgets the secret. B, C, and D share the secret with 3 new people. (6 people)
 

Constraints:

2 <= n <= 1000
1 <= delay < forget <= n
*/

/*

TLE: 10 / 82

class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        vector<pair<char, int>>pers;
        char bgn='a';
        pers.push_back({bgn, 1});
        int t=1;
        while(true){
            t++;
            vector<pair<char, int>>toad;
            for(auto &vals: pers){
                vals.second++;
                if(vals.second>forget){
                    vals.first='#', vals.second=-1;
                } else if(vals.second>delay){
                    char nw=bgn+1;
                    toad.push_back({nw, 1});
                    bgn++;
                }
            }
            pair<char, int>tmp={'#', -1};
            pers.erase(remove(pers.begin(), pers.end(), tmp), pers.end());
            for(auto &vals: toad){
                pers.push_back(vals);
            }
            if(t==n) break;
        }
        return pers.size();
    }
};
*/

class Solution {
public:
    
    int mod=1e9+7;
    
    int dfs(int day, int n, int delay, int forget, vector<int>&memo){
        if(memo[day]!=-1) return memo[day];
        int ans=1;
        if(day+forget<=n) ans--;
        for(int i=day+delay; i<(min(n+1, day+forget)); ++i){
            ans+=dfs(i, n, delay, forget, memo);
            ans%=mod;
        }
        return memo[day]=ans%mod;
    }
    
    int peopleAwareOfSecret(int n, int delay, int forget) {
        vector<int>memo(1001, -1);
        return dfs(1, n, delay, forget, memo);
    }
};