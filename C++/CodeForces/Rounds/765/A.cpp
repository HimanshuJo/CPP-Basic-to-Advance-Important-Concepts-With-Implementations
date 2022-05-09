// A. Ancient Civilization
/*
Martian scientists explore Ganymede, one of Jupiter's numerous moons. Recently, they have found ruins of an ancient civilization. 
The scientists brought to Mars some tablets with writings in a language unknown to science.

They found out that the inhabitants of Ganymede used an alphabet consisting of two letters, and each word was exactly ℓ letters long. 
So, the scientists decided to write each word of this language as an integer from 0 to 2^l−1 inclusively. 
The first letter of the alphabet corresponds to zero bit in this integer, and the second letter corresponds to one bit.

The same word may have various forms in this language. Then, you need to restore the initial form. The process of doing it is described below.

Denote the distance between two words as the amount of positions, in which these words differ. 
For example, the distance between 10012 and 11002 (in binary) is equal to two, as these words have different letters in the second and the fourth positions, 
counting from left to right. Further, denote the distance between words x and y as d(x,y).

Let the word have n forms, the i-th of which is described with an integer xi. All the xi are not necessarily different, 
as two various forms of the word can be written the same. Consider some word y. 
Then, closeness of the word y is equal to the sum of distances to each of the word forms, i. e. the sum d(xi,y) over all 1<=i<=n.

The initial form is the word y with minimal possible nearness.

You need to help the scientists and write the program which finds the initial form of the word given all its known forms. Note that the initial form is not necessarily equal to any of the n given forms

Example
input
7
3 5
18 9 21
3 5
18 18 18
1 1
1
5 30
1 2 3 4 5
6 10
99 35 85 46 78 55
2 1
0 1
8 8
5 16 42 15 83 65 78 42

output
17
18
1
1
39
0
2
*/
#include<cmath>
#include<algorithm>
#include<iostream>
#include<vector>
#include<string>
#include<map>

using namespace std;

string toBinary(int num, int len){
	string ans="";
	if(num!=0){
		while(num!=1){
			if(num%2==0){
				ans+='0';
			} else ans+='1';
			num/=2;
		}
		ans+='1';
	} else ans+='0';
	if(ans.length()!=len){
		while(ans.length()!=len){
			ans+='0';
		}
	}
	reverse(ans.begin(), ans.end());
	return ans;
}

int toDec(string num){
	int ans=0;
	int n=num.length()-1;
	for(int i=0; i<num.length(); ++i){
		ans+=((num[i]-'0')*pow(2, n--));
	}
	return ans;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin>>t;
	while(t--){
		int n, l;
		cin>>n>>l;
		vector<int>in(n);
		for(int i=0; i<n; ++i){
			cin>>in[i];
		}
		vector<string>allbins;
		for(auto &vals: in){
			string curr=toBinary(vals, l);
			allbins.push_back(curr);
		}
		map<int, pair<int, int>>mp;
		for(auto &vals: allbins){
			int sz=vals.length();
			for(int x=0; x<sz; ++x){
				if(vals[x]=='0'){
					mp[x].first++;
				} else mp[x].second++;
			}
		}
		string res="";
		for(auto &entry: mp){
			if(entry.second.first>entry.second.second){
				res+='0';
			} else res+='1';
		}
		cout<<toDec(res)<<"\n";
	}
}

