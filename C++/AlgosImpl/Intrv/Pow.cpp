#include<bits/stdc++.h>
using namespace std;

double power(double x, int n){
    if (n==0){
        return 1;
    }
    double v=pow(x,n/2);
    if (n%2==0){
        return v*v;
    } else {
        return v*v*x;
    }
}

int main(){
    cout<<power(5,3);
}