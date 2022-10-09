// A. Glory Addicts
/*
The hero is addicted to glory, and is fighting against a monster.

The hero has n skills. The i-th skill is of type ai (either fire or frost) and has initial damage bi.

The hero can perform all of the n skills in any order (with each skill performed exactly once). 
When performing each skill, the hero can play a magic as follows:

If the current skill immediately follows another skill of a different type, then its damage is doubled.
In other words,
If a skill of type fire and with initial damage c is performed immediately after a skill of type fire, then it will deal c damage;
If a skill of type fire and with initial damage c is performed immediately after a skill of type frost, then it will deal 2c damage;
If a skill of type frost and with initial damage c is performed immediately after a skill of type fire, then it will deal 2c damage;
If a skill of type frost and with initial damage c is performed immediately after a skill of type frost , then it will deal c damage.
Your task is to find the maximum damage the hero can deal.

Input
Each test contains multiple test cases. The first line contains an integer t (1≤t≤10^5) — the number of test cases. 
The following lines contain the description of each test case.

The first line of each test case contains an integer n (1≤n≤10^5), indicating the number of skills.

The second line of each test case contains n integers a1,a2,…,an (0≤ai≤1), where ai indicates the type of the i-th skill.
Specifically, the i-th skill is of type fire if ai=0, and of type frost if ai=1.

The third line of each test case contains n integers b1,b2,…,bn (1≤bi≤10^9), where bi indicates the initial damage of the i-th skill.

It is guaranteed that the sum of n over all test cases does not exceed 10^5.

Output
For each test case, output the maximum damage the hero can deal.

Example
input
4
4
0 1 1 1
1 10 100 1000
6
0 0 0 1 1 1
3 4 5 6 7 8
3
1 1 1
1000000000 1000000000 1000000000
1
1
1

output
2112
63
3000000000
1

Note
In the first test case, we can order the skills by [3,1,4,2], and the total damage is 100+2×1+2×1000+10=2112.

In the second test case, we can order the skills by [1,4,2,5,3,6], and the total damage is 3+2×6+2×4+2×7+2×5+2×8=63.

In the third test case, we can order the skills by [1,2,3], and the total damage is 1000000000+1000000000+1000000000=3000000000.

In the fourth test case, there is only one skill with initial damage 1, so the total damage is 1.
*/

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
		vector<int>skl(N);
		for(int i=0; i<N; ++i){
			cin>>skl[i];
		}
		vector<int>dmg(N);
		for(int i=0; i<N; ++i){
			cin>>dmg[i];
		}
		vector<vector<int>>comb;
		for(int i=0; i<N; ++i){
			comb.push_back({skl[i], dmg[i]});
		}
		sort(comb.begin(), comb.end());
		vector<int>zeros, ones;
		for(auto &vals: comb){
			if(vals[0]==0){
				zeros.push_back(vals[1]);
			} else{
				ones.push_back(vals[1]);
			}
		}
		if(zeros.size()==ones.size()){
			if(zeros[0]<=ones[0]){
				long long ans=0;
				ans+=zeros[0];
				for(int i=1; i<zeros.size(); ++i){
					ans+=(zeros[i]*2);
				}
				for(int i=0; i<ones.size(); ++i){
					ans+=(ones[i]*2);
				}
				cout<<ans<<endl;
			} else{
				long long ans=0;
				ans+=ones[0];
				for(int i=1; i<ones.size(); ++i){
					ans+=(ones[i]*2);
				}
				for(int i=0; i<zeros.size(); ++i){
					ans+=(zeros[i]*2);
				}
				cout<<ans<<endl;
			}
		} else if(zeros.size()==0&&ones.size()>=1){
			long long ans=0;
			for(int i=0; i<ones.size(); ++i){
				ans+=ones[i];
			}
			cout<<ans<<endl;
		} else if(ones.size()==0&&zeros.size()>=1){
			long long ans=0;
			for(int i=0; i<zeros.size(); ++i){
				ans+=zeros[i];
			}
			cout<<ans<<endl;
		} else if(zeros.size()<ones.size()){
			long long ans=0;
			ans+=(zeros[0]*2);
			ans+=ones[0];
			int sz=ones.size()-1;
			for(int i=1; i<zeros.size(); ++i){
				ans+=(zeros[i]*2);
				if(sz!=0){
					ans+=(ones[sz]*2);
					sz--;
				}
			}
			if(sz!=0){
				ans+=(ones[sz]*2);
				sz--;
			}
			if(sz>=1){
				for(int i=sz; i>=1; --i){
					ans+=ones[i];
				}
			}
			cout<<ans<<endl;
		} else{
			long long ans=0;
			ans+=(ones[0]*2);
			ans+=zeros[0];
			int sz=zeros.size()-1;
			for(int i=1; i<ones.size(); ++i){
				ans+=(ones[i]*2);
				if(sz!=0){
					ans+=(zeros[sz]*2);
					sz--;
				}
			}
			if(sz!=0){
				ans+=(zeros[sz]*2);
				sz--;
			}
			if(sz>=1){
				for(int i=sz; i>=1; --i){
					ans+=zeros[i];
				}
			}
			cout<<ans<<endl;
		}
	}
}