//This is the hard version of the problem. The only difference is that here 2≤k≤100.
// You can make hacks only if both the versions of the problem are solved.
/*
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

2
5 2

0

0

1
5 3

0

0

1

Output

3

4

5


1

4

6

Note

Test Case 1:

In this case, the hidden password is 2

The first query is 3
It is not equal to the current password. So, 0 is returned, 
and the password is changed to 1 since 2⊕(base 2)1=3

The second query is 4
It is not equal to the current password. So, 0 is returned, 
and the password is changed to 5 since 1⊕(base 2)5=4

The third query is 5
It is equal to the current password. So, 1 is returned, and the job is done.

Test Case 2:

In this case, the hidden password is 3

The first query is 1
It is not equal to the current password. So, 0 is returned, 
and the password is changed to 7 since 3⊕(base 3)7=1. 
[3=(10)base_3, 7=(21)base_3, 1=(01)base_3 and 
                 (10)base_3 ⊕(base 3) (21)base_3 = (01)base_3
]

The second query is 4
It is not equal to the current password. So, 0 is returned, 
and the password is changed to 6 since 7⊕(base 3)6=4. 
[7=(21)base_3, 6 = (20)base_3, 4=(11)base_3 and 
                   (21)base_3 ⊕(base 3) (20)base_3 = (11)base_3
]

The third query is 6
It is equal to the current password. So, 1 is returned, and the job is done.

Note that these initial passwords are taken just for the sake of explanation. 
In reality, the grader might behave differently because it is adaptive.

*/
/*
In this whole solution, we will work in base k only and we will convert the 
numbers to decimal only for I/O purpose. 
Notice that any property which is satisfied by k-its will also be satisfied 
by base k numbers since a 
base k number is nothing but a concatenation of k-its.

When we make an incorrect guess, the system changes the password to z such that 
x⊕(base k)z=y. Let's denote the j-th k-it of x by xj. 
Expanding this according to the definition of k-itwise XOR, 
for all individual k-its (xj+zj)mod k=yj ⟹zj=(yj−xj)mod k. 
So, let's define another k-itwise operation a⊖(base k)b =(a−b)mod k. 
Then, z=y⊖(base k)x. 
Now, let's extend the solutions of the Easy Version for this version.

Property 1 — (a⊖_kb)⊖_k(a⊖_kc)=c⊖_kb

Proof

(a⊖_kb)⊖_k(a⊖_kc)
=((a−b)mod k−(a−c)mod k)mod k =(a−b−a+c)mod k =(c−b)mod k =c⊖_kb

Property 2 — (b⊖_ka)⊖_k(c⊖_ka)=b⊖_kc

Proof

(b⊖_ka)⊖_k(c⊖_ka)
=((b−a)mod k−(c−a)mod k)mod k=(b−a−c+a)mod k=(b−c)mod k=b⊖_kc

-------

Again, let's denote the i-th query by qi

Then, qi=qi−1⊖_k[qi−2⊖_k[qi−3⊖_k…⊖_k[q2⊖_k[q1⊖_k(i−1)]]…]]

Let's see why this works.

Claim — If the original password was x, after i queries, the 
password will be qi⊖_k[qi−1⊖_k[qi−2⊖_k…⊖_k[q2⊖_k[q1⊖_kx]]…]]

Proof

Let's prove this by induction.

Base Case — After the 1-st query which is 0, the password will be 0⊖_kx=q1⊖_kx

Induction hypothesis — Let the password after i
queries be qi⊖_k[qi−1⊖_k[qi−2⊖_k…⊖_k[q2⊖_k[q1⊖_kx]]…]]

Inductive Step — The (i+1)-th query is qi+1. After (i+1) queries, 
the password will becomes qi+1⊖_k[qi⊖_k[qi−1⊖_k[qi−2⊖_k…⊖_k[q2⊖_k[q1⊖_kx]]…]]]

Hence, proved by induction.

Now notice that after x queries, the password will become 
qx⊖_k[qx−1⊖_k[qx−2⊖_k…⊖_k[q2⊖_k[q1⊖_kx]]…]] which will be equal to the 
(x+1)-th query. Hence, the problem will be solved after exactly (x+1) queries. 
Since 0≤x<n, the problem will be solved after at most n queries.

But we are not done yet. This solution is O(n^2)
which will time out. The solution for this isn't as simple as what we 
did for the Easy version because the ⊖_k operation is neither associative 
nor commutative. So, it's time to explore some more properties of these operations.

Property 3 — a⊖_k(b⊖_kc)=(a⊖_kb)⊕_kc
Proof:

    a⊖_k(b⊖_kc) =(a−(b−c)mod k)mod k =(a−b+c)mod k =((a−b)mod k+c)mod k =(a⊖_kb)⊕_kc

Property 4 — a⊖_k(b⊕_kc)=(a⊖_kb)⊖_kc

Proof

    a⊖_k(b⊕_kc) =(a−(b+c)mod k)mod k =(a−b−c)mod k =((a−b)mod k−c)mod k =(a⊖_kb)⊖_kc

Now, let's try to simplify our queries.

    q1=0

    q2=q1⊖_k1

    q3=q2⊖_k[q1⊖_k2]=[q2⊖_kq1]⊕_k2 (by Property 3)

    q4=q3⊖_k[q2⊖_k[q1⊖_k3]]=q3⊖_k[[q2⊖_kq1]⊕_k3]
                              =[q3⊖_k[q2⊖_kq1]]⊖_k3(by Property 4)

See the pattern?

You can generalize the i

-th query as -

if i is odd ** Query also conforms like password
    qi=qi−1⊖_k[qi−2⊖_k[qi−3⊖_k…⊖_k[q2⊖_kq1]…]]⊖_k(i−1)
if i is even    
    qi=qi−1⊖_k[qi−2⊖_k[qi−3⊖_k…⊖_k[q2⊖_kq1]…]]⊕_k(i−1)

So, we will maintain a prefix Negative XOR whose value after i queries will be 
    p=qi⊖_k[qi−1⊖_k[qi−2⊖_k…⊖_k[q2⊖_kq1]…]]

Then,
    if i is odd
        qi+1=p⊖_ki
    if i is even
        qi+1=p⊕_ki

Then update p=qi+1⊖_kp
*/
#include <bits/stdc++.h>
using namespace std;

int knxor(int x, int y, int k)
{
    int z = 0;
    int p = 1;
    while (x > 0 || y > 0)
    {
        int a = x % k;
        x = x / k;
        int b = y % k;
        y = y / k;
        int c = (a - b + k) % k;
        z = z + p * c;
        p = p * k;
    }
    return z;
}

int kxor(int x, int y, int k)
{
    int z = 0;
    int p = 1;
    while (x > 0 || y > 0)
    {
        int a = x % k;
        x = x / k;
        int b = y % k;
        y = y / k;
        int c = (a + b) % k;
        z = z + p * c;
        p = p * k;
    }
    return z;
}

int main()
{
    int t = 1;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        int p = 0;
        for (int i = 0; i < n; i++)
        {
            if (i == 0)
                cout << 0 << endl;
            else if (i % 2 == 0)
            {
                int q = kxor(p, i, k);
                cout << q << endl;
                p = knxor(q, p, k);
            }
            else
            {
                int q = knxor(p, i, k);
                cout << q << endl;
                p = knxor(q, p, k);
            }
            int v;
            cin >> v;
            if (v == 1)
                break;
        }
    }
    return 0;
}