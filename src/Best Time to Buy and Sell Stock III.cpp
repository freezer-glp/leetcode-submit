/*Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete at most two transactions.

Note:
You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).

Subscribe to see which companies asked this question

Hide Tags Array Dynamic Programming
Hide Similar Problems*/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
       //������չk�ν��׵�dp�벻����Ҳ���������ֻ���û���dp��2�ν��׵���
       //˼·�Ǵ����ң��������󣬷ֱ����һ��dp,��2�ν��ײ�ֳ��������ν��׵�dp
        int len = prices.size();
        if(len == 0)
            return 0;
        vector<int> left;
        vector<int> right;
        
        int minLeft = prices[0];
        int curMax = 0;
        for(int i : prices) {
            curMax = max(curMax, i - minLeft);
            left.push_back(curMax);
            minLeft = min(minLeft, i);
        }
        curMax = 0;
        int maxRight = prices[len - 1];
        for(int i = len - 1; i >= 0; i--) {
            curMax = max(curMax, maxRight - prices[i]);
            right.push_back(curMax);
            maxRight = max(maxRight, prices[i]);
        }
        int res = 0;
        for(int i = 0; i < len; i++) {
            res = max(res, left[i] + right[len - 1 - i]);
        }        
        return res;
    }
};