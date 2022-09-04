#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

long long gcd(long long A, long long B){
    if(B==0) return A;
    return gcd(B, A%B);
}

long long lcm(long long a, long long b){     
    if(a>b)
        return (a/gcd(a,b))*b;
    else
        return (b/gcd(a,b))*a;    
}

int main(){
    int A=100000000, B=5;
    cout<<A/B<<endl;
    cout<<floor(A/B);
}