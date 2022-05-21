// 2276. Count Integers in Intervals
/*
Given an empty set of intervals, implement a data structure that can:

Add an interval to the set of intervals.
Count the number of integers that are present in at least one interval.
Implement the CountIntervals class:

CountIntervals() Initializes the object with an empty set of intervals.
void add(int left, int right) Adds the interval [left, right] to the set of intervals.
int count() Returns the number of integers that are present in at least one interval.
Note that an interval [left, right] denotes all the integers x where left <= x <= right.

Example 1:

Input
["CountIntervals", "add", "add", "count", "add", "count"]
[[], [2, 3], [7, 10], [], [5, 8], []]
Output
[null, null, null, 6, null, 8]

Explanation
CountIntervals countIntervals = new CountIntervals(); // initialize the object with an empty set of intervals. 
countIntervals.add(2, 3);  // add [2, 3] to the set of intervals.
countIntervals.add(7, 10); // add [7, 10] to the set of intervals.
countIntervals.count();    // return 6
                           // the integers 2 and 3 are present in the interval [2, 3].
                           // the integers 7, 8, 9, and 10 are present in the interval [7, 10].
countIntervals.add(5, 8);  // add [5, 8] to the set of intervals.
countIntervals.count();    // return 8
                           // the integers 2 and 3 are present in the interval [2, 3].
                           // the integers 5 and 6 are present in the interval [5, 8].
                           // the integers 7 and 8 are present in the intervals [5, 8] and [7, 10].
                           // the integers 9 and 10 are present in the interval [7, 10].

Constraints:

1 <= left <= right <= 10^9
At most 10^5 calls in total will be made to add and count.
At least one call will be made to count
*/

/*
TLE: 68 / 72

class CountIntervals {
public:
    
    set<pair<int, int>>intervals;
    int curcount=0;
    int cursize=0;
    int prevsize=0;
    
    CountIntervals() {
        
    }
    
    void add(int left, int right) {
        intervals.insert({left, right});
        cursize=intervals.size();
    }
    
    int count() {
        pair<int, int>prev{0, 0};
        int count_=0;
        if(cursize==prevsize) return curcount;
        for(auto &entries: intervals){
            pair<int, int>vals={entries.first, entries.second};
            if(vals.second<=prev.second) continue;
            if(vals.first>prev.second){
                count_+=(vals.second-vals.first)+1;
                prev=vals;
            } else{
                vals.first=prev.second+1;
                count_+=(vals.second-vals.first)+1;
                prev=vals;
            }
        }
        prevsize=cursize;
        curcount=count_;
        return count_;
    }
};
*/

class CountIntervals {
public:
    
    set<pair<int, int>>st;
    int cnt;
    
    CountIntervals() {
        cnt=0;
    }
    
    void add(int left, int right) {
        auto it=st.upper_bound({left, INT_MIN});
        if(it!=st.begin()&&(--it)->second<left) ++it;
        while(it!=st.end()&&it->first<=right){
            left=min(left, it->first);
            right=max(right, it->second);
            cnt-=(it->second-it->first+1);
            it=st.erase(it);
        }
        st.insert({left, right});
        cnt+=(right-left+1);
    }
    
    int count() {
        return cnt;
    }
};

/**
 * Your CountIntervals object will be instantiated and called as such:
 * CountIntervals* obj = new CountIntervals();
 * obj->add(left,right);
 * int param_2 = obj->count();
 */

// -------*******-------

class CountIntervals2 {
    private:
    TreeNode *root=nullptr;
    
    public:
    CountIntervals() {
        root=new TreeNode();    
    }
    
    int add(TreeNode *node, int begin, int end, int left, int right){
        if(left>end||right<begin){
            return node->val;
        }
        if(end-begin+1==node->val){
            return node->val;
        }
        if(begin==left&&end==right){
            return node->val=end-begin+1;
        }
        int mid=begin+(end-begin)/2;
        if(node->left==nullptr){
            node->left=new TreeNode();
        }
        if(node->right==nullptr){
            node->right=new TreeNode();
        }
        int cnt=0;
        cnt+=add(node->left, begin, mid, max(begin, left), min(mid, right));
        cnt+=add(node->right, mid+1, end, max(mid+1, left), min(end, right));
        return node->val=cnt;
    }
    
    void add(int left, int right) {
        add(root, 1, (int)(1e9+1), left, right);
    }
    
    int count() {
        return root->val;
    }
};
