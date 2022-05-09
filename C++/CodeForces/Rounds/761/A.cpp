// A. Forbidden Subsequence
/*
You are given strings S and T, consisting of lowercase English letters. It is guaranteed that T is a permutation of the string abc.

Find string S', the lexicographically smallest permutation of S such that T is not a subsequence of S'.

String a is a permutation of string b if the number of occurrences of each distinct character is the same in both strings.

A string a is a subsequence of a string b if a can be obtained from b by deletion of several (possibly, zero or all) elements.

A string a is lexicographically smaller than a string b if and only if one of the following holds:

a is a prefix of b, but a!=b;
in the first position where a and b differ, the string a has a letter that appears earlier in the alphabet than the corresponding letter in b.

Example
inputCopy
7
abacaba
abc
cccba
acb
dbsic
bac
abracadabra
abc
dddddddddddd
cba
bbc
abc
ac
abc
outputCopy
aaaacbb
abccc
bcdis
aaaaacbbdrr
dddddddddddd
bbc
ac
*/

#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

bool is_subsequence(string& s, string& sub)
{
	if(sub.length() > s.length()) return false;
	int pos = 0;
	for(char c : sub)
	{
		pos = s.find(c, pos);
		if(pos == string::npos) return false;
		++pos;
	}
	return true;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin>>t;
	while(t--){
		string s;
		cin>>s;
		string t;
		cin>>t;
		int n=s.length();
		int m=t.length();
		bool flag=false;
		for(int i=0; i<n; ++i){
			if(s[i]=='a'||s[i]=='b'||s[i]=='c'){
				flag=true;
				break;
			}
		}
		if(!flag){
			sort(s.begin(), s.end());
			cout<<s<<"\n";
			continue;
		}
		else{
			string temp=s;
			sort(temp.begin(), temp.end());
			string res="";
			int bgnIdx=0;
			bool flag_=false;
			char toChk;
			for(int i=0; i<n; ++i){
				res+=temp[i];
				if(is_subsequence(res, t)){
					flag_=true;
					bgnIdx=i;
					toChk=temp[bgnIdx];
					break;
				}
			}
			if(flag_){
				if(bgnIdx!=n-1){
					int cust;
					bool flag__=false;
					for(int i=bgnIdx; i<n; ++i){
						if(temp[i]!=toChk){
							cust=i;
							flag__=true;
							break;
						}
					}
					if(flag__){
						cust--;
						bgnIdx=cust;
					} else if(temp[n-1]==toChk){
						bgnIdx=n-1;
					}
				}
				char curr=temp[bgnIdx];
				char next;
				int bgnIdx_;
				int fnIdx;
				for(int i=bgnIdx; i>=0; --i){
					if(temp[i]!=curr){
						next=temp[i];
						bgnIdx_=i;
						break;
					}
				}
				for(int i=bgnIdx_; i>=0; --i){
					if(temp[i]!=next){
						fnIdx=i;
						break;
					}
				}
				fnIdx++;
				string nwTemp="";
				for(int i=fnIdx; i<=bgnIdx; ++i){
					nwTemp+=temp[i];
				}
				reverse(nwTemp.begin(), nwTemp.end());
				string fnRes="";
				for(int i=0; i<fnIdx; ++i){
					fnRes+=temp[i];
				}
				fnRes+=nwTemp;
				if(bgnIdx<n-1){
					for(int i=bgnIdx+1; i<n; ++i){
						fnRes+=temp[i];
					}
				}
				cout<<fnRes<<"\n";
			} else{
				cout<<temp<<"\n";
			}
		}
	}
}


