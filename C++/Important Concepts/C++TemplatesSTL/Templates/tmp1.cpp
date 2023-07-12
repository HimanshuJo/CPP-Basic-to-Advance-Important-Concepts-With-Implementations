#include<bits/stdc++.h>
using namespace std;

template<class T>
T big(T n1, T n2){
    if (n1>n2){
        return n1;
    }
    return n2;
}

template<class T1, class T2>
T1 big(T1 n1, T2 n2){
    if (n1>n2){
        cout<<"Ran in mix, n1 is big \n";
        return n1;
    }
    cout<<"Ran in mix, n2 is big \n";
    return n2;
}

template<>
const char* big(const char* s1, const char* s2){
    if (strcmp(s1, s2)>0){
        cout<<"Ran in bigObject template"<<"\n";
        return s1;
    } else{
        cout<<"Ran in bigObject template"<<"\n";
        return s2;
    }
}

template<class T>
void custSwap(T& n1, T& n2){
    T tmp=n1;
    n1=n2;
    n2=tmp;
}

template<class T>
bool isBig(T n1, T n2){
    if (n1>n2){
        return true;
    }
    return false;
}

template<class T>
void custSwap2(T& n1, T& n2){
    if (isBig(n1, n2)){
        T tmp=n1;
        n1=n2;
        n2=tmp;
    }
}

int main(){
    long ln1=100, ln2=111;
    float fn1=100, fn2=111;
    int in1=11, in2=12;
    char a='A', b='B';
    const char* str="ABCD";
    const char* str2="D";
    cout<<"Big in mix types: "<<big(in1, b)<<"\n";
    cout<<"Big Num in int types: "<<big(in1, in1)<<"\n";
    cout<<"Big Num in long types: "<<big(ln1, ln2)<<"\n";
    cout<<"Big Num in float types: "<<big(fn1, fn2)<<"\n";
    cout<<"Big string in string types: "<<big(str, str2)<<"\n";
    cout<<"-------"<<"\n";
    custSwap(ln1, ln2);
    cout<<ln1<<" "<<ln2;
    cout<<"\n";
    custSwap(fn1, fn2);
    cout<<fn1<<" "<<fn2<<"\n";
    cout<<"-------"<<"\n";
    custSwap(str, str2);
    cout<<str<<" "<<str2<<"\n";
    cout<<"-------"<<"\n";
    custSwap2(fn1, fn2);
    cout<<fn1<<" "<<fn2<<"\n";
}