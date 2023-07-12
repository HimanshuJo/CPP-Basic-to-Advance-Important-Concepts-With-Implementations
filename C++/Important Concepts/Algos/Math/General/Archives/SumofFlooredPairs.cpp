/*
Given an integer array nums, return the sum of floor(nums[i]/ nums[j])
for all the pairs of indices 0 <= i, j < nums.length in the array.

	Since the answer can be very large, return its modulo 10^9 + 7

	The floor() function returns the integer part of the division

-------

Example 1:

	Input: nums = [2, 5, 9]

	Output = 10

	Explanation:

		floor(2 / 5) = floor(2 / 9) = floor(5 / 9) = 0
		floor(2 / 2) = floor(5 / 5) = floor(9 / 9) = 1
		floor(5 / 2) = 2
		floor(9 / 2) = 4
		floor(9 / 5) = 1

*/
/*
* Note floor is basically the integer part of the division

Doing the standard procedure like:
	2/2 + 2/5 + 2/9 +
	5/2 + 5/5 + 5/9 +
	9/2 + 9/5 + 9/9 = 10

	but it will result in O(n^2) time

	Intuition:

		Given a number, how to quickly find all the results for that particular number

		Suppose our array is like:

			arr = [2, 3, .... 7, .....]

			so if we just focus on a number her say for example 7,
				so 7/2 = 3
				   7/3 = 2
				   ...

				   7/7 = 1

				   and so on..

			   How to quickly calculate that, without have to enumerate through all the numbers to find it

-------

One way to solve the problem is to use Segment Tree, but another easy way to solve the approach is as follows:

	We firstly have to create quotients for each of the number from 1 to 10^5  --> kind of like pre-processing

		for each of the number we're gonna populate the potential quotient from the number itself to the max number

		-------

		That means that, for example suppose we have a number 2

		suppose in the beginning our quotient array is 0
			quotient = [0, 0, 0...... 0]

			each number in the original array will serve as the index for the value in the quotient array

				so for the number 2, at the index 2, the value in the quotient array will be 1 instead of 0

				that means for the number 2, it's division with 2 will give the quotient 1

			Next we will increase the number by it's next multiple e.g, 2 becomes 4 and so on

				all the multiples will also take the same value

			Next we will take the next number in the original array which is 3, and start doing the same thing for 3,

				if at an index in the quotient array if there is already pre-increment value,
				then we will increment it further by 1
					e.g. in case of 6 -> multiple of 2 and 3

					what does it means, it means that for 6, there are now two numbers that can give us the quotient of 1

		-------

		Like this we'll create our quotient array

			Then we can just do the accumulation of the quotients here

			for example it array will look something like this:

				quotient = [_, _, _, _, _, _, 6, _, ...]

				so for 7 here we can see we can have 6 quotients for the particular given array

				what is essence we are doing that, for each of the given number in the array we're going to mark the potential
					quotient

-------

Another approach to solve the problem is to just fix the denominator
	so if I am able to fix a denominator let's say nums[j], what are the number of
	nums[i] I can have to have the answer a particular fixed number

		e.g. suppose our input array is arr = [2, 5, 9]

				suppose we take the number 5, if 5 is the denominator, 'what are the intervals' where I
				can have a fixed answer

					suppose I want the answer as 0, so my nums[i] lie in the range [0, 4]

						that basically means any value in the range [0, 4] divided by 5 the
						answer will always be a fixed number
							in this case 0

						and if my nums[i] lie in the range [5, 9] the answer will always be 1 (integer division)

						and if my nums[i] lie in the range [10, 14] the answer will always be 2

				That basically provides the idea that, if we know the 'number of numbers' lying in the range
					[0, 4] or [5, 9] or [10, 14] I can easily answer the required value

					how to do that:

						we are fixing nums[j]

							let's say we have:

								x1 no. of numbers in the range [0, 4] giving result = 0

								x2 no. of numbers in the range [5, 9] giving result = 1

							and x3 no. of numbers in the range [10, 14] giving result = 2 and so on

						that means (0 * x1 + 1 * x2 + 2 * x3) and so on

			Also, initially I will be just pre-calculating the frequency of each element in our array

			suppose the frequency of 5 is y in this array

				and for 5 we have already calculated what will be the equation:
					=> sum = 0 * x1 + 1 * x2 + 2 * x3 ...

					finally we will do for 5, (frequency of 5 * sum)

	-------

	We will be maintaining a frequency table which will have a size of 10^5

		suppose for 5, I want to find out the number of elements in the range[25, 29]
			it is important to maintain a prefix-sum of the frequencies for every element of this array
			so that I can easily answer the value

				no. of elements lying in this range will be like:
					(count of index 28 - count of index 24) -> because the array is basically storing the prefix sum

	-------

	Basically for every 'i' I will start iterating from 1 till 10^5 and this is just fixing the
		denominator (denominator is i)
		let's say my i come out to 5, it means that my denominator is 5 currently

		so, here that means for i = 1 we have to travel from 1 till 10^5, then for 2, 3 and so on

			now for every 'i' lie in this range

				I will just iterate j from 1 till i*j <= N (N here is 10^5)

				how we have to fetch the answers basically

				for example suppose I have i = 5, so here we are fixing this denominator
					so for this 'i' what is the number of elements lying in this range

				so here we are fixing the interval, let say for i = 5
					we have [i * j, i * (j + 1) - 1]

					suppose j == 2, then the interval is -> [5 * 2, 5 * (2 + 1) - 1]
														 =  [10, 14]

				    so, here it means for the interval [10, 14] my answer would come out to be 2
				    	and the important point here is that, I need to count the frequency of the elements
				    	lying in this interval

				    	for that we need a prefix sum of the frequencies of the array

			    	we also have to multiple count with 'j' and repeat that for every j

    	Total iterations:

    		for i = 1, we will iterate from j = 1 till i*j <= N, so here we will have N no. of iterations

    		for i = 2, we will iterate from j = 1 till 2*j <= N, so here we will have N/2 no. of iterations

    		for i = 3, we will iterate from j = 1 till 3*j <= N, so here we will have N/3 no. of iterations and so on

			so it will actually be a series like: N + N/2 + N/3 + N/4 ...

				so, its general time complexity is N (log N)
*/
/*
class Solution:
	def sumOfFlooredPairs(self, nums: List[int]) -> int:
		ans = 0
		mmax = max(nums)
		counter = Counter(nums)
		quotients = [0] * (mmax + 1)
		for num, count in counter.items():
			for multiple in range(num, mmax + 1, num):
				quotients[multiple] += count
		sumOfQuotients = list(accumulate(quotients))  # at this point we have a sum of quotients
		mod = 10**9 + 7
		return sum(sumOfQuotients[num] for num in nums) % mod

*/
/*
We can't iterate sum up for all the possible pairs since the given constraints would lead to TLE.

We need to observe that the result of floor(nums[i] / nums[j]), will be -

    0 if nums[i] < nums[j]
    1 if nums[j] <= nums[i] < (2 * nums[j])
    2 if 2 * nums[j] <= nums[i] < (3 * nums[j])
    and so on...

We can use this to build a frequency array and then calculate the prefix sum of it.

After this, for every num in nums, we will add the answer into sum as per the above observation.

    All the numbers in the range [0, num - 1] will contribute 0 to the sum each.
    	The frequency of numbers in this range will be given by freq[num - 1] - freq[0].

    All the numbers in the range [num, 2*num - 1] will contribute 1 to the sum each.
    	Frequency: freq[num] - freq[2num - 1].

    Numbers in [2*num, 3*num - 1] will contribute 3 each.
    	Frequency: freq[2num] - freq[3num - 1].

    And so on till our range covers the maximum element of the nums array...

*/
/*
class Solution{
	public static int sumOfFlooredPairs(int[] nums) {
        int MAX = Integer.MIN_VALUE, MOD = 1000000007;

        int[] freq = new int[2 * 100000 + 1];
        // frequencies
        for(int num : nums) {
        	freq[num]++;
        	MAX = Math.max(MAX, num);
        }
        // prefix sum of frequencies
        for(int num = 1; num <= 2 * MAX; num++) {
        	freq[num] += freq[num - 1];
        }

        int total = 0;
        HashMap<Integer, Integer> seen = new HashMap<>();
        for(int i = 0; i < nums.length; i++) {
        	// for duplicate numbers if we have already calculated the result use it
        	if(seen.containsKey(nums[i])) {
        		total += seen.get(nums[i]);
        	} else {
        		int sum = 0;
            	// to start with nums[i] is dividing all numbers from nums[i] to 2 * nums[i] - 1
            	int left = nums[i], right = 2 * nums[i] - 1, floordiv = 1;
            	while(left <= MAX) {
    	        	sum += floordiv * (freq[right] - freq[left - 1]) % MOD;
    	        	sum %= MOD;
    	        	// shift the range from 2 * nums[i] to 3 * nums[i] - 1 and so on
    	        	left += nums[i]; right += nums[i];
    	        	floordiv += 1;
            	}
            	seen.put(nums[i], sum);
            	total += sum;
        	}
        	total %= MOD;
        }

        return total;
    }
}
*/

class Solution {
	const int MAXN = 1e5 + 1, MOD = 1e9 + 7;
public:
	int sumOfFlooredPairs(vector<int> &nums) {
		vector<long> freq(2 * MAXN + 1);
		long long mx = 0, sum = 0;
		// counting frequency of each element in nums
		for (auto num : nums) {
			++freq[num];
			mx = max((int) mx, num);
		}
		// building prefix sum array of freq.
		// now freq[i] will hold the frequency of numbers less than or equal to i
		for (int i = 1; i <= 2 * MAXN; ++i) {
			freq[i] += freq[i - 1];
		}
		/*
			Each number will be assumed in the denominator as floor(nums[i]/num) and
			using freq array, we can calculate the number of terms contributing
			1, 2, 3, ... to the sum each
		*/
		for (auto num : nums) {
			long long l = num, r = 2 * num - 1, divResult = 1;
			while (l <= mx) {
				sum = (sum + divResult * (freq[r] - freq[l - 1])) % MOD;
				l += num, r += num;
				++divResult;
			}
		}
		return sum;
	}
};
