/*
Given an array nums of distinct integers, return all the possible permutations. 
You can return the answer in any order.

Example 1:

Input: nums = [1,2,3]
Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]

Example 2:

Input: nums = [0,1]
Output: [[0,1],[1,0]]

Example 3:

Input: nums = [1]
Output: [[1]]

public List<List<Integer>> permute(int[] nums) {
   List<List<Integer>> list = new ArrayList<>();
   // Arrays.sort(nums); // not necessary
   backtrack(list, new ArrayList<>(), nums);
   return list;
}

private void backtrack(List<List<Integer>> list, List<Integer> tempList, int [] nums){
   if(tempList.size() == nums.length){
      list.add(new ArrayList<>(tempList));
   } else{
      for(int i = 0; i < nums.length; i++){ 
         if(tempList.contains(nums[i])) continue; // element already exists, skip
         tempList.add(nums[i]);
         backtrack(list, tempList, nums);
         tempList.remove(tempList.size() - 1);
      }
   }
} 
*/

#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

void backtrack(vector<int>&nums, vector<vector<int>>&res, vector<int>&tmpList){
	if(tmpList.size()==nums.size()){
		res.push_back(tmpList);
	} else{
		for(int i=0; i<nums.size(); ++i){
			auto it=find(tmpList.begin(), tmpList.end(), nums[i]);
			if(it!=tmpList.end()) continue;
			tmpList.push_back(nums[i]);
			backtrack(nums, res, tmpList);
			tmpList.pop_back();
		}
	}
}

int main(){
	vector<int>nums{1, 2, 3};
	vector<vector<int>>res;
	vector<int>tmpList;
	backtrack(nums, res, tmpList);
	for(auto &vals: res){
		for(auto &nums: vals){
			cout<<nums<<" ";
		}
		cout<<endl;
	}
}