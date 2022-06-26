// 295. Find Median from Data Stream
/*
The median is the middle value in an ordered integer list. 

If the size of the list is even, there is no middle value and the median 
is the mean of the two middle values.

For example, for arr = [2,3,4], the median is 3.
For example, for arr = [2,3], the median is (2 + 3) / 2 = 2.5.
Implement the MedianFinder class:

MedianFinder() initializes the MedianFinder object.
void addNum(int num) adds the integer num from the data stream to the data structure.
double findMedian() returns the median of all elements so far. 

Answers within 10^-5 of the actual answer will be accepted.

Example 1:

Input
["MedianFinder", "addNum", "addNum", "findMedian", "addNum", "findMedian"]
[[], [1], [2], [], [3], []]
Output
[null, null, null, 1.5, null, 2.0]

Explanation
MedianFinder medianFinder = new MedianFinder();
medianFinder.addNum(1);    // arr = [1]
medianFinder.addNum(2);    // arr = [1, 2]
medianFinder.findMedian(); // return 1.5 (i.e., (1 + 2) / 2)
medianFinder.addNum(3);    // arr[1, 2, 3]
medianFinder.findMedian(); // return 2.0
 

Constraints:

-10^5 <= num <= 10^5
There will be at least one element in the data structure before calling findMedian.
At most 5 * 10^4 calls will be made to addNum and findMedian.
 

Follow up:

If all integer numbers from the stream are in the range [0, 100], how would you optimize your solution?
If 99% of all integer numbers from the stream are in the range [0, 100], how would you optimize your solution?
*/

/*
TLE: 17 / 21

class MedianFinder {
public:
    
    multiset<int>lst;
    int sz=0;
    
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        lst.insert(num);
        sz=lst.size();
    }
    
    double findMedian() {
        double ans=0;
        if(sz%2==0){
            int fst=sz/2, sec=fst-1;
            auto it1=lst.begin(), it2=lst.begin();
            advance(it1, fst);
            advance(it2, sec);
            int one=*it1, two=*it2;
            ans=(double)(one+two)/2;
        } else{
            auto it=lst.begin();
            advance(it, sz/2);
            ans=(double)*it;
        }
        return ans;
    }
};
*/


class MedianFinder {
public:
    
    priority_queue<int, vector<int>>pq1;
    priority_queue<int, vector<int>, greater<>>pq2;
    
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        pq1.push(num);
        int temp=pq1.top();
        pq1.pop();
        pq2.push(temp);
        if(pq1.size()<pq2.size()){
            int curr=pq2.top();
            pq2.pop();
            pq1.push(curr);
        }
    }
    
    double findMedian() {
        return pq1.size()==pq2.size()?(double)(pq1.top()+pq2.top())/2:pq1.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */