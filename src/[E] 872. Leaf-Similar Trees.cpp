/*
Consider all the leaves of a binary tree.  From left to right order, the values of those leaves form a leaf value sequence.



For example, in the given tree above, the leaf value sequence is (6, 7, 4, 9, 8).

Two binary trees are considered leaf-similar if their leaf value sequence is the same.

Return true if and only if the two given trees with head nodes root1 and root2 are leaf-similar.


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
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
      if (!root1 || !root2) return false;
      std::vector<int> r1l, r2l;
      BuildLeaf(root1, r1l);
      BuildLeaf(root2, r2l);
      return CheckSimilar(r1l, r2l);
    }
    
    void BuildLeaf(TreeNode* root, vector<int>& v) {
      if (!root) return;
      if (!root->left && !root->right) v.push_back(root->val);
      if (root->left) BuildLeaf(root->left, v);
      if (root->right) BuildLeaf(root->right, v);
    }
    
    bool CheckSimilar(vector<int>& v1, vector<int>& v2) {
      if (v1.size() != v2.size()) return false;
      for (int i = 0; i < v1.size(); ++i) {
        if (v1[i] != v2[i]) return false;
      }
      return true;
    }
    
};