// D. Martial Arts Tournament
/*
Monocarp is planning to host a martial arts tournament. 
There will be three divisions based on weight: lightweight, middleweight and heavyweight. 

The winner of each division will be determined by a single elimination system.

In particular, that implies that the number of participants in each division should be a 
power of two. Additionally, each division should have a non-zero amount of participants.

n participants have registered for the tournament so far, the i-th of them weighs ai. 
To split participants into divisions, Monocarp is going to establish two integer weight 
boundaries x and y (x<y).

All participants who weigh strictly less than x will be considered lightweight. 
All participants who weigh greater or equal to y will be considered heavyweight. 
The remaining participants will be considered middleweight.

It's possible that the distribution doesn't make the number of participants 
in each division a power of two. It can also lead to empty divisions. 
To fix the issues, Monocarp can invite an arbitrary number of participants to each division.

Note that Monocarp can't kick out any of the n participants who have 
already registered for the tournament.

However, he wants to invite as little extra participants as possible. 
Help Monocarp to choose x and y in such a way that the total amount of 
extra participants required is as small as possible. Output that amount.

Input
The first line contains a single integer t (1≤t≤10^4) — the number of testcases.

The first line of each testcase contains a single integer n (1≤n≤2⋅10^5) — 
the number of the registered participants.

The second line of each testcase contains n integers a1,a2,…,an (1≤ai≤n) — 
the weights of the registered participants.

The sum of n over all testcases doesn't exceed 2⋅10^5.

Output
For each testcase, print a single integer — 
the smallest number of extra participants Monocarp is required to invite after he 
chooses the weight boundaries x and y.

Example
input
4
4
3 1 2 1
1
1
6
2 2 2 1 1 1
8
6 3 6 3 6 3 6 6

output
0
2
3
2
Note

In the first testcase of the example, Monocarp can choose x=2 and y=3. 
Lightweight, middleweight and heavyweight divisions will have 2, 1 and 1 participants, 
respectively. They all are powers of two, so no extra participants are required.

In the second testcase of the example, regardless of the choice of x and y, 
one division will have 1 participant, the rest will have 0. 

Thus, Monocarp will have to invite 1 participant into both of the remaining divisions.

In the third testcase of the example, Monocarp can choose x=1 and y=2. 
Lightweight, middleweight and heavyweight divisions will have 0, 3 and 3 
participants, respectively. So an extra participant is needed in each division.

In the fourth testcase of the example, Monocarp can choose x=8 and y=9. 
Lightweight, middleweight and heavyweight divisions will have 8, 0 and 0 participants, 
respectively. Middleweight and heavyweight division need an extra participant each.
*/

/*
Sort the weights, now choosing x and y will split the array into three consecutive segments.

Consider a naive solution to the problem. You can iterate over the length of the 
first segment and the second segment. The third segment will include everyone remaining.

Now you have to check if there exist some x and y that produce such segment. 
x can be equal to the first element of the second segment 
(since only all elements of the first segment are smaller than it). 

Similarly, y can be equal to the first element of the third segment.

However, if the last element of some segment is equal to the 
first element of the next segment, no x or y can split the array like that.

Otherwise, you can split an array like that. So you can iterate over 
the lengths, check the correctness and choose the best answer.

Now let's optimize it using the condition about powers of two.

First, iterate over the size of the middle division (which is a power of two). 
Then over the length of the first segment (which can be not a power of two). 

Check if the first segment is valid.

So we fixed the length of the first segment and some value which is greater or 
equal than the length of the second segment. That value isn't necessarily equal 
to the length of the second segment because the produced segment might be invalid.

So there is a greedy idea that the second segment should be as long as 
possible under the constraint that it doesn't exceed the fixed value. 

The intuition is the following. Consider the longest possible valid segment. 
Now take the last element away from it. We will have to invite one more 
participant to the middle division. And that element will also get added 
to the third segment, increasing its length. So potentially, you can only 
increase the required number of participants to invite.

This can be implemented in the following fashion. 
For each position i precalculate lefti — the closest possible segment 
border from the left. Iterate over the size of the middle division mid as a 
power of two. Iterate over the length of the first segment len1. 

Find the closest border to the left of len1+mid=left[len1+mid]. 
Get the lengths of the second and the third segments. Find the closest 
powers of two to each length and update the answer.

Overall complexity: O(nlogn) per testcase.
*/

/*
calc = 1
nxt = [1, 0]

for _ in range(int(input())):
  n = int(input())
  a = sorted(list(map(int, input().split())))
  while calc <= n:
    for i in range(calc):
      nxt.append(calc - i - 1)
    calc *= 2
  left = []
  for i in range(n + 1):
    if i == 0 or i == n or a[i] != a[i - 1]:
      left.append(i)
    else:
      left.append(left[-1])
  mid = 1
  ans = n + 2
  while mid <= n:
    for len1 in range(n + 1):
      if left[len1] == len1:
        len2 = left[min(n, len1 + mid)] - len1
        len3 = n - len1 - len2
        ans = min(ans, nxt[len1] + (mid - len2) + nxt[len3])
    mid *= 2
  print(ans)
*/