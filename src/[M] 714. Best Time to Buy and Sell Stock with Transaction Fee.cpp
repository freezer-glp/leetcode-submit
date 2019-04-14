/*
Your are given an array of integers prices, for which the i-th element is the price of a given stock on day i; and a non-negative integer fee representing a transaction fee.

You may complete as many transactions as you like, but you need to pay the transaction fee for each transaction. You may not buy more than 1 share of a stock at a time (ie. you must sell the stock share before you buy again.)

Return the maximum profit you can make.

Example 1:
Input: prices = [1, 3, 2, 8, 4, 9], fee = 2
Output: 8
Explanation: The maximum profit can be achieved by:
Buying at prices[0] = 1
Selling at prices[3] = 8
Buying at prices[4] = 4
Selling at prices[5] = 9
The total profit is ((8 - 1) - 2) + ((9 - 4) - 2) = 8.
*/

class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
      int n = prices.size();
      if (!n) return 0;
      // 0持有
      // 1不持有
      int dp[n][2];
      dp[0][0] = -prices[0];
      dp[0][1] = 0;
      for (int i = 1; i < n; ++i) {
        // 不持有， 前一天持有，今天卖了； 前一天也不持有
        dp[i][1] = max(dp[i-1][0]+prices[i]-fee, dp[i-1][1]);
        // 持有， 前一天不持有，今天买；前一天持有，今天不变
        dp[i][0] = max(dp[i-1][1]-prices[i], dp[i-1][0]);
      }
      return dp[n-1][1];
    }
};