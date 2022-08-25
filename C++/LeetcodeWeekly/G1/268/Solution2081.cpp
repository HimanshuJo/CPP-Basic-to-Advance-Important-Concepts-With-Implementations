// 2081. Sum of k-Mirror Numbers
/* 
A k-mirror number is a positive integer without leading zeros that reads the same both forward and 
backward in base-10 as well as in base-k.

For example, 9 is a 2-mirror number. The representation of 9 in base-10 and base-2 are 9 and 1001 respectively, 
which read the same both forward and backward.
On the contrary, 4 is not a 2-mirror number. The representation of 4 in base-2 is 100, which does not read the 
same both forward and backward.
Given the base k and the number n, return the sum of the n smallest k-mirror numbers.

Example 1:

Input: k = 2, n = 5
Output: 25
Explanation:
The 5 smallest 2-mirror numbers and their representations in base-2 are listed as follows:
  base-10    base-2
    1          1
    3          11
    5          101
    7          111
    9          1001
Their sum = 1 + 3 + 5 + 7 + 9 = 25.

Example 2:

Input: k = 3, n = 7
Output: 499
Explanation:
The 7 smallest 3-mirror numbers are and their representations in base-3 are listed as follows:
  base-10    base-3
    1          1
    2          2
    4          11
    8          22
    121        11111
    151        12121
    212        21212
Their sum = 1 + 2 + 4 + 8 + 121 + 151 + 212 = 499.

Example 3:

Input: k = 7, n = 17
Output: 20379000
Explanation: The 17 smallest 7-mirror numbers are:
1, 2, 3, 4, 5, 6, 8, 121, 171, 242, 292, 16561, 65656, 2137312, 4602064, 6597956, 6958596
 

Constraints:

2 <= k <= 9
1 <= n <= 30
*/

class Solution {
public:
    
    vector<long long>mirror1{0}, mirror2{0};
    
    long long isMirror(long long num, int base){
        long long mul=1;
        while(mul*base<=num){
            mul*=base;
        }
        for(; num; mul/=base*base){
            if(num/mul!=num%base){
                return false;
            }
            num=(num-(num/mul)*mul-num%base)/base;
        }
        return true;
    }
    
    long long generate(int dig, int n, int k, long long firstMul){
        vector<long long>mirror;
        long long res=0;
        for(int i=0; n>0&&i<10; ++i){
            for(int j=0; n>0&&j<mirror1.size(); ++j){
                /*
                cout<<"i "<<i<<" j "<<j<<" firstMul "<<firstMul
                    <<" mirror1[j] "<<mirror1[j]<<" : "<<firstMul*i+mirror1[j]*10+i<<endl;
                cout<<"***---***"<<endl;
                */
                mirror.push_back(firstMul*i+mirror1[j]*10+i);
                if(i!=0&&isMirror(mirror.back(), k)){
                    res+=mirror.back();
                    --n;
                }
            }
        }
        /*
        cout<<"mirror "<<endl;
        for(auto &vals: mirror){
            cout<<vals<<" ";
        }
        cout<<endl;
        cout<<"-------\n";
        */
        swap(mirror1, mirror2);
        swap(mirror2, mirror);
        return res+(n==0?0:generate(dig+1, n, k, firstMul*10));
    }
    
    long long kMirror(int k, int n) {
        long long res=0;
        for(int i=1; n>0&&i<10; ++i){
            mirror2.push_back(i);
            if(isMirror(i, k)){
                res+=i;
                --n;
            }
        }
        /*
        cout<<"mirror2 orig "<<endl;
        for(auto &vals: mirror2){
            cout<<vals<<" ";
        }
        cout<<endl;
        */
        return res+generate(2, n, k, 10);
    }
};