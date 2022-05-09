//Minimum Number of Buckets Required to Collect Rainwater from Houses
/*
You are given a 0-indexed string street. Each character in street is either 'H' representing a house or '.' representing an empty space.

You can place buckets on the empty spaces to collect rainwater that falls from the adjacent houses. 
The rainwater from a house at index i is collected if a bucket is placed at index i - 1 and/or index i + 1. 
A single bucket, if placed adjacent to two houses, can collect the rainwater from both houses.

Return the minimum number of buckets needed so that for every house, there is at least one bucket collecting rainwater from it, or -1 if it is impossible.

Example 2:

Input: street = ".H.H."
Output: 1
Explanation:
We can put a bucket at index 2.
".H.H." -> ".HBH." ('B' denotes where a bucket is placed).
The house at index 1 has a bucket to its right, and the house at index 3 has a bucket to its left.
Thus, for every house, there is at least one bucket collecting rainwater from it.
*/

#include<vector>
#include<string>
#include<iostream>
using namespace std;

/*
Intuition :

Idea is really simple, we need to match pattern for each house 'H'.

We check for adjacent elements of each 'H', and assign buckets if possible.

Now, also note that if we have empty space before as well as after current house H,

then we always put bucket next to current house.
This is due to the reason that, we can have a house next to bucket that we placed.
i.e * . H . H * , so this will become * . H B H *, and we have used least amount of bucket.
Following Cases can be generallized , if street[i] == 'H' :

  Note : "*" means there can be one/more characters 
  
  Case 1 :   [ B 'H' * ], 
  	-> this means we already have a bucket adjacent to current house H, so we can continue
  
  Case 2 : [ * 'H' . ]
  	-> next adjacent is an empty space. So we place bucket at i+1 index. And move ahead.
  	-> This would also handle the case when we have empty spaces at both adjacent element.
  	-> So, we will priortize the one which is in right of current house.
  	
  Case 3 : [ . 'H' H ]
  	-> in this case we are left with no option but to place a bucket at i-1 index. And move ahead
  	-> since we have a house to right of current house H.
  	
  Case 4 : [H 'H' H] or [ 'H' H ] or [H 'H'] or ['H']
  	-> At last if none of the above cases occur. 
  	-> We can conclude that current house H has no empty space either on left or on right side.
  	-> Or we have end of street on either side
  	-> Thus it is impossible to place bucket. and return -1.
*/

class Solution {
	public:
		int minimumBuckets(string street) {
			int n=street.size(), count=0;
			for(int i=0; i<n; ++i){
				if(street[i]=='H'){
					if(i-1>=0&&street[i-1]=='B') continue;
					else if(i+1<n&&street[i+1]=='.'){
						street[i+1]='B';
						count++;
					} else if(i-1>=0&&street[i-1]=='.'){
						street[i-1]='B';
						count++;
					} else return -1;
				}
			}
			return count;
		}
};

int main(){}
