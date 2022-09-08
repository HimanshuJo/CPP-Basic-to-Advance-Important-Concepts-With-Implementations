// A. Mainak and Array
/*
Mainak has an array a1,a2,…,an of n positive integers. He will do the 
following operation to this array exactly once:

Pick a subsegment of this array and cyclically rotate it by any amount.
Formally, he can do the following exactly once:
Pick two integers l and r, such that 1≤l≤r≤n, and any positive integer k.
Repeat this k times: set al=al+1,al+1=al+2,…,ar−1=ar,ar=al (all changes happen at the same time).
Mainak wants to maximize the value of (an−a1) after exactly one such operation. 

Determine the maximum value of (an−a1) that he can obtain.

Input
Each test contains multiple test cases. The first line contains a single integer t (1≤t≤50) — 
the number of test cases. Description of the test cases follows.

The first line of each test case contains a single integer n (1≤n≤2000).

The second line of each test case contains n integers a1,a2,…,an (1≤ai≤999).

It is guaranteed that the sum of n over all test cases does not exceed 2000.

Output
For each test case, output a single integer — the maximum value of (an−a1) that Mainak can 
obtain by doing the operation exactly once.

Example
input
5
6
1 3 9 11 5 7
1
20
3
9 99 999
4
2 1 8 1
3
2 1 5

output
10
0
990
7
4

Note
In the first test case, we can rotate the subarray from index 3 to index 6 by an amount of 2 
(i.e. choose l=3, r=6 and k=2) to get the optimal array:
[1,3,9,11,5,7–––––––––]⟶[1,3,5,7,9,11–––––––––]
So the answer is an−a1=11−1=10.
In the second testcase, it is optimal to rotate the subarray starting and ending at index 1 and 
rotating it by an amount of 2.
In the fourth testcase, it is optimal to rotate the subarray starting from index 1 to index 4 and 
rotating it by an amount of 3. So the answer is 8−1=7.
*/

/*
There are four candidates of the maximum value of an−a1 achievable, each of which can be found in O(n) time.

No subarray is chosen: Answer would be an−a1 in this case.

Chosen subarray contains an and a1 : Answer would be maxi=1n{a(i−1)−ai} 
where a0 is same as an (notice that the previous case is included in this case as well).

Chosen subarray doesn't contain an : Answer would be maxi=1n−1{an−ai}.

Chosen subarray doesn't contain a1 : Answer would be maxi=2n{ai−a1}.

Finally we report the maximum of all of these four values in total time O(n).
*/

/*
TLE:

#include<iostream>
#include<vector>
#include<set>
#include<queue>
#include<algorithm>
using namespace std;

void rightRotate(vector<int>&arr, int n, int k)
{
    k = k % n;
    int i, j;
    for (i = n - k, j = n - 1; i < j; i++, j--) {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
    for (i = 0, j = n - k - 1; i < j; i++, j--) {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
    for (i = 0, j = n - 1; i < j; i++, j--) {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int>in(n, 0);
        for(int i=0; i<n; ++i){
            cin>>in[i];
        }
        int res=INT_MIN;
        for(int l=0; l<n; ++l){
            for(int r=0; r<n; ++r){
                vector<int>temp, temp2, temp3;
                for(int x=0; x<l; ++x){
                    temp2.push_back(in[x]);
                }
                for(int x=l; x<=r; ++x){
                    temp.push_back(in[x]);
                }
                if(r+1<=n-1){
                    for(int x=r+1; x<n; ++x){
                        temp3.push_back(in[x]);
                    }
                }
                for(int k=0; k<temp.size(); ++k){
                    int currk=k;
                    rightRotate(temp, temp.size(), currk);
                    vector<int>anothertmp;
                    for(auto &vals: temp2){
                        anothertmp.push_back(vals);
                    }
                    for(auto &vals: temp){
                        anothertmp.push_back(vals);
                    }
                    for(auto &vals: temp3){
                        anothertmp.push_back(vals);
                    }
                    res=max(res, anothertmp[n-1]-anothertmp[0]);
                }
            }
        }
        cout<<(res==INT_MIN?0:res)<<"\n";
    }
}
*/

#include<iostream>
#include<vector>
#include<set>
#include<queue>
#include<algorithm>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int>in(n, 0);
        for(int i=0; i<n; ++i){
            cin>>in[i];
        }
        int res=0;
        for(int i=1; i<n; ++i){
            res=max(res, in[i-1]-in[i]);
        }
        for(int i=1; i<n; ++i){
            res=max(res, in[i]-in[0]);
        }
        for(int i=0; i<n-1; ++i){
            res=max(res, in[n-1]-in[i]);
        }
        cout<<res<<"\n";
    }
}