#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    //Function to reverse every sub-array group of size k.
    void reverseInGroups(vector<long long>& arr, int n, int k){
        if(k>=n){
            reverse(arr.begin(), arr.end());
        }
        if(k>1&&k<n){
            int sz=arr.size();
            int bgn=0, end=(bgn+k)-1;
            while(bgn<=sz-1&&end<=sz-1){
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
                int prevb=bgn, prevend=end;
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