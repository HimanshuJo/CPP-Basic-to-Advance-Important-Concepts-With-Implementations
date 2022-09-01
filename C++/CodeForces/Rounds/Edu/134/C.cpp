// C. Min-Max Array Transformation
/*
You are given an array a1,a2,…,an, which is sorted in non-descending order. You decided to perform the 
following steps to create array b1,b2,…,bn:

Create an array d consisting of n arbitrary non-negative integers.
Set bi=ai+di for each bi.
Sort the array b in non-descending order.
You are given the resulting array b. For each index i, calculate what is the minimum and maximum 
possible value of di you can choose in order to get the given array b.

Note that the minimum (maximum) di-s are independent of each other, i. e. they can be obtained 
from different possible arrays d.

Example
input
4
3
2 3 5
7 11 13
1
1000
5000
4
1 2 3 4
1 2 3 4
4
10 20 30 40
22 33 33 55

output
5 4 2
11 10 8
4000
4000
0 0 0 0
0 0 0 0
12 2 3 15
23 13 3 15

Note
In the first test case, in order to get dmin1=5, we can choose, 
for example, d=[5,10,6]. Then b = [2+5,3+10,5+6] = [7,13,11] = [7,11,13].

For dmin2=4, we can choose d = [9,4,8]. Then b = [2+9,3+4,5+8] = [11,7,13] = [7,11,13].
*/

/*
TLE

#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin>>t;
	while(t--){
        int n;
        cin>>n;
        vector<int>in1(n);
        for(int i=0; i<n; ++i){
            cin>>in1[i];
        }

        vector<int>in2(n);
        for(int i=0; i<n; ++i){
            cin>>in2[i];
        }
        vector<int>ans1(n, 0);
        vector<int>ans2(n, 0);
        if(in1!=in2){
            for(int i=0; i<n; ++i){
                auto it=lower_bound(in2.begin(), in2.end(), in1[i]);
                int idx=it-in2.begin();
				ans1[i]=in2[idx]-in1[i];
            }
			int curselnum=-1, prevselnum=-1, end=n-1, tmpj=n-1;
			for(int i=0; i<n; ++i){
				while(true){
					if(end-1<0){
						curselnum=-1;
						break;
					}
					bool flag=false;
					curselnum=in2[end];
					prevselnum=in2[end-1];
					int tmpprevend=end-1;
					for(int j=tmpj; j>i; --j){
						int curnum=in1[j];
						if(prevselnum<curnum){
							flag=true;
							break;
						} else{
							if(tmpprevend-1<0) break;
							tmpprevend--;
							prevselnum=in2[tmpprevend];
						}
					}
					if(!flag) break;
					else{
						end--;
						if(end<0){
							curselnum=-1;
							break;
						}
						tmpj-=1;
					}
				}
				if(curselnum==-1){
					ans2[i]=in2[i]-in1[i];
				} else{
					ans2[i]=curselnum-in1[i];
				}
				curselnum=-1, prevselnum=-1, end=n-1, tmpj=n-1;
			}
        }
        for(auto &vals: ans1){
            cout<<vals<<" ";
        }
        cout<<"\n";
        for(auto &vals: ans2){
            cout<<vals<<" ";
        }
        cout<<"\n";
	}
}
*/

#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin>>t;
	while(t--){
        int n;
        cin>>n;
        vector<int>in1(n);
        for(int i=0; i<n; ++i){
            cin>>in1[i];
        }
        vector<int>in2(n);
        for(int i=0; i<n; ++i){
            cin>>in2[i];
        }
        vector<int>ans1(n, 0);
        vector<int>ans2(n, 0);
		int prevmxidx=n-1;
        if(in1!=in2){
            for(int i=n-1; i>=0; --i){
                auto it=lower_bound(in2.begin(), in2.end(), in1[i]);
                int idx=it-in2.begin();
				ans1[i]=in2[idx]-in1[i];
				ans2[i]=in2[prevmxidx]-in1[i];
				if(idx==i){
					prevmxidx=i-1;
				}
            }
        }
        for(auto &vals: ans1){
            cout<<vals<<" ";
        }
        cout<<"\n";
        for(auto &vals: ans2){
            cout<<vals<<" ";
        }
        cout<<"\n";
	}
}