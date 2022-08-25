// B. Absent Remainder
/*
You are given a sequence a1,a2,…,an consisting of n pairwise distinct positive integers.

Find ⌊n/2⌋ different pairs of integers x and y such that:

x≠y;
x and y appear in a;
x mod y doesn't appear in a.
Note that some x or y can belong to multiple pairs.

⌊x⌋ denotes the floor function — the largest integer less than or equal to x. x mod y denotes the remainder from dividing x by y.

If there are multiple solutions, print any of them. It can be shown that at least one solution always exists.

Input
The first line contains a single integer t (1≤t≤10^4) — the number of testcases.

The first line of each testcase contains a single integer n (2≤n≤2⋅10^5) — the length of the sequence.

The second line of each testcase contains n integers a1,a2,…,an (1≤ai≤10^6).

All numbers in the sequence are pairwise distinct. The sum of n over all testcases doesn't exceed 2⋅10^5.

Output
The answer for each testcase should contain ⌊n/2⌋ different pairs of integers x and y such that x≠y, 
x and y appear in a and x mod y doesn't appear in a. Print the pairs one after another.

You can print the pairs in any order. However, the order of numbers in the pair should be exactly
such that the first number is x and the second number is y. All pairs should be pairwise distinct.

If there are multiple solutions, print any of them.

Example
input
4
2
1 4
4
2 8 3 4
5
3 8 5 9 7
6
2 7 5 3 4 8

output
4 1
8 2
8 4
9 5
7 5
8 7
4 3
5 2
Note
In the first testcase there are only two pairs: (1,4) and (4,1). ⌊2/2⌋=1, so we have to find one pair. 
1 mod 4=1, and 1 appears in a, so that pair is invalid. Thus, the only possible answer is a pair (4,1).

In the second testcase, we chose pairs 8 mod 2=0 and 8 mod 4=0. 0 doesn't appear in a, so that answer is valid. 
There are multiple possible answers for that testcase.

In the third testcase, the chosen pairs are 9 mod 5=4 and 7 mod 5=2. Neither 4, nor 2, appears in a, so that answer is valid.

*/
/*
Solution:

There is one important observation: x mod y<y.

Thus, you can obtain at least n−1 pair by choosing y as the minimum number in the sequence and 
x as anything else. n−1≥⌊n2⌋ for any positive n.

Overall complexity: O(n) per testcase.

#include <bits/stdc++.h>

using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &x : a) cin >> x;
    int mn = *min_element(a.begin(), a.end());
    for (int i = 0, k = 0; k < n / 2; ++i) if (a[i] != mn) {
      cout << a[i] << ' ' << mn << '\n';
      k += 1;
    }
  }
}
*/

#include<iostream>
#include<vector>
#include<map>
#include<cmath>
#include<set>
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
		vector<int>in(n);
		vector<int>evnNms;
		map<int, int>mp;
		for(int i=0; i<n; ++i){
			cin>>in[i];
			if(in[i]%2==0){
				evnNms.push_back(in[i]);
			}
			mp[in[i]]++;
		}
		vector<pair<int, int>>res;
		set<pair<int, int>>seen;
		int lm=floor(n/2);
		sort(in.begin(), in.end());
		sort(evnNms.begin(), evnNms.end());
		int end_=evnNms.size()-1;
		bool flag=false;
		for(int i=0; i<evnNms.size(); ++i){
			pair<int, int>curr={evnNms[end_], evnNms[i]};
			int toChk=evnNms[end_]%evnNms[i];
			if(mp.find(toChk)==mp.end()&&seen.find({curr})==seen.end()&&evnNms[end_]!=evnNms[i]){
				res.push_back(curr);
				seen.insert(curr);
				lm--;
			}
			if(lm==0){
				flag=true;
				break;
			} 
		}
		if(!flag){
			if(end_>0){
				end_--;
				while(end_!=0){
					for(int i=0; i<end_; ++i){
						pair<int, int>curr={evnNms[end_], evnNms[i]};
						int toChk=evnNms[end_]%evnNms[i];
						if(mp.find(toChk)==mp.end()&&seen.find({curr})==seen.end()&&evnNms[end_]!=evnNms[i]){
							res.push_back(curr);
							seen.insert(curr);
							lm--;
						}
						if(lm==0){
							flag=true;
							break;
						}
						end_--;
					}
					if(flag||end_==0) break;
				}
			}
		}
		if(!flag){
			int start=0;
			while(lm){
				for(int i=start+1; i<in.size(); ++i){
					pair<int, int>curr={in[i], in[0]};
					int toChk=in[i]%in[0];
					if(mp.find(toChk)==mp.end()&&seen.find({curr})==seen.end()&&in[i]!=in[0]){
						res.push_back(curr);
						seen.insert(curr);
						lm--;
						if(lm==0) break;
					}
				}
				if(lm==0) break;
			}
		}
		for(auto &vals: res){
			cout<<vals.first<<" "<<vals.second<<endl;
		}
	}
}