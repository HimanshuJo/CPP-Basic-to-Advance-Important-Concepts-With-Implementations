#include<iostream>
#include<functional>
#include<cmath>
using namespace std;
using namespace std::placeholders;

template<class T>
class Eq1: public binary_function<T, T, bool>{
    public:
        bool operator()(const T &a, const T &b) const{
            return a==b;
        }
};

double (*func)(double)=sqrt;

int main(){
    int i;
    cout<<"In here: ";
    cin>>i;
    if(not1(logical_not<int>())(i)){
        cout<<"0 not entered\n";
    }
    if(not2(Eq1<int>())(i, 1)){
        cout<<"1 not entered\n";
    }
    auto fn1=bind(plus<int>(), _1, 5);
    cout<<fn1(1)<<endl;
    cout<<func(1.1)<<"\n";
    auto fn2=bind(func, _1);
    cout<<fn2(1.1)<<"\n";
    return 0;
}