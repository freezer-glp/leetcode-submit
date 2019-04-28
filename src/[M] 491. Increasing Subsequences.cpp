/*
Given an integer array, your task is to find all the different possible increasing subsequences of the given array, and the length of an increasing subsequence should be at least 2 .

Example:
Input: [4, 6, 7, 7]
Output: [[4, 6], [4, 7], [4, 6, 7], [4, 6, 7, 7], [6, 7], [6, 7, 7], [7,7], [4,7,7]]
Note:
The length of the given array will not exceed 15.
The range of integer in the given array is [-100,100].
The given array may contain duplicates, and two equal integers should also be considered as a special case of increasing sequence.
*/

class Solution {
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
      int n = nums.size();
      vector<vector<int>> res;
      // if (!n) return res;
      //sort(nums.begin(), nums.end());
      bt(nums, res, 0, vector<int>());
      return res;
    }
    
    void bt(vector<int>& nums, vector<vector<int>>& res, int idx, vector<int> cur_res) {
      // cout <<"idx:"<<idx<<" size:"<<cur_res.size()<<endl;
      if (cur_res.size() > 1) {
        res.push_back(cur_res);
      }
      unordered_map<int, int> hash;
      for (int i = idx; i < nums.size(); ++i) {
        if (hash.find(nums[i]) != hash.end()) {
          continue;
        }
        if (cur_res.empty() || cur_res.back() <= nums[i]) {
          cur_res.push_back(nums[i]);
          bt(nums, res, i+1, cur_res);
          cur_res.pop_back();
        }
        hash[nums[i]] = 1;
      }
    }
};