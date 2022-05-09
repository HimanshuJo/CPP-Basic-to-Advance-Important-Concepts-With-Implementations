// 2234. Maximum Total Beauty of the Gardens
/*
Alice is a caretaker of n gardens and she wants to plant flowers to maximize 
the total beauty of all her gardens.

You are given a 0-indexed integer array flowers of size n, where flowers[i] 
is the number of flowers already planted in the ith garden. 
Flowers that are already planted cannot be removed. You are then given 
another integer newFlowers, which is the maximum number of flowers that 
Alice can additionally plant. You are also given the integers target, full, and partial.

A garden is considered complete if it has at least target flowers. 
The total beauty of the gardens is then determined as the sum of the following:

The number of complete gardens multiplied by full.
The minimum number of flowers in any of the incomplete gardens multiplied by partial. 
If there are no incomplete gardens, then this value will be 0.
Return the maximum total beauty that Alice can obtain after planting at most newFlowers flowers.

Example 1:

Input: flowers = [1,3,1,1], newFlowers = 7, target = 6, full = 12, partial = 1
Output: 14
Explanation: Alice can plant
- 2 flowers in the 0th garden
- 3 flowers in the 1st garden
- 1 flower in the 2nd garden
- 1 flower in the 3rd garden
The gardens will then be [3,6,2,2]. She planted a total of 2 + 3 + 1 + 1 = 7 flowers.
There is 1 garden that is complete.
The minimum number of flowers in the incomplete gardens is 2.
Thus, the total beauty is 1 * 12 + 2 * 1 = 12 + 2 = 14.
No other way of planting flowers can obtain a total beauty higher than 14.
Example 2:

Input: flowers = [2,4,5,3], newFlowers = 10, target = 5, full = 2, partial = 6
Output: 30
Explanation: Alice can plant
- 3 flowers in the 0th garden
- 0 flowers in the 1st garden
- 0 flowers in the 2nd garden
- 2 flowers in the 3rd garden
The gardens will then be [5,4,5,5]. She planted a total of 3 + 0 + 0 + 2 = 5 flowers.
There are 3 gardens that are complete.
The minimum number of flowers in the incomplete gardens is 4.
Thus, the total beauty is 3 * 2 + 4 * 6 = 6 + 24 = 30.
No other way of planting flowers can obtain a total beauty higher than 30.
Note that Alice could make all the gardens complete but in this case, she would obtain a lower total beauty.
 

Constraints:

1 <= flowers.length <= 10^5
1 <= flowers[i], target <= 10^5
1 <= newFlowers <= 10^10
1 <= full, partial <= 10^5
*/
/*
TLE:

class Solution {
public:
    
    long long dfs(vector<int>&orig, vector<int>flowers, long long newFlowers, int target, int full, int partial, int idx, int sz){
        if(idx==sz||newFlowers==0){
            long long curans=0, cnt=0, cmpF=0, minn=LONG_MAX;
            for(int i=0; i<sz; ++i){
                if(flowers[i]>=target) cmpF++;
                if(flowers[i]<minn&&flowers[i]<target){
                    minn=flowers[i];
                }
            }
            if(minn==LONG_MAX) return -1;
            curans=(cmpF*full)+(minn*partial);
            return curans;
        }
        long long npk=LONG_MIN;
        npk=max(npk, dfs(orig, flowers, newFlowers, target, full, partial, idx+1, sz));
        long long pk=LONG_MIN;
        long long tempans=LONG_MIN;
        if(flowers[idx]<target){
            flowers[idx]++;
            tempans=max(tempans, 
                        max(dfs(orig, flowers, newFlowers-1, target, full, partial, idx+1, sz), 
                            dfs(orig, flowers, newFlowers-1, target, full, partial, idx, sz)));   
        } else{
            tempans=max(tempans, dfs(orig, flowers, newFlowers, target, full, partial, idx+1, sz));
        }
        pk=max(pk, tempans);
        return max(pk, npk);
    }
    
    long long maximumBeauty(vector<int>& flowers, long long newFlowers, int target, int full, int partial) {
        int sz=flowers.size();
        return (dfs(flowers, flowers, newFlowers, target, full, partial, 0, sz)==-1?(long long)full*sz:
               dfs(flowers, flowers, newFlowers, target, full, partial, 0, sz));
    }
};
*/

class Solution {
public:

	int binarySearch(vector<long long>&suffixSum, int l, int r, long long newFlowers){
		while(l<=r){
			int mid=(l+r)/2;
			if(suffixSum[mid]>newFlowers)
				l=mid+1;
			else r=mid-1;
		}
		return l;
	}

    long long maximumBeauty(vector<int>& flowers, long long newFlowers, int target, int full, int partial) {
		sort(flowers.begin(), flowers.end(), greater<int>());
		int n=flowers.size();
		vector<long long>suffixSum(n, 0);
		for(int i=n-2; i>=0; --i){
			suffixSum[i]=suffixSum[i+1]+(flowers[i]-flowers[i+1])*(n-i-1);
		}
		long long ans=0;
		for(int i=0; i<n; ++i){
			if(flowers[i]>=target) continue;
			int requi=target-flowers[i];
			int k=binarySearch(suffixSum, i, n-1, newFlowers);
			int curFlowerCount=target-1<flowers[k]+(newFlowers-suffixSum[k])/(n-k)?target-1:
			                   flowers[k]+(newFlowers-suffixSum[k])/(n-k);
			ans=ans>long(i)*full+(long)(partial)*curFlowerCount?ans:
			    long(i)*full+(long)(partial)*curFlowerCount;
			if(requi<=newFlowers){
				newFlowers-=requi;
			} else break;
			if(i==n-1){
				ans=ans>long(n)*full?ans:
				    long(n)*full;
			}
		}
		if(ans==0) return long(full)*n;
		return ans;      
    }
};