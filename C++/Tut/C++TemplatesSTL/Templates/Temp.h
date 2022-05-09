#include<iostream>
#include<string>
#ifndef _TEMP_H
#define _TEMP_H
using namespace std;

class Temp{
    private:
        int deg;
        char mon[20];
    public:
        Temp(int val, char* m):deg(val){
            strncpy(mon, m, 20);
            cout<<"Obj created \n";
        }
        ~Temp(){}
        int comp(const Temp&);
        void disp() const;
};

int Temp::comp(const Temp& d){
    if (deg>d.deg){
        return 1;
    }
    if (deg<d.deg){
        return -1;
    }
    return 0;
}

void Temp::disp() const{
    cout<<mon<<": "<<deg<<"\n";
}

#endif