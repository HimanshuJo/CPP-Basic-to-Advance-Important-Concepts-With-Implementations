#include<bits/stdc++.h>
using ll=long long;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int K;
    cin>>K;
    string A, B;
    cin>>A>>B;
    ll num1=0;
    ll num2=0;
    int l1=A.length()-1;
    int l2=B.length()-1;
    for(int i=0; i<A.length(); ++i){
        ll curr=A[i]-'0';
        num1+=curr*(pow(K, l1));
        l1--;
    }
    for(int i=0; i<B.length(); ++i){
        ll curr=B[i]-'0';
        num2+=curr*(pow(K, l2));
        l2--;
    }
    cout<<num1*num2;
}