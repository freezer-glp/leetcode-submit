/*
A full binary tree is a binary tree where each node has exactly 0 or 2 children.
Return a list of all possible full binary trees with N nodes.  Each element of the answer is the root node of one possible tree.
Each node of each tree in the answer must have node.val = 0.
You may return the final list of trees in any order.
Example 1:
Input: 7
Output: [[0,0,0,null,null,0,0,null,null,0,0],[0,0,0,null,null,0,0,0,0],[0,0,0,0,0,0,0],[0,0,0,0,0,null,null,null,null,0,0],[0,0,0,0,0,null,null,0,0]]
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
    vector<TreeNode*> allPossibleFBT(int N) {
      vector<TreeNode*> res;
      if (N % 2 == 0) {
        return res;
      }
      if (N == 1) {
        res.push_back(new TreeNode(0));
        return res;
      }
      int rest = N - 1;
      for (int i = 1; i <= rest / 2; i+=2) {
        vector<TreeNode*> left = allPossibleFBT(i);
        vector<TreeNode*> right = allPossibleFBT(rest - i);
        for (int j = 0; j < left.size(); ++j) {
          for (int q = 0; q < right.size(); ++q) {
            TreeNode* tmp = new TreeNode(0);
            tmp->left = left[j];
            tmp->right = right[q];
            res.push_back(tmp);
            
            tmp = new TreeNode(0);
            tmp->right = left[j];
            tmp->left = right[q];
            res.push_back(tmp);
          }
        }
      }
      
      return res;
    }
};