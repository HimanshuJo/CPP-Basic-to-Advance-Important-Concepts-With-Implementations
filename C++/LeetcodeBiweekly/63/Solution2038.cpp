#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool winnerOfGame(string s) {
        int countA = 0;
        int countB = 0;
        size_t nPosA = s.find("AAA", 0); // first occurrence
        size_t nPosB = s.find("BBB", 0); // first occurrence
        while (nPosA != string::npos)
        {
            countA++;
            nPosA = s.find("AAA", nPosA + 1);
        }
        while (nPosB != string::npos)
        {
            countB++;
            nPosB = s.find("BBB", nPosB + 1);
        }
        if(countA>countB) return true;
        return false;
    }
};