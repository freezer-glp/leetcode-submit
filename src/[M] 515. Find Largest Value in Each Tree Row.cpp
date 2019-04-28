/*
You need to find the largest value in each row of a binary tree.

Example:
Input: 

          1
         / \
        3   2
       / \   \  
      5   3   9 

Output: [1, 3, 9]
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
    vector<int> largestValues(TreeNode* root) {
      vector<int> res;
      if (!root) return res;
      queue<TreeNode*> q;
      q.push(root);
      while(!q.empty()) {
        int max = q.front()->val;
        int n = q.size();
        while (n > 0) {
          TreeNode* f = q.front();
          q.pop();
          n--;
          max = std::max(max, f->val);
          if (f->left) q.push(f->left);
          if (f->right) q.push(f->right);
        }
        res.push_back(max);
      }
      return res;
    }
};