/*
Given a non-empty binary tree, find the maximum path sum.

For this problem, a path is defined as any sequence of nodes from some starting node to any node in the tree along the parent-child connections. The path must contain at least one node and does not need to go through the root.

Example 1:

Input: [1,2,3]

       1
      / \
     2   3

Output: 6
Example 2:

Input: [-10,9,20,null,null,15,7]

   -10
   / \
  9  20
    /  \
   15   7

Output: 42
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
    int max = INT_MIN;
    int maxPathSum(TreeNode* root) {
      int res = helper(root);
      return std::max(max, res);
    }
    int helper(TreeNode* root) {
      if (!root) return 0;
      if (!root->left && !root->right) { 
        max = root->val > max? root->val: max;
        return root->val;
      }
      
      int lm = helper(root->left);
      if (lm < 0) lm = 0;
      int rm = helper(root->right);
      if (rm < 0) rm = 0;
      int tmp = root->val + lm + rm;
      if (tmp > max) 
        max = tmp;
      return lm > rm? 
        lm>0?lm + root->val:root->val: 
        rm>0?rm + root->val:root->val;
    }
    
  
};