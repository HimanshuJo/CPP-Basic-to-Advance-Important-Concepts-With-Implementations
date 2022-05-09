#include<vector>
#include<iostream>
#include<unordered_map>
using namespace std;

int spf[10001], mod=1e9+7, MAXN=10001;
    
void sieve(){
    spf[1]=1;
    for(int i=2; i<MAXN; ++i)
        spf[i]=i;
    for(int i=4; i<MAXN; i+=2)
        spf[i]=2;
    for(int i=3; i*i<MAXN; ++i){
        if(spf[i]==i){
            for(int j=i*i; j<MAXN; j+=i){
                if(spf[j]==j){
                    spf[j]=i;
                }
            }
        }
    }
}
    
vector<pair<int, int>>getFactors(int x){
    vector<pair<int, int>>factors;
    unordered_map<int, int>freqs;
    while(x!=1){
        freqs[spf[x]]++;
        x/=spf[x];
    }
    for(auto &entries: freqs){
        factors.push_back({entries.first, entries.second});
    }
    return factors;
}

int main()
{
	vector<pair<int, int>>factors;
	sieve();
	for(int i=2; i<=20; ++i){
		cout<<i<<" : "<<endl;
		factors=getFactors(i);
		for(auto &vals: factors){
			cout<<vals.first<<" "<<vals.second;
			cout<<endl;
		}
		cout<<"\n***---***\n";
		cout<<endl;
	}
}
