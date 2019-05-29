/*
Given the root of a binary tree, each node has a value from 0 to 25 representing the letters 'a' to 'z': a value of 0 represents 'a', a value of 1 represents 'b', and so on.

Find the lexicographically smallest string that starts at a leaf of this tree and ends at the root.

(As a reminder, any shorter prefix of a string is lexicographically smaller: for example, "ab" is lexicographically smaller than "aba".  A leaf of a node is a node that has no children.)

Example 1:

Input: [0,1,2,3,4,3,4]
Output: "dba"
Example 2:

Input: [25,1,3,1,3,0,2]
Output: "adz"
Example 3:

Input: [2,2,1,null,1,0,null,0]
Output: "abc"
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
    string smallestFromLeaf(TreeNode* root) {
      string min = "";
      string str = "";
      if (!root) return min
      dfs(root, str, min);
      return min;
    }
    void dfs(TreeNode* root, string& str, string& min) {
      string tmp(1, 'a'+root->val);
      tmp = tmp +str;
      if (!root->left && !root->right) {
        if ((tmp < min) || min.empty()) min = tmp;
        return;
      }
      if (root->left) dfs(root->left, tmp, min);
      if (root->right) dfs(root->right, tmp, min);
    }
};