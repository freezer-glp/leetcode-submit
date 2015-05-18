/*Given a binary tree, return the preorder traversal of its nodes' values.

For example:
Given binary tree {1,#,2,3},
   1
    \
     2
    /
   3
return [1,2,3].*/
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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> v = vector<int>();
        pT(root,v);
        return v;
    }
    void pT(TreeNode* root,vector<int> &v){
        if(!root)
            return;
        v.push_back(root -> val);
        pT(root -> left,v);
        pT(root -> right,v);
    }
};