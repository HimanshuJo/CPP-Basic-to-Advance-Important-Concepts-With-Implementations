#include<bits/stdc++.h>
using ll = long long;
using namespace std;

const int mod=1e9+7;

string to_binary(string str){
    string res="";
    ll curr=stol(str);
    while(curr!=1){
        if(curr%2==0){
            res+='0';
        } else{
            res+='1';
        }
        curr=curr/2;
    }
    res+='1';
    reverse(res.begin(), res.end());
	return res;
}

int power(long long x, unsigned int y, int p)
{
    int res = 1; 
    x = x % p;
    if (x == 0) return 0;
    while (y > 0)
    {
        if (y & 1)
            res = (res*x) % p;
        y = y>>1;
        x = (x*x) % p;
    }
    return res;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string k;
        cin>>k;
        string bk=to_binary(k);
        int sz=bk.length();
        int tmp=sz-1;
        ll ans=0;
        for(int i=0; i<sz; ++i){
            ans+=(bk[i]-'0')*power(n, tmp, mod);
            ans%=mod;
            tmp--;
        }
        cout<<ans<<"\n";
    }
}