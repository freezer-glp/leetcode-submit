/*
The thief has found himself a new place for his thievery again. There is only one entrance to this area, called the "root." Besides the root, each house has one and only one parent house. After a tour, the smart thief realized that "all houses in this place forms a binary tree". It will automatically contact the police if two directly-linked houses were broken into on the same night.

Determine the maximum amount of money the thief can rob tonight without alerting the police.

Example 1:

Input: [3,2,3,null,3,null,1]

     3
    / \
   2   3
    \   \ 
     3   1

Output: 7 
Explanation: Maximum amount of money the thief can rob = 3 + 3 + 1 = 7.
Example 2:

Input: [3,4,5,1,3,null,1]

     3
    / \
   4   5
  / \   \ 
 1   3   1

Output: 9
Explanation: Maximum amount of money the thief can rob = 4 + 5 = 9.
*/
class Solution {
public:
    int rob(TreeNode* root) {
      if (root == nullptr) {
        return 0;
      }
      return std::max(rob(root, true), rob(root, false));
    }
    int rob(TreeNode* root, bool rob_root) {
      if (!root) return 0;
      if (rob_root) {
        int l0 = 0;
        int r0 = 0;
        if (root->left) {
          l0 = find_map(root->left, false);
        }
        if (root->right) {
          r0 = find_map(root->right, false);
        }
        
        return root->val + l0 + r0;
      } else {
        int l0 = 0;
        int l1 = 0;
        int r0 = 0;
        int r1 = 0;
        
        if (root->left) {
          l0 = find_map(root->left, false);
          l1 = find_map(root->left, true);
        }
        if (root->right) {
          r0 = find_map(root->right, false);
          r1 = find_map(root->right, true);
        }
        return std::max(l0+r0, 
                   std::max(l0+r1,
                       std::max(l1+r0, l1+r1)));
      }
    }
    int find_map(TreeNode* root, bool b) {
      unordered_map<TreeNode*, int>& m = b? m_true: m_false;
      auto it = m.find(root);
      if (it != m.end()) {
        return it->second;
      } else {
        int res = b? rob(root, true): rob(root, false);
        m[root] = res;
        return res;
      }
    }
    unordered_map<TreeNode*, int> m_true;
    unordered_map<TreeNode*, int> m_false;
};