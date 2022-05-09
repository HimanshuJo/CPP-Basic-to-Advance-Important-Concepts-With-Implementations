/*
Alice and Bob are playing a game.

They start with a positive integer n and take alternating turns doing operations on it. 
    Each turn a player can subtract from n one of its divisors that isn't 1 or n

The player who cannot make a move on his/her turn loses. Alice always moves first.

Note that they subtract a divisor of the current number in each turn.

You are asked to find out who will win the game if both players play optimally.
Input

The first line contains a single integer t (1≤t≤10^4) — the number of test cases.

Then t test cases follow.

Each test case contains a single integer n (1≤n≤10^9) — the initial number.

Output

For each test case output "Alice" if Alice will win the game or "Bob" if Bob will win, 
if both players play optimally.

Example
Input

4
1
4
12
69

Output

Bob
Alice
Alice
Bob

Note

In the first test case, the game ends immediately because Alice cannot make a move.

In the second test case, Alice can subtract 2 making n=2, then Bob cannot make a move so Alice wins.

In the third test case, Alice can subtract 3 so that n=9. Bob's only move is to subtract 3 and make n=6. 
    Now, Alice can subtract 3 again and n=3

Then Bob cannot make a move, so Alice wins.
*/

/*
    Observation based question:
        There can only be winners in two cases, when the number is odd and when the number is even

        When the number is odd, in that case everytime BOB is winning

            Example:

                Suppose I have the number 21, it has the divisors 3, 7

                Now Alice stated the game, she has 21 as the number with her
                    And this point of time Alice doesn't have any options other than 3 and 7

                    Suppose she has taken 3 as her number, similar pattern will appear, has she taken the
                        other number
                    
                    Alice does -> 21 - 3

                    Bob receives 18

                        Now 18 can have multiple divisors, Bob can do the subtraction with 2, 9, 3

                        But to play optimally Bob has to do the subtraction with 3

                    -------

                    Suppose we have a number in the format (a*b)
                        e.g. 21 = 3 * 7

                        For the odd numbers the divisors will also be odd

                            3 * 7 can be written as:
                                
                                3 + 3 + 3 + 3 + 3 + 3 + 3 or
                                7 + 7 + 7

                        So, in essence if we have a number let's say 21 which is divisible by 3,
                            , subtracting this number with 3 will result in a number which will again
                            be divisible by 3

                    Another example could be, suppose we have a number 25
                        e.g. 25 = (5*5)

                        performing subtraction here will result in 20 (which is again divisible by 5)

                    Coming back to the example of 21, so Bob receives 18 and he perform the optimal subtraction
                        and send back 15

                        Again at this point Alice can do the subtraction with 3 or 5, same pattern will re-appear
                            no matter the number we choose

                            Alice did: 15 - 3, and sends back 12

                            Bob again did: 12 - 3, and sends back 9

                            Alice did: 9 - 3, and sends back 6

                            Bob again did: 6 - 3, and sends back 3 (Alice looses in this case)

                        -------

                        Seeing this pattern we can observe that Alice is only receiving all the numbers which are only
                            odd, and Bob is receiving all the numbers which are just even

        -------

        When the number is even:

            Now here we have two case

                1. A number which has all even divisors

                2. A number which has all odd divisors

            Case1:

                Suppose we take an example of 24 -> 2 * 2 * 2 * 3

                Alice starts with an even number that has an odd divisor
                    Now here Alice can repeats the same pattern of odd, when she was losing with an odd number

                        Alice pick 3 and subtract it with the number (24 - 3)
                        Whenever we pick an even number and subtract it with an odd number, we always get an odd number
                            (Even - Odd = Odd)

                    Now Bob receives an odd number (21)

                        Bob has now two options of (3, 7)

                    Alice receives 18

                        Alice has options of 2, 3, 9, but she plays optimally and picks 3

                    Bob receives 15

                    The cycle continues and in the end the case like (1*a) will happen at the Bob's side and he looses

                -------

                In essence when we have a number which can't be represented as the power of 2
                    (e.g 24 != 2^k)

            -------

            Case 2:

                When a number is represented as the power of 2

                Suppose we have a number 8 -> 2 * 2 * 2

                Alice gets 8, alice ahs the choices of 2, 4, 8

                    Alice picks 2, and Bob receives 6

                        now 6 is a kind of number that has in its divisors an odd number

                        and from the previous discussion and concept we know that, such type of number
                            that has in its divisor an odd number, the person who receives this number first will win

                    Now what happens if Alice picks the number 4

                        Alice picks 4, Bob receives 4

                            again Bob can repeat the same thing and win

                -------

                Suppose we have a number 32

                    32 -> 2 * 2 * 2 * 2 * 2

                    Alice takes 32, Alice can choose 2, 4, 8, 16

                    Suppose Alice picks 2, and sends back 30

                        Now, 30 is such kind of even number that has an odd number present in its divisors

                        In such type of pattern, that person wins who receives that number first

                            in this case Bob is winning

                    Now suppose Alice picks 4, and sends back 28

                        Again, 28 is such kind of number that has an odd number present in its divisors

                        In such type of pattern, that person wins who receives that number first

                            in this case Bob is winning

                    Now suppose Alice picks 8, and sends back 24

                        Again, 24 is such kind of number that has an odd number present in its divisors

                    Now suppose Alice picks 16, and sends back 16

                        In this particular case, 16 is a kind of number that doesn't have an odd number present in
                            its divisors

                        However in this particular case, Bob will also play optimally and can do the
                            subtraction from 2, 4 or 8

                            if Bob picks 8, Alice receive 8

                                Alice can sends back either 2 or 4

                                again Bob can play here optimally and in this particular scenario
                                    no matter what number do Alice picks she is going to loose the game
            -------

            In essence whenever we have a number which can be represented as 2^k
                and k is odd, then definitely Bob will win

                and if k is even, then definitely Alice will win
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        if (n % 2 == 1)
        {
            cout << "Bob"
                 << "\n";
            continue;
        }
        int count = 0;
        while (n % 2 == 0)
        {
            count++;
            n /= 2;
        }
        if (n > 1)
        {
            cout << "Alice"
                 << "\n";
        }
        else if (count % 2 == 0)
        {
            cout << "Alice"
                 << "\n";
        }
        else
        {
            cout << "Bob"
                 << "\n";
        }
    }
}