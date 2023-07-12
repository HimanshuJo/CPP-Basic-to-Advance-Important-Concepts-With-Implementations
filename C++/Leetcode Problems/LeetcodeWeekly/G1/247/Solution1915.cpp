// 1915. Number of wonderful Substrings
/*
 * A wonderful string is a string where at most one letter appears an odd number of times.

    For example, "ccjjc" and "abab" are wonderful, but "ab" is not.

    Given a string word that consists of the first ten lowercase English letters ('a' through 'j'),
    return the number of wonderful non-empty substrings in word. If the same substring appears multiple times
    in word, then count each occurrence separately.

    A substring is a contiguous sequence of characters in a string.

    Example 1:

    Input: word = "aba"
    Output: 4
    Explanation: The four wonderful substrings are underlined below:
    - "aba" -> "a"
    - "aba" -> "b"
    - "aba" -> "a"
    - "aba" -> "aba"

    Example 2:

    Input: word = "aabb"
    Output: 9
    Explanation: The nine wonderful substrings are underlined below:
    - "aabb" -> "a"
    - "aabb" -> "aa"
    - "aabb" -> "aab"
    - "aabb" -> "aabb"
    - "aabb" -> "a"
    - "aabb" -> "abb"
    - "aabb" -> "b"
    - "aabb" -> "bb"
    - "aabb" -> "b"

    Example 3:

    Input: word = "he"
    Output: 2
    Explanation: The two wonderful substrings are underlined below:
    - "he" -> "h"
    - "he" -> "e"

    Constraints:

        1 <= word.length <= 10^5
        word consists of lowercase English letters from 'a' to 'j'.
 */
/*
 * Intuition:
 *
 * 	We can track whether we have an odd(1) or even(0) number of characters using a bit mask
 * 	Every time we see a character - we just flip the corresponding bit.
 *
 * 		here the trick is; we don't track the minimum position for each bit mask,
 * 			here we count how many times we have arrived at that bitmask (count[mask])
 */
/*
 *  Question requires working with parity
    
    A parity of the occurrence of some letters

    Constraints are important to notice here:

        we have only letters from 'a' till 'j' -> only 10 letters

    Brute force won't work because just to find out all the substrings we need O(n^2) complexity

    -------

    For these kind of problems we can use a DP
        For this the tricky part is how can we efficiently check at the current index, what are the wonderful strings
            so far

        For this problem we can use DP with a bit mask
            the reason being, suppose we have a substring as:
                xxxxxxxxxx

            we have 10 bit masks
                suppose our bit mask is: 1010101010

            * The way we're maintaining this mask is that, whenever we see any value either 0 or 1, we simply
                revert them

                That basically means that each of the bit value represent the parity for a particular letter

            So our setting for the string and bit mask is as follows:
                j i h g f e d c b a
                1 0 1 0 1 0 1 0 1 0

            so for a=0 for example, it means that at that particular index we've even number of a's
            and for b=1 for example, it means that at that location we've odd number of c's

             Please note that, at each index we have a full bit mask.
                Why do we need to maintain that, because

                    Assuming at two indices we have the same bit mask, that basically means that:
                        for the substring in between the appearance of all the letters must be even

                        because parity is same: (Odd - Odd = Even)
                            * for info (Even - Even = Even)

                    This covers one scenario that, we have found all the substrings that has 0 odd appearance
                        (In other words, for all the characters, count of a particular character in the string is even)
             -------

             For the scenario of at-most 1:

                Thinking more deeply about the bit masks, how to find the case when for all the characters, the
                    count of each character in the string is at most 1

                    we can simply try to revert each of the bit value
                        for example suppose our substring and bit mask is:
                            h g f e d c b a
                            1 0 1 0 0 1 0 0
                        here if we revert the bit value for 'a' from 0 to 1 and we keep everything else as same
                            the mask will look like: 1 0 1 0 0 1 0 1

                        and if we find the same substring some-where earlier also, that means that
                            the substring has 'a' appears odd number of times
                            because all the other letters in the string are same

                            Basically:
                                Odd - Even = Odd
                                Even - Odd = Odd

            -------

            To store the appearances of each of the bit mask we'll use a dictionary
                Taking an example for the even case:
                    suppose our sub-string and mask is as follows:
                        j i h g f e d c b a
                        1 0 1 0 1 0 1 0 1 0

                suppose at index=0, bitMask1 appears for the first time
                then at index=2, same bitmask appears again
                and finally at index=8, same bitmask appears for the third time

                    so, in total if we have three appearances of the same bitMask, so how many substrings
                        ending with the character at index=8 are wonderful strings
                            ans = 2 (because we have two same masks before)

                Therefore we need a counter to store the appearance of each of the masks
 */
/*

Suppose we have a sample string as:

    A   B   B   A   C   C   B

-------

Some useful tips on XOR:

    Point 1: A^A = 0 (e.g. 45^45 = 0)
    Point 2: A^0 = 1 (e.g. 45^0 = 1)

    XOR table:

        P   Q   P^Q
        0   1   1
        1   0   1
        0   0   0
        1   1   0

    * In same values for P and Q it remains 0 (a horse race kind of thing)

    Point 3: Suppose A^B = C
             When we do C^A again it will be:
                C^A = (A^B)^A
                    =  A^A^B
                    =  0^B
                    =  B

             This signifies that, suppose we have an equation like:
                A^B^C^D^E is our mask

                Now if we perform: mask^C
                    it will be: (A^B^C^D^E)^C
                                = A^B^C^C^D^E
                                = A^B^D^E
            
            * If we Xor a value with itself in any of the equation, that value will be removed

-------

    We have to find what are all the substrings that has at-most 1 letter with odd repetition

    We'll keep our initial mask as 0, and we will perform the Xor operation with each of the
        character in our string, and keep updating our mask

    Here we can use the concepts of Bit-Masking:
        Because here we'll be dealing with just two cases, when the frequency of any
        character in the string is odd or if it's even,
            and both of these can be represented as either 1 or 0 bit

    In our constraints we have character from 'A' till 'J' and we can represent them as
        a sequence of 10 bits
        e.g. A -> 0000000001
             B -> 0000000010
             ...
    
    Since in our current example we have just A, B, C so 3 bits will suffice

    Initially our Mask is: 000

    Our String is:

        A   B   B   A   C   C   B

        1st performing: mask ^ A
            000 ^ 001 = 001
                      = 1

        2nd performing: UpdatedMask ^ B
            001 ^ 010 = 011
                      = 3

        3rd performing: UpdatedMask ^ B
            011 ^ 010 = 001
                      = 1

        4th performing: UpdatedMask ^ A
            001 ^ 001 = 000
                      = 0

        5th performing: UpdatedMask ^ C
            000 ^ 100 = 100
                      = 4

        6th performing: UpdatedMask ^ C
            100 ^ 100 = 000
                      = 0

        7th performing: Updatedmask ^ B
            000 ^ 010 = 010
                      = 2

    Finally the values looks like this:

             A   B   B   A   C   C   B
        0    1   3   1   0   4   0   2

        What's the significance of doing this:

        Case even:

            If the mask value at two points is same, what does this signifies:

                Suppose we have perfrom our mask operation with 1 as:
                    mask = 1 ^ (....)

                    and after some time we have again got the value 1 (this means that whatever
                    value we have in (...) to do the XOR operation those are in pairs)

                    e.g. 1^(A^B^C^B^A^C)

                        C and C are in par and will collectively form 0
                        A and A will collectively form 0
                        B and B will collectively form 0

                        therefore the resultant will be 0
                        finally 1 ^ 0 = 1 (the same value again)

            Therefore, the main thing here to note is that, if at any point in the value of the mask
                if we see a repetition of some value, it means that

                after the first value (of that repeated value in the left) whatever value we have chosen
                    upto the second same value (in the right side)
                    those have the frequency of letters as even

                e.g.

                         A   B   B   A   C   C   B
                    0    1   3   1   0   4   0   2 

                    reaching at second B, we see a repetition in the value of 1, so the first
                        and the second B nullifies each other, therefore such thing is happening

                    similarly when we reach the second A, we check whether we have seen 0 before
                        in this case yes

                So the main point here is to understand that if we see any repetition of the values
                    it means that between those two points (excluding the first one, and including
                    the second one) everything that is there is in pair

        Case odd:

                 A   B   B   A   C   C   B
            0    1   3   1   0   4   0   2

            Suppose we are the first C, and if we perform XOR of this C with all the values
                from 'A' till 'J', what we are going to get?

                Suppose if there were any letters that has been repeated odd number of times
                    e.g. char 'ch'

                    now we are performing XOR of this char with all the chars from 'a' till 'j'
                        what will happen is that this ch will be removed

                        and we will be left with what are all the other values that have even number
                            of repetitions

            e.g.
                         A   B   B   A   C   C   B
                    0    1   3   1   0   4   0   2

                    Suppose we are the last B where the mask value is 2 (010)

                    Now if we start performing XOR operation of this mask for
                        each of the character from 'a' till 'j'

                        e.g. Mask = 010
                            Xor with A
                            010 ^ 001 = 011 (3)

                        Now we'll check whether we have seen 3 before in our mask values
                            in this case "YES" at 1st index of the string
                            and how many times it has come is, just one time
                            (because that many times only even numbers present)

                        So it means that there will be one substring from this particular
                            point (1st index) until the current index (in this case last index)
                            where 'A' will be the letter which will be repeated odd number of times

                            since performing XOR of the mask with 'A' resulted in a repeated value

*/

#include <bits/stdc++.h>
#include <string>
using namespace std;

class Solution
{
public:
    long long wonderfulSubstrings(string word)
    {
        long long count[1024] = {1};
        long long mask = 0L;
        count[0] = 1;
        long long res = 0L;
        for (auto ch : word)
        {
            mask ^= 1 << (ch - 'a');
            res += count[mask];
            for (int i = 0; i < 10; ++i)
            {
                res += count[mask ^ (1 << i)];
            }
            count[mask]++;
        }
        return res;
    }
};