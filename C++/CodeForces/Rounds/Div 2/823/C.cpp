// C. Minimum Notation
/*
You have a string s consisting of digits from 0 to 9 inclusive. You can perform the following 
operation any (possibly zero) number of times:

You can choose a position i and delete a digit d on the i-th position. Then insert the digit min(d+1,9) 
on any position (at the beginning, at the end or in between any two adjacent digits).

What is the lexicographically smallest string you can get by performing these operations?

A string a is lexicographically smaller than a string b of the same length if and only if the following holds:

in the first position where a and b differ, the string a has a smaller digit than the corresponding digit in b.

Input
The first line contains a single integer t (1≤t≤10^4) — the number of test cases. Then the test cases follow.

Each test case consists of a single line that contains one string s (1≤|s|≤2⋅10^5) — the string consisting of digits. 
Please note that s is just a string consisting of digits, so leading zeros are allowed.

It is guaranteed that the sum of lengths of s over all test cases does not exceed 2⋅10^5.

Output
Print a single string — the minimum string that is possible to obtain.

Example
input
4
04829
9
01
314752277691991

output
02599
9
01
111334567888999

Note
In the first test case:

Delete 8 and insert 9 at the end of the notation. The resulting notation is 04299.
Delete 4 and insert 5 in the 3-rd position of the notation. The resulting notation is 02599.
Nothing needs to be done in the second and third test cases.
*/

/*
We leave all suffix minimums by the digits mni (digits less than or equal to the minimum among the 
digits to the right of them), remove the rest and replace them with min(d+1,9) (using the described operations) 

and add to lexicographically minimum order on the right (due to the appropriate order of operations, this is possible). 

The suffix minimums mni should be left, because no matter what digit we leave after mni, it will be no less 
than mni, and therefore will not improve the answer. 

The rest must be removed at the end with operations, since there is a number to the right less than this one, 
i.e. if you remove everything before it (put mni at the current position), 
the answer will become less than if you leave another digit at this position.
*/

#include<vector>
#include<iostream>
#include<unordered_map>
#include<map>
#include<queue>
#include<string>
#include<algorithm>
#include<set>
#define endl "\n"
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        int sz=s.size();
        vector<int>vec(sz+1, 0);
        for(int i=0; i<sz; ++i){
            vec[i]=int(s[i]-'0');
        }
        vector<int>minn(sz+1, 9);
        for(int i=sz-1; i>=0; --i){
            minn[i]=min(minn[i+1], vec[i]);
        }
        vector<int>buff(10, 0);
        string ans="";
        string temp="0123456789";
        for(int i=0; i<sz; ++i){
            for(int j=0; j<minn[i]; ++j){
                while(buff[j]){
                    ans+=temp[j];
                    buff[j]--;
                }
            }
            if(vec[i]==minn[i]){
                ans+=temp[vec[i]];
            } else{
                buff[min(9, vec[i]+1)]++;
            }
        }
        for(int i=0; i<10; ++i){
            while(buff[i]){
                ans+=temp[i];
                buff[i]--;
            }
        }
        cout<<ans<<endl;
    }
}