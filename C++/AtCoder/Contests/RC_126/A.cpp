//Make 10
/*
Problem Statement
We have N2 sticks of length 2 each, N3 sticks of length 3 each, 
and N4 sticks of length 4 each. You can do the following operation 
any number of times.

Choose two sticks.
Let x and y be the lengths of these sticks. Bond them to form a 
stick of length x+y.

Sample Input 1 
5
3 4 1
7 0 0
0 0 7
0 0 0
1000000000000000 1000000000000000 1000000000000000
Sample Output 1 
2
1
0
0
900000000000000
*/
/*
 Exploiting parity
When making a stick of length 10, we will always use an even number of 
sticks of length 3. Thus, instead of having N3 sticks of length 3, 
let us assume that we have ⌊N3/2⌋ sticks of length 6 from the beginning. 
Thus, we can reduce the problem to making sticks of length 10 from 
sticks of lengths 2, 4, and 6. 
Furthermore, by dividing the length of every stick by 2, we end up 
with the following problem.

We have N1 sticks of length 1, N2 sticks of length 2, and N3 sticks of length 3. 
Find the maximum number of sticks of length 5 that can be made.
Below, we deal with this problem instead of the original.

We will call a way to make the maximum possible number of sticks of 
length 5 an optimal solution.

Greedy algorithm
Eventually, we can see that the following greedy algorithm finds an optimal solution.

(Step 1) If we have at least one stick of length 2 and at least one stick of length 3, bond those sticks to form a stick of length 5. Repeat as many times as possible.

(Step 2) If we have at least one stick of length 3 and at least two sticks of length 1, bond those sticks to form a stick of length 5. Repeat as many times as possible.

(Step 3) If we have at least two sticks of length 2 and at least one stick of length 1, bond those sticks to form a stick of length 5. Repeat as many times as possible.

(Step 4) If we have at least one stick of length 2 and at least three sticks of length 1, bond those sticks to form a stick of length 5. Repeat as many times as possible.

(Step 5) If we have at least five sticks of length 1, bond those sticks to form a stick of length 5. Repeat as many times as possible.
*/
#include<bits/stdc++.h>
using ll = long long;
using namespace std;

ll solvel3(ll N1, ll N3){
    ll ans=0;
    ll k=min(N1/2, N3);
    N1-=2*k;
    N3-=k;
    ans+=k;
    ans+=N1/5;
    return ans;
}

ll solvel2(ll N1, ll N2){
    ll ans=0;
    ll k=min(N1, N2/2);
    N1-=k;
    N2-=2*k;
    ans+=k;
    if(N1>=3 and N2>=1){
        N1-=3;
        N2-=1;
        ans+=1;
    }
    ans+=N1/5;
    return ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        ll n2, n3, n4;
        cin>>n2>>n3>>n4;
        ll N1=n2, N2=n4, N3=n3/2;
        ll ans=0;
        ll k=min(N2, N3);
        N2-=k;
        N3-=k;
        ans+=k;
        if(N2==0){
            ans+=solvel3(N1, N3);
        } else{
            ans+=solvel2(N1, N2);
        }
        cout<<ans<<"\n";
    }
}