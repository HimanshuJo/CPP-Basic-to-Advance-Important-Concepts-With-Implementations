// 1733. Minimum Number of People to Teach
/*
 * On a social network consisting of m users and some friendships between users, 
 * two users can communicate with each other if they know a common language.

You are given an integer n, an array languages, and an array friendships where:

    There are n languages numbered 1 through n,
    languages[i] is the set of languages the ith user knows, and
    friendships[i] = [ui, vi] denotes a friendship between the users ui and vi.

	You can choose one language and teach it to some users so that all friends can communicate with each other. 
	Return the minimum number of users you need to teach.
	
	Note that friendships are not transitive, meaning if x is a friend of y and y is a friend of z, 
	this doesn't guarantee that x is a friend of z.
	
Example 1:

Input: n = 2, languages = [[1],[2],[1,2]], friendships = [[1,2],[1,3],[2,3]]
Output: 1
Explanation: You can either teach user 1 the second language or user 2 the first language.

Example 2:

Input: n = 3, languages = [[2],[1,3],[1,2],[3]], friendships = [[1,4],[1,2],[3,4],[2,3]]
Output: 2
Explanation: Teach the third language to users 1 and 3, yielding two users to teach.

 
Constraints:

    2 <= n <= 500
    languages.length == m
    1 <= m <= 500
    1 <= languages[i].length <= n
    1 <= languages[i][j] <= n
    1 <= ui <= languages.length
    1 <= friendships.length <= 500
    All tuples (ui, vi) are unique
    languages[i] contains only unique values
 */
/*
 * Intuition:
 * 	Find out all the friendships that are already possible without any teachings
 *  (no need to teach here anything)
 * 
 * 	The rest we will try to teach using 1 language
 * 		Find out from all the languages what is the minimum we need to teach
 */

class Solution {
public:
    
    bool doesNotNeedsTeaching(vector<vector<int>>&languages, int friendl, int friendr, vector<vector<int>>&memo){
        if(memo[friendl][friendr]!=0) return memo[friendl][friendr]==1;
        for(int i=0; i<languages[friendr].size(); ++i){
            if(find(languages[friendl].begin(), languages[friendl].end(), languages[friendr][i])!=languages[friendl].end()){
                memo[friendl][friendr]=memo[friendr][friendl]=1;
                return true;
            }
        }
        memo[friendl][friendr]=memo[friendr][friendl]=-1;
        return false;
    }
    
    int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
        int lngsz=languages.size();
        int ans=lngsz;
        vector<vector<int>>memo(lngsz+1, vector<int>(lngsz+1, 0));
        for(int lang=1; lang<=n; ++lang){
            int count=0;
            vector<bool>needToTeach(lngsz, false);
            int frsz=friendships.size();
            for(int x=0; x<frsz; ++x){
                int friendl=friendships[x][0]-1;
                int friendr=friendships[x][1]-1;
                if(doesNotNeedsTeaching(languages, friendl, friendr, memo)) continue;
                if(find(languages[friendl].begin(), languages[friendl].end(), lang)==languages[friendl].end()){
                    if(!needToTeach[friendl]){
                        count++;
                        needToTeach[friendl]=true;
                    }
                }
                if(find(languages[friendr].begin(), languages[friendr].end(), lang)==languages[friendr].end()){
                    if(!needToTeach[friendr]){
                        count++;
                        needToTeach[friendr]=true;
                    }
                }
            }
            ans=min(ans, count);
        }
        return ans;
    }
};

int main()
{
    Solution obj;
    vector<vector<int>> languages = {{1}, {2}, {1, 2}};
    vector<vector<int>> friendships = {{1, 2}, {1, 3}, {2, 3}};
    obj.minimumTeaching(2, languages, friendships);
}