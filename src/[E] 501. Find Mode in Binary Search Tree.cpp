/*
Given a binary search tree (BST) with duplicates, find all the mode(s) (the most frequently occurred element) in the given BST.

Assume a BST is defined as follows:

The left subtree of a node contains only nodes with keys less than or equal to the node's key.
The right subtree of a node contains only nodes with keys greater than or equal to the node's key.
Both the left and right subtrees must also be binary search trees.
 

For example:
Given BST [1,null,2,2],

   1
    \
     2
    /
   2
 

return [2].
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
    vector<int> findMode(TreeNode* root) {
      vector<int> res;
      if (!root) return res;
      int max = 0;
      int cur = 1;
      TreeNode* pre = nullptr;
      helper(root, pre, cur, max, res);
      return res;
    }
    void helper(TreeNode* root, TreeNode*& pre, int& cur, int& max, 
                vector<int>& res) {
      if (!root) return;
      helper(root->left, pre, cur, max, res);
      if (pre) {
        if (root->val == pre->val) {
          cur += 1;
        } else { cur = 1; }
      }
      
      if (cur == max) {
        res.push_back(root->val);
      } else if (cur > max) {
        res.clear();
        res.push_back(root->val);
        max = cur;
      }
      pre = root;
      helper(root->right, pre, cur, max, res);
    }
};