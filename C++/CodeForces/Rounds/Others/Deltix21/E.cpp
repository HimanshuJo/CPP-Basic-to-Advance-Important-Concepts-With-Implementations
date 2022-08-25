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

bool hasNextSubstr(int id, string S){
	cout<<"a available "<<S<<endl;
	int len=S.length();
	if(id==len-1) return false;
	for(int i=id+1; i<len; ++i){
		if(S[i]=='b'){
			if(i+1<len){
				for(int x=i+1; x<len; ++x){
					if(S[x]=='c') return true;
				}
			}
		}
	}
	return false;
}

bool hasPrevSubstr(int id, string S){
	cout<<"c available "<<S<<endl;
	if(id==0||id==1) return false;
	int len=S.length();
	for(int i=id-1; i>=0; --i){
		if(S[i]=='b'){
			if(i-1>=0){
				for(int x=i-1; x>=0; --x){
					if(S[x]=='a') return true;
				}
			}
		}
	}
	return false;
}

bool hasPrevNextSubstr(int id, string S){
	cout<<"b available "<<S<<endl;
	int len=S.length();
	if(id==0||id==len-1) return false;
	bool flag1=false;
	for(int i=id-1; i>=0; --i){
		if(S[i]=='a'){
			flag1=true;
			break;
		}
	}
	if(flag1){
		for(int i=id+1; i<len; ++i){
			if(S[i]=='c'){
				return true;
			}
		}
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
		if(c=='a'){
	
			bool curr=hasNextSubstr(in, s);
			if(curr==true) res++;
		}
		else if(c=='b'){
		
			bool curr=hasPrevNextSubstr(in, s);
			if(curr==true) res++;
		}
		else if(c=='c'){
		
			bool curr=hasPrevSubstr(in, s);
			if(curr==true) res++;
		}
		cout<<res<<"\n";
		cout<<"-------\n";
	}
}


