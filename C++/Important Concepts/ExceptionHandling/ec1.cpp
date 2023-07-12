#include<iostream>
using namespace std;

class CustomException{
    public:
    static void custExcep(){
        cout<<"In class ran "<<"\n";
    }
};

class CustomExcepCll2{
    public:
    CustomExcepCll2(){
        cout<<"Calling Now the constructor \n";
    }
    ~CustomExcepCll2(){
        cout<<"Calling Now the destructor \n";
    }
};

void funk1(int val){
    switch(val){
        case -1: throw CustomException();
        case 0: throw "Ending. Encountered zero";
        case 1: cout<<"Standard call start \n"; break;
        default: throw 1;
    }
    cout<<"Standard call ended \n";
}

int main(){
    int val, ret_val=0;
    cout<<"In here: ";
    cin>>val;
    try{
        CustomExcepCll2 obj1;
        funk1(val);
        cout<<"No error \n";
    } catch(const char* msg){
        cout<<"Excep1 encountered \n"<<msg<<"\n";
        ret_val=0;
    } catch(CustomException&){
        cout<<"Excep2 encountered "<<"\n";
        CustomException::custExcep();
        ret_val=1;
    } catch(...){
        cout<<"Not Known \n";
    }
    return ret_val;
}        