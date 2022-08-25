// https://codeforces.com/contest/1612
// https://codeforces.com/blog/entry/97164
// A. Distance
/*
Let's denote the Manhattan distance between two points p1 (with coordinates (x1,y1)) and p2 
(with coordinates (x2,y2)) as d(p1,p2)=|x1−x2|+|y1−y2|. 

For example, the distance between two points with coordinates (1,3) and (4,2) is |1−4|+|3−2|=4.

You are given two points, A and B. The point A has coordinates (0,0), the point B has coordinates (x,y).

Your goal is to find a point C such that:

both coordinates of C are non-negative integers;
d(A,C)=d(A,B)/2 (without any rounding);
d(B,C)=d(A,B)/2 (without any rounding).
Find any point C that meets these constraints, or report that no such point exists.

Input
The first line contains one integer t (1≤t≤3000) — the number of test cases.

Each test case consists of one line containing two integers x and y (0≤x,y≤50) — the coordinates of the point B.

Output
For each test case, print the answer on a separate line as follows:

if it is impossible to find a point C meeting the constraints, print "-1 -1" (without quotes);
otherwise, print two non-negative integers not exceeding 106 — the coordinates of point C meeting the constraints. 
If there are multiple answers, print any of them. 
It can be shown that if any such point exists, it's possible to find a point with coordinates not exceeding 10^6 that meets the constraints.

Example
input
10
49 3
2 50
13 0
0 41
42 0
0 36
13 37
42 16
42 13
0 0

output
23 3
1 25
-1 -1
-1 -1
21 0
0 18
13 12
25 4
-1 -1
0 0

Note
Explanations for some of the test cases from the example:

In the first test case, the point B has coordinates (49,3). 
If the point C has coordinates (23,3), then the distance from A to B is |49−0|+|3−0|=52, 
the distance from A to C is |23−0|+|3−0|=26, and the distance from B to C is |23−49|+|3−3|=26.

In the second test case, the point B has coordinates (2,50). If the point C has coordinates (1,25), 
then the distance from A to B is |2−0|+|50−0|=52, the distance from A to C is |1−0|+|25−0|=26, 
and the distance from B to C is |1−2|+|25−50|=26.

In the third and the fourth test cases, it can be shown that no point with integer coordinates meets the constraints.

In the fifth test case, the point B has coordinates (42,0). If the point C has coordinates (21,0), 
then the distance from A to B is |42−0|+|0−0|=42, the distance from A to C is |21−0|+|0−0|=21,
and the distance from B to C is |21−42|+|0−0|=21.
*/

#include<iostream>
#include<vector>
using namespace std;

int calDist(int X1, int Y1, int X2, int Y2){
	return((abs(X1-X2))+(abs(Y1-Y2)));
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin>>t;
	while(t--){
		int x, y;
		cin>>x>>y;
		bool flag=false;
		int ansX=0;
		int ansY=0;
		int origDist=calDist(x, y, 0, 0);
		for(int i=0; i<50; ++i){
			for(int j=0; j<50; ++j){
				int NwcurrX=i;
				int NwcurrY=j;
				int currDist1=calDist(NwcurrX, NwcurrY, 0, 0); //AC
				int currDist2=calDist(x, y, NwcurrX, NwcurrY); //BC
				if(2*currDist1==origDist&&2*currDist2==origDist){
					flag=true;
					ansX=NwcurrX;
					ansY=NwcurrY;
					break;
				}
			}
		}
		if(flag){
			cout<<ansX<<" "<<ansY<<"\n";
		} else{
			cout<<"-1 -1\n";
		}
	}
}
