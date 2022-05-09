#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long N;
    cin>>N;
    if (N<=120){
        for (int i=0; i<N; ++i){
            cout<<'A';
        }
    } else{
        long long rem=N%120;
        char A='A';
        char B='B';
        string fn="";
        fn+=A;
        long long counter=1;
        while (counter<=rem){
            fn+=B;
            counter*=2;
        }
        long long newRem=counter;
        long long toComp=N-newRem;
        long long strt=0;
        while (strt!=toComp){
            fn+=A;
            strt++;
        }
        cout<<fn;
    }
}