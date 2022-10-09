// B. Tea with Tangerines
/*
There are n pieces of tangerine peel, the i-th of them has size ai. 
In one step it is possible to divide one piece of size x into two pieces of positive integer sizes y and z so that y+z=x.

You want that for each pair of pieces, their sizes differ strictly less than twice. In other words, 
there should not be two pieces of size x and y, such that 2x≤y. What is the minimum possible number of steps needed to satisfy the condition?

Input
The first line of the input contains a single integer t (1≤t≤100) — the number of test cases. The description of test cases follows.

The first line of each test case contains the integer n (1≤n≤100).

Then one line follows, containing n integers a1≤a2≤…≤an (1≤ai≤10^7).

Output
For each test case, output a single line containing the minimum number of steps.

Example
input
3
5
1 2 3 4 5
1
1033
5
600 900 1300 2000 2550

output
10
0
4

Note
In the first test case, we initially have a piece of size 1, so all final pieces must have size 1. 
The total number of steps is: 0+1+2+3+4=10.

In the second test case, we have just one piece, so we don't need to do anything, and the answer is 0 steps.

In the third test case, one of the possible cut options is: 600, 900, (600|700), (1000|1000), (1000|1000|550). 
You can see this option in the picture below. The maximum piece has size 1000, and it is less than 2 times bigger 
than the minimum piece of size 550. 4 steps are done. We can show that it is the minimum possible number of steps.
*/

/*
Let's start with a simple solution.

Let's choose the minimum piece from a and assume that it will remain the minimum until the end.
As the array is sorted, let's define the minimum piece as a1.
It means that in the end, all pieces must be smaller or equal to 2⋅a1−1.

The lower bound of the answer for this solution is ∑i=1n⌈ai/2⋅a1−1⌉.

Let's show that this is achievable.
For each piece, while its size greater than 2⋅a1−1, let's cut off a piece of size 2⋅a1−1.
The only problem is that we could get a piece smaller than a1 in the end.
But it means that before the last cut we had a piece in the range [2⋅a1,3⋅a1−2]. 
All pieces in this range can be easily cut into pieces of the right size in one move.

The only left question is why the minimum piece in the end should have size a1. Actually, it shouldn't, but it gives the best answer anyway.

As was described above, the lower bound of the solution with the minimal piece of size x in the end is ∑i=1n⌈ai/2⋅x−1⌉.

Having a minimal piece with a smaller size, we can't get anything better, because the lower bound will be equal or greater for all x<a1.
*/

#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin>>t;
	while(t--){
		int N;
		cin>>N;
		vector<int>in(N);
		for(int i=0; i<N; ++i){
			cin>>in[i];
		}
		long long ans=0;
		int minn=in[0];
		for(auto &vals: in){
			ans+=(vals-1)/(2*minn-1);
		}
		cout<<ans<<endl;
	}
}