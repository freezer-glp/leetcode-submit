/*
Given a set of distinct positive integers, find the largest subset such that every pair (Si, Sj) of elements in this subset satisfies:

Si % Sj = 0 or Sj % Si = 0.

If there are multiple solutions, return any subset is fine.

Example 1:

Input: [1,2,3]
Output: [1,2] (of course, [1,3] will also be ok)
Example 2:

Input: [1,2,4,8]
Output: [1,2,4,8]
*/
class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
      vector<int> res;
      int n = nums.size();
      if (!n) return res;
      int dp[n];
      for (int i = 0; i < n; ++i) {
        dp[i] = 1;
      }
      int pre[n];
      for (int i = 0; i < n; ++i) {
        pre[i] = -1;
      }
      int max = 0;
      int max_idx = 0;
      // 顺序错乱，不方便判断，如果有序，则<==>后面的数一定可以整除前面的数
      sort(nums.begin(), nums.end());
      for (int i = 1; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
          if (nums[i] % nums[j] == 0) {
            if (dp[j] + 1 > dp[i]) {
              dp[i] = dp[j] + 1;
              // cout<<"dp["<<i<<"]:"<<dp[i]<<endl;
              if (dp[i] > max) {
                max = dp[i];
                max_idx = i;
                // cout <<"max_idx:"<<max_idx<<endl;
              }
              pre[i] = j;
            }
          }
        }
      }
      int mp = max_idx;
      while(mp != -1) {
        res.push_back(nums[mp]);
        mp = pre[mp];
      }
      
      return res;
    }
};