/*
Given the root of a binary tree, find the maximum value V for which there exists different nodes A and B where V = |A.val - B.val| and A is an ancestor of B.

(A node A is an ancestor of B if either: any child of A is equal to B, or any child of A is an ancestor of B.)

Example 1:
Input: [8,3,10,1,6,null,14,null,null,4,7,13]
Output: 7
Explanation: 
We have various ancestor-node differences, some of which are given below :
|8 - 3| = 5
|3 - 7| = 4
|8 - 1| = 7
|10 - 13| = 3
Among all possible differences, the maximum value of 7 is obtained by |8 - 1| = 7.
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
    int maxAncestorDiff(TreeNode* root) {
      if (!root) return 0;
      int max = 0;
      int min = 0;
      int res = -1;
      helper(root, max, min, res);
      // cout <<"max:"<<max<<" min:"<<min<<endl;
      return res;
    }
  
    void helper(TreeNode* root, int& max, int& min, int& res) {
      if (!root->left && !root->right) {
        max = 0;
        min = 0;
        return;
      }
      int lmax = 0, lmin = 0;
      int rmax = 0, rmin = 0;
      int lsub = 0, rsub = 0;
      if (root->left) {
        helper(root->left, lmax, lmin, res);
        lsub = root->val - root->left->val;
      }
      
      if (root->right) {
        helper(root->right, rmax, rmin, res);
        rsub = root->val - root->right->val;
      }
      max = std::max(lsub+lmax, rsub+rmax);
      min = std::min(lsub+lmin, rsub+rmin);
      res = std::max(
        std::max(res,std::max(abs(max), abs(min))),
        std::max(abs(lsub), abs(rsub))
      );
      return;
    }
};