#include<bits/stdc++.h>
#include"Data.h"
#include"Temp.h"
#include"Liste.h"
using namespace std;

void input_func(Liste<Temp>& dataList){
    Temp* dat;
    int deg;
    char mon[20];
    while (true){
        cout<<"In here: ";
        if (!(cin>>mon)){
            strcpy(mon, "No Entry");
        }
        cout<<"Temp here: ";
        if (!(cin>>deg)||deg==99){
            break;
        }
        dat=new Temp(deg, mon);
        dataList.pst(dat);
    }
}

void input_func(Liste<Data>& dataList){
    Data* dat;
    int val;
    while (true){
        cout<<"In here: ";
        if (!(cin>>val)||val==0){
            break;
        }
        dat=new Data(val);
        dataList.pst(dat);
    }
}

template<class T>
void input(Liste<T>& data){
    input_func(data);
}

int main(){
    Liste<Temp>ele1;
    Liste<Data>ele2;
    input(ele1);
    input(ele2);
    ele1.allDisp();
    ele2.allDisp();
    return 0;       
}