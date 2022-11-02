/*
Given an integer array instructions, you are asked to create a sorted array from the elements
in instructions.

You start with an empty container nums. For each element from left to right in instructions,
insert it into nums.

The cost of each insertion is the minimum of the following:

    The number of elements currently in nums that are strictly less than instructions[i].
    The number of elements currently in nums that are strictly greater than instructions[i].

For example, if inserting element 3 into nums = [1,2,3,5], the cost of insertion is min(2, 1)
(elements 1 and 2 are less than 3, element 5 is greater than 3) and nums will become [1,2,3,3,5].

Return the total cost to insert all elements from instructions into nums. Since the answer may be large,
return it modulo 10^9 + 7

Example 1:

Input: instructions = [1,5,6,2]
Output: 1
Explanation: Begin with nums = [].
Insert 1 with cost min(0, 0) = 0, now nums = [1].
Insert 5 with cost min(1, 0) = 0, now nums = [1,5].
Insert 6 with cost min(2, 0) = 0, now nums = [1,5,6].
Insert 2 with cost min(1, 2) = 1, now nums = [1,2,5,6].
The total cost is 0 + 0 + 0 + 1 = 1.

Example 2:

Input: instructions = [1,2,3,6,5,4]
Output: 3
Explanation: Begin with nums = [].
Insert 1 with cost min(0, 0) = 0, now nums = [1].
Insert 2 with cost min(1, 0) = 0, now nums = [1,2].
Insert 3 with cost min(2, 0) = 0, now nums = [1,2,3].
Insert 6 with cost min(3, 0) = 0, now nums = [1,2,3,6].
Insert 5 with cost min(3, 1) = 1, now nums = [1,2,3,5,6].
Insert 4 with cost min(3, 2) = 2, now nums = [1,2,3,4,5,6].
The total cost is 0 + 0 + 0 + 0 + 1 + 2 = 3.
*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution1{
    public:
    int createSortedArray(vector<int>&instructions){
        int mod=1e9+7;
        vector<int>ans;
        int fnans=0;
        for(auto &vals: instructions){
            sort(ans.begin(), ans.end());
            auto it1=lower_bound(ans.begin(), ans.end(), vals);
            auto it2=upper_bound(ans.begin(), ans.end(), vals);
            int numsLessThanVals=-1, numGreaterThanVals=-1;
            if(it1!=ans.end()){
                numsLessThanVals=it1-ans.begin();
            }
            if(it2!=ans.end()){
                numGreaterThanVals=ans.size()-(it2-ans.begin());
            }
            if(numsLessThanVals!=-1&&numsLessThanVals!=-1){
                fnans+=min(numsLessThanVals, numGreaterThanVals);
            }
            ans.push_back(vals);
        }
        return fnans%mod;
    }
};

/*
Use Binary Indexed Tree structure bit to store count of elements in instructions array so far.

For each x in instructions:

    left = bit.getSumRange(0, x - 1):

        Get count of all numbers strictly less than x
    
    right = bit.getSumRange(x + 1, largest):

        Get count of all numbers strictly greater than x

    cost = (cost + min(left, right)) % 1_000_000_007
    
    bit.addValue(x, 1): Increase count of number x by one
*/

class BIT{
    vector<int>bit;

    public:
    BIT(int size){
        bit.assign(size+1, 0);
    }

    /*
        Get sum in the range [0...idx], 1 based indexing
    */
    int getSum(int idx){
        int sum=0;
        for(; idx>0; idx-=idx&(-idx)){
            sum+=bit[idx];
        }
        return sum;
    }

    /*
        Get sum in a definite range [left, right] (left and right are inclusive  --> 1-based indexing)
    */
    int getSumRange(int left, int right){
        return getSum(right)-getSum(left-1);
    }

    void addValue(int idx, int val){
        for(; idx<bit.size(); idx+=idx&(-idx)){
            bit[idx]+=val;
        }
    }

};

class Solution2{
    public:
    int createSortedArray(vector<int>&instructions){
        int maxx=*max_element(instructions.begin(), instructions.end()), mod=1e9+7;
        BIT bit(maxx);
        int fnans=0;
        for(auto &vals: instructions){
            int left=bit.getSumRange(0, vals-1);
            int right=bit.getSumRange(vals+1, maxx);
            fnans+=min(left, right);
            fnans%=mod;
            bit.addValue(vals, 1);
        }
        return fnans;
    }
};

int main(){
    Solution1 obj1;
    Solution2 obj2;
    vector<int>instructions{1,2,3,6,5,4};
    vector<int>instructions1{1,2,3,6,5,4};
    vector<int>instructions2{1,5,6,2};
    int ans=obj2.createSortedArray(instructions);
    int ans1=obj1.createSortedArray(instructions1);
    int ans2=obj1.createSortedArray(instructions2);
    cout<<ans<<endl;
    cout<<ans1<<endl;
    cout<<ans2<<endl;
}