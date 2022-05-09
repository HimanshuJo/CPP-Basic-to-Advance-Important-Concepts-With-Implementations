// Manacher’s Algorithm for Longest Palindromic Substring
/*
Case 1: L[currentRightPosition] = L[currentLeftPosition] applies when:

i-left palindrome is completely contained in center palindrome
i-left palindrome is NOT a prefix of center palindrome
Both above conditions are satisfied when
L[currentLeftPosition] < centerRightPosition – currentRightPosition

Case 2: L[currentRightPosition] = L[currentLeftPosition] applies when:

i-left palindrome is prefix of center palindrome (means completely contained also)
center palindrome is suffix of input string
Above conditions are satisfied when
L[currentLeftPosition] = centerRightPosition – currentRightPosition (For 1st condition) AND
centerRightPosition = 2*N where N is input string length N (For 2nd condition).

Case 3: L[currentRightPosition] > = L[currentLeftPosition] applies when:

i-left palindrome is prefix of center palindrome (and so i-left palindrome is completely 
contained in center palindrome)
center palindrome is NOT suffix of input string
Above conditions are satisfied when
L[currentLeftPosition] = centerRightPosition – currentRightPosition (For 1st condition) AND
centerRightPosition < 2*N where N is input string length N (For 2nd condition).
In this case, there is a possibility of i-right palindrome expansion and so length of 
i-right palindrome is at least as long as length of i-left palindrome.

Case 4: L[currentRightPosition] > = centerRightPosition – currentRightPosition applies when:

i-left palindrome is NOT completely contained in center palindrome
Above condition is satisfied when
L[currentLeftPosition] > centerRightPosition – currentRightPosition
*/

#include <bits/stdc++.h>
using namespace std;
char text[100];
int min(int a, int b)
{
    int res = a;
    if (b < a)
        res = b;
    return res;
}

void findLongestPalindromicString()
{
    int N = strlen(text);
    if (N == 0)
        return;
    N = 2 * N + 1;         //Position count
    vector<int> LPSArr(N); //LPS Length Array
    LPSArr[0] = 0;
    LPSArr[1] = 1;
    int CenterPos = 1;      //centerPosition
    int CenterRightPos = 2; //centerRightPosition
    int CurrRghtPos = 0;    //currentRightPosition
    int currLftPos;         //currentLeftPosition
    int maxLPSLength = 0;
    int maxLPSCenterPosition = 0;
    int start = -1;
    int end = -1;
    int diff = -1;

    //Uncomment it to print LPS Length array
    //printf("%d %d ", L[0], L[1]);
    for (CurrRghtPos = 2; CurrRghtPos < N; CurrRghtPos++)
    {
        //get currentLeftPosition for currentRightPosition
        currLftPos = 2 * CenterPos - CurrRghtPos;
        LPSArr[CurrRghtPos] = 0;
        diff = CenterRightPos - CurrRghtPos;
        //If currentRightPosition is within centerRightPosition
        if (diff > 0)
            LPSArr[CurrRghtPos] = min(LPSArr[currLftPos], diff);

        //Attempt to expand palindrome centered at currentRightPosition
        //Here for odd positions, we compare characters and
        //if match then increment LPS Length by ONE
        //If even position, we just increment LPS by ONE without
        //any character comparison
        while (((CurrRghtPos + LPSArr[CurrRghtPos]) < N &&
                (CurrRghtPos - LPSArr[CurrRghtPos]) > 0) &&
               (((CurrRghtPos + LPSArr[CurrRghtPos] + 1) % 2 == 0) ||
                (text[(CurrRghtPos + LPSArr[CurrRghtPos] + 1) / 2] ==
                 text[(CurrRghtPos - LPSArr[CurrRghtPos] - 1) / 2])))
        {
            LPSArr[CurrRghtPos]++;
        }

        if (LPSArr[CurrRghtPos] > maxLPSLength) // Track maxLPSLength
        {
            maxLPSLength = LPSArr[CurrRghtPos];
            maxLPSCenterPosition = CurrRghtPos;
        }

        //If palindrome centered at currentRightPosition
        //expand beyond centerRightPosition,
        //adjust centerPosition based on expanded palindrome.
        if (CurrRghtPos + LPSArr[CurrRghtPos] > CenterRightPos)
        {
            CenterPos = CurrRghtPos;
            CenterRightPos = CurrRghtPos + LPSArr[CurrRghtPos];
        }
        //Uncomment it to print LPS Length array
        //printf("%d ", L[i]);
    }
    //printf("\n");
    start = (maxLPSCenterPosition - maxLPSLength) / 2;
    end = start + maxLPSLength - 1;
    printf("LPS of string is %s : ", text);
    for (CurrRghtPos = start; CurrRghtPos <= end; CurrRghtPos++)
        printf("%c", text[CurrRghtPos]);
    printf("\n");
}

int main(int argc, char *argv[])
{

    strcpy(text, "babcbabcbaccba");
    findLongestPalindromicString();

    strcpy(text, "abaaba");
    findLongestPalindromicString();

    strcpy(text, "abababa");
    findLongestPalindromicString();

    strcpy(text, "abcbabcbabcba");
    findLongestPalindromicString();

    strcpy(text, "forgeeksskeegfor");
    findLongestPalindromicString();

    strcpy(text, "caba");
    findLongestPalindromicString();

    strcpy(text, "abacdfgdcaba");
    findLongestPalindromicString();

    strcpy(text, "abacdfgdcabba");
    findLongestPalindromicString();

    strcpy(text, "abacdedcaba");
    findLongestPalindromicString();

    return 0;
}
