/*
Given a binary tree, find the length of the longest path where each node in the path has the same value. This path may or may not pass through the root.
The length of path between two nodes is represented by the number of edges between them.
Example 1:
Input:

              5
             / \
            4   5
           / \   \
          1   1   5
Output: 2
Example 2:
Input:

              1
             / \
            4   5
           / \   \
          4   4   5
Output: 2
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
    int max = 0;
    int longestUnivaluePath(TreeNode* root) {
      if (!root) return 0;
      helper(root, root->val);
      return max;
    }
    
    int helper(TreeNode* root, int father_val) {
      if (!root) return 0;
      int l = helper(root->left, root->val);
      int r = helper(root->right, root->val);
      if ((l+r)>max) max = l+r;
      if(root->val == father_val) {
        return std::max(l, r) + 1;
      }
      return 0;
    }
};