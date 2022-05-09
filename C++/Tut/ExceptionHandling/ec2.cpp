#include<iostream>
using namespace std;

class CustomException{
    public:
    static void custExcep(){
        cout<<"Ran in class \n";
    }
};

class CustExcepCl2{
    public:
    CustExcepCl2(){
        cout<<"Calling now the constructor \n";
    }
    ~CustExcepCl2(){
        cout<<"Calling now the destructor \n";
    }
};

void funk1(int val){
    switch(val){
        case-1: throw CustomException();
        case 0: throw "Zero Encountered. Ending run \n";
        case 1: cout<<"Standard call \n"; break;
        default: throw 1;
    }
}

int main(){
    int val, val2, ret_val=0;
    cout<<"In Outer: ";
    cin>>val;
    try{
        CustExcepCl2 obj1;
        funk1(val);
        try{
            cout<<"In Inner: ";
            cin>>val2;
            funk1(val2);
        }
        catch(CustomException&){
            //throw;
            cout<<"Class level Exception. Inner \n";
            CustomException::custExcep();
            ret_val=1;
        }
        catch(const char* msg){
            cout<<msg<<"\n";
            ret_val=0;
        }
        catch(...){
            //throw;
            cout<<"Unknown Inner\n";
        }
    }
    catch(CustomException&){
        cout<<"Class level Exception. Outer \n";
        CustomException::custExcep();
        ret_val=1;
    }
    catch(const char* msg){
        cout<<msg<<"\n";
    }
    catch(...){
        cout<<"Unknown Outer "<<"\n";
    }
    return ret_val;
}