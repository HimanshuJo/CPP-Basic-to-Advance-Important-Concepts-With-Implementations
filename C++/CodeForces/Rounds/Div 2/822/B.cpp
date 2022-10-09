// B. Bright, Nice, Brilliant
/*
There is a pyramid which consists of n floors. The floors are numbered from top to bottom in increasing order. 
In the pyramid, the i-th floor consists of i rooms.

Denote the j-th room on the i-th floor as (i,j). For all positive integers i and j such that 1≤j≤i<n, 
there are 2 one-way staircases which lead from (i,j) to (i+1,j) and from (i,j) to (i+1,j+1) respectively.

In each room you can either put a torch or leave it empty. Define the brightness of a room (i,j) to be 
the number of rooms with a torch from which you can reach the room (i,j) through a non-negative number of staircases.

For example, when n=5 and torches are placed in the rooms (1,1), (2,1), (3,2), (4,1), (4,3), and (5,3), 
the pyramid can be illustrated as follows:

The pyramid is called nice if and only if for all floors, all rooms in the floor have the same brightness.

Define the brilliance of a nice pyramid to be the sum of brightness over the rooms (1,1), (2,1), (3,1), ..., (n,1).

Find an arrangement of torches in the pyramid, such that the resulting pyramid is nice and its brilliance is maximized.

We can show that an answer always exists. If there are multiple answers, output any one of them.

Input
The first line of the input contains a single integer t (1≤t≤100) — the number of test cases. 
The description of the test cases follows.

The only line of each test case contains a single positive integer n (1≤n≤500) — 
the number of floors in the pyramid.

It is guaranteed that the sum of n over all test cases does not exceed 500.

Output
For each test case, output n lines, the arrangement of torches in the pyramid.

The i-th line should contain i integers, each separated with a space. 
The j-th integer on the i-th line should be 1 if room (i,j) has a torch, and 0 otherwise.

We can show that an answer always exists. If there are multiple answers, output any one of them.

Example
input
3
1
2
3

output
1 
1 
1 1 
1 
1 1 
1 0 1 
*/

#include<vector>
#include<iostream>
#include<unordered_map>
#include<map>
#include<queue>
#define endl "\n"
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<string>ans;
        for(int i=0; i<N; ++i){
            if(i==0){
                ans.push_back("1");
            } else if(i==1){
                ans.push_back("1 1");
            } else if(i!=N-1){
                string temp="";
                temp+='1';
                temp+=' ';
                int count=i+1;
                count-=1;
                while(count){
                    if(count>1){
                        temp+='0';
                        temp+=' ';
                        count--;
                    } else{
                        temp+='1';
                        temp+=' ';
                        count--;
                    }
                }
                ans.push_back(temp);
            } else{
                int count=i+1;
                string temp="";
                temp+='1';
                temp+=' ';
                count--;
                while(count){
                    if(count>1){
                        temp+='0';
                        temp+=' ';
                        count--;
                    } else{
                        temp+='1';
                        temp+=' ';
                        count--;
                    }
                }
                ans.push_back(temp);
            }
        }
        for(auto &vals: ans){
            cout<<vals<<endl;
        }
    }
}