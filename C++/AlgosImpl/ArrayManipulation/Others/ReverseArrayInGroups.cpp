// Reverse array in groups
/*
Given an array arr[] of positive integers of size N. Reverse every sub-array group of size K.

Example 1:

Input:
N = 5, K = 3
arr[] = {1,2,3,4,5}
Output: 3 2 1 5 4
Explanation: First group consists of elements
1, 2, 3. Second group consists of 4,5.
 

Example 2:

Input:
N = 4, K = 3
arr[] = {5,6,8,9}
Output: 8 6 5 9
 

Your Task:
You don't need to read input or print anything. 
The task is to complete the function reverseInGroups() which takes the array, N and K as input 
parameters and modifies the array in-place. 

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(N)

Constraints:
1 ≤ N, K ≤ 10^7
1 ≤ A[i] ≤ 10^18
*/

#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;

class Solution{
public:
    
    void reverseInGroups(vector<long long>& arr, int n, int k){
        if(k>=n){
            reverse(arr.begin(), arr.end());
        }
        if(k>1&&k<n){
            int sz=arr.size();
            int bgn=0, end=(bgn+k)-1;
            while(bgn<=sz-1&&end<=sz-1){
                /*
                    First swap the first sub-array
                */
                int tmpb=bgn, tmped=end;
                if(tmped==tmpb+1){
                    swap(arr[tmpb], arr[tmped]);
                } else{
                    while(tmpb!=tmped){
                        swap(arr[tmpb], arr[tmped]);
                        tmpb++;
                        tmped--;
                        if(tmpb>tmped) break;
                    }   
                }
                int prevend=end;
                bgn=(bgn+k);
                end=(bgn+k)-1;
                if(bgn>=sz){
                    int tmpb=prevend+1, tmped=n-1;
                    if(tmpb<=sz-1){
                        if(tmped==tmpb+1){
                            swap(arr[tmpb], arr[tmped]);
                            break;
                        } else{
                            while(tmpb!=tmped){
                                swap(arr[tmpb], arr[tmped]);
                                tmpb++;
                                tmped--;
                                if(tmpb>tmped) break;
                            }
                            break;   
                        }   
                    }
                }
                if(end>=sz){
                    int tmpb=bgn, tmped=n-1;
                    if(tmped==tmpb+1){
                        swap(arr[tmpb], arr[tmped]);
                        break;
                    } else if(tmped==tmpb){
                        break;
                    } else{
                        while(tmpb!=tmped){
                            swap(arr[tmpb], arr[tmped]);
                            tmpb++;
                            tmped--;
                            if(tmpb>tmped) break;
                        }
                        break;   
                    }
                }
            }   
        }
    }
};

int main() {
    int t; 
    cin >> t; 
    while(t--){ 
        int n;
        cin >> n; 
        vector<long long> arr; 
        int k;
        cin >> k; 
        for(long long i = 0; i<n; i++)
        {
            long long x;
            cin >> x; 
            arr.push_back(x); 
        }
        Solution ob;
        ob.reverseInGroups(arr, n, k);
        for(long long i = 0; i<n; i++){
            cout << arr[i] << " "; 
        }
        cout << endl;
    }
}