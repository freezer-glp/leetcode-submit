/*
Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

For example, this binary tree [1,2,2,3,4,4,3] is symmetric:

    1
   / \
  2   2
 / \ / \
3  4 4  3
But the following [1,2,2,null,3,null,3] is not:
    1
   / \
  2   2
   \   \
   3    3
Note:
Bonus points if you could solve it both recursively and iteratively.
*/
//  recursively
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
    bool isSymmetric(TreeNode* root) {
      if (!root) { return true; }
      return helper(root->left, root->right);
    }
    bool helper(TreeNode* r1, TreeNode* r2) {
      if (!r1 && !r2) { return true; }
      if (!r1 || !r2) { return false; }
      if (r1->val == r2->val) {
        return helper(r1->left, r2->right) && helper(r1->right, r2->left);
      }
      return false;
    }
};

// iteratively
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
      queue<TreeNode*> q;
      q.push(root);
      q.push(root);
      while(!q.empty()) {
        TreeNode* n1 = q.front();
        q.pop();
        TreeNode* n2 = q.front();
        q.pop();
        if (!n1 && !n2) { continue; }
        if (!n1 || !n2) { return false; }
        if (n1->val != n2->val) {return false; }
        q.push(n1->left);
        q.push(n2->right);
        q.push(n1->right);
        q.push(n2->left);
      }
      return true;
    }
};