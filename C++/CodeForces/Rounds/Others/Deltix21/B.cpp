// B. William the Vigilant
/*
Before becoming a successful trader William got a university degree. During his education an interesting situation happened, after which William started to 
listen to homework assignments much more attentively. What follows is the correct formal description of the homework assignment:

You are given a string s of length n only consisting of characters "a", "b" and "c". There are q queries of format (pos,c), meaning replacing the element of
string s at position pos with character c. After each query you must output the minimal number of characters in the string, which have to be replaced, so that 
the string doesn't contain string "abc" as a substring. A valid replacement of a character is replacing it with "a", "b" or "c".

A string x is a substring of a string y if x can be obtained from y by deletion of several (possibly, zero or all) characters from the beginning and several 
(possibly, zero or all) characters from the end.

Example
input
9 10
abcabcabc
1 a
1 b
2 c
3 a
4 b
5 c
8 a
9 b
1 c
4 a
output
3
2
2
2
1
2
1
1
1
0
*/
#include<string>
#include<vector>
#include<iostream>
#include<map>
using namespace std;

void computeLPSArray(string pat, int M, int lps[])
{
	int len = 0;
	int i = 1;
	lps[0] = 0;
	while (i < M)
	{
		if (pat[i] == pat[len])
		{
			len++;
			lps[i] = len;
			i++;
		}
		else
		{
			if (len != 0)
			{
				len = lps[len - 1];
			}
			else
			{
				lps[i] = len;
				i++;
			}
		}
	}
}

int KMPSearch(string pat, string txt)
{
	int M = pat.length();
	int N = txt.length();
	int lps[M];
	int j = 0;
	computeLPSArray(pat, M, lps);
	int i = 0;
	int res = 0;
	int next_i = 0;
	while (i < N)
	{
		if (pat[j] == txt[i])
		{
			j++;
			i++;
		}
		if (j == M)
		{
			j = lps[j - 1];
			res++;
		}
		else if (i < N && pat[j] != txt[i])
		{
			if (j != 0)
				j = lps[j - 1];
			else
				i = i + 1;
		}
	}
	return res;
}

bool hasSubstr(int id, string S)
{
	for(int d=-2;d<=0;d++)
	{
		if(id+d>=0&&S.substr(id+d,3)=="abc") return true;
	}
	return false;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, q;
	cin>>n>>q;
	string s;
	cin>>s;
	int res=KMPSearch("abc", s);
	for(int i=0; i<q; ++i){
		int in;
		char c;
		cin>>in;
		in--;
		cin>>c;
		if(hasSubstr(in, s)) res--;
		s[in]=c;
		if(hasSubstr(in, s)) res++;
		cout<<res<<"\n";
	}
}

