// 1735. Count Ways to Make Array With Product
/*
You are given a 2D integer array, queries. For each queries[i], where queries[i] = [ni, ki], 
find the number of different ways you can place positive integers into an array of size ni such 
that the product of the integers is ki. As the number of ways may be too large, the answer to the ith query is 
the number of ways modulo 109 + 7.

Return an integer array answer where answer.length == queries.length, and answer[i] is the answer to the ith query.

Example 1:

Input: queries = [[2,6],[5,1],[73,660]]
Output: [4,1,50734910]
Explanation: Each query is independent.
[2,6]: There are 4 ways to fill an array of size 2 that multiply to 6: [1,6], [2,3], [3,2], [6,1].
[5,1]: There is 1 way to fill an array of size 5 that multiply to 1: [1,1,1,1,1].
[73,660]: There are 1050734917 ways to fill an array of size 73 that multiply to 660. 1050734917 modulo 109 + 7 = 50734910.
Example 2:

Input: queries = [[1,1],[2,2],[3,3],[4,4],[5,5]]
Output: [1,2,3,10,5]
 

Constraints:

1 <= queries.length <= 10^4
1 <= ni, ki <= 10^4
*/

class Solution {
public:
    
    int spf[10001], mod=1e9+7, MAXN=10001;
    
    void sieve(){
        spf[1]=1;
        for(int i=2; i<MAXN; ++i)
            spf[i]=i;
        for(int i=4; i<MAXN; i+=2)
            spf[i]=2;
        for(int i=3; i*i<MAXN; ++i){
            if(spf[i]==i){
                for(int j=i*i; j<MAXN; j+=i){
                    if(spf[j]==j){
                        spf[j]=i;
                    }
                }
            }
        }
    }
    
    vector<int>getFactors(int x){
        vector<int>factors;
        unordered_map<int, int>freqs;
        while(x!=1){
            freqs[spf[x]]++;
            x/=spf[x];
        }
        for(auto &entries: freqs){
            factors.push_back(entries.second);
        }
        return factors;
    }
    
    vector<int> waysToFillArray(vector<vector<int>>& queries) {
        vector<int>res;
        sieve();
        long long choose[10050][33]={0};
        for(int j=0; j!=MAXN; ++j)
            choose[j][0]=1;
        for(int n=1; n!=MAXN+49; ++n){
            for(int r=1; r!=33; ++r){
                choose[n][r]=(choose[n-1][r-1]+choose[n-1][r])%mod;
            }
        }
        for(auto &vals: queries){
            int n=vals[0], k=vals[1];
            auto freqs=getFactors(k);
            long long curr=1;
            for(int f: freqs){
                curr=(curr*choose[n+f-1][f])%mod;
            }
            res.push_back(curr);
        }
        return res;
    }
};