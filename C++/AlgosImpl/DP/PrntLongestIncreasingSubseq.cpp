// Construction of Longest Increasing Subsequence(LIS) and printing LIS sequence
/*
The longest Increasing Subsequence (LIS) problem is to find the length of 
the longest subsequence of a given sequence such that all elements of the 
subsequence are sorted in increasing order.

Examples: 

Input:  [10, 22, 9, 33, 21, 50, 41, 60, 80]
Output: [10, 22, 33, 50, 60, 80] 
OR [10 22 33 41 60 80] or any other LIS of same length.
*/

/*
Let arr[0..n-1] be the input array. We define vector L such that L[i] is 
itself is a vector that stores LIS of arr that ends with arr[i]. 
For example, for array [3, 2, 6, 4, 5, 1], 

L[0]: 3
L[1]: 2
L[2]: 2 6
L[3]: 2 4
L[4]: 2 4 5
L[5]: 1
Therefore, for index i, L[i] can be recursively written as – 

L[0] = {arr[O]}
L[i] = {Max(L[j])} + arr[i] 
where j < i and arr[j] < arr[i] and if there is no such j then L[i] = arr[i]
*/

#include<iostream>
#include<vector>
using namespace std;

void prntLIS(vector<int>&arr){
    for (int x: arr){
        cout<<x<<" ";
    }
}

void constructPrntLIS(int arr[], int n){
    vector<vector<int>>L(n);
    L[0].push_back(arr[0]);
    for (int i=1; i<n; ++i){
        for (int j=0; j<i; ++j){
            /*
                e.g. 
                i=2
                    j=0
                        arr[0]<arr[2]
                        L[0]=3 and size=1
                        L[2]={}
                        1+1>0 therefore L[2]=L[0] -> L[2]=3 (+ curr ind number)

                    j=1
                        arr[1]<arr[2]
                        L[1]=2 and size=1
                        L[2]=3
                        1+1>1 therefore L[2]=L[1] -> L[2]=2 (+ curr ind number)

                -------
                i=4
                    j=0
                        arr[0]<arr[4]
                        L[0]=3 and size=1
                        L[4]={}
                        1+1>0 therefore L[4]=L[0] -> L[4]=3 (+ curr ind number)

                    j=1
                        arr[1]<arr[4]
                        L[1]=2 and size=1
                        L[4]={3}
                        1+1>1 therefore L[4]=L[1] -> L[4]=2 (+ curr ind number)

                    j=2
                        arr[2]>arr[4] X

                    j=3
                        arr[3]<arr[4]
                        L[3]={2, 4} and size=2
                        L[4]={2}
                        2+1>1 therefore L[4]=L[3] -> L[4]={2, 4} (+ curr ind number)

            */
            if ((arr[j]<arr[i])&&(L[j].size()+1)>L[i].size()){
                L[i]=L[j];
            }
        }
        L[i].push_back(arr[i]);
    }
    vector<int>maxx=L[0];
    for (vector<int>x: L){
        if (x.size()>maxx.size()){
            maxx=x;
        }
    }
    prntLIS(maxx);
}

int main(){
    int arr[]={3, 2, 6, 4, 5, 7};
    constructPrntLIS(arr, sizeof(arr)/sizeof(arr[0]));
}