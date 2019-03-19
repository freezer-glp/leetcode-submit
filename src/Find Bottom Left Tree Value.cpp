/*
Given a binary tree, find the leftmost value in the last row of the tree.

Example 1:
Input:

    2
   / \
  1   3

Output:
1
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
    int findBottomLeftValue(TreeNode* root) {
      queue<TreeNode*> q;
      if (!root) return 0;
      q.push(root);
      int last = 0;
      while (!q.empty()) {
        TreeNode* tmp = q.front();
        q.pop();
        if (tmp->right) {
          q.push(tmp->right);
        }
        if (tmp->left) {
          q.push(tmp->left);
        }
        last = tmp->val;
      }
      return last;
    }
};
