// D. Line
/*
There are n people in a horizontal line, each looking either to the left or the right. 
Each person counts the number of people in the direction they are looking. The value of the 
line is the sum of each person's count.

For example, in the arrangement LRRLL, where L stands for a person looking left and R stands for a 
person looking right, the counts for each person are [0,3,2,3,4], and the value is 0+3+2+3+4=12.

You are given the initial arrangement of people in the line. For each k from 1 to n, determine 
the maximum value of the line if you can change the direction of at most k people.

Input
The input consists of multiple test cases. The first line contains an integer t (1≤t≤100) — the number of test cases. 
The description of the test cases follows.

The first line of each test case contains an integer n (1≤n≤2⋅105) — the length of the line.

The following line contains a string consisting of n characters, each of which is either L or R, 
representing a person facing left or right, respectively — the description of the line.

It is guaranteed that the sum of n over all test cases does not exceed 2⋅10^5.

Please note that the answer for some test cases won't fit into 32-bit integer type, so you should use at 
least 64-bit integer type in your programming language (like long long for C++).

Output
For each test case, output n space-separated non-negative integers — the maximum value of the line 
if you can change the direction of at most k people for each k from 1 to n, inclusive.

Example
input
6
3
LLR
5
LRRLL
1
L
12
LRRRLLLRLLRL
10
LLLLLRRRRR
9
LRLRLRLRL

output
3 5 5 
16 16 16 16 16 
0 
86 95 98 101 102 102 102 102 102 102 102 102 
29 38 45 52 57 62 65 68 69 70 
44 50 54 56 56 56 56 56 56 

Note
In the first test case:

k=1: change the direction of 1 person to make the line RLR. The total value is 2+1+0=3.
k=2: change the direction of 2 people to make the line RLL. The total value is 2+1+2=5.
k=3: change the direction of 2 people to make the line RLL. The total value is 2+1+2=5. 
Note that you have to change the direction of at most k people.
In the second test case, it is optimal to only change the direction of the first person for all 
k from 1 to 5 (that is, make the line RRRLL).
*/
/*
TLE

#include<iostream>
#include<vector>
#include<map>
#include<unordered_map>
#include<queue>
#include<algorithm>
#define ll long long
#define endl "\n"
using namespace std;

struct custComp{
    bool operator()(const pair<int, int>&A, const pair<int, int>&B){
        return A.first>B.first;
    }
};

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin>>t;
	while(t--){
        int n; 
        cin>>n;
        string s;
        cin>>s;
        map<int, pair<ll, ll>>mp;
        vector<pair<int, int>>grt;
        for(int i=0; i<n; ++i){
            ll frst=(i-1)+1;
            ll sec=(n-i)-1;
            mp[i]={frst, sec};
            grt.push_back({max(frst, sec), i});
        }
        sort(grt.begin(), grt.end(), custComp());
        vector<ll>fnres(n);
        vector<ll>tmpres(n);
        ll prevpres=0;
        for(int i=0; i<n; ++i){
            if(s[i]=='L'){
                prevpres+=mp[i].first;
                tmpres[i]=mp[i].first;
            } else{
                prevpres+=mp[i].second;
                tmpres[i]=mp[i].second;
            }
        }
        for(int i=0; i<n; ++i){
            ll curr=prevpres;
            int count=i;
            int sz=grt.size();
            for(int j=0; j<sz; ++j){
                int idx=grt[j].second;
                if(tmpres[idx]!=grt[j].first){
                    curr-=tmpres[idx];
                    curr+=(grt[j]).first;
                    count--;
                    if(count<0) break;
                }
            }
            fnres[i]=curr;
        }
        for(auto &vals: fnres){
            cout<<vals<<" ";
        }
        cout<<endl;
    }
}
*/

/*
For each person, let's calculate how much the value will change if they turn around. 
For example, in the line LRRLL, if the i-th person turns around, then the value of the line will 
change by +4, −2, 0, −2, −4, respectively. (For instance, if the second person turns around, they see 3 
people before and 1 person after, so the value of the line changes by −2 if they turn around.)

Now note that if a person turns around, it doesn't affect anyone else's value. 

So the solution is a greedy one: let's sort the array of values in increasing order. 
Afterwards, we should go from the left to the right, and see if the value will increase if this person 
turns around; if it does, we should add it to the current total and continue.

The time complexity of this solution is O(nlogn) per testcase.
*/

#include<iostream>
#include<vector>
#include<map>
#include<unordered_map>
#include<queue>
#include<algorithm>
#define ll long long
#define endl "\n"
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin>>t;
	while(t--){
        int n; 
        cin>>n;
        string s;
        cin>>s;
        // If the person would've seen in the other direction
        vector<ll>vec;
        ll cursm=0;
        for(int i=0; i<n; ++i){
            if(s[i]=='L'){
               vec.push_back((n-1-i)-i);
               cursm+=i;
            } else{
                vec.push_back(i-(n-1-i));
                cursm+=n-1-i;
            }
        }
        /*
            Each time I will change the direction of the person who can see the most person
        */
        sort(vec.begin(), vec.end(), greater<int>());
        for(int i=0; i<n; ++i){
            if(vec[i]>0){
                cursm+=vec[i];
            }
            cout<<cursm<<" ";
        }
        cout<<endl;
    }
}