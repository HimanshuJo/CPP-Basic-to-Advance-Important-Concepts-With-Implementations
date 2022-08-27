// 1912. Design Movie Rental System
/*
You have a movie renting company consisting of n shops. 
You want to implement a renting system that supports searching for, booking, and returning movies. 
The system should also support generating a report of the currently rented movies.

Each movie is given as a 2D integer array entries where 
	entries[i] = [shopi, moviei, pricei] 

	indicates that there is a copy of movie moviei at shop shopi with a rental price of pricei. 

	Each shop carries at most one copy of a movie moviei.

The system should support the following functions:

	Search: Finds the cheapest 5 shops that have an unrented copy of a given movie. 
			The shops should be sorted by price in ascending order, and in case of a tie, the one with 
			the smaller shopi should appear first. 

			If there are less than 5 matching shops, then all of them should be returned. 
			If no shop has an unrented copy, then an empty list should be returned.

	Rent: Rents an unrented copy of a given movie from a given shop.

	Drop: Drops off a previously rented copy of a given movie at a given shop.

	Report: Returns the cheapest 5 rented movies (possibly of the same movie ID) as a 2D list res where 
			res[j] = [shopj, moviej] describes that the jth cheapest rented movie moviej was rented from 
            the shop shopj. 

			The movies in res should be sorted by price in ascending order, and in case of a tie, 
			the one with the smaller shopj should appear first, and if there is still tie, 
			the one with the smaller moviej should appear first. 

			If there are fewer than 5 rented movies, then all of them should be returned. 
			If no movies are currently being rented, then an empty list should be returned.

Implement the MovieRentingSystem class:

    MovieRentingSystem(int n, int[][] entries):

    	Initializes the MovieRentingSystem object with n shops and the movies in entries.

    List<Integer> search(int movie):

    	Returns a list of shops that have an unrented copy of the given movie as described above.

    void rent(int shop, int movie):

    	Rents the given movie from the given shop.

    void drop(int shop, int movie):

    	Drops off a previously rented movie at the given shop.

    List<List<Integer>> report():

    	Returns a list of cheapest rented movies as described above.

Note: The test cases will be generated such that rent will only be called if the shop has an unrented copy 
	  of the movie, and drop will only be called if the shop had previously rented out the movie.

Example 1:

Input
["MovieRentingSystem", "search", "rent", "rent", "report", "drop", "search"]
[[3, [[0, 1, 5], [0, 2, 6], [0, 3, 7], [1, 1, 4], [1, 2, 7], [2, 1, 5]]], [1], [0, 1], [1, 2], [], [1, 2], [2]]
Output
[null, [1, 0, 2], null, null, [[0, 1], [1, 2]], null, [0, 1]]

Explanation
MovieRentingSystem movieRentingSystem = new MovieRentingSystem(3, [[0, 1, 5], [0, 2, 6], [0, 3, 7], [1, 1, 4], [1, 2, 7], [2, 1, 5]]);
movieRentingSystem.search(1); 
	// return [1, 0, 2], Movies of ID 1 are unrented at shops 1, 0, and 2. 
	// Shop 1 is cheapest; shop 0 and 2 are the same price, so order by shop number.
movieRentingSystem.rent(0, 1); // Rent movie 1 from shop 0. Unrented/Available movies at shop 0 are now [2,3].
movieRentingSystem.rent(1, 2); // Rent movie 2 from shop 1. Unrented movies at shop 1 are now [1].
movieRentingSystem.report();   // return [[0, 1], [1, 2]]. Movie 1 from shop 0 is cheapest, followed by movie 2 from shop 1.
movieRentingSystem.drop(1, 2); // Drop off movie 2 at shop 1. Unrented movies at shop 1 are now [1,2].
movieRentingSystem.search(2);  // return [0, 1]. Movies of ID 2 are unrented at shops 0 and 1. Shop 0 is cheapest, followed by shop 1.
*/

/*
TLE: 37 / 42

class MovieRentingSystem {
public:
    
    struct custComp1{
        bool operator()(const vector<int>&A, const vector<int>&B) const{
            return A[0]==B[0]?A[1]==B[1]?A[2]>B[2]:A[1]>B[1]:A[0]>B[0];
        }
    };
    
    struct custComp2{
        bool operator()(const vector<int>&A, const vector<int>&B) const{
            return A[0]==B[0]?A[1]==B[1]?A[2]>B[2]:A[1]>B[1]:A[0]>B[0];
        }
    };
    
    map<int, vector<pair<int, int>>>shpWthMv;
    unordered_map<int, unordered_map<int, int>>shpMvPr;
    priority_queue<vector<int>, vector<vector<int>>, custComp1>pq1;
    priority_queue<vector<int>, vector<vector<int>>, custComp2>pq2;
    
    MovieRentingSystem(int n, vector<vector<int>>& entries) {
        for(auto &vals: entries){
            int shop=vals[0], movie=vals[1], price=vals[2];
            shpWthMv[movie].push_back({shop, price});
            unordered_map<int, int>&temp=shpMvPr[shop];
            temp[movie]=price;
            pq1.push({price, shop, movie});
        }
    }
    
    vector<int> search(int movie) {
        vector<pair<int, int>>&curgdshps=shpWthMv[movie];
        vector<int>ans;
        vector<vector<int>>temppairs;
        while(!pq1.empty()){
            vector<int>temp=pq1.top();
            pq1.pop();
            temppairs.push_back(temp);
            int shop=temp[1], price=temp[0];
            pair<int, int>curshpdt={shop, price};
            auto it=find(curgdshps.begin(), curgdshps.end(), curshpdt);
            if(it!=curgdshps.end()){
                ans.push_back(temp[1]);
                if(ans.size()==5) break;
            }
        }
        for(auto &vals: temppairs){
            pq1.push(vals);
        }
        return ans;
    }
    
    void rent(int shop, int movie) {
        vector<pair<int, int>>&curgdshps=shpWthMv[movie];
        int pr=shpMvPr[shop][movie];
        pq2.push({pr, shop, movie});
        pair<int, int>temp={shop, pr};
        auto it=find(curgdshps.begin(), curgdshps.end(), temp);
        curgdshps.erase(it);
    }
    
    void drop(int shop, int movie) {
        vector<pair<int, int>>&curgdshps=shpWthMv[movie];
        int pr=shpMvPr[shop][movie];
        curgdshps.push_back({shop, pr});
        vector<vector<int>>temppairs;
        while(!pq2.empty()){
            vector<int>curr=pq2.top();
            pq2.pop();
            if(curr[1]==shop&&curr[2]==movie){
                break;
            } else temppairs.push_back(curr); 
        }
        for(auto &vals: temppairs){
            pq2.push(vals);
        }
    }
    
    vector<vector<int>> report() {
        vector<vector<int>>ans;
        vector<vector<int>>temppairs;
        while(!pq2.empty()){
            vector<int>curr=pq2.top();
            pq2.pop();
            temppairs.push_back(curr);
            int shop=curr[1], movie=curr[2];
            ans.push_back({shop, movie});
            if(ans.size()==5) break;
        }
        for(auto &vals: temppairs){
            pq2.push(vals);
        }
        return ans;
    }
};

*/

class MovieRentingSystem {
public:
    
    vector<set<pair<int, int>>>avl=vector<set<pair<int, int>>>(10010);
    vector<set<pair<int, int>>>getPrice=vector<set<pair<int, int>>>(10010);
    set<pair<int, pair<int, int>>>rented;
    
    MovieRentingSystem(int n, vector<vector<int>>& entries) {
        for(auto &vals: entries){
            int shop=vals[0], movie=vals[1], price=vals[2];
            avl[movie].insert({price, shop});
            getPrice[movie].insert({shop, price});
        }
    }
    
    vector<int> search(int movie) {
        vector<int>ans;
        int i=0;
        for(auto &vals: avl[movie]){
            ans.push_back(vals.second);
            ++i;
            if(i>=5) break;
        }
        return ans;
    }
    
    void rent(int shop, int movie) {
        auto it=getPrice[movie].lower_bound({shop, INT_MIN});
        int price=(*it).second;
        avl[movie].erase({price, shop});
        rented.insert({price, {shop, movie}});
    }
    
    void drop(int shop, int movie) {
        auto it=getPrice[movie].lower_bound({shop, INT_MIN});
        int price=(*it).second;
        avl[movie].insert({price, shop});
        rented.erase({price, {shop, movie}});
    }
    
    vector<vector<int>> report() {
        vector<vector<int>>ans;
        int i=0;
        for(auto &vals: rented){
            ans.push_back({vals.second.first, vals.second.second});
            ++i;
            if(i>=5) break;
        }
        return ans;
    }
};

/**
 * Your MovieRentingSystem object will be instantiated and called as such:
 * MovieRentingSystem* obj = new MovieRentingSystem(n, entries);
 * vector<int> param_1 = obj->search(movie);
 * obj->rent(shop,movie);
 * obj->drop(shop,movie);
 * vector<vector<int>> param_4 = obj->report();
 */
