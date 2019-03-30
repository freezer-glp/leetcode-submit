/*
Given inorder and postorder traversal of a tree, construct the binary tree.

Note:
You may assume that duplicates do not exist in the tree.

For example, given

inorder = [9,3,15,20,7]
postorder = [9,15,7,20,3]
Return the following binary tree:

    3
   / \
  9  20
    /  \
   15   7
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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
      if (inorder.size() == 0) return nullptr;
      return buildTree(inorder, 0, inorder.size() - 1, 
                       postorder, 0, postorder.size() - 1);
    }
    
    TreeNode* buildTree(vector<int>& in, int li, int ri, 
                       vector<int>& po, int lp, int rp) {
      TreeNode* root = new TreeNode(po[rp]);
      if (li == ri) return root;
      int i;
      for (i = li; i < ri; ++i) {
        if (in[i] == root->val) break;
      }
      if (i > li)
        root->left = buildTree(in, li, i - 1, po, lp + i - li, rp - (ri - i) - 1);
      
      if (i < ri)
        root->right = buildTree(in, i + 1, ri, po, rp - ri + 1, rp - 1);
      return root;
    }
};