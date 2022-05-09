// 875. Koko Eating Bananas
/*
Koko loves to eat bananas. There are n piles of bananas, the ith pile has piles[i] bananas. 
The guards have gone and will come back in h hours.

Koko can decide her bananas-per-hour eating speed of k. 
Each hour, she chooses some pile of bananas and eats k bananas 
from that pile. If the pile has less than k bananas, she eats all of them instead and 
will not eat any more bananas during this hour.

Koko likes to eat slowly but still wants to finish eating all the bananas before the guards return.

Return the minimum integer k such that she can eat all the bananas within h hours.

Example 1:

Input: piles = [3,6,7,11], h = 8
Output: 4
Example 2:

Input: piles = [30,11,23,4,20], h = 5
Output: 30
Example 3:

Input: piles = [30,11,23,4,20], h = 6
Output: 23
*/

/*
Intuition

If Koko can finish eating all the bananas (within H hours) with an eating speed of K, 
she can finish with a larger speed too.

If we let possible(K) be true if and only if Koko can finish with an eating speed of K, 
then there is some X such that possible(K) = True if and only if K >= X.

For example, with piles = [3, 6, 7, 11] and H = 8, there is some X = 4 so that 
possible(1) = possible(2) = possible(3) = False, 
and possible(4) = possible(5) = ... = True.

def minEatingSpeed(piles: List[int], H: int) -> int:
    def feasible(speed) -> bool:
        # return sum(math.ceil(pile / speed) for pile in piles) <= H  # slower        
        return sum((pile - 1) // speed + 1 for pile in piles) <= H  # faster

    left, right = 1, max(piles)
    while left < right:
        mid = left  + (right - left) // 2
        if feasible(mid):
            right = mid
        else:
            left = mid + 1
    return left
*/

class Solution {
public:

	bool isValid(vector<int>&piles, int val, int h){
		int time=0;
		for(auto &pile: piles){
			time+=(pile-1)/val+1;
		}
		return time<=h;
	}

    int minEatingSpeed(vector<int>& piles, int h) {
        int left=1, right=*max_element(piles.begin(), piles.end());
        int ans=0;
        while(left<=right){
            int mid=left+(right-left)/2;
            if(isValid(piles, mid, h)){
                ans=mid;
                right=mid-1;
            } else{
                left=mid+1;
            }
        }
        return ans;
    }
};