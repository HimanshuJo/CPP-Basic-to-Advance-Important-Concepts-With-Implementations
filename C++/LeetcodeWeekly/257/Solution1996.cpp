// The Number of Weak Characters in the Game
/*
You are playing a game that contains multiple characters, and each of the characters has two main properties: attack and defense. You are given a 2D integer array properties where properties[i] = [attacki, defensei] represents the properties of the ith character in the game.

A character is said to be weak if any other character has both attack and defense levels strictly greater than this character's attack and defense levels. More formally, a character i is said to be weak if there exists another character j where attackj > attacki and defensej > defensei.

Return the number of weak characters.

Example 3:

Input: properties = [[1,5],[10,4],[4,3]]
Output: 1
Explanation: The third character is weak because the second character has a strictly greater attack and defense.
*/
/*
Algo:
we need both attack and defence of the player should be less than the other player then only we can say the later person is weaker
so we need to see two parameter(defence and attack) to give our answer
we can do a thing lets sort the array on one parameter and then we will see how will we handle the other one
if the array is sorted on one parameter we only need to worry about other. As the array is sorted the greater index cant be weaker than then smaller index i.e if i > j i cant be weaker than j (as the array is sorted)
so lets iterate from back and store the maximum element we encounter(as if we found a larger element(value of second parameter) on right it will be weaker as the second element is less and first one was already less because of sorting so both strenght and defence is weak)
when ever we encounter this we increased our answer by one

EDGE CASE : if on sorting 2 element have same attack strength we will put the one with greater defence first because 
  we only need both parameter to be strictly greater.if we ignore this case we will increase the answer in following case
(5, 2), (5, 4) our code will give answer 1 if we dont handle edge case while the answer should be zero
example:
         -(5,2),(5,4) gives ans 1 (wrong ans as both have strength of 5 which is not strictly increasing
		 we need to tackle this that why we put (5,4) before (5,2) to tackle the case ) 
         
		 -(5,4),(5,2) gives ans 0 (which is correct)

	
	

DRY RUN:
		 [[1,5],[10,4],[4,3]] 
		- let sort this as mention above (on strength)
		 [1,5],[4,3],[10,4]
		 -now move from back that is 2 index of array and keep on storing max till now and comparing
		     when i==2
			     4 is not less than mtn(INT_MIN) so we dont increase ans but our mtn get updated to 4
		     when i==1
			    3 is less than mtn(4) so we increase our ans by 1 ( (3,4) is weaker than (10,4)  )
			when i==0
			  5 is not less than mtn(4) so we dont increase our ans
			 
			 our final ans is 1
*/
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    //handling the edge case while sorting
    static bool comp(vector<int> &a, vector<int> &b)
    {
        if (a[0] == b[0])
        {
            return a[1] > b[1];
        }
        return a[0] < b[0];
    }
    int numberOfWeakCharacters(vector<vector<int>> &properties)
    {
        sort(properties.begin(), properties.end(), comp); //sorting the array
        int mtn = INT_MIN;                                //max till now while moving from right
        int ans = 0;

        for (int i = properties.size() - 1; i >= 0; i--)
        {
            if (properties[i][1] < mtn) // if the second parameter is also less increase the ans
                ans++;
            mtn = max(mtn, properties[i][1]);
        }
        return ans;
    }
};