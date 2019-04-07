/*
Given an integer n, generate all structurally unique BST's (binary search trees) that store values 1 ... n.

Example:

Input: 3
Output:
[
  [1,null,3,2],
  [3,2,null,1],
  [3,1,null,null,2],
  [2,1,3],
  [1,null,2,null,3]
]
Explanation:
The above output corresponds to the 5 unique BST's shown below:

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3
*/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
static int _ = []
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();
class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
      vector<TreeNode*> res;
      if (!n) { return res; }
      helper(1, n);
      return dp[1][n];
    }
    void helper(int start, int end) {
      if (dp[start][end].size() != 0) {
        return ;
      }
      if (start > end) {
        dp[start][end].push_back(nullptr);
        return;
      }
      for (int i = start; i <= end; ++i) {
        helper(start, i - 1);
        helper(i + 1, end);
        for (auto l : dp[start][i - 1]) {
          for (auto r : dp[i+1][end]) {
            TreeNode* root = new TreeNode(i);
            root->left = l;
            root->right = r;
            dp[start][end].push_back(root);
          }
        }
      }
      return;
    }
    vector<TreeNode*> dp[100+1][100+1];
};