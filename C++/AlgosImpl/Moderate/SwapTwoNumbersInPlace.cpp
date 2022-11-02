/*
    Swapping two numbers in place without the use of a temporary variable
*/

#include<iostream>
#include<vector>
using namespace std;

class SwappingNumbers{
    protected:
    int A, B;
    public:
    SwappingNumbers(){};
    
    int getFirstNum(){
        return A;
    }

    void setFirstNum(int num){
        A=num;
    }

    int getSecNum(){
        return B;
    }

    void setSecNum(int num){
        B=num;
    }

    pair<int, int> swapNumbers(){
        if(A>B){
            A=A-B;
            B=B+A;
            A=B-A;
        } else{
            B=B-A;
            A=A+B;
            B=A-B;
        }
        return {A, B};
    }

    pair<int, int> swapNumbersUsingXOR(){
        A=A^B; // Firstly making A as the difference of A and B
        B=A^B; // B is basically B + diff (here A)
        A=A^B; // A is basically one of the other value that resulted in new B
        return {A, B};
    }
};

int main(){
    SwappingNumbers obj;
    obj.setFirstNum(154);
    obj.setSecNum(899);
    int frstNum=obj.getFirstNum();
    int secNum=obj.getSecNum();
    cout<<"Original Value of A and B: "<<frstNum<<" "<<secNum<<endl;
    pair<int, int>ans=obj.swapNumbers();
    cout<<"New Value of A and B: "<<ans.first<<" "<<ans.second<<endl;
}

