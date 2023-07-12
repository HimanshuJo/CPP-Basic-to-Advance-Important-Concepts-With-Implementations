#include<iostream>
#include<bitset>
#include<stdexcept>
using namespace std;

template<class T, int n>
class Array{
    private:
        T array[n];
    public:
        int get_size() const {
            return n;
        }
    T& operator[](int i);
};

template<class T, int n>
T& Array<T, n>::operator[](int i){
    if(i<0||i>=n){
        throw out_of_range("Out of range\n");
    }
    return array[i];
}

int main(){
    Array<int, 10>int1;
    //bitset<4>bits;
    try{
        // bset.set(pos) makes bset[pos] = 1  
        // i.e. default is 1
        //bits.set(5);
        bitset<32>bits(string("1110115"));
    }
    catch(out_of_range& e1){
        cout<<"Exception occurred in bitset: "<<e1.what()<<"\n";
    }
    catch(invalid_argument &e1){
        cout<<"Invalid Argument occurred in bitset: "<<e1.what()<<"\n";
    }
    try{
        for (int i=0; i<20; ++i){
            int1[i]=i*i;
        }
    }
    catch(out_of_range& e2){
        cout<<"Exception occurred in Array: "<<e2.what()<<"\n";
    }
    try{
        string str1="Hemnshh";
        string str2="Joshi";
        str1.append(str2, str1.length()-1, 3);
        cout<<str1<<"\n";
    }
    catch(out_of_range& e3){
        cerr<<"Exception occurred in string: "<<e3.what()<<"\n";
    }
    return 0;
}