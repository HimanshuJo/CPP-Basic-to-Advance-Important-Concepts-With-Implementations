#include<bits/stdc++.h>
using namespace std;
using ll=long long;

#define N 51
const int mod=998244353;
int n, k;
ll cal[N][N], fac[N];
map<int, ll>dp[N];

ll gcd(ll A, ll B){
	if(B==0) return A;
	return (gcd(B, A%B));
}

ll lcm(ll A, ll B){
	return (A*B/gcd(A, B));
}

ll qpow(ll A, ll B){
	ll res=1;
	while(B){
		if(B&1){
			res=res*A%mod;
		}
		A=A*A%mod;
		B>>=1;
	}
	return res;
}

int main(){
	cin>>n>>k;
	cal[0][0]=1;
	for(int i=1; i<=n; ++i){
		cal[i][0]=1;
		for(int j=1; j<=i; ++j){
			cal[i][j]=(cal[i-1][j]+cal[i-1][j-1])%mod;
		}
	}
	fac[0]=fac[1]=1;
	for(ll i=2; i<=n; ++i){
		fac[i]=fac[i-1]*i%mod;
	}
	dp[0][1]=1;
	int maxx=1;
	for (int i=0 ; i<=n ; i++)
		for (int j=1 ; j<=maxx ; j++){
			if (!dp[i][j]) continue;
			for (int x=1 ; i+x<=n ; x++){
				dp[i+x][lcm(j,x)]+=dp[i][j]*cal[n-i-1][x-1]%mod*fac[x-1]%mod;
				dp[i+x][lcm(j,x)]%=mod;
				maxx=max(maxx,lcm(j,x));
			}
		}	
	ll ans=0;
	for(int j=1; j<=maxx; ++j){
		if(dp[n][j]!=0){
			ans=(ans+dp[n][j]*qpow(j, k)%mod)%mod;
		}
	}
	cout<<ans%mod<<"\n";
}

