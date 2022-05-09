// A. Div. 7
/*
You are given an integer n. You have to change the minimum number of digits in it in such a way that 
the resulting number does not have any leading zeroes and is divisible by 7.

If there are multiple ways to do it, print any of them. If the given number is already divisible by 7, leave it unchanged.

Input
The first line contains one integer t (1≤t≤990) — the number of test cases.

Then the test cases follow, each test case consists of one line containing one integer n (10≤n≤999).

Output
For each test case, print one integer without any leading zeroes — the result of your changes 
(i.e. the integer that is divisible by 7 and can be obtained by changing the minimum possible number of digits in n).

If there are multiple ways to apply changes, print any resulting number. 
If the given number is already divisible by 7, just print it.

Example
input
3
42
23
377

output
42
28
777

Note
In the first test case of the example, 42 is already divisible by 7, so there's no need to change it.

In the second test case of the example, there are multiple answers — 28, 21 or 63.

In the third test case of the example, other possible answers are 357, 371 and 378. Note that you cannot print 077 or 77.

*/

#include<iostream>
#include<string>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		if(n%7==0){
			cout<<n<<"\n";
			continue;
		}
		int frst=n-1, sec=n+1;
		while(frst%7!=0){
			frst--;
			if(frst<0) break;
		}
		while(sec%7!=0){
			sec++;
			if(sec>2*n+n) break;
		}
		string to_check=to_string(n);
		string temp1=to_string(frst);
		string temp2=to_string(sec);
		int cnt1=0, cnt2=0;
		int len1=temp1.length(), len2=temp2.length(), fnlen=to_check.length();
		if(len1==fnlen&&len2==fnlen){
			for(int i=0; i<fnlen; ++i){
				if(to_check[i]==temp1[i]){
					cnt1++;
				}
				if(to_check[i]==temp2[i]){
					cnt2++;
				}
			}
			if(cnt1>=cnt2){
				cout<<frst<<"\n";
			} else if(cnt2>cnt1){
				cout<<sec<<"\n";
			}
		} else if(len1!=fnlen&&len2==fnlen){
			cout<<sec<<"\n";
		} else if(len1==fnlen&&len2!=fnlen){
			cout<<frst<<"\n";
		} else{}
	}
}
