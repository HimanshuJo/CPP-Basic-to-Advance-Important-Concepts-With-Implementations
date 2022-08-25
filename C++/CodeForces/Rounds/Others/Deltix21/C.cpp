#include<iostream>
#include<vector>
#include<cmath>
#include<cstring>
using namespace std;
using ll=long long;

const int MAXN=1123456;
vector<bool> prime(MAXN, false), seen(MAXN, false);

void primes(){
	for(int i=2; i<MAXN; ++i){
		if(!seen[i]){
			prime[i]=true;
		}
		for(int j=i; j<MAXN; j+=i){
			seen[j]=true;
		}
	}
}

ll solve(int n, int e, const vector<int>&isOne, vector<int>&isPrime){
	vector<int>ones;
	vector<bool>grouped(n+1, false);
	ll ans=0;
	for(int i=1; i<=n; ++i){
		if(!grouped[i]){
			ones.clear();
			int currOnes=0;
			for(int j=i; j<=n; j+=e){
				if((!isOne[j]&&!isPrime[j])||grouped[j]) break;
				grouped[j]=true;
				if(isOne[j]) currOnes++;
				else{
					ones.push_back(currOnes);
					currOnes=0;
				}
			}
			if(ones.size()==0) continue;
			ones.push_back(currOnes);
			for(int j=0; j<ones.size(); ++j){
				ans+=ones[j];
				if(j>0&&j<ones.size()-1){
					ans+=ones[j];
				}
				if(j<ones.size()-1){
					ans+=(ll)(ones[j])*(ll)(ones[j+1]);
				}
			}
		}
	}
	return ans;
}


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin>>t;
	primes();
	while(t--){
		int n, e;
		cin>>n>>e;
		vector<int>isOne(n+1, 0);
		vector<int>isPrime(n+1, 0);
		for(int i=1; i<=n; ++i){
			int a;
			cin>>a;
			if(a==1){
				isOne[i]=1;
			} else if(prime[a]){
				isPrime[i]=1;
			}
		}
		ll res=solve(n, e, isOne, isPrime);
		cout<<res<<"\n";
	}
}
