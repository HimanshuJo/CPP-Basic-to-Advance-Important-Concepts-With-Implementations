# Red and Blue Lamps
'''
Problem Statement
There are N lamps numbered 1 through N arranged in a row. 
You are going to light R of them in red and N−R in blue.
For each i=1,…,N−1, a reward of Ai is given if Lamp i and Lamp i+1 light up 
in different colors.

Find the maximum total reward that can be obtained by efficiently deciding the 
colors of the lamps.

Sample Input 1 
6 2
3 1 4 1 5
Sample Output 1 
11
Lighting up Lamps 3,5 in red and Lamps 1,2,4,6 in blue yields a total reward of 
A2+A3+A4+A5=11.

You cannot get any more, so the answer is 11.
'''
'''
We can assume R≤N/2 by flipping red and blue.

In the optimal solution, no two red lamps are adjacent to each other.

We will show that if there are consecutive red lamps, then we can increase the reward with some appropriate operations.
Take the maximum i such that Lamp i and Lamp i+1 are both red. Take the minimum j≥i such that Lamp j and Lamp j+1 are both blue (or j=N if there is no such j). Then, we can flip the colors of Lamp i+1 through Lamp j so that we can increase the amount of reward without changing the number of red lamps in most cases.
The only exception is when j=N and N is lighted red, in which case flipping the colors decreases the number of red lamps by one. However, we can prove that there are three consecutive blue lamps in the range of Lamp 1 through i−1, or both Lamp 1 and Lamp 2 are blue, so by flipping such one from blue to red, we can still increase the amount of reward without changing the number of red lamps.

Therefore, the problem can be rephrased as follows.

“Given N lamps numbered 1 through N, you will light exactly R lamps in red and the 
remaining in blue. You will gain a reward of Bi if you light Lamp i in red. 
If you are forbidden to light two adjacent lamps in red, what is the maximum sum of reward?”

Hereinafter we will consider the rephrased problem.

The proof that the solution is concave
In the following Solutions 2 and 3, we will use the properties that the answer is a concave function of R. We first prove that property.

Claim:
For A=(A1,…,AN), let f(x) be “the maximum sum of x elements of A chosen so that 
no two adjacent elements is chosen.” Then, f is a concave function in the range 0≤x≤N/2.

Proof:
In order to prove that a function defined on integers is concave, it is sufficient 
to prove that f(x−1)+f(x+1)≤2f(x) for all x

Let a=(a1,…,ax−1) and b=(b1,…,bx+1) be the indices achieving the optimal solution 
for x−1 and x+1, respectively, and let c=(c1,…,c2x) be a concatenation of a and b, sorted.

Then, a sequence consisting of even-indexed elements of c, c′=(c1,c3,…,c2x−1), 
and that of odd-indexed elements, c′′=(c2,c4,…,c2x), are both valid choices of x elements.

Why c′and c′′ are valid?
If not, then there exists i such that ci+2−ci=1, but it implies that no matter which 
sequence (a or b) ci,ci+1 and ci+2 originates from, either a or b contains consecutive values, 
which violates the rules of a and b.

Combination a weighs f(x−1) and combination b weighs f(x+1), so c′ and c′′ weighs 
f(x−1)+f(x+1), and especially at least one of them is no less than the half,
f(x−1)+f(x+1)/2

Therefore, we could actually find a combinations of x elements whose sum is at least
f(x−1)+f(x+1)/2, so we can see f(x)≥ 2f(x−1)+f(x+1)
'''​

N, R = map(int, input().split())
A = list(map(int, input().split()))
R = min(R, N - R)
inf = 10**18

B = [0] * N
for i in range(N - 1):
  B[i] += A[i]
  B[i + 1] += A[i]

def f(C):
  dp = [(-inf, 0)] * (N + 1)
  ep = [(-inf, 0)] * (N + 1)
  ep[0] = (0, 0)
  for i in range(N):
    dp[i + 1] = (ep[i][0] + B[i] - C, ep[i][1] + 1)
    ep[i + 1] = max(dp[i], ep[i])
  return max(dp[N], ep[N])


ok = 0
ng = 1 << 31
while ok + 1 < ng:
  med = (ng + ok) // 2
  val, cnt = f(med)
  if cnt >= R:
    ok = med
  else:
    ng = med
val, cnt = f(ok)
print(val + R * ok)
