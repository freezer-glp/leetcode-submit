/*Given a binary tree, flatten it to a linked list in-place.

For example,
Given

         1
        / \
       2   5
      / \   \
     3   4   6
The flattened tree should look like:
   1
    \
     2
      \
       3
        \
         4
          \
           5
            \
             6
click to show hints.

Hints:
If you notice carefully in the flattened tree, each node's right child points to the next node of a pre-order traversal.

Hide Tags Tree Depth-first Search
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
    TreeNode* help(TreeNode* root){
        if(root == NULL)
            return NULL;
        TreeNode* l = NULL, * r = NULL;
        if(root -> left)
            l = root -> left;
        if(root -> right)
            r = root -> right;
            
        if(l == NULL && r == NULL){ // don't have left and right
            return root;
        }
            
        if(l){//root has left subtree
            l = help(l);//construct left sub tree,l is the new tree's root
            root -> right = l;
            TreeNode* cnode = l;
            while(cnode -> right != NULL)
                cnode = cnode -> right;
            if(r){
                r = help(r);
                cnode -> right =  r;
            }else{
                cnode -> right = NULL;
                
            }
        }else{//only build right subtree
            r = help(r);
            root -> right = r;
        }
        root -> left = NULL;
        return root;
    }
    void flatten(TreeNode* root) {
        root = help(root);
        
    }
};