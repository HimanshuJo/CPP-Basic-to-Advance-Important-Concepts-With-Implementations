#include<iostream>
using namespace std;

template<class T, int n>
class Array{
    private:
        T array[n];
    public:
        int get_size() const {
            return n;
        }
        T& operator[] (int i);
    public:
        class Overflow{
            private:
                int range;
            public:
                Overflow(int i): range(i){}
                int get_range() const{
                    return range;
                }
                int get_maxN() const{
                    return n;
                }
        };
};

template<class T, int n>
T &Array<T, n>::operator[](int i){
    if (i<0||i>=n){
        throw Overflow(i);
    }
    return array[i];
}

int main(){
    Array<char, 20>str1;
    Array<int, 10>int1;
    cout<<"Entry here: ";
    cin.getline(&str1[0], str1.get_size());
    cout<<"Entered \n";
    for (int i=0; str1[i]!='\0'; ++i){
        cout<<(str1[i]-'a')+1<<" ";
    }
    cout<<"\n";
    try{
        str1[20]='A';
    }
    catch(Array<char, 20>::Overflow& e1){
        cout<<"Overflowed at pos: "<<e1.get_range()<<"\n";
        cout<<"Max Size "<<e1.get_maxN()<<"\n";
    }
    try{
        for (int i=0; i<20; ++i){
            int1[i]=i*i;
            cout<<int1[i]<<" ";
        }
        cout<<"\n";
    }
    catch(Array<int, 10>::Overflow& e2){
        cout<<"\nOverflowed at pos: "<<e2.get_range()<<"\n";
        cout<<"Max Size "<<e2.get_maxN()<<"\n";
    }
    return 0;
}