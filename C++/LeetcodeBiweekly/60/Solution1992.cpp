// Find All Groups of Farmland
/*
You are given a 0-indexed m x n binary matrix land where a 0 represents a hectare of forested land and a 1 represents a hectare of farmland.

To keep the land organized, there are designated rectangular areas of hectares that consist entirely of farmland. These rectangular areas are called groups. No two groups are adjacent, meaning farmland in one group is not four-directionally adjacent to another farmland in a different group.

land can be represented by a coordinate system where the top left corner of land is (0, 0) and the bottom right corner of land is (m-1, n-1). Find the coordinates of the top left and bottom right corner of each group of farmland. A group of farmland with a top left corner at (r1, c1) and a bottom right corner at (r2, c2) is represented by the 4-length array [r1, c1, r2, c2].

Return a 2D array containing the 4-length arrays described above for each group of farmland in land. If there are no groups of farmland, return an empty array. You may return the answer in any order.

Input: land = [[1,0,0],[0,1,1],[0,1,1]]
Output: [[0,0,0,0],[1,1,2,2]]
Explanation:
The first group has a top left corner at land[0][0] and a bottom right corner at land[0][0].
The second group has a top left corner at land[1][1] and a bottom right corner at land[2][2].
*/

class Solution {
public:
    
    bool isValid(vector<vector<int>>&land, int rws, int cols, int nwx, int nwy){
        return nwx>=0&&nwy>=0&&nwx<=rws-1&&nwy<=cols-1&&land[nwx][nwy]==1;
    }
    
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        vector<vector<int>>res;
        int rws=land.size(), cols=land[0].size();
        queue<pair<int, int>>q;
        vector<vector<int>>dir{{1, 0}, {-1, 0}, {0, -1}, {0, 1}};
        for(int i=0; i<rws; ++i){
            for(int j=0; j<cols; ++j){
                if(land[i][j]==1){
                    vector<int>temp;
                    temp.push_back(i);
                    temp.push_back(j);
                    land[i][j]=0;
                    q.push({i, j});
                    while(!q.empty()){
                        int sz=q.size();
                        while(sz--){
                            pair<int, int>curr=q.front();
                            q.pop();
                            for(auto &vals: dir){
                                int nwx=curr.first+vals[0], nwy=curr.second+vals[1];
                                if(isValid(land, rws, cols, nwx, nwy)){
                                    land[nwx][nwy]=0;
                                    temp.push_back(nwx);
                                    temp.push_back(nwy);
                                    q.push({nwx, nwy});
                                }
                            }
                        }
                    }
                    res.push_back({temp[0], temp[1], temp[temp.size()-2], temp[temp.size()-1]});
                }
            }
        }
        return res;
    }
};