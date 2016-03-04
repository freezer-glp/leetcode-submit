/*Say you have an array for which the ith element is the price of a given stock on day i.

If you were only permitted to complete at most one transaction (ie, buy one and sell one share of the stock), design an algorithm to find the maximum profit.

Subscribe to see which companies asked this question

Hide Tags Array Dynamic Programming
Show Similar Problems
*/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int len = prices.size();
        if(len == 0) return 0;
        int min = prices[0];
        int max = 0;
        for(int i : prices) {
            if(i < min)
                min = i;
            if(i - min > max)
                max = i - min;
        }
        return max;
        
    }
};
//暴力法超时
// class Solution {
// public:
//     int maxProfit(vector<int>& prices) {
//         int len = prices.size();
//         if(len == 0) return 0;
//         vector<int> best(len);
//         for(int i = 0; i <= len - 1; i++) {
//             int max = 0;
//             for(int j = i + 1; j <= len - 1; j++) {
//                 if(prices[j] - prices[i] > max)
//                     max = prices[j] - prices[i];
//             } 
//             best[i] = max;
//         }
//         int ans = 0;
//         for(int i : best)
//             if(i > ans)
//                 ans = i;
        
//         return ans;
//     }
// };