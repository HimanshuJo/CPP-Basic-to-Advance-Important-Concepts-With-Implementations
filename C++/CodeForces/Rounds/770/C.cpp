// C. OKEA
/*
You work for a well-known department store that uses leading technologies and employs mechanistic work — that is, robots!

The department you work in sells n*k items. The first item costs 1 dollar, the second item costs 2 dollars, and so on: 
i-th item costs i dollars. The items are situated on shelves. The items form a rectangular grid: there are n shelves in total, 
and each shelf contains exactly k items. We will denote by ai,j the price of j-th item (counting from the left) on the i-th shelf, 1<=i<=n,1<=j<=k.

Occasionally robots get curious and ponder on the following question: what is the mean price (arithmetic average) of items ai,l,ai,l+1,...,ai,r
for some shelf i and indices l<=r? Unfortunately, the old robots can only work with whole numbers. 
If the mean price turns out not to be an integer, they break down.

You care about robots' welfare. You want to arrange the items in such a way that the robots cannot theoretically break. 
Formally, you want to choose such a two-dimensional array a that:

Every number from 1 to n*k (inclusively) occurs exactly once.
For each i,l,r, the mean price of items from l to r on i-th shelf is an integer.
Find out if such an arrangement is possible, and if it is, give any example of such arrangement.

Input
The first line contains a single integer t (1<=t<=500) — the number of test cases.

The first and only line of each test case contains two integers n and k (1<=n,k<=500) — the number of shelves and length of each shelf, respectively.

It is guaranteed that the sum n over all test cases does not exceed 500 and the sum k over all test cases does not exceed 500.

Output
Print the answer for each test case.

If such an arrangement exists, print "YES" on a single line. After that, print any example on n lines of k numbers each, one line per shelf.
Each number from 1 to n*k must occur exactly once in the output.

If no good arrangement exists, print a single word "NO" on its own line.

Example
input
4
1 1
2 2
3 3
3 1

output
YES
1 
YES
1 3 
2 4 
NO
YES
1 
2 
3 
*/
/*
If k=1, you can put items on the shelves in any order.

Otherwise, there are at least 2 items on each shelf. If there are items of different parity on the shelf,
it is obvious that there are two neighboring items of different parity, but then the arithmetic mean of these two items won't be whole,
which is against the constraints. Therefore, all items on each shelf are of the same parity.

Notice that if the number of shelves n is odd, we cannot arrange the items correctly because the number of 
shelves with even and odd items must be the same (that is, if k>=2).

Let us show that for even n there is always an answer. 
On i-th shelf we will place items with prices i,i+n,i+2*n,..,i+n*(k−1). 
We can use the formula for the sum of an arithmetic progression to compute the sum of prices of a subsegment with coordinates i,l up to i,r:

sum=i*(r−l+1)+(n(l−1)+n(r−1)/2)*(r−l+1)==i*(r−l+1)+n/2*(l+r−2)*(r−l+1)==(r−l+1)*(i+n/2*(l+r−2))
The length of the segment (r−l+1) always divides this sum, since n is even. Therefore, this arrangement fits the requirements of the problem.
*/


#include<iostream>
#include<vector>
using namespace std;
using ll=long long;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin>>t;
	while(t--){
		int n, k;
		cin>>n>>k;
		vector<vector<int>>res(n, vector<int>(k, 0));
		if(k==1){
			cout<<"YES\n";
			for(int i=0; i<n; ++i){
				res[i][0]=i+1;
			}
			for(auto &vals: res){
				for(auto &nums: vals)
					cout<<nums<<" ";
				cout<<"\n";
			}
			continue;
		} else if(n==1){
			if(k>=2){
				cout<<"NO\n";
				continue;
			}
		} else{
			if(n%2!=0){
				cout<<"NO\n";
			} else{
				int bgnevn=2, bgnodd=1, evn=bgnevn, odd=bgnodd;
				for(int i=0; i<n; ++i){
					for(int j=0; j<k; ++j){
						if(i%2==0){
							res[i][j]=odd;
							odd+=n;
						} else{
							res[i][j]=evn;
							evn+=n;
						}
					}
					if(i%2==0){
						bgnodd+=2;
						odd=bgnodd;
					}
					else{
						bgnevn+=2;
						evn=bgnevn;
					}
				}
				cout<<"YES\n";
				for(auto &vals: res){
					for(auto &nums: vals){
						cout<<nums<<" ";
					}
					cout<<"\n";
				}
			}
		}
	}
}
