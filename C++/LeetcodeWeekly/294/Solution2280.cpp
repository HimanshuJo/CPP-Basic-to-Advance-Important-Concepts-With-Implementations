// 2280. Minimum Lines to Represent a Line Chart
/*
You are given a 2D integer array stockPrices where stockPrices[i] = [dayi, pricei] 
indicates the price of the stock on day dayi is pricei. 

A line chart is created from the array by plotting the points on an XY plane 
with the X-axis representing the day and the Y-axis representing the price and connecting adjacent points.

Input: stockPrices = [[1,7],[2,6],[3,5],[4,4],[5,4],[6,3],[7,2],[8,1]]
Output: 3
Explanation:
The diagram above represents the input, with the X-axis representing the day and Y-axis representing the price.
The following 3 lines can be drawn to represent the line chart:
- Line 1 (in red) from (1,7) to (4,4) passing through (1,7), (2,6), (3,5), and (4,4).
- Line 2 (in blue) from (4,4) to (5,4).
- Line 3 (in green) from (5,4) to (8,1) passing through (5,4), (6,3), (7,2), and (8,1).
It can be shown that it is not possible to represent the line chart using less than 3 lines.

Input: stockPrices = [[3,4],[1,2],[7,8],[2,3]]
Output: 1
Explanation:
As shown in the diagram above, the line chart can be represented with a single line.

Constraints:

1 <= stockPrices.length <= 10^5
stockPrices[i].length == 2
1 <= dayi, pricei <= 10^9
All dayi are distinct.
*/

/*
Solution 2:

struct custComp{
  bool operator()(const vector<int>&A, const vector<int>&B){
      return (A[0]==B[0]?A[1]<B[1]:A[0]<B[0]);
  }
};

class Solution {
public:

    int minimumLines(vector<vector<int>>& stockPrices) {
        sort(stockPrices.begin(), stockPrices.end(), custComp());
        int ans=1;
        int sz=stockPrices.size();
        if(sz==1) return 0;
        if(sz>=3){
            for(int i=2; i<sz; ++i){
                long long x3=stockPrices[i-2][0], y3=stockPrices[i-2][1];
                long long x2=stockPrices[i-1][0], y2=stockPrices[i-1][1];
                long long x1=stockPrices[i][0], y1=stockPrices[i][1];
                long long diff1=(y3-y2)*(x2-x1);
                long long diff2=(y2-y1)*(x3-x2);
                if(diff1!=diff2) ans++;
            }   
        }
        return ans;
    }
};
*/

struct custComp{
  bool operator()(const vector<int>&A, const vector<int>&B){
      return (A[0]==B[0]?A[1]<B[1]:A[0]<B[0]);
  }
};

class Solution {
public:
    
    double slope(int x1, int y1, int x2, int y2){
        return ((double)(y2 - y1) / (x2 - x1));
    }

    int minimumLines(vector<vector<int>>& stockPrices) {
        int mod=1e9;
        sort(stockPrices.begin(), stockPrices.end(), custComp());
        int ans=1;
        double currslope=0;
        int sz=stockPrices.size();
        if(sz==1) return 0;
        int bgnX=stockPrices[0][0]%mod, bgnY=stockPrices[0][1]%mod;
        if(sz>=2){
            int bgnX2=stockPrices[1][0]%mod, bgnY2=stockPrices[1][1]%mod;
            if(bgnY2>bgnY){
                currslope=slope(bgnX, bgnY, bgnX2, bgnY2);
            } else{
                currslope=slope(bgnX2, bgnY2, bgnX, bgnY);
            }
            bgnX=bgnX2, bgnY=bgnY2;
        } else return 1;
        if(sz>=3){
            for(int i=2; i<sz; ++i){
                vector<int>curr=stockPrices[i];
                if(curr[1]%mod<bgnY){
                    double tmpslope=slope(curr[0]%mod, curr[1]%mod, bgnX, bgnY);
                    if(tmpslope!=currslope){
                        ans++;  
                    }
                    bgnX=curr[0]%=mod, bgnY=curr[1]%=mod;
                    currslope=tmpslope;
                } else if(curr[1]%mod>bgnY){
                    double tmpslope=slope(bgnX, bgnY, curr[0]%mod, curr[1]%mod);
                    if(tmpslope!=currslope){
                        ans++;  
                    }
                    bgnX=curr[0]%mod, bgnY=curr[1]%mod;
                    currslope=tmpslope;
                } else if(curr[1]%mod==bgnY){
                    if(currslope!=0) ans++;
                    bgnX=curr[0]%mod, bgnY=curr[1]%mod;
                    currslope=0;
                }
            }   
        }
        return ans;
    }
};