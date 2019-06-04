/*
Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete as many transactions as you like (ie, buy one and sell one share of the stock multiple times) with the following restrictions:

You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
After you sell your stock, you cannot buy stock on next day. (ie, cooldown 1 day)
Example:

Input: [1,2,3,0,2]
Output: 3 
Explanation: transactions = [buy, sell, cooldown, buy, sell]
*/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
      int n = prices.size();
      if (!n) return 0;
      // n, 1 - n-1
      // 0, 当天不持有
      // 1, 当天持有股票
      // 2, 当天冷却
      int dp[n][3];
      dp[0][0] = 0;
      dp[0][1] = -prices[0]; // 买入后，利润是下降的
      dp[0][2] = 0;
      for (int i = 1; i < n; ++i) {
        // 不持有，max(昨天也不持有，昨天是冷却)
        dp[i][0] = max(dp[i-1][0], dp[i-1][2]);
        // 持有，max(昨天也持有今天不卖，昨天不持有今天买入)
        dp[i][1] = max(dp[i-1][1], dp[i-1][0]-prices[i]);
        // 冷却，昨天刚好卖出
        dp[i][2] = dp[i-1][1]+prices[i];
      } 
      
      // 最后一天为不持有或者冷冻期，利润最大
      return max(dp[n-1][0], dp[n-1][2]);      
    }
};