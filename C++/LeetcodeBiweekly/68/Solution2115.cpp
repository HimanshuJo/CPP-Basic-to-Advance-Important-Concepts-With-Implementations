// 2115. Find All Possible Recipes from Given Supplies
/*
You have information about n different recipes. You are given a string array recipes and a 2D string array ingredients. 
The ith recipe has the name recipes[i], and you can create it if you have all the needed ingredients from ingredients[i]. 
Ingredients to a recipe may need to be created from other recipes, i.e., ingredients[i] may contain a string that is in recipes.

You are also given a string array supplies containing all the ingredients that you initially have, and you have an infinite supply of all of them.

Return a list of all the recipes that you can create. You may return the answer in any order.

Note that two recipes may contain each other in their ingredients.


Example 1:

Input: recipes = ["bread"], ingredients = [["yeast","flour"]], supplies = ["yeast","flour","corn"]
Output: ["bread"]
Explanation:
We can create "bread" since we have the ingredients "yeast" and "flour".

Example 2:

Input: recipes = ["bread","sandwich"], ingredients = [["yeast","flour"],["bread","meat"]], supplies = ["yeast","flour","meat"]
Output: ["bread","sandwich"]
Explanation:
We can create "bread" since we have the ingredients "yeast" and "flour".
We can create "sandwich" since we have the ingredient "meat" and can create the ingredient "bread".

Example 3:

Input: recipes = ["bread","sandwich","burger"], ingredients = [["yeast","flour"],["bread","meat"],["sandwich","meat","bread"]], supplies = ["yeast","flour","meat"]
Output: ["bread","sandwich","burger"]
Explanation:
We can create "bread" since we have the ingredients "yeast" and "flour".
We can create "sandwich" since we have the ingredient "meat" and can create the ingredient "bread".
We can create "burger" since we have the ingredient "meat" and can create the ingredients "bread" and "sandwich".
 

Constraints:

n == recipes.length == ingredients.length
1 <= n <= 100
1 <= ingredients[i].length, supplies.length <= 100
1 <= recipes[i].length, ingredients[i][j].length, supplies[k].length <= 10
recipes[i], ingredients[i][j], and supplies[k] consist only of lowercase English letters.
All the values of recipes and supplies combined are unique.
Each ingredients[i] does not contain any duplicate values.
*/

/*
Standard dfs: TLE 40 / 112

class Solution {
public:

    vector<string> dfs(vector<string>&recipes, vector<vector<string>>&ingredients, vector<string>&supplies, vector<string>&curans, set<int>&seen, unordered_map<int, vector<string>>&memo, int idx, int sz){
        if(idx>=sz) return curans;
        if(memo.find(idx)!=memo.end()) return memo[idx];
        string currrecipe=recipes[idx];
        vector<string>ingreneed=ingredients[idx];
        bool flag2=false;
        for(auto &vals: ingreneed){
            auto it_=find(supplies.begin(), supplies.end(), vals);
            if(it_==supplies.end()){
                flag2=true;
                break;
            }
        }
        if(!flag2){
            curans.push_back(currrecipe);
            supplies.push_back(currrecipe);
        }
        seen.insert(idx);
        for(int i=0; i<sz; ++i){
            if(seen.find(i)==seen.end()){
                dfs(recipes, ingredients, supplies, curans, seen, memo, i, sz);
            }
        }
        return memo[idx]=curans;
    }

    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        int sz=recipes.size();
        vector<string>fnans;
        for(int i=0; i<sz; ++i){
            vector<string>curans;
            unordered_map<int, vector<string>>memo;
            set<int>seen;
            dfs(recipes, ingredients, supplies, curans, seen, memo, i, sz);
            if(curans.size()>fnans.size()){
                fnans=curans;
            }
        }
        return fnans;      
    }
};
*/

class Solution {
public:
    
    vector<string>res;
    unordered_set<string>st1;
    unordered_set<string>st2;
    
    bool dfs(vector<string>&recipes, vector<vector<string>>&ingredients, unordered_map<string, int>&mp, int idx, vector<bool>&seen){
        if(st1.find(recipes[idx])!=st1.end()) return true;
        if(st2.find(recipes[idx])!=st2.end()) return false;
        if(seen[idx]) return false;
        seen[idx]=true;
        for(string ingre: ingredients[idx]){
            // couldn't find a particular supply: already invalid
            // but still other checks needed
            if(st1.find(ingre)==st1.end()){
                // couldn't find a particular supply for the current recipe, 
                // but still we've a recipe to make from this particular ingredient
                if(mp.find(ingre)!=mp.end()){
                    // starting dfs taking into account current ingredient as the new recipe to make
                    if(!dfs(recipes, ingredients, mp, mp[ingre], seen)){
                        st2.insert(recipes[mp[ingre]]);
                        return false;
                    }
                } else{
                    // couldn't find a particular supply for the current recipe, 
                    // and there is no recipe to make from this particular ingredient
                    // already invalid, no dfs run
                    st2.insert(recipes[idx]);
                    return false;
                }
            }
        }
        seen[idx]=false;
        return true;
    }
    
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        unordered_map<string, int>mp;
        int n=recipes.size();
        vector<bool>seen(n, false);
        for(int i=0; i<n; ++i){
            mp[recipes[i]]=i;
        }
        for(string str: supplies){
            st1.insert(str);
        }
        for(int i=0; i<n; ++i){
            if(dfs(recipes, ingredients, mp, i, seen)){
                st1.insert(recipes[i]);
                res.push_back(recipes[i]);
            }
        }
        return res;
    }
};