// D. Friends and the Restaurant
/*
A group of n friends decide to go to a restaurant. Each of the friends plans to order meals 
for xi burles and has a total of yi burles (1≤i≤n).

The friends decide to split their visit to the restaurant into several days. 
Each day, some group of at least two friends goes to the restaurant. 
Each of the friends visits the restaurant no more than once (that is, these groups do not intersect). 
These groups must satisfy the condition that the total budget of each group must be not less than the amount 
of burles that the friends in the group are going to spend at the restaurant. 

In other words, the sum of all xi values in the group must not exceed the sum of yi values in the group.

What is the maximum number of days friends can visit the restaurant?

For example, let there be n=6 friends for whom x = [8,3,9,2,4,5] and y = [5,3,1,4,5,10]. Then:

first and sixth friends can go to the restaurant on the first day. They will spend 8+5=13 burles at the restaurant, 
and their total budget is 5+10=15 burles. 
Since 15≥13, they can actually form a group.

friends with indices 2,4,5 can form a second group. 
They will spend 3+2+4=9 burles at the restaurant, and their total budget will be 3+4+5=12 burles (12≥9).

It can be shown that they will not be able to form more groups so that each group has at least two 
friends and each group can pay the bill.

So, the maximum number of groups the friends can split into is 2. Friends will visit the restaurant 
for a maximum of two days. Note that the 3-rd friend will not visit the restaurant at all.

Output the maximum number of days the friends can visit the restaurant for given n, x and y.

Input
The first line of the input contains an integer t (1≤t≤10^4) — the number of test cases in the test.

The descriptions of the test cases follow.

The first line of each test case contains a single integer n (2≤n≤10^5) — the number of friends.

The second line of each test case contains exactly n integers x1,x2,…,xn (1≤xi≤10^9). 
The value of xi corresponds to the number of burles that the friend numbered i plans to spend at the restaurant.

The third line of each test case contains exactly n integers y1,y2,…,yn (1≤yi≤10^9). 
The value yi corresponds to the number of burles that the friend numbered i has.

It is guaranteed that the sum of n values over all test cases does not exceed 10^5.

Output
For each test case, print the maximum number of days to visit the restaurant. 
If friends cannot form even one group to visit the restaurant, print 0.

Example
input
6
6
8 3 9 2 4 5
5 3 1 4 5 10
4
1 2 3 4
1 1 2 2
3
2 3 7
1 3 10
6
2 3 6 9 5 7
3 2 7 10 6 10
6
5 4 2 1 8 100
1 1 1 1 1 200
6
1 4 1 2 4 2
1 3 3 2 3 4

output
2
0
1
3
1
3

Note
The first test case in explained in the problem statement.

In the second test case, friends cannot form at least one group of two or more people.

In the third test case, one way to visit the restaurant in one day is to go in a group of 
all three friends (1+3+10≥2+3+7). Note that they do not have the option of splitting into two groups.
*/

/*
First, we sort the friends in descending order of yi−xi. Now for each friend we know the amount of
money he lacks, or vice versa, which he has in excess.

In order to maximize the number of days, it is most advantageous for friends to break 
into pairs. It is the number of groups that matters, not the number of people in the group, 
so adding a third person to the pair won't improve the answer in any way.

Let's solve the problem using two pointers: for the richest friend, find the first friend from 
the end such that the sum of their values y exceeds the sum of their values x. 

Then repeat this for all subsequent friends until the pointers meet.

If no pair could be formed, or none of the friends has a value x greater than y, then the answer is -1.

Otherwise, print the number of pairs formed.
*/

#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<string>
#include<queue>
#include<unordered_map>
#include<map>
#include<unordered_set>
#include<set>
#define endl "\n"
#define ll long long
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int>spnd(n), has(n);
        for(int i=0; i<n; ++i){
            cin>>spnd[i];
        }
        for(int i=0; i<n; ++i){
            cin>>has[i];
        }
        vector<ll>diff;
        for(int i=0; i<n; ++i){
            diff.push_back(has[i]-spnd[i]);
        }
        sort(diff.begin(), diff.end(), greater<int>());
        int j=n-1, count=0;
        for(int i=0; i<n; ++i){
            while(j>i&&diff[i]+diff[j]<0){
                --j;
            }
            if(j<=i) break;
            count++, --j;
        }
        cout<<count<<endl;
    }
}