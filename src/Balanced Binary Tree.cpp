//Balanced Binary Tree
/*Given a binary tree, determine if it is height-balanced. 
For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of 
the two subtrees of every node never differ by more than 1.
*/
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int dfsdepth(TreeNode *root){
		if(root == NULL)
			return 0;
		else{
			return max(dfsdepth(root -> left), dfsdepth(root -> right))+1;
		}
        
    }
    bool isBalanced(TreeNode *root) {
        if(root == NULL)
			return true;
		else{
			if(isBalanced(root -> left) && isBalanced(root -> right)){
				if(abs(dfsdepth(root -> left) - dfsdepth(root -> right)) <= 1)
					return true;
			}
			return false;
		}
    }
};