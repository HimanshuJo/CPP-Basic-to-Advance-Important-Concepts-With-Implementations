#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<string>
#include<queue>
#include<unordered_map>
#include<map>
#include<unordered_set>
#include<set>
#define endl "\n"
using namespace std;
using ll=long long;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--){
        ll a, b, c;
        cin>>a>>b>>c;
        ll timefrele1=abs(a-1);
        ll timefrele2=abs(b-c)+abs(1-c);
        if(timefrele1==timefrele2){
            cout<<3<<endl;
        } else if(timefrele2<timefrele1){
            cout<<2<<endl;
        } else{
            cout<<1<<endl;
        }
    }
}