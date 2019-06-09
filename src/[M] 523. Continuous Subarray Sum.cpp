/*
Given a list of non-negative numbers and a target integer k, write a function to check if the array has a continuous subarray of size at least 2 that sums up to the multiple of k, that is, sums up to n*k where n is also an integer.

 

Example 1:

Input: [23, 2, 4, 6, 7],  k=6
Output: True
Explanation: Because [2, 4] is a continuous subarray of size 2 and sums up to 6.
*/
class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
      for(int i=1; i<nums.size(); i++){
        nums[i] += nums[i-1];
      }
      // 暴力法超时，这里非常巧妙利用两段和的差，求中间段的和  
        
      for(int i=0; i<nums.size(); i++){
        for(int j=i+1; j<nums.size(); j++){
          int val = (i==0? nums[j] : nums[j]-nums[i-1]);
          if((k==0 && val==0) || (k!=0 && val%k==0)) return true;
        }
      }
      return false;
    }
};
