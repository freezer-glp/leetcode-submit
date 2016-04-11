/*Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete as many transactions as you like (ie, buy one and sell one share of the stock multiple times). However, you may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).

Subscribe to see which companies asked this question

Hide Tags Array Greedy
Show Similar Problems
*/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int low, high, sum = 0;
        int len = prices.size();
        if(len == 0)
            return 0;
        for(int i = 0; i < len; i++) {
            while(i + 1 < len && prices[i + 1] < prices[i])//find the lower one
                i++;
            if(i == len - 1)
                return sum;
            low = prices[i];
            while(i + 1 < len && prices[i + 1] > prices[i]) //find the higher one
                i++;
            high = prices[i];
            sum += (high - low);
        }
        return sum;
    }
};