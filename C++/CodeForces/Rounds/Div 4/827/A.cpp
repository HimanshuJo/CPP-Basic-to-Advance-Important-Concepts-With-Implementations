// A. Sum
/*
You are given three integers a, b, and c. Determine if one of them is the sum of the other two.

Input
The first line contains a single integer t (1≤t≤9261) — the number of test cases.

The description of each test case consists of three integers a, b, c (0≤a,b,c≤20).

Output
For each test case, output "YES" if one of the numbers is the sum of the other two, and "NO" otherwise.

You can output the answer in any case (for example, the strings "yEs", "yes", "Yes" and "YES" will be recognized as a positive answer).

Example
input
7
1 4 3
2 5 8
9 11 20
0 0 0
20 20 20
4 12 3
15 7 8

output
YES
NO
YES
YES
NO
NO
YES

Note
In the first test case, 1+3=4.

In the second test case, none of the numbers is the sum of the other two.

In the third test case, 9+11=20.
*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define endl "\n"

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin>>t;
	while(t--){
		int a, b, c;
		cin>>a>>b>>c;
		bool flag=false;
		if(a==b+c){
			flag=true;
		}
		if(flag){
			cout<<"Yes"<<endl;
		} else{
			if(b==a+c){
				flag=true;
				cout<<"Yes"<<endl;
			}
			if(!flag){
				if(c==a+b){
					cout<<"Yes"<<endl;
				} else{
					cout<<"No"<<endl;
				}
			}
		}
	}
}