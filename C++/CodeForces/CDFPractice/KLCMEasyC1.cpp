/*

You are given a positive integer n. Find k positive integers a1,a2,…,ak, such that:

a1+a2+…+ak=n
LCM(a1,a2,…,ak)≤ n/2

Example
input
3
3 3
8 3
14 3

output
1 1 1
4 2 2
2 6 6

Algo:

    Most important to notice in the problem is

        If we find the LCM of of any value with 1, e.g. LCM(1, x)  --> It will always be x

            LCM is basically the most smallest value, for example if we say LCM(a, b) = c

                that means c is that smallest value, that will be divisible by a and b

                    that means remainder of c / a = 0, and remainder of c / b = 0

        -------

        First thing to notice in the question is to check
            if n is odd or n is even

        -------

        If n is ODD

            suppose n = 3 and k = 3 (so we have to find 3 values)

                so, the first value we can take is 1

                so, the next two values will be 

                        (n - 1) / 2

                    How:

                        if n is odd then, n - 1 will always be an even value

                        and the LCM of 1 with the first (n - 1) / 2 will be (n - 1) / 2

                        and the LCM of 1 with the other (n - 1) / 2 will be (n - 1) / 2

                        and finally the LCM of (n - 1) / 2 and (n - 1) / 2 will always be less than n / 2

        -------

        If n is EVEN

            Here we will have two sub-cases

                If n is even and n / 2 is also even

                    suppose k = 3 and we have three positions to fill

                    we can fix the first position as n / 2

                        now the remaining sum is n / 2

                            and with this remaining sum and we have to find the rest two remaining values

                            then the rest two values can be

                                n / 4

                        In essence the LCM of n / 2, n / 4, n / 4 will always be <= n / 2

                -------

                If n is even and n / 2 is odd

                    if n / 2 is odd, then (n - 2) / 2 will always be even

                    Hence, we can fix the first value as 2

                        and the rest two values can be (n - 2) / 2

                    In essence the LCM of 2, (n - 2) / 2, (n - 2) / 2 will always be <= n / 2


/**/

#define ll long long
#include<iostream>

using namespace std;

int main() {
    
    ll int t;
    cin >> t;

    while (t--) {
        ll int n, k;
        cin >> n >> k;

        int z = k - 3;

        while (z > 0) {
            cout << 1 << " ", z--;
        }

        n = n - (k - 3);
        if (n < 0) continue;

        if (n % 2 == 0) {
            ll int k  = n / 2;
            if (k % 2 == 1) {
                cout << 2 << " " << (n - 2) / 2 << " " << (n - 2) / 2 << "\n";
            } else {
                cout << n / 2 << " " << n / 4 << " " << n / 4 << "\n";
            }
        } else {
            cout << 1 << " " << (n - 1) / 2 << " " << (n - 1) / 2 <<"\n";
        }
    }
}