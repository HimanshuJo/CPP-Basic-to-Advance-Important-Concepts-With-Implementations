/*
Given a sorted and rotated array A of N distinct elements which is rotated at some point, 
and given an element key. The task is to find the index of the given element key in the array A.

Example 1:

Input:
N = 9
A[] = {5, 6, 7, 8, 9, 10, 1, 2, 3}
key = 10
Output:
5
Explanation: 10 is found at index 5.
Example 2:

Input:
N = 4
A[] = {3, 5, 1, 2}
key = 6
Output:
-1

Explanation: There is no element that has value 6.
Your Task:
Complete the function search() which takes an array arr[] and start, 
end index of the array and the K as input parameters, and returns the answer.

Can you solve it in expected time complexity?

Expected Time Complexity: O(log N).
Expected Auxiliary Space: O(1).

Constraints:
1 ≤ N ≤ 10^7
0 ≤ A[i] ≤ 10^8
1 ≤ key ≤ 10^8
*/
/*
Solution2:

#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
    int search(int A[], int l, int h, int key){
        if(l>h) return -1;
        int mid=(l+h)/2;
        if(A[mid]==key) return mid;
        if(A[l]<=A[mid]){
            if(key>=A[l]&&key<=A[mid]){
                return (search(A, l, mid, key));
            }
            return (search(A, mid+1, h, key));
        }
        if(key>=A[mid]&&key<=A[h]){
            return (search(A, mid+1, h, key));
        }
        return (search(A, l, mid, key));
    }
};

int main() {
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int A[n];
        for(int i = 0; i < n; i++)
            cin >> A[i];
        int key;
        cin >> key;
        Solution ob;
        cout << ob.search(A, 0, n - 1, key) << endl;
    }
return 0;
}
*/

#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
    
    int binarySearch(int A[], int left, int right, int key){
        int ans=-1;
        while(left<=right){
            int mid=left+(right-left)/2;
            if(A[mid]==key){
                ans=mid;
                return ans;
            } else {
                if(A[mid]>key){
                    right=mid-1;
                } else{
                    left=mid+1;
                }
            }
        }
        return ans;
    }
    
    int search(int A[], int l, int h, int key){
        int possIdx=0;
        int sz=h+1;
        int curr=A[sz-1];
        if(sz==2){
            if(A[0]==key) return 0;
            else if(A[1]==key) return 1;
            else return -1;
        }
        for(int i=sz-2; i>=0; --i){
            if(A[i]>curr){
                possIdx=i;
                break;
            }
        }
        int bgnf=0, endf=possIdx;
        int ans1=binarySearch(A, bgnf, endf, key);
        if(ans1!=-1) return ans1;
        if(possIdx+1>=sz){
            return -1;
        }
        int bgns=possIdx+1, ends=sz-1;
        return binarySearch(A, bgns, ends, key);
    }
};

int main() {
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int A[n];
        for(int i = 0; i < n; i++)
            cin >> A[i];
        int key;
        cin >> key;
        Solution ob;
        cout << ob.search(A, 0, n - 1, key) << endl;
    }
return 0;
}