#include <bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    set<string> res;
    int mod=1e9+7;
    void allSubSeqRec(string str, int n, int index, string curr)
    {
        if (index == n || (curr.length()>1&&curr[0]=='0')) return;

        if (!curr.empty())
        {
            res.insert(curr);
        }

        for (int i = index + 1; i < n; i++)
        {

            curr += str[i];
            if (curr.length()==1){
                allSubSeqRec(str, n, i, curr);
            }
            if (curr.length()>1&&curr[0]!='0')
                allSubSeqRec(str, n, i, curr);

            // backtracking
            curr = curr.erase(curr.size() - 1);
        }
        return;
    }

    // Generates power set in lexicographic
    // order.
    void allSubSeq(string str)
    {
        allSubSeqRec(str, str.size(), -1, "");
    }

    int numberOfUniqueGoodSubsequences(string binary) {
        allSubSeq(binary);
        int ans=0;
        for (auto &entry: res){
            //cout<<entry<<endl;
            if (entry.length()==1){
                ans++;
            } else {
                if (entry[0]!='0'){
                    ans++;
                }
            }
        }
        return ans%mod;
    }
};