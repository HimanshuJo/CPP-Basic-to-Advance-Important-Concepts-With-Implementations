/*
    Find the largest contiguous array sum of an array

    E.g. arr{1, 2, 3, 4, 5}

         Output: 15 (1+2+3+4+5)

         arr{-2, -3, 4, -1, -2, 1, 5, -3}

         Output: 7 (4-1-2+1+5)
*/

#include<iostream>
#include<vector>
using namespace std;

int findLargestContiguousArraySum(vector<int>&in){
    int fnmax=INT_MIN, curmax=0, sz=in.size();
    for(int i=0; i<sz; ++i){
        curmax+=in[i];
        if(fnmax<curmax){
            fnmax=curmax;
        }
        curmax=curmax<0?in[i]<0?0:in[i]:curmax;
    }
    return fnmax;
}

int main(){
    vector<int>in{-2, -3, 4, -1, -2, 1, 5, -3};
    vector<int>in2{1, 2, 3, 4, 5};
    vector<int>in3{6, 7, 8, 9, 0};
    int largestContiguousArrSm=findLargestContiguousArraySum(in);
    int largestContigousArrSm2=findLargestContiguousArraySum(in2);
    int largestContigousArrSm3=findLargestContiguousArraySum(in3);
    cout<<largestContiguousArrSm<<endl;
    cout<<largestContigousArrSm2<<endl;
    cout<<largestContigousArrSm3<<endl;
}