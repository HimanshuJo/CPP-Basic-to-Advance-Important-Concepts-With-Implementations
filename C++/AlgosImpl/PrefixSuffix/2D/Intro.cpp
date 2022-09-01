/*
Now, what if we wanted to process Q queries for the sum over a sub-rectangle of
a 2D matrix with N rows and M columns? Let's assume both rows and columns
are 1-indexed, and we use the following matrix as an example:

	0	0	0	0	0	0
	0	1	5	6	11	8
	0	1	7	11	9	4
	0	4	6	1	3	2
	0	7	5	4	2	3

Naively, each sum query would then take O(NM) time, for a total of
O(QNM). This is too slow.

-------

Let's take the following example region, which we want to sum:

	0	0	0	0	0	0
	0	1	5	6	11	8
	0	1	'7	11	9	4
	0	4	6	1	3'	2
	0	7	5	4	2	3

Manually summing all the cells, we have a sub-matrix sum of 7+11+9+6+1+3 = 37

-------

The first logical optimization would be to do one-dimensional prefix sums of
each row. Then, we'd have the following row-prefix sum matrix. The desired
sub-array sum of each row in our desired region is simply the green cell minus
the red cell in that respective row. We do this for each row to get (28-1) + (14-4) = 37

	0	0	0	0	0	0
	0	1	6	12	23	31
	0	'1	8	19	'28	32
	0	4'	10	11	14'	16
	0	7	12	16	18	21

-------

Now, if we wanted to find a sub-matrix sum, we could break up the sub-matrix into
a sub-array for each row, and then add their sums, which would be calculated
using the prefix sums method described earlier. Since the matrix has N rows, 
the time complexity of this is O(QN)

This might be fast enough for Q=10^5 and N=10^3, but we can do better.

-------

In fact, we can do two-dimensional prefix sums. In our two dimensional prefix sum array, we have

prefix[a][b]= i=1∑a j=1∑b arr[i][j].

-------

This can be calculated as follows for row index 1<=i<=n and column index 1<=j<=m

	prefix[i][j] = prefix[i−1][j] + prefix[i][j−1] − prefix[i−1][j−1] + arr[i][j]

-------

The submatrix sum between rows a and A and columns b and B, can thus be expressed as follows:

	sum_{i=a}^{A} sum_{j=b}^{B} arr[i][j] = prefix[A][B] - prefix[a-1][B] - prefix[A][b-1] + prefix[a-1][b-1]

*/

/*
Forest Queries:

You are given an n×n grid representing the map of a forest. 

Each square is either empty or contains a tree. 
The upper-left square has coordinates (1,1), and the lower-right square has coordinates (n,n).

Your task is to process q queries of the form: how many trees are inside a given rectangle in the forest?

Input

The first input line has two integers n and q: the size of the forest and the number of queries.

Then, there are n lines describing the forest. Each line has n characters: . is an empty square and * is a tree.

Finally, there are q lines describing the queries. Each line has four integers y1, x1, y2, x2 corresponding 
to the corners of a rectangle.

Output

Print the number of trees inside each rectangle.

Constraints
1≤n≤1000
1≤q≤2⋅10^5
1≤y1≤y2≤n
1≤x1≤x2≤n

Example

Input:
4 3
.*..
*.**
**..
****
2 2 3 4
3 1 3 1
1 1 2 2

Output:
3
1
2
*/

#include<iostream>
#include<vector>
using namespace std;

constexpr int MAX_SIDE=1000;
int tree_pref[MAX_SIDE+1][MAX_SIDE+1];
int forest[MAX_SIDE+1][MAX_SIDE+1];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int N, Q;
	cin>>N>>Q;
	for(int i=0; i<N; ++i){
		for(int j=0; j<N; ++j){
			char a;
			cin>>a;
			forest[i+1][j+1]+=a=='*';
		}
	}
	for(int i=1; i<=N; ++i){
		for(int j=1; j<=N; ++j){
			tree_pref[i][j]=forest[i][j]+tree_pref[i-1][j]+tree_pref[i][j-1]-tree_pref[i-1][j-1];
		}
	}
	for(int q=0; q<Q; ++q){
		int from_rw, to_rw, from_col, to_col;
		cin>>from_rw>>from_col>>to_rw>>to_col;
		cout<<tree_pref[to_rw][to_col]-tree_pref[from_rw-1][to_col]-
		      tree_pref[to_rw][from_col-1]+tree_pref[from_rw-1][from_col-1]<<"\n";
	}
}