// A. Working Week
/*
Your working week consists of n days numbered from 1 to n, after day n goes day 1 again. 
And 3 of them are days off. One of the days off is the last day, day n. 
You have to decide when the other two are.

Choosing days off, you pursue two goals:

No two days should go one after the other. Note that you can't make day 1 a day off because it follows day n.

Working segments framed by days off should be as dissimilar as possible in duration. 
More specifically, if the segments are of size l1, l2, and l3 days long, you want to maximize min(|l1−l2|,|l2−l3|,|l3−l1|).

Output the maximum value of min(|l1−l2|,|l2−l3|,|l3−l1|) that can be obtained.

Input
The first line of the input contains a single integer t (1≤t≤1000) — 
the number of test cases. The description of test cases follows.

The only line of each test case contains the integer n (6≤n≤10^9).

Output
For each test case, output one integer — the maximum possible obtained value.

Example
input
3
6
10
1033

output
0
1
342

Note
In the image below you can see the example solutions for the first two test cases. 
Chosen days off are shown in purple. Working segments are underlined in green.

In test case 1, the only options for days off are days 2, 3, and 4 (because 1 and 5 are next to day n). 
So the only way to place them without selecting neighboring days is to choose days 2 and 4. 
Thus, l1=l2=l3=1, and the answer min(|l1−l2|,|l2−l3|,|l3−l1|)=0.
*/

/*
TLE:

#include<iostream>
#include<algorithm>
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
		int ans=0;
		for(int i=2; i<=N-2; ++i){
			int frstval=2;
			for(int j=i+1; j<=N-2; ++j){
				if(abs(i-j)!=1&&abs(j-N)!=1){
					int secVal=j;
					int frstseg=abs(1-frstval), secseg=abs((frstval+1)-secVal), thrdseg=abs(secVal-(N-1));
					int frstdiff=abs(frstseg-secseg), secdiff=abs(secseg-thrdseg), thrddiff=abs(thrdseg-frstseg);
					ans=max(ans, min(frstdiff, min(secdiff, thrddiff)));
				}
			}
		}
		cout<<ans<<endl;
	}
}
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
		cout<<((N-3)/3)-1<<endl;
	}
}