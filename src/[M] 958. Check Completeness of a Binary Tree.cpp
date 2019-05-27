/*
Given a binary tree, determine if it is a complete binary tree.
Definition of a complete binary tree from Wikipedia:
In a complete binary tree every level, except possibly the last, is completely filled, and all nodes in the last level are as far left as possible. It can have between 1 and 2h nodes inclusive at the last level h.

Example 1:
Input: [1,2,3,4,5,6]
Output: true
Explanation: Every level before the last is full (ie. levels with node-values {1} and {2, 3}), and all nodes in the last level ({4, 5, 6}) are as far left as possible.
Example 2:

Input: [1,2,3,4,5,null,7]
Output: false
Explanation: The node with value 7 isn't as far left as possible.
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
    bool isCompleteTree(TreeNode* root) {
      if (!root) return false;
      int height =  helper(root);
      // cout <<"height:"<<height<<endl;
      queue<TreeNode*> q;
      q.push(root);
      int level = 1;
      std::vector<TreeNode*> leaf;
      
      while(!q.empty()) {
        int need = 1 << (level-1);
        if (level < height) {
          if (q.size() != need) return false;
        } 
        int len = q.size();
        while (len--) {
          if (level < height-1) {
            if(!q.front()->left || !q.front()->right) return false;
            q.push(q.front()->left);
            q.push(q.front()->right);
            q.pop();
          } else if (level == height - 1){
            q.push(q.front()->left);
            q.push(q.front()->right);
            q.pop();
          } else if (level == height) {
            leaf.push_back(q.front());
            q.pop();
          }
        }
        if (level == height) {
          bool flag = false;
          for (int i = 0; i < leaf.size(); ++i) {
            if (!leaf[i]) {
              flag = true;
            }
            if (flag && leaf[i]) {
              return false;
            }
          }
          return true;
        }
        level ++;
      }
      return false;
    } 
    
    int helper(TreeNode* root) {
      if (!root) return 0;
      if (!root->left && !root->right) {
        return 1;
      }
      
      int l = helper(root->left), r = helper(root->right);
      return l > r? l + 1: r + 1;
    }
};