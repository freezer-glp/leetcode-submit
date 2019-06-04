/*
Given an integer array with all positive numbers and no duplicates, find the number of possible combinations that add up to a positive integer target.

Example:

nums = [1, 2, 3]
target = 4

The possible combination ways are:
(1, 1, 1, 1)
(1, 1, 2)
(1, 2, 1)
(1, 3)
(2, 1, 1)
(2, 2)
(3, 1)

Note that different sequences are counted as different combinations.

Therefore the output is 7.
*/
// 下面这个记录中间结果的居然也超时。。
class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        int n = nums.size();
        if (!n || target <= 0) return 0;
        sort(nums.begin(), nums.end());
        int dp[target+1];
        for (int i = 0; i < target+1; ++i)
            dp[i] = 0;
        //dp[0] = 1;
        helper(nums, target, dp);
        return dp[target];
    }
    int helper(vector<int>& nums, int target, int* dp) {
        if (target == 0) {
            return 1;
        }
        if (dp[target] != 0) return dp[target];
        
        //dp[target] = 0;
        int sum = 0;
        for (int j = 0; j < nums.size(); ++j) {
            if (nums[j] > target) break;
            sum += helper(nums, target-nums[j], dp);
        }
        dp[target] = sum;
        return dp[target];
    }
};

// 完全的迭代版动态规划
class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
      int n = nums.size();
      if (!n || target <= 0) return 0;
      sort(nums.begin(), nums.end());
      unsigned long long dp[target+1];
      for (int i = 0; i < target+1; ++i) {
        dp[i] = 0;
      }
      dp[0] = 1;
      for (int i = 0; i < target; ++i) {
        for (int num: nums) {
          if (i + num <= target) {
            dp[i+num] += dp[i];
            //cout <<"dp["<<i<<"+"<<num<<"="<<i+num<<"]:"<<dp[i+num]<<endl;
          }
        }
      }
      return dp[target];
    }
};