// D. Maximum AND
/*
You are given two arrays a and b, consisting of n integers each.

Let's define a function f(a,b) as follows:

let's define an array c of size n, where ci=ai⊕bi (⊕ denotes bitwise XOR);

the value of the function is c1&c2&⋯&cn (i.e. bitwise AND of the entire array c).

Find the maximum value of the function f(a,b) if you can reorder the array b in an arbitrary way 
(leaving the initial order is also an option).

Example
input
3
5
1 0 0 3 3
2 3 2 1 0
3
1 1 1
0 0 3
8
0 1 2 3 4 5 6 7
7 6 5 4 3 2 1 0

output
2
0
7
*/

/*
Algo:

We will build the answer greedily, from the highest significant bit to the lowest one. 
Let's analyze how to check if the answer can have the highest bit equal to 1. 

It means that every value in c should have its highest bit equal to 1, so for every i, 
exactly one of the numbers {ai,bi} should have this bit equal to 1. 

For both of the given arrays, we can calculate how many elements have which value of this bit, 
and then the number of elements with 1 in this bit in the array a should be equal to the number of 
elements with 0 in the array b (and the same for elements with 0 in a and elements with 1 in b). 

If these values are equal, it means that the elements of a and b can be matched in such a way that in every pair, 
the XOR of them has 1 in this bit. If it is so, then the highest bit of the answer is 1, otherwise it is 0.

Okay, then let's proceed to the next bit. Should we just do the same to check if this bit can be equal to 1 
in the answer? Unfortunately, that's not enough. Let's look at the case: a=[3,0], b=[2,1]. 
We can get the value 1 in the 0-th bit or in the 1-st bit, but not in both simultaneously. 
So, for the next bit, we need to make sure that not only we can get 1 in the result, but we can 
also do this without transforming some of the 1-s to 0-s in the higher bits. 

If it is impossible, it doesn't matter if we can get 1 in the current bit since it will be 
sub-optimal, so we have to use an ordering that gets 0 in this bit.

In general case, it means that we have to solve the following sub-problem: check if we can obtain 1 in 
several bits of the answer; let these bits be {x1,x2,…,xk} (x1 to xk−1 are the bits that we have already 
checked; xk is the new bit we are trying to check). 

Let mask be the number that has 1 in every bit xi and 0 in every other bit. The elements should be 
matched in such a way that (ai&mask)⊕(bi&mask)=mask. 

If we group all numbers from a and from b according to the value of ai&mask (or bi&mask), 
then for every group of elements from a, there is a corresponding group in b such that we can match the 
elements from the first group only with the elements from the second group. 

So, if for every such group, its size in a is equal to the size of the corresponding group in b, 
then we can set all bits from {x1,x2,…,xk} to 1 simultaneously.

Some implementation notes: if the number of bits we need to check is big, the number of groups can 
become too large to handle all of them (since it is 2k). So, to store the number of 
elements in each group, we should use some associative data structure, like, for example, 
std::map in C++. If you use a map, splitting elements into groups will be done in O(nlogn), 
so in total, you will get complexity of O(nlognlogA), where A is the maximum possible value in the input.
*/

#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;

bool check(int num, vector<int>&A, vector<int>&B){
    int sz=A.size();
    unordered_map<int, int>mp;
    for(int i=0; i<sz; ++i){
        mp[A[i]&num]++;
    }
    for(int i=0; i<sz; ++i){
        mp[~B[i]&num]--;
    }
    bool ans=true;
    for(auto &entries: mp){
        ans&=entries.second==0;
    }
    return ans;
}

int main(){
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
        int ans=0;
        for(int bit=29; bit>=0; --bit){
            if(check(ans|(1<<bit), A, B)){
                ans|=1<<bit;
            }
        }
        cout<<ans<<"\n";
    }
}