//2249. Count Lattice Points Inside a Circle
/*
Given a 2D integer array circles where circles[i] = [xi, yi, ri] represents the 
center (xi, yi) and radius ri of the ith circle drawn on a grid, return the number of 
lattice points that are present inside at least one circle.

Note:

A lattice point is a point with integer coordinates.
Points that lie on the circumference of a circle are also considered to be inside it.

Input: circles = [[2,2,1]]
Output: 5
Explanation:
The figure above shows the given circle.
The lattice points present inside the circle are (1, 2), (2, 1), (2, 2), (2, 3), and (3, 2) and are shown in green.
Other points such as (1, 1) and (1, 3), which are shown in red, are not considered inside the circle.
Hence, the number of lattice points present inside at least one circle is 5.

Input: circles = [[2,2,2],[3,4,1]]
Output: 16
Explanation:
The figure above shows the given circles.
There are exactly 16 lattice points which are present inside at least one circle. 
Some of them are (0, 2), (2, 0), (2, 4), (3, 2), and (4, 4).

Constraints:

1 <= circles.length <= 200
circles[i].length == 3
1 <= xi, yi <= 100
1 <= ri <= min(xi, yi)
*/

/*
Solution2:

class Solution {
public:
    
    int countLatticePoints(vector<vector<int>>& circles) {
        int sz=circles.size();
        int res=0;
        for(int x_=0; x_<=200; x_++)
        {
            for(int y_=0; y_<=200; ++y_){
                for(int i=0; i<sz; ++i){
                    int r=circles[i][2], x=circles[i][0], y=circles[i][1];
                    if((x-x_)*(x-x_)+(y-y_)*(y-y_)<=r*r){
                        res++;
                        break;
                    }
                }
            }
        }
        return res;
    }
};
*/

class Solution {
public:
    
    set<pair<int, int>>st;
    
    void LatticePoints(int r, int x, int y){
        for(int x_=-r; x_<=r; x_++)
        {
            for(int y_=-r; y_<=r; ++y_){
                if((x_*x_)+(y_*y_)<=r*r){
                    st.insert({x_+x, y_+y});
                }
            }
        }
    }
    
    int countLatticePoints(vector<vector<int>>& circles) {
        int sz=circles.size();
        int res=0;
        for(int i=0; i<sz; ++i){
            int r=circles[i][2], x=circles[i][0], y=circles[i][1];
            LatticePoints(r, x, y);
        }
        return st.size();
    }
};