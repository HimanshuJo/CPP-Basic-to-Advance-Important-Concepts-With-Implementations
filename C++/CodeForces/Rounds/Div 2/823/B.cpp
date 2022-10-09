// B. Meeting on the Line
/*
n people live on the coordinate line, the i-th one lives at the point xi (1≤i≤n). 
They want to choose a position x0 to meet. The i-th person will spend |xi−x0| minutes to get to the 
meeting place. Also, the i-th person needs ti minutes to get dressed, so in total he or she needs ti+|xi−x0| minutes.

Here |y| denotes the absolute value of y.

These people ask you to find a position x0 that minimizes the time in which all n people can gather at the meeting place.

Input
The first line contains a single integer t (1≤t≤10^3) — the number of test cases. Then the test cases follow.

Each test case consists of three lines.

The first line contains a single integer n (1≤n≤10^5) — the number of people.

The second line contains n integers x1,x2,…,xn (0≤xi≤10^8) — the positions of the people.

The third line contains n integers t1,t2,…,tn (0≤ti≤10^8), where ti is the time i-th person needs to get dressed.

It is guaranteed that the sum of n over all test cases does not exceed 2⋅105.

Output
For each test case, print a single real number — the optimum position x0. It can be shown that 
the optimal position x0 is unique.

Your answer will be considered correct if its absolute or relative error does not exceed 10^−6. 
Formally, let your answer be a, the jury's answer be b. Your answer will be considered correct if |a−b|/max(1,|b|)≤10^−6.

Example
input
7
1
0
3
2
3 1
0 0
2
1 4
0 0
3
1 2 3
0 0 0
3
1 2 3
4 1 2
3
3 3 3
5 3 3
6
5 4 7 2 10 4
3 2 5 1 4 6

output
0
2
2.5
2
1
3
6

Note

In the 1-st test case there is one person, so it is efficient to choose his or her position for the meeting place. 
Then he or she will get to it in 3 minutes, that he or she need to get dressed.

In the 2-nd test case there are 2 people who don't need time to get dressed. Each of them needs one minute to get to position 2.

In the 5-th test case the 1-st person needs 4 minutes to get to position 1 (4 minutes to get dressed and 0 minutes on the way);
the 2-nd person needs 2 minutes to get to position 1 (1 minute to get dressed and 1 minute on the way); 
the 3-rd person needs 4 minutes to get to position 1 (2 minutes to get dressed and 2 minutes on the way).
*/

/*
There are many solutions to this problem, here are 2 of them.

1) Let people be able to meet in time T, then they could meet in time T+ε, 
where ε>0. 

So we can find T by binary search. 
It remains to learn how to check whether people can meet for a specific time T. 

To do this, for the i-th person, find a segment of positions that he can get to in time T: 
if T<ti then this segment is empty, otherwise it is [xi−(T−ti),xi+(T−ti)]. 

Then people will be able to meet only if these segments intersect, that is, the minimum of the right borders 
is greater than or equal to the maximum of the left borders. 

In order to find the answer by the minimum T, you need to intersect these segments in the same way 
(should get a point, but due to accuracy, most likely, a segment of a very small length will turn out) 
and take any point of this intersection. Asymptotics is O(nlogn).

-------

2) If all ti were equal to 0, then this would be a classical problem, the solution of which would be to find 
the average of the minimum and maximum coordinates of people. 

We can reduce our problem to this one if we replace the person (xi, ti) with two people: 
(xi−ti, 0) and (xi+ti, 0). 

Proof. Let the meeting be at the point y. 

       Let xi≤y. Then this person will need ti+y−xi of time to get to her, 
       and the two we want to replace him with — y−xi+ti and y−xi−ti. 

       it is easy to see that the first value is equal to the initial value, and the second is not greater 
       than the initial value, then the maximum of these two values is equal to the initial value. 

       The proof is similar for the case y≤xi. Then for any meeting point, the time in the original problem and after the 
       replacement does not differ, which means that such a replacement will not change the answer and it can be done. 

       Asymptotics is O(n).
*/

#include<iostream>
#include<vector>
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
		vector<int>time(N);
		for(int i=0; i<N; ++i){
			cin>>time[i];
		}
		vector<int>combT;
		for(int i=0; i<N; ++i){
			combT.push_back(in[i]-time[i]);
			combT.push_back(in[i]+time[i]);
		}
		int minn=INT_MAX, maxx=INT_MIN;
		for(auto &vals: combT){
			minn=min(minn, vals);
			maxx=max(maxx, vals);
		}
		long long fnav=minn+maxx;
		cout<<fnav/2;
		if(fnav%2!=0){
			cout<<".5\n";
		} else{
			cout<<endl;
		}
	}
}