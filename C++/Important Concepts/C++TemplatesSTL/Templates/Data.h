#include<iostream>
#ifndef _DATA_H_
#define _DATA_H_
using namespace std;

class Data{
    private:
        int val;
    public:
        Data(int value):val(value){
            cout<<"Class object created \n";
        }
        ~Data(){}
        int comp(const Data&);
        void disp() const;
};

int Data::comp(const Data& d){
    if (val>d.val){
        return 1;
    }
    if (val<d.val){
        return -1;
    }
    return 0;
}

void Data::disp() const{
    cout<<val<<"\n";
}

#endif