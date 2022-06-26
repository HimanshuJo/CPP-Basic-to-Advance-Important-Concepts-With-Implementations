// 1776. Car Fleet II
/*
There are n cars traveling at different speeds in the same direction along a one-lane road. 
You are given an array cars of length n, where cars[i] = [positioni, speedi] represents:

positioni is the distance between the ith car and the beginning of the road in meters. 
It is guaranteed that positioni < positioni+1.

speedi is the initial speed of the ith car in meters per second.

For simplicity, cars can be considered as points moving along the number line. 
Two cars collide when they occupy the same position. 

Once a car collides with another car, they unite and form a single car fleet. 
The cars in the formed fleet will have the same position and the same speed, 
which is the initial speed of the slowest car in the fleet.

Return an array answer, where answer[i] is the time, in seconds, 
at which the ith car collides with the next car, or -1 if the car does not collide
with the next car. 

Answers within 10^-5 of the actual answers are accepted.

Example 1:

Input: cars = [[1,2],[2,1],[4,3],[7,2]]
Output: [1.00000,-1.00000,3.00000,-1.00000]
Explanation: After exactly one second, the first car will collide with the second car, 
and form a car fleet with speed 1 m/s. After exactly 3 seconds, the third car will collide 
with the fourth car, and form a car fleet with speed 2 m/s.

Example 2:

Input: cars = [[3,4],[5,4],[6,3],[9,1]]
Output: [2.00000,1.00000,1.50000,-1.00000]
 

Constraints:

1 <= cars.length <= 10^5
1 <= positioni, speedi <= 10^6
positioni < positioni+1
*/

class Solution1 {
public:
    
    double catchTime(vector<vector<int>>&cars, int i, int j){
        return ((double)(cars[i][0]-cars[j][0])/(cars[j][1]-cars[i][1]));
    }
    
    vector<double> getCollisionTimes(vector<vector<int>>& cars) {
        int sz=cars.size();
        vector<double>res(sz, -1);
        stack<int>stk;
        /*
        	As soon as a car c1 catches another car c2, we can say that c1 vanishes into c2
        	(that means that after catching c2, we may view c1 as non existing
        	(cars before c1 may not catches c1))
        */
        /*
        	We can define a stack storing the indexes of cars as follows:

        	Assuming cars c0, c1, c2, .... ck are in the stack and they satisfy:

        		a) v0>v1>v2...vk, where vi is the velocity of car ci

        		b) ci+1 is the car that ci vanishes into, namely if only these cars exist
        		   
        		   then what will happen is that c0 vanishes int c1,

        		   then c1 vanishes int c2....ck-1 vanishes into ck
        */
        for(int i=sz-1; i>=0; --i){
            vector<int>curcar=cars[i];
            while(!stk.empty()){
                int nxtcaridx=stk.top();
                vector<int>nxtcar=cars[nxtcaridx];
        		/*
            		If both the conditions are satisfied

            			a) 'curcar' is faster than 'nxtcar'

            			b) 'curcar' catches 'nxtcar' before 'nxtcar' vanishes into other car

            		Then we know that 'nxtcar' is the car that 'curcar' catches first
            		(i.e 'curcar' vanishes into 'nxtcar')
            	*/
                if(curcar[1]>nxtcar[1]&&(res[nxtcaridx]==-1||catchTime(cars, i, nxtcaridx)<=res[nxtcaridx])){
                    res[i]=catchTime(cars, i, nxtcaridx);
                    break;
                }
                /*
                	At this point we've either of 2 conditions:

                		a) cars before 'curcar' will vanish into 'curcar' first before catching 'nxtcar'

                		b) 'nxtcar' vanishes into another car even before 'curcar' catches it

            		Either way 'nxtcar' can not be catched by 'curcar' or cars before 'curcar'
                */
                stk.pop();
            }
            stk.push(i);
        }
        return res;
    }
};

// -------*******-------

class Solution2 {
public:
    vector<double> getCollisionTimes(vector<vector<int>>& cars) {
        int sz=cars.size();
        stack<vector<int>>stk;
        vector<double>ans(sz, -1);
        for(int i=sz-1; i>=0; --i){
            int currd=cars[i][0], currspd=cars[i][1];
            while(!stk.empty()){
                int nextd=cars[stk.top()[0]][0], nextspd=stk.top()[1], nextidx=stk.top()[0];
                if(currspd<=nextspd||(1.0*(nextd-currd)/(currspd-nextspd)>=ans[nextidx]&&ans[nextidx]>0)){
                    stk.pop();   
                } else break;
            }
            if(!stk.empty()){
                ans[i]=1.0*(cars[stk.top()[0]][0]-currd)/(currspd-stk.top()[1]);
            }
            stk.push({i, cars[i][1]});
        }
        return ans;
    }
};
