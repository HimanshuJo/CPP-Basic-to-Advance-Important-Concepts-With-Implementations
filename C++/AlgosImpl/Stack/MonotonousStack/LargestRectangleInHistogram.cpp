/*
Monotonous stack:

	Monotone: 

		therefore, the data stored in the monotone stack should be orderly, 
		so the monotone stack is also divided into monotone increasing stack and 
		monotone decreasing stack.

-------

Monotonically increasing stack: 

	monotonically increasing stack is from the bottom of the stack to the top of the stack, 
	and the data is from large to small

-------

Monotonic decrement stack: 

	monotonic decrement stack is from the bottom of the stack to the top of the stack, 
	and the data is from small to large

-------

Pseudo code:

stack<int> st;

for (Traverse this array)
{
	if (Stack empty || Stack top element is greater than or equal to the current comparison element)
	{
		Push ;
	}
	else
	{
		while (Stack is not empty && The stack top element is smaller than the current element)
		{
			Stack top element out of stack;
			Update results;
		}
		Current data stack;
	}
}
*/

// Largest Rectangle in Histogram
/*
Given an array of integers heights representing the histogram's bar height where 
the width of each bar is 1, return the area of the largest rectangle in the histogram.

Input: heights = [2,1,5,6,2,3]
Output: 10
Explanation: The above is a histogram where width of each bar is 1.
The largest rectangle is shown in the red area, which has an area = 10 units.

Input: heights = [2,4]
Output: 4

Constraints:

1 <= heights.length <= 10^5
0 <= heights[i] <= 10^4
*/

// TLE: 87/98
class Solution1 {
public:
    int largestRectangleArea(vector<int>& heights) {
        int sz=heights.size();
        if(sz==0) return 0;
        int res=0;
        for(int i=0; i<sz; ++i){
        	int left=i;
        	int curHeight=heights[i];
        	while(left>0&&heights[left-1]>=curHeight){
        		left--;
        	}
        	int right=i;
        	while(right<sz-1&&heights[right+1]>=curHeight){
        		right++;
        	}
        	int width=right-left+1;
        	res=max(res, width*curHeight);
        }
        return res;
    }
};

// -------*******-------

class Solution2 {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int>stk;
        int maxA=0;
        int sz=heights.size();
        for(int i=0; i<=sz; ++i){
            while(!stk.empty()&&(i==sz||heights[stk.top()]>=heights[i])){
                int currHeight=heights[stk.top()];
                stk.pop();
                int width;
                if(stk.empty()) width=i;
                else width=i-stk.top()-1;
                maxA=max(maxA, width*currHeight);
            }
            stk.push(i);
        }
        return maxA;
    }
};

// -------*******-------

class Solution3 {
public:
    int largestRectangleArea(vector<int>& heights) {
        int sz=heights.size();
        int tempHeights[sz+1];
        for(int i=0; i<sz; ++i){
            tempHeights[i]=heights[i];
        }
        /*
        in order to get all the elements in the stack out of the stack, 
        element 0 is added at the end of the stack
        */
        tempHeights[sz]=0;
        int maxx=0, top_=0;
        stack<int>stk;
        for(int i=0; i<=sz; ++i){
            // creating monotonic increasing stack
            if(stk.empty()||tempHeights[stk.top()]<=tempHeights[i]){
                stk.push(i);
            } else{
            	// for the current histogram height find the max possible area
                while(!stk.empty()&&tempHeights[stk.top()]>tempHeights[i]){
                    top_=stk.top();
                    stk.pop();
                    /*
                    i-top_: refers to the width of the current matrix, and
                    tempHeights[top_]: refers to the current height
                    */
                    maxx=max(maxx, (i-top_)*tempHeights[top_]);
                }
                /*
                In particular, we should think about:

                    stack.push(top_);
                    tempHeights[top] = tempHeights[i];

                Note that when the element at the top of the stack is larger than 
                the element to be inserted, the element at the top of the stack needs to be pop(), 
                but the element to be inserted can be expanded to the left

                However, in order to maintain the incremental attribute in the stack and allow 
                i to expand to the left, we simply modified the subscript of i and changed it to the 
                leftmost top subscript. 

                Therefore, when we need to obtain the rectangular area based on him next time, 
                the width will be expanded.
                */
                stk.push(top_);
                tempHeights[top_]=tempHeights[i];
            }
        }
        return maxx;
    }
};


// -------*******-------

class Solution4 {
public:
    int largestRectangleArea(vector<int>& heights) {
        int sz=heights.size();
        stack<int>stk;
        int leftSmaller[sz], rightSmaller[sz];
        for(int i=0; i<sz; ++i){
            while(!stk.empty()&&heights[stk.top()]>=heights[i]){
                stk.pop();
            }
            if(stk.empty()) leftSmaller[i]=0;
            else leftSmaller[i]=stk.top()+1;
            stk.push(i);
        }
        while(!stk.empty()) stk.pop();
        for(int i=sz-1; i>=0; --i){
            while(!stk.empty()&&heights[stk.top()]>=heights[i]){
                stk.pop();
            }
            if(stk.empty()) rightSmaller[i]=sz-1;
            else rightSmaller[i]=stk.top()-1;
            stk.push(i);
        }
        int maxA=0;
        for(int i=0; i<sz; ++i){
            maxA=max(maxA, heights[i]*(rightSmaller[i]-leftSmaller[i]+1));
        }
        return maxA;
    }
};

// -------*******-------

class Solution5 {
public:
    int largestRectangleArea(vector<int>& heights) {
        int sz=heights.size();
        vector<int>tempHeight(sz+1, 0);
        for(int i=0; i<sz; ++i){
            tempHeight[i]=heights[i];
        }
        vector<int>stk(sz+2, 0);
        vector<int>w(sz+2, 0);
        long long maxx=0, p=0;
        for(int i=0; i<=sz; ++i){
            /*
            when the top element of the stack is smaller than the current element,
            it is directly put on the stack
            */
            if(stk[p]<tempHeight[i]){
                stk[++p]=tempHeight[i];
                w[p]=1;
            } else{
                // width value of the current expansion
                long long width=0;
                /*
                when stack top element is larger than the current element, the stack top
                element must not extend to the right
                */
                /*
                Pop to the stack top element is less than or equal to the current element,
                and the area of the stack top element of the monotonic stack is recorded
                in the pop process
                */
                while(stk[p]>tempHeight[i]){
                    width+=w[p];
                    maxx=max(maxx, stk[p]*width);
                    p--;
                    if(p<0) break;
                }
                stk[++p]=tempHeight[i];
                w[p]=width+1;
            }
        }
        return maxx;
    }
};
