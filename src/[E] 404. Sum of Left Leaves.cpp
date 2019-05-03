/*
Find the sum of all left leaves in a given binary tree.

Example:

    3
   / \
  9  20
    /  \
   15   7

There are two left leaves in the binary tree, with values 9 and 15 respectively. Return 24.
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
class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
      int sum = 0;
      helper(root, false, sum);
      return sum;
    }
    void helper(TreeNode* root, bool is_left, int& sum) {
      if (!root) return;
      if (!root->left && !root->right && is_left) {
        sum += root->val;
      }
      helper(root->left, true, sum);
      helper(root->right, false, sum);
    }
};