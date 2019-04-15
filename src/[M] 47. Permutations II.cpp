/*
Given a collection of numbers that might contain duplicates, return all possible unique permutations.

Example:

Input: [1,1,2]
Output:
[
  [1,1,2],
  [1,2,1],
  [2,1,1]
]
*/
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
      int n = nums.size();
      vector<vector<int>> res;
      if (!n) return res;
      std::sort(nums.begin(), nums.end());
      perm(nums, 0, n-1, res);
      return res;
    }
   
    void perm(vector<int>& nums, int l, int r, vector<vector<int>>& res) {
      if (l == r) {
        res.push_back(nums);
        return;
      }
      
      for (int i = l; i <= r; ++i) {
        if (IsUsed(nums, i, l)) continue;
        swap(nums[l], nums[i]);
        perm(nums, l+1, r, res);
        swap(nums[l], nums[i]);
      }
    }
  
    bool IsUsed(vector<int>& nums, int i, int l) {
      for(int j = l; j < i; ++j) {
        if (nums[j] == nums[i])
            return true;
      }
      return false;
    }
};