#include<iostream>
using namespace std;

class CustomException{
    public:
    CustomException(){
        cout<<"Call to Const.. \n";
    }
    ~CustomException(){
        cout<<"Call to Dest.. \n";
    }
};

void funk1(int val){
    switch(val){
        case -1: throw CustomException();
        case 0: throw "Encountered Zero. Ending \n";
        case 1: cout<<"Standard run started \n"; break;
        default: throw 99;
    }
    cout<<"Standard run ended \n";
}

void expectHandle(){
    cout<<"Unexpected error encountered \n";
    throw "Ending unexpectedly";
}

int main(){
    int val, ret_val=0;
    set_unexpected(expectHandle);
    cout<<"In here: ";
    cin>>val;
    try{
        CustomException obj;
        funk1(val);
        cout<<"No Exception encountered \n";
    }
    catch(CustomException&){
        cout<<"Class level Exception \n";
        ret_val=1;
        return ret_val;
    }
    catch(const char* msg){
        cout<<msg<<"\n";
        ret_val=0;
    }
    return ret_val;
}