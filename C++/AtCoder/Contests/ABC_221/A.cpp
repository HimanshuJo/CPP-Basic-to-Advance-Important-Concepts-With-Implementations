#include<bits/stdc++.h>
using namespace std;

int ipow(int base, int exp)
{
    int result = 1;
    for (;;)
    {
        if (exp & 1)
            result *= base;
        exp >>= 1;
        if (!exp)
            break;
        base *= base;
    }
    return result;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int A, B;
    cin>>A>>B;
    if(A==B)cout<<1;
    else{
        cout<<(ipow(32, abs(A-B)));
    }
}