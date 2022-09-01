// E. Counting Rectangles
/*
You have n rectangles, the i-th rectangle has height hi and width wi.

You are asked q queries of the form hs ws hb wb.

For each query output, the total area of rectangles you own that can fit a rectangle of 
height hs and width ws while also fitting in a rectangle of height hb and width wb. 

In other words, print ∑hi⋅wi for i such that hs<hi<hb and ws<wi<wb.

Please note, that if two rectangles have the same height or the same width, then they cannot 
fit inside each other. Also note that you cannot rotate rectangles.

Please note that the answer for some test cases won't fit into 32-bit integer type, so 
you should use at least 64-bit integer type in your programming language (like long long for C++).

Input
The first line of the input contains an integer t (1≤t≤100) — the number of test cases.

The first line of each test case two integers n,q (1≤n≤10^5; 1≤q≤10^5) — the number of rectangles 
you own and the number of queries.

Then n lines follow, each containing two integers hi,wi (1≤hi,wi≤1000) — the height and width of the i-th rectangle.

Then q lines follow, each containing four integers hs,ws,hb,wb (1≤hs<hb, ws<wb≤1000) — the description of each query.

The sum of q over all test cases does not exceed 105, and the sum of n over all test cases does not exceed 10^5.

Output
For each test case, output q lines, the i-th line containing the answer to the i-th query.

Example
input
3
2 1
2 3
3 2
1 1 3 4
5 5
1 1
2 2
3 3
4 4
5 5
3 3 6 6
2 1 4 5
1 1 2 10
1 1 100 100
1 1 3 3
3 1
999 999
999 999
999 998
1 1 1000 1000

output
6
41
9
0
54
4
2993004

In the first test case, there is only one query. We need to find the sum of areas of all rectangles 
that can fit a 1×1 rectangle inside of it and fit into a 3×4 rectangle.

Only the 2×3 rectangle works, because 1<2 (comparing heights) and 1<3 (comparing widths), 
so the 1×1 rectangle fits inside, and 2<3 (comparing heights) and 3<4 (comparing widths), 
so it fits inside the 3×4 rectangle. The 3×2 rectangle is too tall to fit in a 3×4 rectangle. 

The total area is 2⋅3=6.
*/

/*
TLE

#include<iostream>
#include<vector>
#define ll long long
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--){
		int n, q;
		cin>>n>>q;
		vector<pair<int, int>>in;
		for(int i=0; i<n; ++i){
			int hi, wi;
			cin>>hi>>wi;
			in.push_back({hi, wi});
		}
		vector<vector<int>>queries;
		for(int i=0; i<q; ++i){
			vector<int>temp;
			int hs, ws, hb, wb;
			cin>>hs>>ws>>hb>>wb;
			temp.push_back(hs);
			temp.push_back(ws);
			temp.push_back(hb);
			temp.push_back(wb);
			queries.push_back(temp);
		}
		vector<ll>res(q);
        int idx=0;
        for(auto &entries: queries){
            ll curar=0;
            for(auto &vals: in){
                pair<int, int>frst, sec;
                if(entries[0]<vals.first&&entries[1]<vals.second){
                    if(entries[2]>vals.first&&entries[3]>vals.second){
                        curar+=vals.first*vals.second;
                    }
                }
            }
            res[idx++]=curar;
        }
		for(int i=0; i<q; ++i){
			cout<<res[i]<<endl;
		}
	}
}
*/

#include<iostream>
#include<vector>
#define ll long long
#define endl "\n"
using namespace std;

ll a[1005][1005];
ll prefsm[1005][1005];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--){
		ll n, q;
		cin>>n>>q;
        for(int i=0; i<=1001; ++i){
            for(int j=0; j<=1001; ++j){
                a[i][j]=prefsm[i][j]=0;
            }
        }
        for(int i=0; i<n; ++i){
            ll h, w;
            cin>>h>>w;
            a[h][w]+=h*w;
        }
        for(int i=0; i<1000; ++i){
            for(int j=1; j<1000; ++j){
                prefsm[i][j]=prefsm[i-1][j]+prefsm[i][j-1]-prefsm[i-1][j-1]+a[i][j];
            }
        }
        for(int i=0; i<q; ++i){
            ll hs, ws, hb, wb;
            cin>>hs>>ws>>hb>>wb;
            cout<<prefsm[hb-1][wb-1]-prefsm[hb-1][ws]-prefsm[hs][wb-1]+prefsm[hs][ws]<<endl;
        }
	}
}