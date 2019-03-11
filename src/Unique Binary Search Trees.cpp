/*Given n, how many structurally unique BST's (binary search trees) that store values 1...n?

For example,
Given n = 3, there are a total of 5 unique BST's.

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3
Subscribe to see which companies asked this question

Hide Tags Tree Dynamic Programming
Show Similar Problems
*/
class Solution {
public:
    int numTrees(int n) {
        if(n < 0)
            return -1;
        int dp[n + 1];
        dp[0] = dp[1] = 1;
        /*
         n个数， 轮流当根节点。 j 当根节点的时候，1~(j-1)在其左子树，有dp[j-1]种排法； j+1 ~ n 在其右子树，有dp[n - j]种排法
         所以 dp[n] = dp[j] * dp[n - j]
         */
        for(int i = 1; i <= n; i++) {
            int sum = 0;
            for(int j = 1; j <= i; j++ ) {
                sum += dp[j - 1] * dp[i - j];
            }
            dp[i] = sum;
        }
        return dp[n];
    }
};