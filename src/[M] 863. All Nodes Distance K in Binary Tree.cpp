/*
We are given a binary tree (with root node root), a target node, and an integer value K.

Return a list of the values of all nodes that have a distance K from the target node.  The answer can be returned in any order.

Example 1:

Input: root = [3,5,1,6,2,0,8,null,null,7,4], target = 5, K = 2

Output: [7,4,1]

Explanation: 
The nodes that are a distance 2 from the target node (with value 5)
have values 7, 4, and 1.
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
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
      vector<int> res;
      findNode(root, target->val, K, res);
      return res;
    }
    
    int findNode(TreeNode* root, int target, int k, vector<int>& res) {
      if (!root) return -1;
      if (root->val == target) {
        if (k == 0) {
          res.push_back(root->val);
          return -1;
        }
        findRes(root->left, k-1, res);
        findRes(root->right, k-1, res);
        return 1;
      }
      int l = findNode(root->left, target, k, res);
      if (l != -1) {
        if (l == k) {
          res.push_back(root->val);
        } else {
          findRes(root->right, k-l-1, res);
        }
        return l + 1;
      }
      int r = findNode(root->right, target, k, res);
      
      if (r != -1) {
        if (r == k) {
          res.push_back(root->val);
        } else {
          findRes(root->left, k-r-1, res);
        }
        return r + 1;
      }
      return -1;
    }
    
    void findRes(TreeNode* root, int k, vector<int>& res) {
      if (!root) return;
      if (k == 0) {
        res.push_back(root->val);
        return;
      }
      findRes(root->left, k - 1, res);
      findRes(root->right, k - 1, res);
    }
};