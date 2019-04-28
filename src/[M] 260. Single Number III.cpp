/*
Given an array of numbers nums, in which exactly two elements appear only once and all the other elements appear exactly twice. Find the two elements that appear only once.

Example:

Input:  [1,2,1,3,2,5]
Output: [3,5]
*/
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
      vector<int> res;
      if (nums.empty()) return res;
      int a = nums[0];
      for (int i = 1; i < nums.size(); i++) {
        a ^= nums[i];
      }
      int b = 1;
      while ((a & b) == 0) {
        b <<= 1;
      }
      vector<int> v1;
      vector<int> v2;
      for (auto num: nums) {
        if (num & b) {
          v1.push_back(num);
        } else {
          v2.push_back(num);
        }
      }
      int c = v1[0];
      for (int i = 1; i < v1.size(); i++) {
        c ^= v1[i];
      }
      res.push_back(c);
      
      c = v2[0];
      for (int i = 1; i < v2.size(); i++) {
        c ^= v2[i];
      }
      res.push_back(c);
      return res;
    }
};