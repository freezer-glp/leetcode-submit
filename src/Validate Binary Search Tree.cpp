/*Validate Binary Search Tree
Given a binary tree, determine if it is a valid binary search tree (BST).

Assume a BST is defined as follows:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.*/
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
    int findMax(TreeNode* root){
        //if(!root)
        //    return -1;
        if(!(root -> left) && !(root -> right)){
            return  root -> val;
        }
        int ml=-999999,mr=-999999,m = root -> val;
        if(root -> left)
            ml = findMax(root -> left);
        if(root -> right)
            mr = findMax(root -> right);
            
        if(ml > m)
            m = ml;
        if(mr > m)
            m = mr;
        return m;
    }
    int findMin(TreeNode* root){
       // if(!root)
       //     return -1;
        if(!(root -> left) && !(root -> right)){
            return  root -> val;
        }
        int ml=999999,mr=999999,m = root -> val;
        if(root -> left)
            ml = findMin(root -> left);
        if(root -> right)
            mr = findMin(root -> right);
            
        if(ml < m)
            m = ml;
        if(mr < m)
            m = mr;
        return m;
    }
    bool isValidBST(TreeNode* root) {
        if(!root)
            return true;
        if(!(root -> left) && !(root -> right))
            return true;
        bool vl=true,vr=true;
        if(root -> left){
            if(findMax(root -> left) >= root -> val)
                return false;
            else                
                vl = isValidBST(root -> left);
        }
        
        if(root -> right){
            if(findMin(root -> right) <= root -> val)
                return false;
            else                
                vr = isValidBST(root -> right);
        }
        
        return vl && vr;
        
    }
};