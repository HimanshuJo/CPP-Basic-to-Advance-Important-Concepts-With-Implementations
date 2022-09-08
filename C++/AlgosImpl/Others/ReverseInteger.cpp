#include<bits/stdc++.h>
using namespace std;

int reverse(int x){
    int rev=0;
    while (x!=0){
        rev=x%10+rev*10;;
        x/=10;
    }
    return rev;
}

int main(){
    cout<<reverse(123);
}