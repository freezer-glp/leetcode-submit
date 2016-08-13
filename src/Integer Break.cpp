/*Given a positive integer n, break it into the sum of at least two positive integers and maximize the product of those integers. Return the maximum product you can get.

For example, given n = 2, return 1 (2 = 1 + 1); given n = 10, return 36 (10 = 3 + 3 + 4).

Note: You may assume that n is not less than 2 and not larger than 58.

Hint:

There is a simple O(n) solution to this problem.
You may check the breaking results of n ranging from 7 to 10 to discover the regularities.
Credits:
Special thanks to @jianchao.li.fighter for adding this problem and creating all test cases.

Subscribe to see which companies asked this question

Hide Tags Dynamic Programming Math
*/
class Solution {
public:
    int integerBreak(int n) {
        int dp[n + 1];
        for(int i = 0; i <= n; i++) {
            dp[i] = 1;
        }
        //dp[2] = 1是肯定的
        for(int i = 3; i <= n; i++) {
            for(int j = 1; j < i; j++) {
                // 因为可以切割成多个数，所以可以取一个分割线
                // 左半部分和右半部分依旧可以动态规划
                dp[i] = max(dp[i], max(j, dp[j]) * max(i - j, dp[i - j]));
            }
        }
        return dp[n];
    }
};