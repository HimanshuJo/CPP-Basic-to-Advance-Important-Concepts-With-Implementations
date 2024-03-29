// 2064. Minimized Maximum of Products Distributed to Any Store
/*
You are given an integer n indicating there are n specialty retail stores. 
There are m product types of varying amounts, which are given as a 0-indexed 
integer array quantities, where quantities[i] represents the number of products of the ith product type.

You need to distribute all products to the retail stores following these rules:

A store can only be given at most one product type but can be given any amount of it.

After distribution, each store will have been given some number of products (possibly 0). 
Let x represent the maximum number of products given to any store. 

You want x to be as small as possible, i.e., you want to minimize the maximum number 
of products that are given to any store.

Return the minimum possible x.

Example 1:

Input: n = 6, quantities = [11,6]
Output: 3
Explanation: One optimal way is:
- The 11 products of type 0 are distributed to the first four stores in these amounts: 2, 3, 3, 3
- The 6 products of type 1 are distributed to the other two stores in these amounts: 3, 3
The maximum number of products given to any store is max(2, 3, 3, 3, 3, 3) = 3.
Example 2:

Input: n = 7, quantities = [15,10,10]
Output: 5
Explanation: One optimal way is:
- The 15 products of type 0 are distributed to the first three stores in these amounts: 5, 5, 5
- The 10 products of type 1 are distributed to the next two stores in these amounts: 5, 5
- The 10 products of type 2 are distributed to the last two stores in these amounts: 5, 5
The maximum number of products given to any store is max(5, 5, 5, 5, 5, 5, 5) = 5.
Example 3:

Input: n = 1, quantities = [100000]
Output: 100000
Explanation: The only optimal way is:
- The 100000 products of type 0 are distributed to the only store.
The maximum number of products given to any store is max(100000) = 100000.
 

Constraints:

m == quantities.length
1 <= m <= n <= 10^5
1 <= quantities[i] <= 10^5
*/

/*
Binary search the products distributed to every store.
The search range it between left = 1 and right = 100000.
We can also use right = max(A), no big difference.

For a products to distributed,
we needs ceil(A[i] / mid) store,

I use (a + mid - 1) / mid to calculate this.

We sum up the stores we needs and check whether we have that enough stores.
If we have enough stores, mid is big enough.

then change right = mid

If we have no enough stores, mid is too small,

then change left = mid + 1
*/

class Solution {
public:
    
    bool isPossible(vector<int>&quantities, int n, int mid){
        int count=0;
        int sz=quantities.size();
        for(int i=0; i<sz; ++i){
            if(quantities[i]<=mid){
                count++;
            } else{
                int temp=quantities[i];
                while(temp>0){
                    temp-=mid;
                    count++;
                }
            }
            if(count>n) return false;
        }
        return true;
    }
    
    int minimizedMaximum(int n, vector<int>& quantities) {
        int left=1, right=*max_element(quantities.begin(), quantities.end());
        int ans=INT_MAX;
        while(left<=right){
            int mid=left+(right-left)/2;
            if(isPossible(quantities, n, mid)){
                ans=min(ans, mid);
                right=mid-1;
            } else{
                left=mid+1;
            }
        }
        return ans;
    }
};

// -------*******-------

class Solution2 {
    public:
        int BinarySearch(int left, int right, vector<int>&quantities, const int n){
            if(left>=right) return left;
            int mid=left+(right-left)/2;
            int sum=0;
            for(auto &vals: quantities)
                sum+=(vals+mid-1)/mid;
            if(sum>n) BinarySearch(mid+1, right, quantities, n);
            else BinarySearch(left, mid, quantities, n);
            return left;
        }

        int minimizedMaximum(int n, vector<int>& quantities) {
            int left=1, right=1e5;
            left=BinarySearch(left, right, quantities, n);
            return left;
        }   
};

int main(){
    Solution obj;
    vector<int>quantities{15,10,10};
    obj.minimizedMaximum(7, quantities);
}