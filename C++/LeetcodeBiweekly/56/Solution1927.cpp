// 1927. Sum Game
/*
Alice and Bob take turns playing a game, with Alice starting first.

You are given a string num of even length consisting of digits and '?' characters. 
On each turn, a player will do the following if there is still at least one '?' in num:

Choose an index i where num[i] == '?'.
Replace num[i] with any digit between '0' and '9'.
The game ends when there are no more '?' characters in num.

For Bob to win, the sum of the digits in the first half of num must be equal to the sum of the 
digits in the second half. For Alice to win, the sums must not be equal.

For example, if the game ended with num = "243801", then Bob wins because 2+4+3 = 8+0+1. 
If the game ended with num = "243803", then Alice wins because 2+4+3 != 8+0+3.
Assuming Alice and Bob play optimally, return true if Alice will win and false if Bob will win.

Example 1:

Input: num = "5023"
Output: false
Explanation: There are no moves to be made.
The sum of the first half is equal to the sum of the second half: 5 + 0 = 2 + 3.
Example 2:

Input: num = "25??"
Output: true
Explanation: Alice can replace one of the '?'s with '9' and it will be impossible for Bob to make the sums equal.
Example 3:

Input: num = "?3295???"
Output: false
Explanation: It can be proven that Bob will always win. One possible outcome is:
- Alice replaces the first '?' with '9'. num = "93295???".
- Bob replaces one of the '?' in the right half with '9'. num = "932959??".
- Alice replaces one of the '?' in the right half with '2'. num = "9329592?".
- Bob replaces the last '?' in the right half with '7'. num = "93295927".
Bob wins because 9 + 3 + 2 + 9 = 5 + 9 + 2 + 7.
 

Constraints:

2 <= num.length <= 10^5
num.length is even.
num consists of only digits and '?'.
*/

/*
Algo:

The idea is either alice or bob want to maximize the 1st half of string and minimize the 2nd half of string. 
If alice want to maximize, bob trys to minimize and viceversa.

->let cnt1 be the number of places to be replaced in 1st half and cnt2 be the number of places replaced in 
2nd half and sum is result of (sum of values in 1st half - sum of values in 2nd half) .

->It doesn't matter who wants to maximize(because both play optimally), sum will add up (cnt1/2)*9 in the 1st half 
and decrease by (cnt2/9).

-> if final sum ans ==0 then BOB wins else Alice wins!!

-> But if the total number of question marks are odd, then there is definite edge towards Alice because, 
she starts the game first and get a chance to replace one extra question mark. In this case, Alice will Win.

-------

leftQCnt is the count of '?' in the first half. 
So, one of the person will replace '?" with 9 while the other one will replace it with 0, 
so the expected value will be (0+9)/2. 

So, now as we know that count of '?' in the first half is cnt1 so half of them will be replaced with 9 
and another half of them will be replaced with 0. so the answer will be (leftQCnt/2)*0+(leftQCnt/2)*9 = (leftQCnt/2)*9.
And same logic goes for second half.

-------

Observation I
If there is only one '?', Alice will win. Alice have at least one choice to make the sum uneven.

Observation II
If Alice play last, Alice will win. Same as Observations I.

Observation III
Now we have even number of '?', say they are on left and right. Alice pick first '?', 
Bob should pick '?' on the other side with same number to cancel out Alice's move. 
Repeat this until all '?' are on one side.

Now the problem becomes: can Alice and Bob pick to make up the difference between left sum and right sum.

Observation IV
If there are only 2 '?' left, the difference has to be 9 for Bob to win. Because no matter what Alice choose, 
Bob can pick one to make 9. This means, at any rounds, whatever Alice pick, Bob can counter and make the 
pair sum 9. [0,9] [1,8] [2,7] [3,6] [4,5]

Final Observation V
If there are 4 '?' left, then the difference has to be 18 for Bob to win.
*/

class Solution {
public:
    bool sumGame(string num) {
        int n=num.length();
        int sum=0;
        int leftQCnt=0, rightQCnt=0;
        for(int i=0; i<n; ++i){
            if(i<n/2){
                if(num[i]=='?') leftQCnt++;
                else sum+=(num[i]-'0');
            } else{
                if(num[i]=='?') rightQCnt++;
                else sum-=(num[i]-'0');
            }
        }
        if((leftQCnt+rightQCnt)%2!=0) return true;
        int ans=sum+(leftQCnt/2)*9-(rightQCnt/2)*9;
        return ans!=0;
    }
};