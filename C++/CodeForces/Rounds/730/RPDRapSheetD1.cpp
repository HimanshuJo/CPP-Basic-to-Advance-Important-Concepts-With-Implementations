/*
This is the easy version of the problem. The only difference is that here k=2

You can make hacks only if both the versions of the problem are solved.

This is an interactive problem.

Every decimal number has a base k equivalent. The individual digits of a base k number 
are called k-its. Let's define the k-itwise XOR of two k-its a and b as (a+b)mod k

The k-itwise XOR of two base k numbers is equal to the new number formed by taking 
the k-itwise XOR of their corresponding k-its. 
The k-itwise XOR of two decimal numbers a and b is denoted by a⊕kb and is 
equal to the decimal representation of the k-itwise XOR of the base k 
representations of a and b. All further numbers used in the 
statement below are in decimal unless specified. When k=2 
(it is always true in this version), the k-itwise XOR is the same as the bitwise XOR.

You have hacked the criminal database of Rockport Police Department (RPD), 
also known as the Rap Sheet. But in order to access it, you require a 
password. You don't know it, but you are quite sure that it lies between 0
and n−1 inclusive. So, you have decided to guess it. Luckily, 
you can try at most n times without being blocked by the system. 
But the system is adaptive. Each time you make an incorrect guess, 
it changes the password. Specifically, if the password before the guess was x, and 
you guess a different number y, then the system changes the password to a 
number z such that x⊕kz=y

Guess the password and break into the system.
Input

The first line of input contains a single integer t
(1≤t≤10000) denoting the number of test cases. t test cases follow.

The first line of each test case contains two integers n
(1≤n≤2⋅10^5) and k (k=2)

It is guaranteed that the sum of n over all test cases does not exceed 2⋅10^5

Interaction

For each test case, first read two integers n and k. Then you may ask up to n queries.

For each query, print a single integer y
(0≤y≤2⋅10^7). Let the current password be x. After that, read an integer r

If x=y, you will read r=1 and the test case is solved. You must then continue 
solving the remaining test cases.

Else, you will read r=0. At this moment the password is changed to a number z 
such that x⊕kz=y

After printing a query, do not forget to output the end of line and 
flush the output. Otherwise, you will get the Idleness limit exceeded verdict.

To do this, use:

    fflush(stdout) or cout.flush() in C++;
    System.out.flush() in Java;
    flush(output) in Pascal;
    stdout.flush() in Python;
    see documentation for other languages. 

If you ask an invalid query or exceed n queries, you will read r=−1

and you will receive the Wrong Answer verdict. Make sure to exit immediately to 
avoid unexpected verdicts.

Note that the interactor is adaptive. That is, the original password is not 
fixed in the beginning and may depend on your queries. 
But it is guaranteed that at any moment there is at least one initial 
password such that all the answers to the queries are consistent.

Hacks:

To use hacks, use the following format of tests:

The first line should contain a single integer t
(1≤t≤10000) — the number of test cases.

The first and only line of each test case should contain two integers n
(1≤n≤2⋅10^5) and k (k=2) denoting the number of queries and the base respectively. 
The optimal original password is automatically decided by the adaptive interactor.

You must ensure that the sum of nover all test cases does not exceed 2⋅10^5

Example
Input

1
5 2

0

0

1

Output

3

4

5

Note

In the example test case, the hidden password is 2

The first query is 3
It is not equal to the current password. So, 0 is returned, and 
the password is changed to 1 since 2⊕21=3

The second query is 4 It is not equal to the current password. So, 0 is returned, 
and the password is changed to 5 since 1⊕25=4

The third query is 5
It is equal to the current password. So, 1 is returned, and the job is done.

Note that this initial password is taken just for the sake of explanation. 
When you submit, the interactor might behave differently because it is adaptive.
*/
/*
Again, let qi denote the i-th query. Then,

qi=(i−1)⊕q1⊕q2⊕…⊕qi−2⊕qi−1

Let's see why this works.

Claim — If the original password was x, after i queries, the current password will 
        be x⊕q1⊕q2⊕…⊕qi−1⊕qi

Proof

Let's prove this by induction.

Base Condition — The first query is 0 After 1-st query, the password becomes x⊕0=x⊕q1

Induction Hypothesis — Let the password after i-th query be x⊕q1⊕q2⊕…⊕qi−1⊕qi

Inductive step — 
    The (i+1)-th query will be qi+1. 
    So, the password after (i+1)-th query will be 
        (x⊕q1⊕q2⊕…⊕qi−1⊕qi)⊕qi+1 =x⊕q1⊕q2⊕…⊕qi−1⊕qi⊕qi+1

Hence, proved by induction.

Now notice that after x
queries, the password will become x⊕q1⊕q2⊕…⊕qx−1⊕qx. 
And our (x+1)-th query will be x⊕q1⊕q2⊕…⊕qx−1⊕qx which is the same as the 
current password. So, the problem will be solved after (x+1) queries. 
Since 0≤x<n, the problem will be solved in at most n queries.

But we are not done yet. We can't afford to calculate the value of each query 
naively in O(n) because this will time out. To handle this, we need to maintain a 
prefix XOR whose value will be p=q1⊕q2⊕…⊕qi−1⊕qi after i queries. 
For the (i+1)-th query, find qi+1=p⊕i and update p=p⊕qi+1

Time Complexity

O(n)
or O(n⋅log2n) depending upon the implementation.
*/
#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        int curr = 0;
        int pass = 0;
        for (int i = 0; i < n; ++i)
        {
            curr = pass ^ i;
            cout << curr << endl;
            pass ^= curr;
            int response;
            cin >> response;
            if (response == 1)
            {
                break;
            }
        }
    }
    return 0;
}
