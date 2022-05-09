// B - Minimize Ordering
/*
Problem Statement
You are given a string S. Find the lexicographically smallest string S 
′obtained by permuting the characters of S.

Here, for different two strings s=s1, s2, …sn and t=t1, t2, …tm, s<t holds lexicographically
when one of the conditions below is satisfied.

There is an integer i (1≤i≤min(n,m)) such that si<ti and sj=tj for all integers j (1≤j<i).

si=ti for all integers i (1≤i≤min(n,m)), and n<m.

Input
Input is given from Standard Input in the following format:

S
Output
Print the lexicographically smallest string S′ obtained by permuting the characters in S.

Sample Input 1 
aba

Sample Output 1 
aab
Three strings can be obtained by permuting aba:

aba
aab
baa
The lexicographically smallest among them is aab.

Sample Input 2 
zzzz

Sample Output 2 
zzzz
*/

#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    string S;
    cin>>S;
    sort(S.begin(), S.end());
    cout<<S<<"\n";
}