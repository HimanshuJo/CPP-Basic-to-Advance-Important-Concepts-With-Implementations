// The Earliest and Latest Rounds Where Players Compete

/*
 * There is a tournament where n players are participating.
 * The players are standing in a single row and are numbered from 1 to n based 
 * on their initial standing position
 * (player 1 is the first player in the row, player 2 is the second player in the row, etc.)
 * 
 * The tournament consists of multiple rounds (starting from round number 1). 
 * In each round, the ith player from the front of the row competes against the 
 * ith player from the end of the row, and the winner advances to the next round. 
 * 
 * When the number of players is odd for the current round, the player in the middle 
 * automatically advances to the next round.
 * 
 * For example, if the row consists of players 1, 2, 4, 6, 7

    Player 1 competes against player 7.
    Player 2 competes against player 6.
    Player 4 automatically advances to the next round.

	After each round is over, the winners are lined back up in the 
	row based on the original ordering assigned to them initially (ascending order).
	
	The players numbered firstPlayer and secondPlayer are the best in the tournament. 
	They can win against any other player before they compete against each other. 
	If any two other players compete against each other, either of them might win, 
	and thus you may choose the outcome of this round.
	
	Given the integers n, firstPlayer, and secondPlayer, return an integer 
	array containing two values, the earliest possible round number and the 
	latest possible round number in which these two players will compete against each other,
	respectively.
	
	Example 1:

	Input: n = 11, firstPlayer = 2, secondPlayer = 4
	Output: [3,4]
	Explanation:
	One possible scenario which leads to the earliest round number:
	First round: 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11
	Second round: 2, 3, 4, 5, 6, 11
	Third round: 2, 3, 4
	One possible scenario which leads to the latest round number:
	First round: 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11
	Second round: 1, 2, 3, 4, 5, 6
	Third round: 1, 2, 4
	Fourth round: 2, 4

 */

/*
 * We can try all the combinations, and it should work  since n is limited to 28.
 * 
 * For the first round, we have no more than 2^12 choices (14 pairs, and the winners are 
 * pre-defined for 2 pairs)
 * 
 * Second round - 2^5, then 2^2, then 1 choice. Finally we will have just two winners
 * 
 * In total we have 524,288 combinations and 5 rounds
 * 
 * -------
 * 
 * The tricky part is to make the algorithm as efficient as possible. For that we can use a
 * 	bit-masking technique (very powerful)
 * 
 * -------
 * 
 * We move i and j to pick the pairs; when i >= j, we start a new round
 * 
 * When i and j point to our finalists, we can update the min and the max rounds
 */

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int mn = 10000;
    int mx = 0;
    int first;
    int second;
    void dfs(vector<int> &arr, int round)
    {
        int size = arr.size() / 2;
        if (arr.size() == 1)
            return;
        for (int i = 0; i < size; i++)
        {
            //if we can match first and second in this round.
            if (arr[i] == first && arr[arr.size() - i - 1] == second)
            {
                mn = min(mn, round);
                mx = max(mx, round);
                return;
            }
        }
        bool f1 = false, f2 = false;
        for (auto n : arr)
        {
            f1 |= n == first;
            f2 |= n == second;
        }
        if (!f1 || !f2)
        { //can not find first and second player.
            return;
        }
        vector<int> nextarr(size + (arr.size() % 2));
        int m = (1 * (int)pow(2, size)) - 1;
        for (int i = 0; i <= m; i++)
        { //try all the winning status for the left side players.
            int left = 0, right = nextarr.size() - 1;
            for (int j = 0; j < size; j++)
            {
                if ((1 * (int)pow(2, j)) & i)
                { //left side player win, put it to the next array.
                    nextarr[left++] = arr[j];
                }
                else
                { //right side player win.
                    nextarr[right--] = arr[arr.size() - j - 1];
                }
            }
            if (arr.size() % 2)
            { //middle player go to the next round.
                nextarr[left] = arr[arr.size() / 2];
            }
            dfs(nextarr, round + 1);
        }
    }
    
    vector<int> earliestAndLatest(int n, int firstPlayer, int secondPlayer)
    {
        vector<int> arr(n);
        for (int i = 1; i <= n; i++)
        {
            arr[i - 1] = i;
        }
        first = firstPlayer;
        second = secondPlayer;
        dfs(arr, 1);
        return {mn, mx};
    }
};