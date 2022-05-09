#include<iostream>
#include<functional>
using namespace std;

template<class T>
class Eq1: public binary_function<T, T, bool>{
    public:
    bool operator()(const T &a, const T &b) const{
        return a==b;
    }
};

template<class T>
class addVal: public unary_function<T, T>{
    private:
        T val;
    public:
        addVal(const T &newVal): val(newVal){};
        T operator()(const T &arg) const{
            return arg+val;
        }
};

int main(){
    int i;
    cout<<"In here ";
    cin>>i;
    if(logical_not<int>()(i)){
        cout<<"Entered 0\n";
    }
    if(Eq1<int>()(i, 1)){
        cout<<"Entered 1\n";
    }
    cout<<addVal<int>(5)(i)<<endl;
    if(less<int>()(i, 100)){
        cout<<"i is small\n";
    }
    return 0;
}