// F. Interacdive Problem
/*
This problem is interactive.

We decided to play a game with you and guess the number x (1<=x<n), where you know the number n.

You can make queries like this:

+ c: this command assigns x=x+c (1<=c<n) and then returns you the value ⌊x/n⌋ (x divide by n and round down).
You win if you guess the current number with no more than 10 queries

Interaction
The interaction begins by reading an integer n (2<n<=1000), which is written in the input data on its own line.

Then you can make no more than 10 queries. To make a query, print on a separate line:

+ c: this command will assign x=x+c (1<=c<n) and then print ⌊x/n⌋ (divide x by n and round down) on a separate line.
Print the answer, like the queries, on a separate line. The answer doesn't count in number of queries. To output it, use the following format:

! x: the current value of x.
After that, your program should exit.

You have to use a flush operation right after printing each line. For example, in C++ you should use the function fflush(stdout), 
in Java — System.out.flush(), in Pascal — flush(output) and in Python — sys.stdout.flush().

Note that the interactor is not responsive.

To make a hack, use the following format: a single line must contain two numbers x and n, separated by a space.

Examples
input
3

1
output
+ 1

! 3
*/

#include<iostream>
using namespace std;

int main(){
	int n;
	cin>>n;
	int left=1, right=n;
	int div=0;
	while(right-left>1){
		int mid=left+(right-left)/2;
		cout<<"+ "<<n-mid<<endl;
		int d;
		cin>>d;
		if(d>div){
			left=mid;
		} else right=mid;
		left=(left+n-mid)%n;
		right=(right+n-mid)%n;
		if(right==0) right=n;
		div=d;
	}
	cout<<"! "<<div*n+left;
}
