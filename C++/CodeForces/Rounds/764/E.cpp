// E. Masha-forgetful
/*
Masha meets a new friend and learns his phone number — s. She wants to remember it as soon as possible. 
The phone number — is a string of length m that consists of digits from 0 to 9. The phone number may start with 0.

Masha already knows n phone numbers (all numbers have the same length m). 
It will be easier for her to remember a new number if the s is represented as segments of
numbers she already knows. Each such segment must be of length at least 2, otherwise there will be too many segments 
and Masha will get confused.

For example, Masha needs to remember the number: s= '12345678' and she already knows n=4 numbers: '12340219', '20215601', '56782022', '12300678'. 
You can represent s as a 3 segment: '1234' of number one, '56' of number two, and '78' of number three. There are other ways to represent s.

Masha asks you for help, she asks you to break the string s into segments of length 2 or more of the numbers she already knows. 
If there are several possible answers, print any of them.

Example
input
5

4 8
12340219
20215601
56782022
12300678
12345678

2 3
134
126
123

1 4
1210
1221

4 3
251
064
859
957
054

4 7
7968636
9486033
4614224
5454197
9482268

output
3
1 4 1
5 6 2
3 4 3
-1
2
1 2 1
2 3 1
-1
3
1 3 2
5 6 3
3 4 1
*/

#include<algorithm>
#include<vector>
#include<iostream>
#include<map>
#include<tuple>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin>>t;
	while(t--){
		int n, m;
		cin>>n>>m;
		vector<bool>dp(m+1, false);
		map<string, bool>seen;
		map<string, tuple<int, int, int>>pos;
		vector<int>pr(m+1);
		vector<string>cache;
		dp[0]=true;
		for(int i=0; i<n; ++i){
			string s;
			cin>>s;
			for(int j=0; j<m; ++j){
				string t;
				t+=s[j];
				for(int k=1; k<=2; ++k){
					if(k+j>=m) break;
					t+=s[k+j];
					if(!seen[t]){
						seen[t]=true;
						pos[t]=make_tuple(j, j+k, i);
						cache.push_back(t);
					}
				}
			}
		}
		string s;
		cin>>s;
		for(int i=0; i<m; ++i){
			string t;
			t+=s[i];
			for(int k=1; k<=2; ++k){
				if(i-k<0) break;
				t=s[i-k]+t;
				if(seen[t]&&dp[i-k]){
					dp[i+1]=true;
					pr[i+1]=i-k;
				}
				if(dp[i+1]) break;
			}
		}
		for(string t: cache){
			seen[t]=false;
		}
		if(!dp[m]){
			cout<<"-1\n";
			continue;
		}
		vector<tuple<int, int, int>>ans;
		for(int k=m; k>0;){
			int p=pr[k];
			string t=s.substr(p, k-p);
			ans.emplace_back(pos[t]);
			k=p;
		}
		cout<<(ans.size())<<"\n";
		reverse(ans.begin(), ans.end());
		for(auto &vals: ans){
			cout<<get<0>(vals)+1<<" "<<get<1>(vals)+1<<" "<<get<2>(vals)+1<<endl;
		}
	}
}

