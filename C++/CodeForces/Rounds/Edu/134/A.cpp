// A. Image
/*
You have an image file of size 2×2, consisting of 4 pixels. Each pixel can have one of 26 
different colors, denoted by lowercase Latin letters.

You want to recolor some of the pixels of the image so that all 4 pixels have the same color. 
In one move, you can choose no more than two pixels of the same color and paint them into some other 
color (if you choose two pixels, both should be painted into the same color).

What is the minimum number of moves you have to make in order to fulfill your goal?

Example
input
5
rb
br
cc
wb
aa
aa
ab
cd
yy
xx

output
1
2
0
3
1

Note
Let's analyze the test cases of the example.

In the first test case, you can paint the bottom left pixel and the top right pixel (which share the same color) 
into the color r, so all pixels have this color.

In the second test case, two moves are enough:

paint both top pixels, which have the same color c, into the color b;
paint the bottom left pixel into the color b.
In the third test case, all pixels already have the same color.

In the fourth test case, you may leave any of the pixels unchanged, and paint all three other pixels 
into the color of that pixel in three moves.

In the fifth test case, you can paint both top pixels into the color x.
*/

#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin>>t;
	while(t--){
		vector<vector<char>>in(2, vector<char>(2));
		for(int i=0; i<2; ++i){
			for(int j=0; j<2; ++j){
				cin>>in[i][j];
			}
		}
		int ans=INT_MAX;
		vector<vector<char>>temp=in;
		char currcolr=temp[0][0];
		int curcount=0;
		for(int i=0; i<2; ++i){
			for(int j=0; j<2; ++j){
				if(temp[i][j]!=currcolr){
					curcount++;
					char nxtcolor=temp[i][j];
					temp[i][j]=currcolr;
					for(int ii=0; ii<2; ++ii){
						for(int jj=0; jj<2; ++jj){
							if(temp[ii][jj]==nxtcolor){
								temp[ii][jj]=currcolr;
							}
						}
					}
				}
			}
		}
		ans=min(ans, curcount);
		temp=in;
		currcolr=temp[0][1];
		curcount=0;
		for(int i=0; i<2; ++i){
			for(int j=0; j<2; ++j){
				if(temp[i][j]!=currcolr){
					curcount++;
					char nxtcolor=temp[i][j];
					temp[i][j]=currcolr;
					for(int ii=0; ii<2; ++ii){
						for(int jj=0; jj<2; ++jj){
							if(temp[ii][jj]==nxtcolor){
								temp[ii][jj]=currcolr;
							}
						}
					}
				}
			}
		}
		ans=min(ans, curcount);
		temp=in;
		currcolr=temp[1][0];
		curcount=0;
		for(int i=0; i<2; ++i){
			for(int j=0; j<2; ++j){
				if(temp[i][j]!=currcolr){
					curcount++;
					char nxtcolor=temp[i][j];
					temp[i][j]=currcolr;
					for(int ii=0; ii<2; ++ii){
						for(int jj=0; jj<2; ++jj){
							if(temp[ii][jj]==nxtcolor){
								temp[ii][jj]=currcolr;
							}
						}
					}
				}
			}
		}
		ans=min(ans, curcount);
		temp=in;
		currcolr=temp[1][1];
		curcount=0;
		for(int i=0; i<2; ++i){
			for(int j=0; j<2; ++j){
				if(temp[i][j]!=currcolr){
					curcount++;
					char nxtcolor=temp[i][j];
					temp[i][j]=currcolr;
					for(int ii=0; ii<2; ++ii){
						for(int jj=0; jj<2; ++jj){
							if(temp[ii][jj]==nxtcolor){
								temp[ii][jj]=currcolr;
							}
						}
					}
				}
			}
		}
		ans=min(ans, curcount);
		cout<<ans<<endl;
	}
}