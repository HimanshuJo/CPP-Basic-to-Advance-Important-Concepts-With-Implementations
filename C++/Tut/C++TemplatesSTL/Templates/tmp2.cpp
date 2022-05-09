#include<bits/stdc++.h>
#include<cstdlib>
using namespace std;

template<class T, int n=20>
//template<class T, int n>
class Array{
    private:
        T array[n];
    public:
        int get_size() const{
            return n;
        }
        T& operator[](int i);
};

template<class T, int n>
T &Array<T, n>::operator[](int i){
    if (i<0||i>=n){
        cout<<"Array overflow \n";
        exit(1);
    }
    return array[i];
}

int main(){
    Array<char>str1;
    Array<int>intgs;
    cout<<"In here "<<endl;
    cin.getline(&str1[0], str1.get_size());
    for (int i=0; str1[i]!='\0'; ++i){
        cout<<str1[i]<<" ";
    }
    return 0;
}