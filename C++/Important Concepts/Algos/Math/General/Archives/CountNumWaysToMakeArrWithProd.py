'''

You are given a 2D integer array, queries. 

For each queries[i], where queries[i] = [ni, ki], find the number of different ways you can 
place positive integers into an array of size ni such that the product of the integers is ki. 

As the number of ways may be too large, the answer to the ith query is the number of ways modulo 10^9 + 7.

Return an integer array answer where answer.length == queries.length, and answer[i] is the answer to the ith query.

Example 1:

Input: queries = [[2,6],[5,1],[73,660]]
Output: [4,1,50734910]

Explanation: Each query is independent.
    
[2,6]: There are 4 ways to fill an array of size 2 that multiply to 6: [1,6], [2,3], [3,2], [6,1].
[5,1]: There is 1 way to fill an array of size 5 that multiply to 1: [1,1,1,1,1].
[73,660]: There are 1050734917 ways to fill an array of size 73 that multiply to 660. 

1050734917 modulo 10^9 + 7 = 50734910.

'''

'''

Some important concepts regarding the questions:

	Prime Factors

	Calculate number of combinations

-------

Some important points to notice:
	All the numbers in each of the valid output, are in fact the part of the prime factors of the
		number (or the product) which we have to make

	Example in the first case, the product which we have to make is 6:
		so 2 and 3 are the prime factors for this number

		and we will try to place all the prime factors in n slots (2 in this case)

			and the total possible combinations will be our final result

	-------

	What are the prime factors and why do we need them:

		Prime Factors:

			Each number can be represented by combinations of the product of the prime numbers
				which each number has some power on top of it

			e.g. suppose we have a number 660

					so 660 = 2^2 * 3^1 * 5^1 * 11^1

					Hence the prime factors for 660 are 2, 3, 5, 11

						also for 2 in this case here we have 'two' 2's we need to use
						we have 'one' 3 to use
						we have 'one' 5 to use
						we have 'one' 11 to use

			This is one concept from the game theory that for any number, we can always split
				that number into bunch of prime numbers

				* One point to notice that prime numbers always starts from 2,

				* 1 is not the prime number

		-------

		Why will this help us here in this case:
			Since we are trying to distribute different numbers into different slots (n here in this case)

			and the product of all those numbers has to be 'k' in this case here

		Now for the example of [73, 660]

			The prime factors of 660 = 2^2 * 3^1 * 5^1 * 11^1
				here we have 2 2's
							 1 3's
							 1 5's
							 1 11's

			 	In this particular case, we need to somehow place the above numbers into 73 slots,
			 		and we need to calculate the total number of ways we can do that

			 		one arrangement could be:

			 			2 2 3 5 11 1 1 1 1 .... 1 1 ( another 61 1's)

	 			Here in the above case we also have duplicate numbers e.g 2 2's

	 				by placing these 2 2's into different locations, we might end up with different results

 				Therefore for each of the number we have to consider it's placing probability separately

 					for each of the prime numbers the probabilities are independent

		-------

		hence in essence we also have to calculate the probabilities for each of the numbers independently

			but there might occur a problem in placing 2 2's into 73 slots

	-------

	Calculating Probabilities:

		Calc(73, 2) * Calc(73, 1) * Calc(73, 1) + .... 
			(Since each of the case is independent, we have to multiply all those scenarios together)

		In the second place in the calc function, we are only considering the count of that number
			in the prime factorization, not the number itself

			we are considering the same number individually

			we are trying to identify that for example, with 73 slots
				
				with how many ways we can put two numbers that can't be distinguished with each other
				(in the above example 2)

				similarly for calc(73, 1) -> how many ways we can put 1 numbers into 73 slots

		-------

		Also important point here to note is that, for the scenario calc(73, 2)
			how many ways we can put 2 numbers (which are basically same) into 73 slots,

			now those 2 numbers don't have to be in the same slot,
				e.g. if we put 2's in the same slot, it will result in 4

				4, 2, 2  -> these are two different scenarios

		To consider this scenario:

			For this we have a very classic problem we call 'Stars and Bars'

-------

Stars and Bars:

	Suppose we have n slots, and suppose we have k duplicate values
		now what are the different scenarios we can place them,
			Since we can place multiple values into one slot

			* imp k can be > than n

		The final result will be:

			n+k-1 Choose k = n+k-1 Choose n-1

			Why?

				Because of stars and Bars

					Stars means -> k indistinguishable values

					Bars means -> slots

				so if we have some stars (all are same) and let's say we have bars

					the bars can be anywhere

					as k can be greater than n, so we can put multiple k's into the same slots

				-------

				Suppose n = 3 (here we have 3 slots)

					    therefore we have n - 1 bars or separators

					    	* * * | * * | * * *

				    	so primarily with n - 1 bars, we split k stars into n parts

				    	so what we are saying is that, 
				    		on the first slot we are putting 3 stars
				    		and in the second slot we are putting 2 stars
				    		and in the third slot also we are putting 2 stars

		    		For the case, when n > k, that means there could be some slots which are basically
		    			empty

    			Hence the total arrangement for this problem becomes

    				The total no. of stars + total no. of bars ->

    					n+k-1 Choose n-1

    				And among all those kind of arrangements

    					we need to choose either (n - 1) bars or the arrangement of k stars

-------

So with the frequency of each prime factors we can calculate the ways/scenarios for that prime factors
	independently

	In the end we just need to multiply those values together

	-------

	E.g. for [2, 6] case we have in total 2 slots

			we have 2 prime factors, and the count for both the prime factors in 1

		And if we consider our 'Stars and Bars' algo. we are basically saying that, we are trying to
			place the 2 into 2 bars here

			_ _

			so we can put 2 in the first bar or in the second bar

				for the 3 is same

			Hence, if we suppose we put both the prime factors into one slot
				we will get 6, and the other bar will off-course be 1

			and if we put those prime factors into different slots, then we will get a different arrangement

-------

To calculate combinations we have a standard way:
	nCk = n! / k! * (n - k) !

	However, this is very slow

	With big number, it will definitely overflow. However, the formula works for smaller numbers

	-------

	If we have a big number, to calculate the factorial efficiently:
		We can use the 'Inverse' Factorial

'''


class Solution:
	def waysToFillArray(self, queries: List[List[int]]) -> List[int]:
		
		# need to calculate the prime factors
		# since we are going to repeatedly calculate that, we can add a dp(a cache)
		@lru_cache(None)
		def getPrimeFactors(n):
			ans = []
			i = 2
			# for the prime factors it's guaranteed that, the biggest prime factor
			# is always smaller than the square root of n
			while i*i <= n:
				# what we are really interested in the frequency of each of the prime factors
				cnt = 0
				# for each of the candidates we are performing n%i
				while n % i == 0:
					# if n%i == 0 then its a prime factor
					cnt += 1
					# we will continue using i to divide n until the remaining n can't be divided
					# by i then we know that we've to find an another prime factor
					n //= i
				if cnt > 0:
					ans.append(cnt)
				i += 1
			if n > 1:
				# the reason being, the last one or the remaining one could also be the last
				# prime factor, in that case we also need to add that one to our final result
				ans.append(1)
			return ans
		ans = []
		mod = 10**9 + 7
		for n, k in queries:
			cur = 1
			for num, cnt in getPrimeFactors(k):
				# for each of the count we want to calculate the scenarios independently
				# in the end we'll just accumulate together by multiplying all the numbers
				cur *= math.combo(cnt + n - 1, cnt)
				cur %= mod
			ans.append(cur)

		return ans

'''

from math import comb

class Solution:
    def getDivisorBuckets(self, spf, x):
        buckets = defaultdict(int)
        while x != 1:
            buckets[spf[x]] += 1
            x //= spf[x]
        return buckets.values()
    
    def getSieve(self, n):
        isprime = [True for _ in range(n)]  
        prime = []  
        spf = [None for _ in range(n)]

        isprime[0] = isprime[1] = False
        for i in range(2, n):
            if isprime[i]:
                prime.append(i)
                spf[i] = i
                
            j = 0
            while (j < len(prime) and i * prime[j] < n and prime[j] <= spf[i]):
                isprime[i * prime[j]] = False
                spf[i * prime[j]] = prime[j] 
                
                j += 1

        return spf

    def waysToFillArray(self, queries: List[List[int]]) -> List[int]:
        OST = 1000000007
        MAX_N = max(q[1] for q in queries) + 1
        spf = self.getSieve(MAX_N)
            
        res = [1 for x in range(len(queries))]
        for idx, q in enumerate(queries):
            bars = q[0]-1
            for n in self.getDivisorBuckets(spf, q[1]):
                res[idx] = (res[idx] * comb(n + bars, bars)) % OST
        return res

'''

'''

Time complexity:

	Suppose the length of the queries in 'm'

		For each of the m, we need to get the 'prime factors count'

			so the total is going to be sqrt(n)

		so it will be m * n^0.5

	-------

	Time complexity

    Getting sieve takes O(N*log(log(N)) in basic implementation and O(N) in optimized.

    Getting prime array with prime factors takes O(log(N)) on average due to the hash-map.

    The length of array won't exceed 6 because 2 * 3 * 5 * 7 * 11 * 13 > 10000, 
    so O(6) = O(1) for loop iterations.

    Getting C(n + a - 1, n - 1), where a is the maximum number of the same prime divisors, 
    which doesn't exceed 14 since 2^14 > 10000.

    C(n + a - 1, n - 1) = (n+a-1) * (n+a-2) * ... * n / a!
    					= H(n, a) < (N+13) * (N+12) * ... * N / 14! 
    					= H(N, 14) -> H(n, a) = O(a)
    					= O(log(N)) in our case because log2(N) < 14).

    You might think that computing each combination takes O(log(N)), but that's not like that. 

    After computing prime factorization, we are doing O(a0) + O(a1) + ... + O(ap) operations
    	where a0+a1+...+ap < log2(N) - thus, O(log(N)) in total.
    
    Moreover, if we precompute combinations in advance with O(N*log(N)), we will have O(1) here.

Overall O(N*log(N)) time complexity can be achieved.

-------

Conclusion:

	The key idea for this problem is that:

		we first have to identify that since we need to distribute some numbers into different slots
			and final result has to be equal to the k

			Then we should always look for the 'prime factors'

	Next one is that, with those kind of prime numbers, we need to calculate the scenarios independently

		because in case of two multiple same prime number, we have to use the principle of
			Stars and bars

			as placing of those 2 same numbers will result in different result

-------

primes = (2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97)
class Solution:
    def waysToFillArray(self, queries: List[List[int]]) -> List[int]:
        def nK(n: int, k: int) -> int:
            res = 1
            for p in primes:
                r = 0
                while k % p == 0:
                    r += 1
                    k /= p
                res *= comb(n - 1 + r, r)
            if (k != 1):
                res *= n            
            return res % 1000000007
        
        return [nK(n, k) for n, k in queries]

-------

1. Prime factorization

	Since k is limited to 10,000, we only need primes till 100. If, after we try all primes, 
	k is greater than 1, then k itself is a (larger) prime.

2. Stars and bars

	For the following demonstration, we'll use k = 8 and n = 3. 

	We factorize 8 as 2 * 2 * 2. 

	For the array of size 3, we can distribute our factors as follows (element is 1 if we put all factors elsewhere):

		   2 *  2 *  2 || = 8, 1, 1: 222__
		   2 *  2 |  2 |  = 4, 2, 1: 22_2_
		   2 |  2 *  2 |  = 2, 4, 1: 2_22_
		 | 2 *  2 *  2 |  = 1, 8, 1: _222_
		   2 *  2 || 2    = 4, 1, 2: 22__2
		   2 |  2 |  2    = 2, 2, 2: 2_2_2
		 | 2 *  2 |  2    = 1, 4, 2: _22_2
		   2 || 2 *  2    = 2, 1, 4: 2__22
		 | 2 |  2 *  2    = 1, 2, 4: _2_22
		|| 2 *  2 *  2    = 1, 1, 8: __222

	The number of combinations can be calculated using the stars and bars approach. 

	We want to select 3 stars (our prime factors) into 5 positions (3 stars + 2 bars). 

	The above example demonstrates why there are 5 positions.

	In other words, we need to count combinations of placing r factors ("stars") 
	into n - 1 + r positions ("stars" + "bars"). 

	We can precompute combinations using the pascal triangle approach.

	    Note that we have no more than 13 "stars", because 2 ^ 14 > 10,000. 

	    Therefore, we cannot have more than 10,012 stars and bars.

3. Distinguishable stars

	This is the coolest part! The "stars and bars" approach works when all "stars" 
	are the same (indistinguishable). 

	Here, we can have different counts of multiple factors (e.g. 2, 2, 2, 3, 3, 5 for 360). 

	This becomes very simple when you consider factors independently: {2, 2, 2}, {3, 3} and {5}.

	Using the "stars and bars" approach, we can distribute {2, 2, 2} into array of size 3 in 
	10 ways (3 stars into 5 positions). 

	There are 6 ways to put {3, 3} into the same array (2 into 4), and 3 ways to put {5} there (1 into 3). 

	Thus, we have 10 * 6 * 3 = 180 total ways to distribute all factors.

'''