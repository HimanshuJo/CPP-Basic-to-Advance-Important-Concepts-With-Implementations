/*
There are n people participating in some contest, they start participating 
in x minutes intervals. 
That means the first participant starts at time 0, 
the second participant starts at time x, the third — at time 2⋅x, and so on.

Duration of contest is t minutes for each participant, so the 
first participant finishes the contest at time t, the second — 
at time t+x, and so on. 

When a participant finishes the contest, their dissatisfaction 
equals to the number of participants that started the contest 
(or starting it now), but haven't yet finished it.

Determine the sum of dissatisfaction of all participants.

Input

The first line contains a single integer k (1≤k≤1000) — the number of test cases.

Each of the next k lines contains three integers n, x, t (1≤n,x,t≤2⋅10^9) — 
the number of participants, the start interval and the contest duration.

Output

Print k lines, in the i-th line print the total dissatisfaction of
participants in the i-th test case.

Example
Input

4
4 2 5
3 1 2
3 3 10
2000000000 1 2000000000

Output

5
3
3
1999999999000000000
*/
/*

Suppose we have x=3 and t=10

then first student will attend the contest at 0,
     second student will attend the contest at 3,
     third student will attend the contest at 6,
     fourth student will attend the contest at 9, and so on

now when will the students leave the contest,

     first student will finish the contest at 10
     second student will finish the contest at 13
     third student will finish the contest at 16,
     fourth student will finish the contest at 19, and so on

Now what will be the dis-satisfaction for all the students:

    for the first student as he is leaving at 10, so until that time
        2nd, 3rd, and 4th students will still be attending the contest

        so 0 -> has dis-satisfaction 3

    for the second student as he is leaving at 13, so until that time
        3rd and 4th students will still be attending the contest and if
        the no. of students are infinite, then for the first student
        at 12 there should already be a replacement

        so 1 -> has dis-satisfaction 3 similary for other students also it is same

-------

If the number of students are not infinite:

    taking the example of the last student, for him the dis-satisfaction will
        be 0, as no one will be there

    so for finite number of students, the trend of same value of dis-satisfaction
        will first rise, then it will start dropping (as no. of students will drop)

    -------

    Suppose n=6, x=3 and t=10

    Timeline:

        0 3 6 9 10 12 13 15 16 19 22 25
                ^     ^     ^  ^  ^  ^

        ^ denotes the leaving time of the students

        dis-satisfactions for individual students:

            for 0 -> 3 (students at 3, 6, 9)

            for 3 -> 3 (students at 6, 9, 12)

            for 6 -> 3 (students at 9, 12, 15)

            since our total number of students were 6, so after this there
                will be no replacement number to count

            for 9 -> we will be calculating its dis-satisfaction level
                until the range 19
                and we have only two number present (12, 15)

                so 2

            similarly for 12 -> 1

            for 15 -> 0 

    -------

    So a trend is first rising then decreasing

        How to calculate the value of this main number:

            suppose z=3 and n=6

            for 1 -> students giving exams are {2, 3, 4} = 3
            for 2 -> students giving exams are {3, 4, 5} = 3
            for 3 -> students giving exams are {4, 5, 6} = 3
            for 4 -> students giving exams are {5, 6} = 2
            for 5 -> students giving exams are {6} = 1
            for 6 -> students giving exams are {} = 0

        so for the final z students, the value will decrease from the main point

        -------

        suppose x=3 and t=10

            every other student is sitting after an interval of 3

            so we will calculate between 0 and 10,
                how many intervals of 3 do we have?
                    => (10-0)/3
                    => 3 (integer division)

            Now how many students are there who have the same dis-satisfaction level
                and 
                
            how many students are there whose dis-satisfaction level
                decreases after that point

                our pattern was like this:

                    z
                    z
                    z
                    z
                    z
                    ...
                    z-1
                    z-2
                    z-3
                    ...
                    2
                    1
                    0

            how to calculate the entire sum:

                Suppose we fist multiply all teh students with z
                    => n*z (meaning all the students have the dis-satisfaction
                            level as z)

                        but with this we have calculate for the last z students
                            some extra value

                    for the last value, we have calculated:
                        z, z more (because it should have a value of 0)

                    for 1, we have calculated:
                        z, z-1 more

                    for 2, we have calculated:
                        z, z-2 more

                    similarly we follow that, and reach z-1

                    for z-1, we have calculated:
                        z, 1 more

                Therefore we'll do:
                    n*z - Extra values

                This extra value is nothing but:
                    some of first n numbers

                Therefore the formula becomes:

                    n*z - ((z * z+1) / 2)

    -------

    Corner case:

        when n<z

        example n=2, z=3

        Timeline:

            1 2 10
                ^

            for 1, dissatisfaction level -> 1
            for 2, dissatisfaction level -> 0

        In this case, answer will be:
            sum of first n-1 natural numbers
*/

#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int k;
    cin >> k;
    while (k--)
    {
        ll n, x, t;
        cin >> n >> x >> t;
        ll z = t / x;
        if (z > n)
        {
            cout << (n - 1) * (n) / 2 << "\n";
        }
        else
        {
            ll ans = z * n;
            ans -= (z) * (z + 1) / 2;
            cout << ans << "\n";
        }
    }
}