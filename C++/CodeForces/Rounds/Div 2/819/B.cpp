// B. Mainak and Interesting Sequence
/*
Mainak has two positive integers n and m.

Mainak finds a sequence a1,a2,…,an of n positive integers interesting, if for all integers i (1≤i≤n), 
the bitwise XOR of all elements in a which are strictly less than ai is 0. 

Formally if pi is the bitwise XOR of all elements in a which are strictly less than ai, 
then a is an interesting sequence if p1=p2=…=pn=0.

For example, sequences [1,3,2,3,1,2,3], [4,4,4,4], [25] are interesting, whereas [1,2,3,4] 
(p2=1≠0), [4,1,1,2,4] (p1=1⊕1⊕2=2≠0), [29,30,30] (p2=29≠0) aren't interesting.

Here a⊕b denotes bitwise XOR of integers a and b.

Find any interesting sequence a1,a2,…,an (or report that there exists no such sequence) such 
that the sum of the elements in the sequence a is equal to m, i.e. a1+a2…+an=m.

As a reminder, the bitwise XOR of an empty sequence is considered to be 0.

Input
Each test contains multiple test cases. The first line contains a single integer t (1≤t≤10^5) — 
the number of test cases. Description of the test cases follows.

The first line and the only line of each test case contains two integers n and m (1≤n≤10^5, 1≤m≤10^9) — 
the length of the sequence and the sum of the elements.

It is guaranteed that the sum of n over all test cases does not exceed 10^5.

Output
For each test case, if there exists some interesting sequence, output "Yes" on the first line, 
otherwise output "No". You may print each letter in any case (for example, "YES", "Yes", "yes", "yEs" 
will all be recognized as positive answer).

If the answer is "Yes", output n positive integers a1,a2,…,an (ai≥1), forming an interesting sequence such 
that a1+a2…+an=m. If there are multiple solutions, output any.

Example
input
4
1 3
6 12
2 1
3 6

output
Yes
3
Yes
1 3 2 2 3 1
No
Yes
2 2 2

Note

In the first test case, [3] is the only interesting sequence of length 1 having sum 3.
In the third test case, there is no sequence of length 2 having sum of elements equal to 1, 
so there is no such interesting sequence.
In the fourth test case, p1=p2=p3=0, because bitwise XOR of an empty sequence is 0.
*/

/*
    Lemma: In an interesting sequence a1,a2,…,an, every element other than 
    the largest must have even occurrences.

    Proof: For the sake of contradiction, assume that for some x (x>0), 
    such than x≠maxi=1n{ai}, x appears an odd number of times. 

    Let P(z) denote the bitwise XOR of all elements in a that are less than z. By assumption P(x)=0. 
    Now, since x is not maximum of the sequence a, there exists y in a, such that x<y and there are no 
    other elements t such that x<t<y (in other words, y is the immediate larger element of x in a). 

    Again, P(y)=0 as well by assumption. However, since x appears an odd number of times, we have: 
    0=P(y)=P(x)⊕x=0⊕x=x, which is a contradiction as x must be positive.

This gives us an O(n) solution as follows:

Case - I: If n>m — It is clearly impossible to construct an interesting sequence with 
sum equal to m (as integers must be positive).

Case - II: n is odd — Create (n−1) occurrences of 1, and a single occurrence of (m−n+1).

Case - III: n is even, m is even — Create (n−2) occurrences of 1 and two occurrences of (m−n+2)/2.

Case - IV: n is even, m is odd — No such interesting sequences exist.

Proof: For the sake of contradiction assume that such an interesting sequence, a, exists. 
Since m is odd, there must be an odd number x that occurs an odd number of times in a. 

Again since n is even there must be another integer y (different from x) that occurs an also odd number of times. 
Hence either x or y (whichever is lower) violates the lemma.
*/

#include<iostream>
#include<vector>
#include<set>
#include<queue>
#include<algorithm>
#define endl "\n"
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        if(n==1){
            cout<<"YES\n";
            cout<<m<<endl;
        } else if(n>m||((m&1)==1&&(n&1)==0)){
            cout<<"NO\n";
        } else if(n==m){
            cout<<"YES\n";
            for(int i=0; i<n; ++i){
                cout<<1<<" ";
            }
            cout<<endl;
        } else if((m&1)==0&&m/2==n){
            cout<<"YES\n";
            for(int i=0; i<n; ++i){
                cout<<2<<" ";
            }
            cout<<endl;
        } else if((m&1)==0&&(n&1)==0){
            cout<<"YES\n";
            for(int i=2; i<n; ++i){
                cout<<1<<" ";
            }
            cout<<(m-n+2)/2<<" "<<(m-n+2)/2;
            cout<<endl;
        } else if((n&1)==1){
            cout<<"YES\n";
            for(int i=1; i<n; ++i){
                cout<<1<<" ";
            }
            cout<<(m-n+1)<<endl;
        } else{
            cout<<"NO\n";
        }
    }
}