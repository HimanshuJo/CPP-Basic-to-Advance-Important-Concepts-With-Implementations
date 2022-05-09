// https://codeforces.com/contest/1613
// https://codeforces.com/blog/entry/97467
// A. Long Comparison
/*
Monocarp wrote down two numbers on a whiteboard. 
Both numbers follow a specific format: a positive integer x with p zeros appended to its end.

Now Monocarp asks you to compare these two numbers. Can you help him?

Input
The first line contains a single integer t (1≤t≤10^4) — the number of testcases.

The first line of each testcase contains two integers x1 and p1 (1≤x1≤10^6;0≤p1≤10^6) — the description of the first number.

The second line of each testcase contains two integers x2 and p2 (1≤x2≤10^6;0≤p2≤10^6) — the description of the second number.

Output
For each testcase print the result of the comparison of the given two numbers. 
If the first number is smaller than the second one, print '<'. 
If the first number is greater than the second one, print '>'. If they are equal, print '='.

Example
input
5
2 1
19 0
10 2
100 1
1999 0
2 3
1 0
1 0
99 0
1 2
output
>
=
<
=
<
Note
The comparisons in the example are: 20>19, 1000=1000, 1999<2000, 1=1, 99<100.
*/

#include<iostream>
#include<vector>
#include<string>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin>>t;
	while(t--){
		int x1, p1;
		cin>>x1>>p1;
		int x2, p2;
		cin>>x2>>p2;
		string frst=to_string(x1);
		string sec=to_string(x2);
		int l1=frst.length()+p1;
		int l2=sec.length()+p2;
		if(l1==l2){
			bool flag=false;
			int minn=min(frst.length(), sec.length());
			for(int i=0; i<minn; ++i){
				if(frst[i]-'0'>sec[i]-'0'){
					cout<<">\n";
					flag=true;
					break;
				} else if(frst[i]-'0'<sec[i]-'0'){
					cout<<"<\n";
					flag=true;
					break;
				}
				if(flag) break;
			}
			if(!flag){
				int maxx=max(frst.length(), sec.length());
				string maxStr=frst.length()>sec.length()?frst:sec;
				if(maxStr==frst){
					for(int i=minn; i<maxx; ++i){
						if(frst[i]-'0'>=1){
							cout<<">\n";
							flag=true;
							break;
						}
					}
				} else{
					for(int i=minn; i<maxx; ++i){
						if(sec[i]-'0'>=1){
							cout<<"<\n";
							flag=true;
							break;
						}
					}
				}
			}
			if(!flag)
				cout<<"=\n";
			continue;
		}
		if(l1<l2){
			cout<<"<\n";
			continue;
		}
		if(l1>l2){
			cout<<">\n";
			continue;
		}
	}
}
