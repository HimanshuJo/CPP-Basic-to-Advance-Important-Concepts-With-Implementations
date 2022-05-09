// B. Make AP
/*
Polycarp has 3 positive integers a, b and c. He can perform the following operation exactly once.

Choose a positive integer m and multiply exactly one of the integers a, b or c by m.
Can Polycarp make it so that after performing the operation, the sequence of three numbers a, b, c (in this order) 
forms an arithmetic progression? Note that you cannot change the order of a, b and c.

Formally, a sequence x1,x2,…,xn is called an arithmetic progression (AP) if there exists a number d (called "common difference") 
such that xi+1=xi+d for all i from 1 to n−1. In this problem, n=3.

For example, the following sequences are AP: [5,10,15], [3,2,1], [1,1,1], and [13,10,7]. 
The following sequences are not AP: [1,2,4], [0,1,0] and [1,3,2].

You need to answer t independent test cases.

Example
input
11
10 5 30
30 5 10
1 2 3
1 6 3
2 6 3
1 1 1
1 1 2
1 1 3
1 100000000 1
2 1 1
1 2 2

output
YES
YES
YES
YES
NO
YES
NO
YES
YES
NO
YES
*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin>>n;
	while(n--){
		int a, b, c;
		cin>>a>>b>>c;
		int m1=a+c;
		if(m1%(2*b)==0){
			cout<<"YES\n";
			continue;
		}
		int m2=(2*b-a);
		if(m2>0&&(m2%c==0)){
			cout<<"YES\n";
			continue;
		}
		int m3=(2*b-c);
		if(m3>0&&(m3%a==0)){
			cout<<"YES\n";
			continue;
		}
		cout<<"NO\n";
	}
}
