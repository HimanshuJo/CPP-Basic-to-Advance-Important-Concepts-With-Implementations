//2250. Count Number of Rectangles Containing Each Point
/*
You are given a 2D integer array rectangles where rectangles[i] = [li, hi] indicates that 
ith rectangle has a length of li and a height of hi. 
You are also given a 2D integer array points where points[j] = [xj, yj] is a point with coordinates (xj, yj).

The ith rectangle has its bottom-left corner point at the coordinates (0, 0) and its 
top-right corner point at (li, hi).

Return an integer array count of length points.length where count[j] is the number 
of rectangles that contain the jth point.

The ith rectangle contains the jth point if 0 <= xj <= li and 0 <= yj <= hi. 
Note that points that lie on the edges of a rectangle are also considered to be 
contained by that rectangle.

Input: rectangles = [[1,2],[2,3],[2,5]], points = [[2,1],[1,4]]
Output: [2,1]
Explanation: 
The first rectangle contains no points.
The second rectangle contains only the point (2, 1).
The third rectangle contains the points (2, 1) and (1, 4).
The number of rectangles that contain the point (2, 1) is 2.
The number of rectangles that contain the point (1, 4) is 1.
Therefore, we return [2, 1].

Input: rectangles = [[1,1],[2,2],[3,3]], points = [[1,3],[1,1]]
Output: [1,3]
Explanation:
The first rectangle contains only the point (1, 1).
The second rectangle contains only the point (1, 1).
The third rectangle contains the points (1, 3) and (1, 1).
The number of rectangles that contain the point (1, 3) is 1.
The number of rectangles that contain the point (1, 1) is 3.
Therefore, we return [1, 3].

Constraints:

1 <= rectangles.length, points.length <= 5 * 104
rectangles[i].length == points[j].length == 2
1 <= li, xj <= 109
1 <= hi, yj <= 100
All the rectangles are unique.
All the points are unique.
*/
/*
TLE:

class Solution {
public:
    vector<int> countRectangles(vector<vector<int>>& rectangles, vector<vector<int>>& points) {
        sort(rectangles.begin(), rectangles.end(), greater<>());
        int sz=points.size();
        int sz_=rectangles.size();
        vector<int>res(sz, 0);
        int idx=0;
        for(auto &pentries: points){
            int count=0;
            for(int i=0; i<sz_; ++i){
                vector<int>rentries=rectangles[i];
                if(rentries[0]>=pentries[0]&&rentries[1]>=pentries[1]){
                    count++;
                } else if(rentries[0]<pentries[0]){
                    break;
                }
            }
            res[idx]=count;
            idx++;
        }
        return res;
    }
};
*/

class Solution {
public:
    
    int binarySearch(vector<int>&vec, int x){
        int res=vec.size();
        int left=0, right=vec.size()-1;
        while(left<=right){
            int mid=left+(right-left)/2;
            if(vec[mid]>=x){
                res=mid;
                right=mid-1;
            } else{
                left=mid+1;
            }
        }
        return res;
    }
    
    vector<int> countRectangles(vector<vector<int>>& rectangles, vector<vector<int>>& points) {
        unordered_map<int, vector<int>>mp;
        for(auto &rentries: rectangles){
            mp[rentries[1]].push_back(rentries[0]);
        }
        for(int i=0; i<=100; ++i){
            vector<int>vec=mp[i];
            sort((mp[i]).begin(), (mp[i]).end());
        }
        int sz=points.size();
        int sz_=rectangles.size();
        vector<int>res(sz, 0);
        int idx=0;
        for(auto &pentries: points){
            int count=0;
            for(int i=pentries[1]; i<=100; ++i){
                if(mp.find(i)!=mp.end()){
                    int idx=binarySearch(mp[i], pentries[0]);
                    count+=mp[i].size()-idx;
                }
            }
            res[idx]=count;
            idx++;
        }
        return res;
    }
};