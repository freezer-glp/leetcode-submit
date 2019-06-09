/*
Given an array of scores that are non-negative integers. Player 1 picks one of the numbers from either end of the array followed by the player 2 and then player 1 and so on. Each time a player picks a number, that number will not be available for the next player. This continues until all the scores have been chosen. The player with the maximum score wins.

Given an array of scores, predict whether player 1 is the winner. You can assume each player plays to maximize his score.

Example 1:
Input: [1, 5, 2]
Output: False
Explanation: Initially, player 1 can choose between 1 and 2. 
If he chooses 2 (or 1), then player 2 can choose from 1 (or 2) and 5. If player 2 chooses 5, then player 1 will be left with 1 (or 2). 
So, final score of player 1 is 1 + 2 = 3, and player 2 is 5. 
Hence, player 1 will never be the winner and you need to return False.
Example 2:
Input: [1, 5, 233, 7]
Output: True
Explanation: Player 1 first chooses 1. Then player 2 have to choose between 5 and 7. No matter which number player 2 choose, player 1 can choose 233.
Finally, player 1 has more score (234) than player 2 (12), so you need to return True representing player1 can win.

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/predict-the-winner
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
      if (nums.empty()) return true;
      int len = nums.size();
      int dp[len][len];
      int sum = 0;
      for (int i = 0; i < len; ++i) {
        sum += nums[i];
        dp[i][i] = nums[i];
        for (int j = i + 1; j < len; ++j) {
          dp[i][j] = 0;
        }
      }
      
      for (int l = 1; l < len; ++l) {
        for (int i = 0; i < len - l; ++i) {
          int j = l + i;
          if (l == 1) 
            dp[i][j] = std::max(nums[i], nums[j]);
          else {
            // 选手2同样需要取最大值，所以这里取min
            dp[i][j] = std::max(
                nums[i] + std::min(dp[i+2][j], dp[i+1][j-1]),
                nums[j] + std::min(dp[i][j-2], dp[i+1][j-1]) 
            );
          }
        }
      }
      return dp[0][len-1] >= sum - dp[0][len-1];
    }
};