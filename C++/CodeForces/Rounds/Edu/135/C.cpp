// C. Digital Logarithm
/*
Let's define f(x) for a positive integer x as the length of the base-10 representation of x 
without leading zeros. I like to call it a digital logarithm. Similar to a digital root, 
if you are familiar with that.

You are given two arrays a and b, each containing n positive integers. In one operation, you do the following:

pick some integer i from 1 to n;
assign either f(ai) to ai or f(bi) to bi.
Two arrays are considered similar to each other if you can rearrange the elements in both of them, 
so that they are equal (e.g. ai=bi for all i from 1 to n).

What's the smallest number of operations required to make a and b similar to each other?

Input
The first line contains a single integer t (1≤t≤10^4) — the number of testcases.

The first line of the testcase contains a single integer n (1≤n≤2⋅10^5) — the number of elements in each of the arrays.

The second line contains n integers a1,a2,…,an (1≤ai<10^9).

The third line contains n integers b1,b2,…,bn (1≤bj<10^9).

The sum of n over all testcases doesn't exceed 2⋅10^5.

Output
For each testcase, print the smallest number of operations required to make a and b similar to each other.

Example
input
4
1
1
1000
4
1 2 3 4
3 1 4 2
3
2 9 3
1 100 9
10
75019 709259 5 611271314 9024533 81871864 9 3 6 4865
9503 2 371245467 6 7 37376159 8 364036498 52295554 169

output
2
0
2
18
Note
In the first testcase, you can apply the digital logarithm to b1 twice.

In the second testcase, the arrays are already similar to each other.

In the third testcase, you can first apply the digital logarithm to a1, then to b2.
*/

/*
First, why can you always make the arrays similar? Applying a digital logarithm to any number will 
eventually make it equal to 1. Thus, you can at least make all numbers into 1s in both arrays.

Then notice the most important thing — applying the digital logarithm to a number greater than 1 
always makes this number smaller.

Thus, if a number appears in only one of the arrays, you will have to do one of the followings two things:

	decrease some greater number to make it equal to this one;
	decrease this number.

What if there is no greater number at all? This is the case for the largest number in 
both arrays altogether. If it appears in only one of the arrays, you must always decrease.

If it appears in both, though, why decrease it further? Worst case, you will decrease it in one array, 
then you'll have to decrease it in the other array as well. This is never more optimal 
than just matching one occurrence in both arrays to each other and removing them from the arrays.

So, the proposed solution is the following. Consider the largest element in each array. 
If they are equal, remove both. If not, apply digital logarithm to the larger of them. 
Continue until the arrays are empty.

What's the estimated complexity of this algorithm? Each number in the first array will 
be considered at most the number of times you can decrease it with a digital logarithm operation plus one. 
That is at most 2+1 — a number greater than 9 always becomes a single digit and a single digit 
always becomes 1. Same goes for the second array. So the complexity is basically linear.

To implement it efficiently, you will have to use some data structure that provides three operations:

peek at the maximum;
remove the maximum;
insert a new element.
The perfect one is a heap — priority_queue in C++.

Overall complexity: O(nlogn) per testcase.
*/

#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<queue>
#include<string>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int>A(n), B(n);
        for(int i=0; i<n; ++i){
            cin>>A[i];
        }
        for(int i=0; i<n; ++i){
            cin>>B[i];
        }
        priority_queue<int, vector<int>>pq1, pq2;
        for(auto &vals: A){
            pq1.push(vals);
        }
        for(auto &vals: B){
            pq2.push(vals);
        }
        int ans=0;
        while(!pq1.empty()&&!pq2.empty()){
            int curAtp=pq1.top(), curBtp=pq2.top();
            if(curAtp==curBtp){
                pq1.pop();
                pq2.pop();
                continue;
            }
            ans++;
            if(curAtp<curBtp){
                int nwnm=(to_string(curBtp)).length();
                pq2.pop();
                pq2.push(nwnm);
            } else{
                int nwnum=(to_string(curAtp)).length();
                pq1.pop();
                pq1.push(nwnum);
            }
        }
        cout<<ans<<"\n";
    }
}