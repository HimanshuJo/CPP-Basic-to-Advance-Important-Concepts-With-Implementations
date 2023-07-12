#include<iostream>
#include<stdexcept>
using namespace std;

int main(){

    #ifdef _MSVC_LANG

        std::cout << "_MSVC_LANG: " <<
            _MSVC_LANG << std::endl;
    #else

        std::cout <<"__cplusplus: " <<
            __cplusplus << std::endl;
    #endif

    int val;
    cin.exceptions(ios::eofbit|ios::failbit);
    try{
        cout<<"In here: ";
        cin>>val;
    }
    catch(ios_base::failure& e){
        cout<<"Ios Exceptions occurred: "<<cin.exceptions()<<"\n";
    }
    return 0;
}